#!/usr/bin/env python3
"""Prove the final 0xA9ED0 stream ends at its parser terminator before A9F70."""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

try:
    from tools.effect_timeline import parse_program, partition_program
except ModuleNotFoundError:
    from effect_timeline import parse_program, partition_program


IMAGE_BASE = 0x00100000
STREAM = 0x004A9ED0
NEXT_ROOT = 0x004A9F70


def create_receipt(image: bytes, source: Path) -> dict[str, object]:
    text = source.read_text(encoding="utf-8")
    refs = (
        r"FLOAT_CALLBACK\(\s*func_00421B00,\s*func_004220B0,\s*[^,]+,\s*D_004A9ED0,",
        r"FLOAT_CALLBACK\(\s*func_00421B20,\s*func_004220B0,\s*[^,]+,\s*D_004A9F70,",
    )
    if not all(re.search(pattern, text) for pattern in refs):
        raise SystemExit("expected adjacent func_00421B00/func_00421B20 callback data roots")
    independent_zero_refs = [
        path.as_posix()
        for path in Path("src").rglob("*.c")
        if re.search(r"\bD_004A9F60\b", path.read_text(encoding="utf-8"))
    ]
    if independent_zero_refs:
        raise SystemExit(f"A9F60 has independent C references: {independent_zero_refs}")
    start = STREAM - IMAGE_BASE
    limit = NEXT_ROOT - IMAGE_BASE
    program = parse_program(image, start, limit)
    if program.count != 1:
        raise SystemExit(f"unexpected record count {program.count}")
    runs = partition_program(image, program)
    native = [run for run in runs if run.kind == "native_read"]
    opaque = [run for run in runs if run.kind == "opaque"]
    program_end = IMAGE_BASE + program.end
    raw_tail = NEXT_ROOT - program_end
    if raw_tail < 0:
        raise SystemExit("parser terminator crossed the next independently referenced root")
    zero_terminator = image[0x004A9F60 - IMAGE_BASE]
    if program_end != 0x004A9F61 or zero_terminator != 0:
        raise SystemExit("the stream no longer terminates at the A9F60 zero byte")
    native_size = sum(run.end - run.start for run in native)
    opaque_size = sum(run.end - run.start for run in opaque)
    span = NEXT_ROOT - STREAM
    if native_size != 134 or opaque_size != 11 or raw_tail != 15:
        raise SystemExit(
            f"unexpected split: native={native_size}, opaque={opaque_size}, tail={raw_tail}"
        )
    if native_size + opaque_size + raw_tail != span:
        raise SystemExit("stream/gap spans do not cover through the next callback root")
    return {
        "callback_root": {"symbol": "D_004A9ED0", "address": f"0x{STREAM:08X}"},
        "next_callback_root": {"symbol": "D_004A9F70", "address": f"0x{NEXT_ROOT:08X}"},
        "record_count": program.count,
        "native_terminator": {
            "address": "0x004A9F60",
            "value": zero_terminator,
            "belongs_to_parser_stream": True,
            "independent_C_symbol_references": independent_zero_refs,
        },
        "native_read_bytes": native_size,
        "opaque_payload_bytes": opaque_size,
        "unread_tail_bytes": raw_tail,
        "total_covered_bytes": span,
        "native_read_runs": [
            {
                "address": f"0x{IMAGE_BASE + run.start:08X}",
                "size": run.end - run.start,
                "fields": [field.name for field in run.fields],
            }
            for run in native
        ],
        "opaque_runs": [
            {"address": f"0x{IMAGE_BASE + run.start:08X}", "size": run.end - run.start}
            for run in opaque
        ],
        "raw_tail": {"address": f"0x{program_end:08X}", "size": raw_tail},
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--source", type=Path, default=Path("src/float_callbacks.c"))
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    receipt = create_receipt(args.rom.read_bytes(), args.source)
    output = json.dumps(receipt, indent=2) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(output, encoding="utf-8")
    else:
        print(output, end="")


if __name__ == "__main__":
    main()
