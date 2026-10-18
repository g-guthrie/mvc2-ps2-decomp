#!/usr/bin/env python3
"""Audit native SD/LD spill candidates and test available C with unmodified Sony GCC."""
import argparse
import csv
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]


def inventory(target):
    image = target.read_bytes()
    selected = []
    with (ROOT / "config/functions.csv").open() as stream:
        for row in csv.DictReader(stream):
            address, size = int(row["address"], 0), int(row["size"], 0)
            words = struct.unpack("<" + "I" * (size // 4), image[address - 0x100000:address - 0x100000 + size])
            saves = []
            for word in words[:32]:
                if word >> 26 in (2, 3):
                    break
                register = word >> 16 & 31
                if word >> 26 == 63 and word >> 21 & 31 == 29 and (16 <= register <= 23 or register in (30, 31)):
                    saves.append((register, word & 65535))
            offsets = sorted({offset for _, offset in saves})
            if len(offsets) >= 2 and all(b - a == 16 for a, b in zip(offsets, offsets[1:])):
                selected.append({"name": row["name"], "address": row["address"], "size": row["size"], "saves": saves})
    return selected


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--target", type=Path, default=ROOT / "private/SLUS_204.86.rom")
    parser.add_argument("--inventory", type=Path, help="explicit CSV with name,address,size, e.g. the original 196-function list")
    parser.add_argument("--output", type=Path, default=ROOT / "build/sony29-probes")
    args = parser.parse_args()
    os.chdir(ROOT)
    args.output.mkdir(parents=True, exist_ok=True)
    if args.inventory:
        with args.inventory.open() as stream:
            selected = list(csv.DictReader(stream))
    else:
        selected = inventory(args.target)
    wanted = {row["name"]: row for row in selected}
    definitions = {}
    for source in sorted((ROOT / "src").glob("*.c")):
        for name in re.findall(r"\b(func_[0-9a-fA-F]{8})\s*\([^;{}]*\)\s*\{", source.read_text()):
            if name in wanted:
                definitions.setdefault(name, []).append(source.relative_to(ROOT).as_posix())
    results = []
    for row in selected:
        if row["name"] not in definitions:
            results.append({**row, "status": "no C definition"})
    for source in sorted({p for paths in definitions.values() for p in paths}):
        unit = args.output / Path(source).stem
        preprocessed = unit.with_suffix(".i")
        preprocess = subprocess.run([os.environ["WIBO"], os.environ["SNCPP"], "-P", "-Isrc", source, str(preprocessed)], capture_output=True, text=True)
        for threshold in (0, 8):
            assembly = unit.with_suffix(f".g{threshold}.s")
            obj = unit.with_suffix(f".g{threshold}.o")
            names = [name for name, paths in definitions.items() if source in paths]
            commands = [
                [os.environ["WIBO"], os.environ["EE29CC1"], str(preprocessed), "-O2", f"-G{threshold}", "-ffunction-sections", "-quiet", "-o", str(assembly)],
                [os.environ["WIBO"], os.environ["SNAS"], f"-G{threshold}", "-o", str(obj), str(assembly)],
            ]
            failed = preprocess if preprocess.returncode else None
            for command in commands:
                if failed:
                    break
                run = subprocess.run(command, capture_output=True, text=True)
                if run.returncode:
                    failed = run
            for name in names:
                result = {**wanted[name], "source": source, "small_data_threshold": threshold}
                if failed:
                    result.update(status="compile failure", detail=(failed.stdout + failed.stderr)[-4000:])
                else:
                    catalog = unit.with_suffix(".csv")
                    with catalog.open("w") as stream:
                        writer = csv.DictWriter(stream, fieldnames=["name", "address", "size", "source", "status"])
                        writer.writeheader()
                        writer.writerow({key: value for key, value in {**wanted[name], "source": source, "status": "complete"}.items() if key in writer.fieldnames})
                    check = subprocess.run([sys.executable, "tools/verify_object.py", str(obj), str(args.target), "--source", source, "--matches", str(catalog)], capture_output=True, text=True)
                    result.update(status="exact" if check.returncode == 0 else "mismatch", detail=(check.stdout + check.stderr)[-4000:])
                results.append(result)
    report = args.output / "report.json"
    report.write_text(json.dumps({"inventory_count": len(selected), "functions_with_C": len(definitions), "results": results}, indent=2) + "\n")
    print(f"{len(selected)} candidates; {len(definitions)} with C; {sum(r['status'] == 'exact' for r in results)} exact compiler/source/flag results. Report: {report}")
    print("No source, catalog, object instructions, or matching credit were modified.")


if __name__ == "__main__":
    main()
