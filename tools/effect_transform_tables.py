"""Evidence-backed selectors and record layout for the effect quad lookups."""

from __future__ import annotations

from collections.abc import Iterable


TABLE1_BASE = 0x004A6F80
TABLE2_BASE = 0x004A7F80
TABLE_SIZE = 0x1000
ROW_SIZE = 16
NEXT_OWNER = 0x004A8F80

# func_00422740 compares the input byte to ASCII ranges and loads four words
# from the corresponding records. It also has these fixed row loads.
TEXT_ASCII_RANGES = ((16, 26), (26, 52), (52, 78))
TEXT_FIXED_ROWS = (80, 81, 145, 146, 149)


def body_table1_selectors(opcodes: Iterable[int]) -> set[int]:
    """Return body opcodes that reach D_004A6F80 in func_00422150."""
    special = {0, 1, 4, 5, 10, 13}
    return {opcode & 0xFF for opcode in opcodes if (opcode & 0xFF) not in special}


def accessed_rows(opcodes: Iterable[int]) -> list[int]:
    rows = body_table1_selectors(opcodes)
    for start, end in TEXT_ASCII_RANGES:
        rows.update(range(start, end))
    rows.update(TEXT_FIXED_ROWS)
    return sorted(rows)


def contiguous_row_runs(rows: Iterable[int]) -> list[tuple[int, int]]:
    """Return half-open row intervals from a set of individually proven rows."""
    ordered = sorted(set(rows))
    if not ordered:
        return []
    runs = []
    start = previous = ordered[0]
    for row in ordered[1:]:
        if row != previous + 1:
            runs.append((start, previous + 1))
            start = row
        previous = row
    runs.append((start, previous + 1))
    return runs


def signed_quad(data: bytes, address: int) -> tuple[int, int, int, int]:
    """Read the four native signed-word fields at an address in a loaded image."""
    offset = address - 0x00100000
    fields = data[offset:offset + ROW_SIZE]
    if len(fields) != ROW_SIZE:
        raise ValueError(f"quad outside image at 0x{address:08X}")
    return tuple(
        int.from_bytes(fields[i:i + 4], "little", signed=True)
        for i in range(0, ROW_SIZE, 4)
    )  # type: ignore[return-value]
