#!/usr/bin/env python3
"""Report source/native callback roots in the late effect-timeline family."""

from __future__ import annotations

import argparse
import csv
from pathlib import Path

try:
    from tools.effect_timeline import parse_program, partition_program
    from tools.report_effect_transform_tables import IMAGE_BASE, callback_roots
except ModuleNotFoundError:
    from effect_timeline import parse_program, partition_program
    from report_effect_transform_tables import IMAGE_BASE, callback_roots


START = 0x004A9F70
END = 0x004AA980
NATIVE_ONLY_ROOTS = {
    0x004AA160: "func_00421C00 conditional callback at 0x00421C44",
    0x004AA240: "func_00421C00 conditional callback at 0x00421C7C",
    0x004AA7B0: "native callsite 0x00421E90",
}
NEXT_OWNER_SYMBOL = "gPs2SystemText_004AA980"


def late_roots() -> list[tuple[int, str]]:
    roots = {
        address: "source callback root"
        for address in callback_roots()
        if START <= address < END
    }
    roots.update(NATIVE_ONLY_ROOTS)
    return sorted(roots.items())


def verify_next_owner() -> None:
    with Path("config/data_units.csv").open(newline="", encoding="utf-8") as stream:
        units = {row["name"]: row for row in csv.DictReader(stream)}
    owner = units.get(NEXT_OWNER_SYMBOL)
    if owner is None or int(owner["address"], 0) != END:
        raise SystemExit(f"missing independent next owner {NEXT_OWNER_SYMBOL} at 0x{END:08X}")


def parse_late_family(image: bytes) -> list[dict[str, object]]:
    verify_next_owner()
    roots = late_roots()
    if len(roots) != 22:
        raise SystemExit(f"expected 22 callback roots in late family, found {len(roots)}")
    rows = []
    total_read = total_opaque = total_gap = total_commands = 0
    for index, (address, origin) in enumerate(roots):
        if index + 1 < len(roots):
            next_root = roots[index + 1][0]
            next_origin = roots[index + 1][1]
        else:
            next_root = END
            next_origin = f"independent source symbol {NEXT_OWNER_SYMBOL}"
        start = address - IMAGE_BASE
        limit = next_root - IMAGE_BASE
        program = parse_program(image, start, limit)
        if program.count != 1:
            raise SystemExit(f"unexpected count {program.count} at 0x{address:08X}")
        if program.end > limit:
            raise SystemExit(f"stream at 0x{address:08X} crosses next root")
        runs = partition_program(image, program)
        read_bytes = sum(run.end - run.start for run in runs if run.kind == "native_read")
        opaque_bytes = sum(run.end - run.start for run in runs if run.kind == "opaque")
        stream_bytes = program.end - program.start
        gap_bytes = limit - program.end
        command_count = sum(len(record.commands) for record in program.records)
        total_read += read_bytes
        total_opaque += opaque_bytes
        total_gap += gap_bytes
        total_commands += command_count
        rows.append(
            {
                "kind": "stream",
                "address": f"0x{address:08X}",
                "origin": origin,
                "next_root": f"0x{next_root:08X}",
                "next_root_origin": next_origin,
                "record_count": program.count,
                "stream_bytes": stream_bytes,
                "native_read_bytes": read_bytes,
                "opaque_payload_bytes": opaque_bytes,
                "raw_gap_bytes": gap_bytes,
                "body_command_count": command_count,
            }
        )
    span = END - START
    if (total_read, total_opaque, total_gap) != (2202, 191, 183):
        raise SystemExit(
            f"accounting changed: native-read={total_read}, opaque={total_opaque}, gap={total_gap}"
        )
    if total_read + total_opaque + total_gap != span:
        raise SystemExit("parser, opaque, and root-gap spans do not cover the family")
    rows.append(
        {
            "kind": "TOTAL",
            "address": f"0x{START:08X}",
            "origin": "22 source/native callback roots",
            "next_root": f"0x{END:08X}",
            "next_root_origin": f"independent source symbol {NEXT_OWNER_SYMBOL}",
            "record_count": len(roots),
            "stream_bytes": total_read + total_opaque,
            "native_read_bytes": total_read,
            "opaque_payload_bytes": total_opaque,
            "raw_gap_bytes": total_gap,
            "body_command_count": total_commands,
        }
    )
    return rows


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    rows = parse_late_family(args.rom.read_bytes())
    headers = [
        "kind", "address", "origin", "next_root", "next_root_origin",
        "record_count", "stream_bytes", "native_read_bytes",
        "opaque_payload_bytes", "raw_gap_bytes", "body_command_count",
    ]
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        with args.output.open("w", newline="", encoding="utf-8") as stream:
            writer = csv.DictWriter(stream, fieldnames=headers, lineterminator="\n")
            writer.writeheader()
            writer.writerows(rows)
    else:
        writer = csv.DictWriter(__import__("sys").stdout, fieldnames=headers, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


if __name__ == "__main__":
    main()
