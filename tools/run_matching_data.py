#!/usr/bin/env python3
"""Compile and private-verify each source-owned initialized-data unit.

Called by tools/compile_matching_data.sh. Units compile in parallel over a
process pool and verify in the worker with the retail image and config
tables loaded once; compiled objects are cached by content (see
tools/build_runner.py). Every unit runs even after a failure, and all
failures are reported at the end.

usage: run_matching_data.py BUILD TARGET WIBO MWCC [--jobs N] [--no-cache]
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import os
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build_runner  # noqa: E402

FLAGS = ["-c", "-lang", "c", "-O3", "-sdatathreshold", "0", "-i", "src/data", "-i", "src"]

_settings: dict = {}


def init_worker(settings: dict) -> None:
    _settings.update(settings)
    _settings["cache"] = build_runner.CompileCache(Path(settings["cache_root"]), settings["use_cache"])
    build_runner.install_verifier_memo()


VU_ASM = Path(__file__).resolve().parent / "vu_asm.py"
GNU_AS = os.environ.get("AS", "mipsel-linux-gnu-as")
GAS_FLAGS = ["-EL", "-march=r5900", "-mabi=eabi", "-G0", "-no-pad-sections"]
# Hand-written sources per kind: ee_code_blob units are EE machine code kept in
# .data (kernel patches copied to their runtime address) as GNU as sources;
# VU1 microcode packets are VU assembly (tools/vu_asm.py).
ASM_KINDS = {".s": "ee_code_blob", ".vsm": "vu1_microcode_dma_packets"}


def assemble_vu_unit(unit: dict, object_path: Path) -> subprocess.CompletedProcess:
    """Assemble hand-written VU microcode (src/vu/*.vsm) into a data object."""
    name, size = unit["name"], int(unit["size"], 0)
    binary = object_path.with_suffix(".bin")
    wrapper = object_path.with_suffix(".s")
    result = subprocess.run(
        [sys.executable, str(VU_ASM), "asm", unit["source"], "-o", str(binary)],
        text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
    )
    if result.returncode:
        return result
    wrapper.write_text(
        f'.section {unit["section"]}, "aw"\n.p2align 4\n.globl {name}\n'
        f'.type {name}, @object\n.size {name}, {size}\n{name}:\n'
        f'.incbin "{binary.resolve()}"\n'
    )
    return subprocess.run(
        [GNU_AS, *GAS_FLAGS, "-o", str(object_path), str(wrapper)],
        text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
    )


def compile_and_verify(unit: dict) -> tuple[bool, str, bool]:
    source = Path(unit["source"])
    name = unit["name"]
    wibo, mwcc, target = _settings["wibo"], _settings["mwcc"], _settings["target"]
    # Match generate_hybrid_relink.py's object naming convention.
    object_path = Path(_settings["build"]) / source.relative_to("src").with_suffix(".o")
    object_path.parent.mkdir(parents=True, exist_ok=True)
    expected_kind = ASM_KINDS.get(source.suffix)
    if expected_kind and unit["kind"] != expected_kind:
        return False, f"{source.suffix} data source requires kind {expected_kind}: {name}\n", False
    digest = hashlib.sha256(f"{build_runner.CACHE_VERSION}\0data\0{wibo}\0{mwcc}\0".encode())
    digest.update(" ".join(FLAGS).encode() + b"\0" + str(source).encode())
    digest.update(build_runner.file_digest(source, (Path("src/data"), Path("src"))))
    if source.suffix == ".vsm":
        digest.update(VU_ASM.read_bytes())
    stat = os.stat(mwcc)
    digest.update(f"{stat.st_size}:{stat.st_mtime_ns}".encode())
    key = digest.hexdigest()
    cache = _settings["cache"]
    log = cache.restore(key, [object_path])
    cached = log is not None
    if not cached:
        if object_path.exists():
            object_path.unlink()
        if source.suffix == ".vsm":
            result = assemble_vu_unit(unit, object_path)
        elif source.suffix == ".s":
            result = subprocess.run(
                [GNU_AS, *GAS_FLAGS, "-o", str(object_path), str(source)],
                text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            )
        else:
            env = dict(os.environ, MWCIncludes=str(Path(mwcc).parent))
            result = subprocess.run(
                [wibo, mwcc, str(source), *FLAGS, "-o", str(object_path)],
                env=env, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            )
        if result.returncode:
            return False, (
                f"compile failed for {name} from {source} "
                f"(exit {result.returncode})\n{result.stdout}"
            ), False
        log = result.stdout
        cache.store(key, [object_path], log)
    ok, output = build_runner.run_tool_main(
        "verify_data_object", [str(object_path), target, "--name", name]
    )
    if not ok:
        return False, f"verification failed for {name} from {source}\n{output}", cached
    return True, log + output, cached


def verify_switch_table(unit: dict) -> tuple[bool, str, bool]:
    source = Path(unit["source"])
    name = unit["name"]
    if unit["source"] not in _settings["code_sources"]:
        return False, f"compiler switch table has no registered C owner: {name}\n", False
    object_path = Path(_settings["build"]) / source.relative_to("src").with_suffix(".o")
    if not object_path.is_file():
        return False, f"compile code owner before its switch table: {source}\n", False
    ok, output = build_runner.run_tool_main("verify_data_object", [
        str(object_path), _settings["target"], "--name", name,
        "--symbols", "config/symbol_addrs.txt",
    ])
    return ok, output if ok else f"verification failed for {name}\n{output}", False


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("build")
    parser.add_argument("target")
    parser.add_argument("wibo")
    parser.add_argument("mwcc")
    parser.add_argument("--jobs", type=int, default=None)
    parser.add_argument("--no-cache", action="store_true")
    parser.add_argument("--cache-dir", default="build/cache/data")
    args = parser.parse_args()
    jobs = args.jobs or build_runner.worker_count()
    started = time.monotonic()
    Path(args.build, "data").mkdir(parents=True, exist_ok=True)

    with Path("config/data_units.csv").open(newline="", encoding="utf-8") as stream:
        units = list(csv.DictReader(stream))
    with Path("config/matches.csv").open(newline="", encoding="utf-8") as stream:
        code_sources = {
            row["source"] for row in csv.DictReader(stream)
            if row["status"] in {"matching", "complete"}
        }

    standalone = [unit for unit in units if unit["kind"] != "compiler_switch_table"]
    switch_tables = [unit for unit in units if unit["kind"] == "compiler_switch_table"]
    owners = {}
    for unit in standalone:
        object_name = Path(unit["source"]).stem + ".o"
        previous = owners.setdefault(object_name, unit)
        if previous is not unit:
            raise SystemExit(
                f"standalone data units {previous['name']} and {unit['name']} "
                f"share output object path {object_name}"
            )

    settings = {
        "build": args.build, "target": args.target, "wibo": args.wibo, "mwcc": args.mwcc,
        "cache_root": args.cache_dir, "use_cache": not args.no_cache,
        "code_sources": code_sources,
    }
    failures, cached = [], 0
    with ProcessPoolExecutor(max_workers=jobs, initializer=init_worker, initargs=(settings,)) as pool:
        futures = {pool.submit(compile_and_verify, unit): unit for unit in standalone}
        for future in as_completed(futures):
            ok, output, was_cached = future.result()
            cached += was_cached
            sys.stdout.write(output)
            if not ok:
                failures.append(output)
    # Switch tables live in code objects, which are all built by now.
    init_worker(settings)
    for unit in switch_tables:
        ok, output, _ = verify_switch_table(unit)
        sys.stdout.write(output)
        if not ok:
            failures.append(output)
    elapsed = time.monotonic() - started
    print(f"run_matching_data: {len(units)} units in {elapsed:.0f}s, {cached} restored from cache")
    if failures:
        print(f"run_matching_data: {len(failures)} data unit(s) failed:", file=sys.stderr)
        for failure in failures:
            print(failure.rstrip(), file=sys.stderr)
        raise SystemExit(1)


if __name__ == "__main__":
    main()
