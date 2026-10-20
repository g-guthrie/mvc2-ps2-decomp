#!/usr/bin/env python3
"""Report native-bounded effect quad tables using the retail image."""

from __future__ import annotations

import argparse
import csv
import json
import re
from pathlib import Path

try:
    from tools.effect_timeline import parse_program
    from tools.effect_transform_tables import (
        NEXT_OWNER,
        ROW_SIZE,
        TABLE1_BASE,
        TABLE2_BASE,
        TABLE_SIZE,
        accessed_rows,
        body_table1_selectors,
        contiguous_row_runs,
        signed_quad,
    )
except ModuleNotFoundError:
    from effect_timeline import parse_program
    from effect_transform_tables import (
        NEXT_OWNER,
        ROW_SIZE,
        TABLE1_BASE,
        TABLE2_BASE,
        TABLE_SIZE,
        accessed_rows,
        body_table1_selectors,
        contiguous_row_runs,
        signed_quad,
    )


IMAGE_BASE = 0x00100000
STREAM_END = 0x004AA980
STREAM_END_SYMBOL = "gPs2SystemText_004AA980"
NATIVE_ONLY_ROOT_BOUNDS = {
    0x004A9360: (0x004A93D0, "native func_004220B0 callsite 0x00421540"),
    0x004A96B0: (0x004A9720, "native func_004220B0 callsite 0x00421750"),
    0x004AA160: (0x004AA240, "func_00421C00 conditional callback at 0x00421C44"),
    0x004AA240: (0x004AA320, "func_00421C00 conditional callback at 0x00421C7C"),
    0x004AA7B0: (0x004AA800, "native func_004220B0 callsite 0x00421E90"),
}
CALLBACK_SOURCES = (
    Path("src/float_callbacks.c"),
    Path("src/effect_state_callbacks.c"),
    Path("src/effect_followup_callbacks.c"),
    Path("src/effect_choice_callbacks.c"),
)


def callback_roots() -> list[int]:
    sources = {path.name: path.read_text() for path in CALLBACK_SOURCES}
    roots: set[int] = set()

    def add(pattern: str, source: str) -> None:
        roots.update(int(symbol[2:], 16) for symbol in re.findall(pattern, source))

    add(
        r"FLOAT_CALLBACK\([^,]+,\s*func_004220B0,\s*[^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
        sources["float_callbacks.c"],
    )
    add(
        r"STATE_EFFECT\([^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
        sources["effect_state_callbacks.c"],
    )
    add(
        r"FOLLOWUP_EFFECT\([^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
        sources["effect_followup_callbacks.c"],
    )
    choice = sources["effect_choice_callbacks.c"]
    add(r"CHOICE_EFFECT\([^,]+,[^,]+,\s*(D_004A[0-9A-Fa-f]{4})", choice)
    add(r"CHOICE_EFFECT\([^,]+,[^,]+,[^,]+,\s*(D_004A[0-9A-Fa-f]{4})", choice)
    for source in sources.values():
        add(r"func_004220B0\([^,]+,\s*(D_004A[0-9A-Fa-f]{4})", source)
    return sorted(roots)


def parser_root_inventory() -> list[int]:
    return sorted(set(callback_roots()) | set(NATIVE_ONLY_ROOT_BOUNDS))


def complement_row_runs(rows: list[int]) -> list[tuple[int, int]]:
    used = set(rows)
    return contiguous_row_runs(row for row in range(TABLE_SIZE // ROW_SIZE) if row not in used)


def verify_stream_end_owner() -> None:
    with Path("config/data_units.csv").open(newline="", encoding="utf-8") as stream:
        units = {row["name"]: row for row in csv.DictReader(stream)}
    owner = units.get(STREAM_END_SYMBOL)
    if owner is None or int(owner["address"], 0) != STREAM_END:
        raise SystemExit(
            f"missing effect stream end owner {STREAM_END_SYMBOL} at 0x{STREAM_END:08X}"
        )


def create_receipt(image: bytes) -> dict[str, object]:
    verify_stream_end_owner()
    source_roots = callback_roots()
    if len(source_roots) != 47:
        raise SystemExit(f"expected 47 source-backed parser roots, found {len(source_roots)}")
    roots = parser_root_inventory()
    if len(roots) != 52:
        raise SystemExit(f"expected 52 source/native parser roots, found {len(roots)}")
    if TABLE1_BASE + TABLE_SIZE != TABLE2_BASE:
        raise SystemExit("the table1 next-base boundary changed")
    if TABLE2_BASE + TABLE_SIZE != NEXT_OWNER:
        raise SystemExit("the table2 next-owner boundary changed")

    selectors: set[int] = set()
    body_opcode10: list[dict[str, int]] = []
    parsed_roots = []
    for index, address in enumerate(roots):
        if index + 1 < len(roots):
            next_root = roots[index + 1]
            next_origin = (
                NATIVE_ONLY_ROOT_BOUNDS[next_root][1]
                if next_root in NATIVE_ONLY_ROOT_BOUNDS
                else "source callback reference"
            )
        else:
            next_root = STREAM_END
            next_origin = f"independent source symbol {STREAM_END_SYMBOL}"
        if address in NATIVE_ONLY_ROOT_BOUNDS:
            expected_next, origin = NATIVE_ONLY_ROOT_BOUNDS[address]
            if expected_next != next_root:
                raise SystemExit(
                    f"native root 0x{address:08X} has proven bound 0x{expected_next:08X}, "
                    f"but actual root inventory gives 0x{next_root:08X}"
                )
        else:
            origin = "source callback reference"
        limit = next_root - IMAGE_BASE
        program = parse_program(image, address - IMAGE_BASE, limit)
        if program.count != 1:
            raise SystemExit(f"unexpected count {program.count} at 0x{address:08X}")
        if program.end > limit:
            raise SystemExit(f"stream at 0x{address:08X} crosses bound 0x{next_root:08X}")
        opcodes = [command.opcode for record in program.records for command in record.commands]
        root_selectors = body_table1_selectors(opcodes)
        selectors.update(root_selectors)
        for record in program.records:
            for command in record.commands:
                if command.opcode == 10:
                    body_opcode10.append(
                        {"stream": address, "command_address": IMAGE_BASE + command.offset,
                         "index": command.operand[0]}
                    )
        parsed_roots.append(
            {
                "address": f"0x{address:08X}",
                "origin": origin,
                "next_root": f"0x{next_root:08X}",
                "next_root_origin": next_origin,
                "count": program.count,
                "parsed_bytes": program.end - program.start,
                "body_command_count": sum(len(record.commands) for record in program.records),
                "body_table1_selectors": sorted(root_selectors),
            }
        )

    rows = accessed_rows(selectors)
    if any(row >= TABLE_SIZE // ROW_SIZE for row in rows):
        raise SystemExit("a source-backed table index exceeds the proven 256-row bound")
    typed_runs = []
    for first, end in contiguous_row_runs(rows):
        entries = []
        for row in range(first, end):
            address = TABLE1_BASE + row * ROW_SIZE
            entries.append(
                {
                    "row": row,
                    "address": f"0x{address:08X}",
                    "components_s32": list(signed_quad(image, address)),
                }
            )
        typed_runs.append(
            {
                "first_row": first,
                "end_row_exclusive": end,
                "address": f"0x{TABLE1_BASE + first * ROW_SIZE:08X}",
                "size": (end - first) * ROW_SIZE,
                "entries": entries,
            }
        )

    raw_runs = [
        {
            "first_row": first,
            "end_row_exclusive": end,
            "address": f"0x{TABLE1_BASE + first * ROW_SIZE:08X}",
            "size": (end - first) * ROW_SIZE,
            "zero_initialized": not any(
                image[TABLE1_BASE + first * ROW_SIZE - IMAGE_BASE:
                      TABLE1_BASE + end * ROW_SIZE - IMAGE_BASE]
            ),
        }
        for first, end in complement_row_runs(rows)
    ]

    table2 = image[TABLE2_BASE - IMAGE_BASE:TABLE2_BASE - IMAGE_BASE + TABLE_SIZE]
    if len(table2) != TABLE_SIZE:
        raise SystemExit("retail image is short at table2")
    table1_read_bytes = len(rows) * ROW_SIZE
    table1_raw_bytes = TABLE_SIZE - table1_read_bytes
    if table1_read_bytes + table1_raw_bytes + TABLE_SIZE != 2 * TABLE_SIZE:
        raise SystemExit("quad table coverage does not partition both bounded spans")

    return {
        "layout": "four native signed 32-bit components per 16-byte record",
        "table1": {
            "base": f"0x{TABLE1_BASE:08X}",
            "logical_span_bytes": TABLE_SIZE,
            "next_table_base": f"0x{TABLE2_BASE:08X}",
            "native_opcode_source": "func_00422150 body opcode byte; special opcodes 0,1,4,5,10,13 bypass this lookup",
            "text_source": "func_00422740 ASCII ranges 0x30-0x39, 0x41-0x5A, 0x61-0x7A plus fixed rows 80,81,145,146,149",
            "observed_stream_selector_values": sorted(selectors),
            "observed_stream_selector_count": len(selectors),
            "typed_row_count": len(rows),
            "typed_bytes": table1_read_bytes,
            "raw_bytes": table1_raw_bytes,
            "typed_runs": typed_runs,
            "raw_runs": raw_runs,
        },
        "table2": {
            "base": f"0x{TABLE2_BASE:08X}",
            "logical_candidate_span_bytes": TABLE_SIZE,
            "next_independent_owner": f"0x{NEXT_OWNER:08X}",
            "native_path": "func_00422150 body opcode 10 reads u8 index and uses index*16",
            "observed_opcode10_accesses": body_opcode10,
            "zero_initialized": not any(table2),
            "verified_image_bytes": len(table2),
            "credit": "placeholder_no_observed_stream_selector",
        },
        "parser_roots": parsed_roots,
        "coverage_bytes": 2 * TABLE_SIZE,
        "typed_bytes": table1_read_bytes,
        "raw_or_held_bytes": table1_raw_bytes + TABLE_SIZE,
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    receipt = create_receipt(args.rom.read_bytes())
    output = json.dumps(receipt, indent=2) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(output, encoding="utf-8")
    else:
        print(output, end="")


if __name__ == "__main__":
    main()
