#!/usr/bin/env python3
"""Emit parser receipts for independently referenced 0x4A9280 streams."""

from __future__ import annotations

import json
import re
import argparse
import csv
from pathlib import Path

try:
    from tools.effect_timeline import TimelineParseError, parse_program, partition_program
except ModuleNotFoundError:
    from effect_timeline import TimelineParseError, parse_program, partition_program


BASE = 0x004A9280
# The next independently referenced callback root, not the old import cutoff.
END = 0x004A9F70
IMAGE_BASE = 0x00100000
CALLBACK_SOURCES = (
    Path("src/float_callbacks.c"),
    Path("src/effect_state_callbacks.c"),
    Path("src/effect_followup_callbacks.c"),
    Path("src/effect_choice_callbacks.c"),
)


NATIVE_ONLY_ROOTS = {
    0x004A9360: "native callsite 0x00421540",
    0x004A96B0: "native callsite 0x00421750",
}


def _command_receipt(command, phase: str) -> dict[str, object]:
    opcode = command.opcode
    operand = command.operand
    if phase == "preamble":
        kind = {
            1: "header_values_be16_be16_u8",
            5: "saved_target_offset_u8",
            6: "parameter_u8",
            7: "parameter_u8",
            8: "parameter_u8",
            9: "parameter_u8",
            11: "parameter_u8",
            12: "opaque_two_byte_payload",
        }.get(opcode, "preamble_opcode_only")
    else:
        kind = {
            0: "terminator",
            1: "be16_value_then_three_opaque_bytes",
            4: "offset_operand_u8",
            5: "target_offset_plus_saved_byte",
            10: "native_table_row_index_u8",
            13: "target_offset_plus_8",
        }.get(opcode, "native_table_selector")
    typed_operand_bytes = len(operand)
    opaque_operand_bytes = 0
    if phase == "body" and opcode == 1:
        typed_operand_bytes = 2
        opaque_operand_bytes = 3
    elif phase == "preamble" and opcode == 12:
        typed_operand_bytes = 0
        opaque_operand_bytes = 2
    return {
        "address": f"0x{BASE + command.offset:08X}",
        "opcode": opcode,
        "kind": kind,
        "operand_bytes": operand.hex(),
        "native_read_operand_bytes": typed_operand_bytes,
        "opaque_operand_bytes": opaque_operand_bytes,
    }


def load_original_bytes(path: Path) -> bytes:
    if path.is_file():
        words = [int(value, 16) for value in re.findall(r"0x([0-9A-Fa-f]{8})u", path.read_text())]
        return b"".join(word.to_bytes(4, "little") for word in words)

    # After the raw placeholder is split, reconstruct the same byte range from
    # its one-symbol C data units. Each typed member and opaque gap is u8.
    units = []
    with Path("config/data_units.csv").open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            address = int(row["address"], 0)
            if BASE <= address < END:
                units.append((address, int(row["size"], 0), row["name"], Path(row["source"])))
    units.sort()
    image = bytearray(END - BASE)
    written = bytearray(END - BASE)
    for address, size, name, source in units:
        text = source.read_text()
        initializer = re.search(
            rf"\b{re.escape(name)}\s*(?:\[[^\]]*\])?\s*=\s*\{{(.*?)\}}\s*;",
            text,
            re.DOTALL,
        )
        if initializer is None:
            raise SystemExit(f"cannot find byte initializer for {name}")
        values = [int(value, 16) for value in re.findall(r"0x([0-9A-Fa-f]{2})u?", initializer.group(1))]
        if len(values) != size:
            raise SystemExit(f"byte initializer size mismatch for {name}: {len(values)} != {size}")
        offset = address - BASE
        if any(written[offset:offset + size]):
            raise SystemExit(f"overlapping byte data unit: {name}")
        image[offset:offset + size] = bytes(values)
        written[offset:offset + size] = bytes([1]) * size
    if not all(written):
        raise SystemExit("data units leave a hole in the effect family")
    return bytes(image)


def callback_roots() -> list[int]:
    sources = {path.name: path.read_text() for path in CALLBACK_SOURCES}
    roots = set(
        int(symbol[2:], 16)
        for symbol in re.findall(
            r"FLOAT_CALLBACK\([^,]+,\s*func_004220B0,\s*[^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
            sources["float_callbacks.c"],
        )
    )
    roots.update(
        int(symbol[2:], 16)
        for symbol in re.findall(
            r"STATE_EFFECT\([^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
            sources["effect_state_callbacks.c"],
        )
    )
    roots.update(
        int(symbol[2:], 16)
        for symbol in re.findall(
            r"FOLLOWUP_EFFECT\([^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
            sources["effect_followup_callbacks.c"],
        )
    )
    choice = sources["effect_choice_callbacks.c"]
    roots.update(
        int(symbol[2:], 16)
        for symbol in re.findall(
            r"CHOICE_EFFECT\([^,]+,[^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
            choice,
        )
    )
    roots.update(
        int(symbol[2:], 16)
        for symbol in re.findall(
            r"CHOICE_EFFECT\([^,]+,[^,]+,[^,]+,\s*(D_004A[0-9A-Fa-f]{4})",
            choice,
        )
    )
    for source in sources.values():
        roots.update(
            int(symbol[2:], 16)
            for symbol in re.findall(
                r"func_004220B0\([^,]+,\s*(D_004A[0-9A-Fa-f]{4})", source
            )
        )
    roots.update(NATIVE_ONLY_ROOTS)
    return sorted(address for address in roots if BASE <= address < END)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", type=Path)
    parser.add_argument("--rom", type=Path, help="loaded retail image used by verify_data_object.py")
    args = parser.parse_args()
    if args.rom:
        image = args.rom.read_bytes()
        lo, hi = BASE - IMAGE_BASE, END - IMAGE_BASE
        if hi > len(image):
            raise SystemExit(f"retail image is too short for 0x{BASE:08X}..0x{END:08X}")
        data = image[lo:hi]
    else:
        data = load_original_bytes(Path("src/data/data_u32_004A9280.c"))
    roots = callback_roots()
    if len(roots) != 25:
        raise SystemExit(f"expected 25 independently referenced roots, found {len(roots)}")
    native_read_bytes = 0
    opaque_payload_bytes = 0
    raw_gap_bytes = 0
    native_read_run_count = 0
    opaque_run_count = 0
    records = []
    for index, address in enumerate(roots):
        next_owner = roots[index + 1] if index + 1 < len(roots) else END
        start = address - BASE
        limit = next_owner - BASE
        try:
            program = parse_program(data, start, limit)
        except TimelineParseError as error:
            raise SystemExit(f"0x{address:08X} crosses next owner 0x{next_owner:08X}: {error}")
        if program.count != 1:
            raise SystemExit(f"unexpected record count {program.count} at 0x{address:08X}")
        if program.end > limit:
            raise SystemExit(f"terminator crosses next owner at 0x{address:08X}")
        length = program.end - start
        gap = limit - program.end
        runs = partition_program(data, program)
        read_runs = [run for run in runs if run.kind == "native_read"]
        opaque_runs = [run for run in runs if run.kind == "opaque"]
        read_size = sum(run.end - run.start for run in read_runs)
        opaque_size = sum(run.end - run.start for run in opaque_runs)
        native_read_bytes += read_size
        opaque_payload_bytes += opaque_size
        raw_gap_bytes += gap
        native_read_run_count += len(read_runs)
        opaque_run_count += len(opaque_runs)
        records.append(
            {
                "address": f"0x{address:08X}",
                "boundary_address": f"0x{next_owner:08X}",
                    "boundary_kind": "next_callback_root",
                "span_bytes": limit - start,
                "count": program.count,
                "record_lengths": [record.end - record.start for record in program.records],
                "command_counts": [len(record.commands) for record in program.records],
                "native_read_bytes": read_size,
                "opaque_payload_bytes": opaque_size,
                "raw_gap_bytes": gap,
                "raw_gap_address": f"0x{BASE + program.end:08X}",
                "native_read_runs": [
                    {
                        "address": f"0x{BASE + run.start:08X}",
                        "size": run.end - run.start,
                        "fields": [
                            {"name": field.name, "value": field.value}
                            for field in run.fields
                        ],
                    }
                    for run in read_runs
                ],
                "opaque_runs": [
                    {"address": f"0x{BASE + run.start:08X}", "size": run.end - run.start}
                    for run in opaque_runs
                ],
                "records": [
                    {
                        "address": f"0x{BASE + record.start:08X}",
                        "end_address": f"0x{BASE + record.end:08X}",
                        "base": record.base,
                        "preamble": [_command_receipt(command, "preamble") for command in record.preamble],
                        "commands": [_command_receipt(command, "body") for command in record.commands],
                    }
                    for record in program.records
                ],
                "status": "complete_before_next_owner",
            }
        )
    held_bytes = 0  # Every bound is now an independently referenced next root.
    total_covered = native_read_bytes + opaque_payload_bytes + raw_gap_bytes + held_bytes
    expected_native_read = 2845
    expected_opaque = 254
    expected_gap = 213
    if (native_read_bytes != expected_native_read or opaque_payload_bytes != expected_opaque
            or raw_gap_bytes != expected_gap or total_covered != END - BASE):
        raise SystemExit(
            f"receipt changed: native-read={native_read_bytes} (expected {expected_native_read}), "
            f"opaque={opaque_payload_bytes} (expected {expected_opaque}), "
            f"raw gaps={raw_gap_bytes} (expected {expected_gap}), coverage={total_covered}"
        )
    report = json.dumps(
        {
            "grammar": "native func_00422150, preamble/body cursor movements",
            "native_read_bytes": native_read_bytes,
            "opaque_payload_bytes": opaque_payload_bytes,
            "inter_root_gap_bytes": raw_gap_bytes,
            "held_bytes": held_bytes,
            "total_covered_bytes": total_covered,
            "native_read_run_count": native_read_run_count,
            "opaque_run_count": opaque_run_count,
            "roots": records,
        },
        indent=2,
    )
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(report + "\n", encoding="utf-8")
    else:
        print(report)


if __name__ == "__main__":
    main()
