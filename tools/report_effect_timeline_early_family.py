#!/usr/bin/env python3
"""Report native/source-bounded streams preceding the A9280 family."""

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


START = 0x004A8F80
END = 0x004A9280


def early_roots() -> list[int]:
    return sorted(address for address in callback_roots() if START <= address < END)


def parse_early_family(image: bytes) -> list[dict[str, object]]:
    roots = early_roots()
    if roots != [0x004A8F80, 0x004A9000, 0x004A9060, 0x004A9120, 0x004A91E0]:
        raise SystemExit(f"unexpected early callback roots: {[hex(root) for root in roots]}")
    rows = []
    total_read = total_opaque = total_gap = total_commands = 0
    for index, address in enumerate(roots):
        next_root = roots[index + 1] if index + 1 < len(roots) else END
        program = parse_program(image, address - IMAGE_BASE, next_root - IMAGE_BASE)
        if program.count != 1:
            raise SystemExit(f"unexpected count {program.count} at 0x{address:08X}")
        if program.end > next_root - IMAGE_BASE:
            raise SystemExit(f"stream at 0x{address:08X} crosses next callback root")
        runs = partition_program(image, program)
        read_bytes = sum(run.end - run.start for run in runs if run.kind == "native_read")
        opaque_bytes = sum(run.end - run.start for run in runs if run.kind == "opaque")
        stream_bytes = program.end - program.start
        gap_bytes = next_root - (IMAGE_BASE + program.end)
        command_count = sum(len(record.commands) for record in program.records)
        total_read += read_bytes
        total_opaque += opaque_bytes
        total_gap += gap_bytes
        total_commands += command_count
        rows.append(
            {
                "kind": "stream",
                "address": f"0x{address:08X}",
                "next_callback_root": f"0x{next_root:08X}",
                "record_count": program.count,
                "stream_bytes": stream_bytes,
                "native_read_bytes": read_bytes,
                "opaque_payload_bytes": opaque_bytes,
                "raw_gap_bytes": gap_bytes,
                "body_command_count": command_count,
            }
        )
    span = END - START
    if (total_read, total_opaque, total_gap) != (646, 58, 64):
        raise SystemExit(
            f"accounting changed: native-read={total_read}, opaque={total_opaque}, gap={total_gap}"
        )
    if total_read + total_opaque + total_gap != span:
        raise SystemExit("parser, opaque, and root-gap spans do not cover the family")
    rows.append(
        {
            "kind": "TOTAL",
            "address": f"0x{START:08X}",
            "next_callback_root": f"0x{END:08X}",
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
    rows = parse_early_family(args.rom.read_bytes())
    headers = [
        "kind", "address", "next_callback_root", "record_count", "stream_bytes",
        "native_read_bytes", "opaque_payload_bytes", "raw_gap_bytes", "body_command_count",
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
