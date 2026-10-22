#!/usr/bin/env python3
"""Run tools/compile_matching.sh in parallel, with verification in-process.

compile_matching.sh stays the single source of truth for how each unit is
built, and still runs on its own with `sh`. This runner reads it instead of
executing it top to bottom:

1. The prelude (up to `mkdir -p "$BUILD"`) runs once in `sh`, and the
   environment it leaves is reused for every command.
2. The body is split into logical commands. `for unit in ...; do ... done`
   loops are expanded. Any other shell control flow is rejected, so a
   construct this runner cannot schedule fails loudly.
3. Commands that name a common `$BUILD/...` file are joined into one job and
   keep their script order. Jobs share no build files, so they run in
   parallel.
4. `tools/verify_object.py` commands run in the worker process, with the
   retail image and config tables loaded once (see tools/build_runner.py).
   Every other command runs in `sh`, with its outputs cached by content.

Every job runs even after a failure, and all failures are reported at the
end, so one broken unit does not hide the next. The data stage
(tools/compile_matching_data.sh) runs after the code jobs finish, as in the
serial script.

usage: run_matching.py [--jobs N] [--no-cache] [--code-only]
"""

from __future__ import annotations

import argparse
import hashlib
import os
import re
import shlex
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build_runner  # noqa: E402

SCRIPT = Path("tools/compile_matching.sh")
DATA_STEP = 'PYTHON="$PYTHON" tools/compile_matching_data.sh'
PRELUDE_END = 'mkdir -p "$BUILD"'
VERIFY_PREFIX = '"$PYTHON" tools/verify_object.py '
BUILD_FILE_RE = re.compile(r"\$BUILD/([A-Za-z0-9_.$/-]+)")
VAR_RE = re.compile(r"\$\{?([A-Za-z_][A-Za-z0-9_]*)")
REPO_FILE_RE = re.compile(r"(?<![\w$/.-])((?:src|include|tools|asm|config)/[A-Za-z0-9_./-]+)")
FOR_RE = re.compile(r"^for (\w+) in ([^;]*); do$")
CONTROL_RE = re.compile(r"^(if|then|else|elif|fi|while|until|case|esac|do|done)\b")


def logical_lines(lines: list[str]) -> list[str]:
    result, parts = [], []
    for line in lines:
        stripped = line.strip()
        if not parts and (not stripped or stripped.startswith("#")):
            continue
        if line.rstrip().endswith("\\"):
            parts.append(line.rstrip()[:-1].strip())
            continue
        parts.append(stripped)
        result.append(" ".join(part for part in parts if part))
        parts = []
    if parts:
        raise SystemExit(f"{SCRIPT}: file ends inside a continued command")
    return result


def parse_script(text: str) -> tuple[str, list[str]]:
    lines = text.split("\n")
    try:
        end = next(i for i, line in enumerate(lines) if line.strip() == PRELUDE_END)
        data = next(i for i, line in enumerate(lines) if line.strip() == DATA_STEP)
    except StopIteration:
        raise SystemExit(f"{SCRIPT}: missing prelude end or data step line") from None
    if any(line.strip() and not line.strip().startswith("#") for line in lines[data + 1:]):
        raise SystemExit(f"{SCRIPT}: commands after the data step are not supported")
    prelude = "\n".join(lines[:end + 1])
    commands: list[str] = []
    body = iter(logical_lines(lines[end + 1:data]))
    for command in body:
        loop = FOR_RE.match(command)
        if loop:
            variable, values = loop.group(1), loop.group(2).split()
            inner = []
            for nested in body:
                if nested == "done":
                    break
                if FOR_RE.match(nested) or CONTROL_RE.match(nested):
                    raise SystemExit(f"{SCRIPT}: unsupported nesting in loop: {nested[:60]}")
                inner.append(nested)
            else:
                raise SystemExit(f"{SCRIPT}: loop without done")
            for value in values:
                for nested in inner:
                    commands.append(
                        nested.replace("${" + variable + "}", value).replace("$" + variable, value)
                    )
            continue
        if CONTROL_RE.match(command):
            raise SystemExit(f"{SCRIPT}: unsupported shell control flow: {command[:60]}")
        commands.append(command)
    return prelude, commands


def group_jobs(commands: list[str]) -> list[list[str]]:
    parent = list(range(len(commands)))

    def find(i):
        while parent[i] != i:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    owner: dict[str, int] = {}
    for index, command in enumerate(commands):
        for name in BUILD_FILE_RE.findall(command):
            if name in owner:
                parent[find(index)] = find(owner[name])
            else:
                owner[name] = index
    groups: dict[int, list[str]] = {}
    for index, command in enumerate(commands):
        groups.setdefault(find(index), []).append(command)
    return [groups[root] for root in sorted(groups)]


def prelude_environment(prelude: str) -> dict[str, str]:
    script = prelude + '\nexport BUILD PYTHON MATCH_FLAGS SNCPP SNCC1 SNAS GNUAS EE29CC1 2>/dev/null || true\nenv -0\n'
    result = subprocess.run(["sh", "-c", script], stdout=subprocess.PIPE, check=True)
    env = {}
    for item in result.stdout.split(b"\0"):
        if b"=" in item:
            key, _, value = item.partition(b"=")
            env[key.decode()] = value.decode()
    return env


_env: dict[str, str] = {}
_cache: build_runner.CompileCache | None = None


def init_worker(env: dict[str, str], cache_root: str, use_cache: bool) -> None:
    global _env, _cache
    _env = env
    _cache = build_runner.CompileCache(Path(cache_root), use_cache)
    build_runner.install_verifier_memo()


def expand(word: str) -> str:
    return word.replace("$BUILD", _env["BUILD"]).replace("$PYTHON", _env.get("PYTHON", "python3"))


def command_key(command: str, earlier: dict[str, bytes]) -> str:
    digest = hashlib.sha256(f"{build_runner.CACHE_VERSION}\0{command}\0".encode())
    for name in sorted(set(VAR_RE.findall(command))):
        value = _env.get(name, "")
        digest.update(f"{name}={value}\0".encode())
        if os.path.isfile(value):
            stat = os.stat(value)
            digest.update(f"{stat.st_size}:{stat.st_mtime_ns}\0".encode())
    words = command.split()
    include_dirs = [Path(words[i + 1]) for i, w in enumerate(words[:-1]) if w in {"-i", "-I"}]
    for path in sorted(set(REPO_FILE_RE.findall(command))):
        if os.path.isfile(path):
            digest.update(path.encode() + b"\0" + build_runner.file_digest(Path(path), include_dirs))
    for name, content in sorted(earlier.items()):
        if f"$BUILD/{name}" in command:
            digest.update(name.encode() + b"\0" + content)
    return digest.hexdigest()


def run_job(commands: list[str]) -> tuple[bool, str, int, int]:
    log, cached, ran = [], 0, 0
    produced: dict[str, bytes] = {}
    for command in commands:
        if command.startswith(VERIFY_PREFIX):
            argv = [expand(word) for word in shlex.split(command)[2:]]
            ok, output = build_runner.run_tool_main("verify_object", argv)
            log.append(output)
            if not ok:
                return False, "".join(log) + f"failed: {command}\n", cached, ran
            continue
        names = list(dict.fromkeys(BUILD_FILE_RE.findall(command)))
        outputs = [Path(_env["BUILD"], name) for name in names]
        key = command_key(command, produced)
        restored = _cache.restore(key, outputs)
        if restored is not None:
            log.append(restored)
            cached += 1
        else:
            for name, output in zip(names, outputs):
                if name not in produced and output.exists():
                    output.unlink()  # a stale object must not survive a failed step
            result = subprocess.run(
                ["sh", "-eu", "-c", command], env=_env, text=True,
                stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            )
            log.append(result.stdout)
            if result.returncode:
                return False, "".join(log) + f"failed (exit {result.returncode}): {command}\n", cached, ran
            _cache.store(key, outputs, result.stdout)
            ran += 1
        for name, output in zip(names, outputs):
            if output.is_file():
                produced[name] = hashlib.sha256(output.read_bytes()).digest()
    return True, "".join(log), cached, ran


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--jobs", type=int, default=None)
    parser.add_argument("--no-cache", action="store_true")
    parser.add_argument("--code-only", action="store_true")
    parser.add_argument("--cache-dir", default="build/cache/code")
    args = parser.parse_args()
    jobs = args.jobs or build_runner.worker_count()
    started = time.monotonic()

    prelude, commands = parse_script(SCRIPT.read_text(encoding="utf-8"))
    env = prelude_environment(prelude)
    groups = group_jobs(commands)
    print(f"run_matching: {len(commands)} commands in {len(groups)} jobs on {jobs} workers", flush=True)

    failures, cached, ran = [], 0, 0
    with ProcessPoolExecutor(
        max_workers=jobs, initializer=init_worker,
        initargs=(env, args.cache_dir, not args.no_cache),
    ) as pool:
        futures = {pool.submit(run_job, group): group for group in groups}
        for future in as_completed(futures):
            ok, output, job_cached, job_ran = future.result()
            cached += job_cached
            ran += job_ran
            sys.stdout.write(output)
            if not ok:
                tail = output.rstrip().splitlines()[-2:]
                failures.append("\n    ".join(reversed(tail)))
    elapsed = time.monotonic() - started
    print(f"run_matching: code stage {elapsed:.0f}s, {ran} commands run, {cached} restored from cache")
    if failures:
        print(f"run_matching: {len(failures)} code job(s) failed:", file=sys.stderr)
        for failure in failures:
            print(f"  {failure}", file=sys.stderr)
        raise SystemExit(1)
    if args.code_only:
        return
    subprocess.run(["sh", "tools/compile_matching_data.sh"], env=env, check=True)


if __name__ == "__main__":
    main()
