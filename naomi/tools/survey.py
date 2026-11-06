#!/usr/bin/env python3
"""Index raw SH-4 BSR call hints in the reference main image.

This is navigation evidence only: an opcode hit is not a function boundary.
"""
import argparse
import json
from collections import defaultdict

from core import ROOT, load, number, sha, verify_rom
from vendor.sh4dis.sh4 import disasm



def survey():
    target = load(ROOT / "config/target.json")
    program = verify_rom(target)
    main = target["main"]
    base, offset, size = (number(main[k]) for k in ("address", "rom_offset", "size"))
    image = program[offset:offset + size]
    calls = defaultdict(list)
    for pos in range(0, len(image) - 1, 2):
        word = int.from_bytes(image[pos:pos + 2], "little")
        if word >> 12 != 0xB:
            continue
        disp = word & 0x0FFF
        if disp & 0x800:
            disp -= 0x1000
        callsite = base + pos
        destination = callsite + 4 + disp * 2
        if base <= destination < base + size and destination % 2 == 0:
            calls[destination].append(callsite)
    rows = []
    for destination in sorted(calls):
        pos = destination - base
        word = int.from_bytes(image[pos:pos + 2], "little")
        rows.append({
            "target": f"0x{destination:08x}",
            "reference_word": f"0x{word:04x}",
            "disassembly": disasm(word, destination),
            "incoming_raw_calls": [f"0x{x:08x}" for x in calls[destination]],
        })
    return {"main_sha256": sha(image),
            "status": "provisional raw-opcode hints, not proven code/function boundaries",
            "candidates": rows}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, default=20, help="print the first N target summaries (default: 20)")
    args = parser.parse_args()
    result = survey()
    (ROOT / "build").mkdir(exist_ok=True)
    (ROOT / "build/survey.json").write_text(json.dumps(result, indent=2) + "\n")
    if args.limit is None:
        print(json.dumps(result, indent=2))
    else:
        for row in result["candidates"][:max(0, args.limit)]:
            print(f"{row['target']} <- {len(row['incoming_raw_calls'])} raw BSR call(s): {row['disassembly']}")


if __name__ == "__main__":
    main()
