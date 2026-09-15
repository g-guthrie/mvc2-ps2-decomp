"""Canonical layout and catalog rules for decomp.dev / objdiff stats.

matched_*  = decompiled (exact matching source vs retail)
complete_* = linked (that matching source is placed by the hybrid linker)

decomp.dev "decompiled" reads matched_code_percent.
decomp.dev "fully linked" reads complete_code_percent.

Every credited byte must be a unique address in the conservative spans.
Overlaps, ranges outside the span, or complete > matched fail the catalog.
"""

from __future__ import annotations

import csv
from pathlib import Path

BASE_ADDRESS = 0x00100000
TEXT_SIZE = 0x324200
DATA_SIZE = 0x9E380
TEXT_END = BASE_ADDRESS + TEXT_SIZE
DATA_BEGIN = TEXT_END
DATA_END = DATA_BEGIN + DATA_SIZE


def unique_covered_bytes(intervals: list[tuple[int, int]], lo: int, hi: int) -> int:
    """Union of [start, start+size) clipped to [lo, hi). Overlaps count once."""
    clipped = []
    for start, size in intervals:
        a = max(start, lo)
        b = min(start + size, hi)
        if b > a:
            clipped.append((a, b))
    clipped.sort()
    covered = 0
    cur = lo
    for a, b in clipped:
        if b <= cur:
            continue
        covered += b - max(a, cur)
        cur = max(cur, b)
    return covered


def first_overlap(intervals: list[tuple[int, int, str]]) -> tuple[str, str] | None:
    ordered = sorted(intervals, key=lambda item: item[0])
    for prev, cur in zip(ordered, ordered[1:]):
        if cur[0] < prev[0] + prev[1]:
            return prev[2], cur[2]
    return None


def require_disjoint(intervals: list[tuple[int, int, str]], kind: str) -> None:
    overlap = first_overlap(intervals)
    if overlap:
        raise SystemExit(f"overlapping {kind}: {overlap[0]} and {overlap[1]}")


def require_span(name: str, address: int, size: int, lo: int, hi: int, kind: str) -> None:
    if size <= 0:
        raise SystemExit(f"{kind} {name} has non-positive size")
    if address < lo or address + size > hi:
        raise SystemExit(f"{kind} {name} is outside the {kind} span")


def load_csv_rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8") as stream:
        return list(csv.DictReader(stream))


def validate_code_catalog(
    functions: list[dict], matches: dict[str, dict]
) -> None:
    by_name = {row["name"]: row for row in functions}
    intervals = []
    for name, match in matches.items():
        function = by_name.get(name)
        if function is None:
            raise SystemExit(f"matched function missing from inventory: {name}")
        if (function["address"], function["size"]) != (match["address"], match["size"]):
            raise SystemExit(f"matched function range disagrees with inventory: {name}")
        require_span(name, match["address"], match["size"], BASE_ADDRESS, TEXT_END, "function")
        intervals.append((match["address"], match["size"], name))
    require_disjoint(intervals, "code matches")
    covered = unique_covered_bytes(
        [(match["address"], match["size"]) for match in matches.values()],
        BASE_ADDRESS,
        TEXT_END,
    )
    raw = sum(match["size"] for match in matches.values())
    if covered != raw:
        raise SystemExit(
            f"code match bytes {raw} != unique coverage {covered} (overlaps or out of span)"
        )


def validate_data_catalog(
    units: dict[str, tuple[int, int]], matches: dict[str, dict]
) -> None:
    if set(units) != {name for name, row in matches.items()}:
        missing = set(units) - set(matches)
        extra = set(matches) - set(units)
        if missing:
            raise SystemExit(f"data unit missing from matches: {sorted(missing)[0]}")
        if extra:
            raise SystemExit(f"data match missing from catalog: {sorted(extra)[0]}")
    intervals = []
    for name, match in matches.items():
        expected = units[name]
        found = (match["address"], match["size"])
        if expected != found:
            raise SystemExit(f"data match range disagrees with catalog: {name}")
        require_span(name, match["address"], match["size"], DATA_BEGIN, DATA_END, "data")
        intervals.append((match["address"], match["size"], name))
    require_disjoint(intervals, "data units")
    covered = unique_covered_bytes(
        [(match["address"], match["size"]) for match in matches.values()],
        DATA_BEGIN,
        DATA_END,
    )
    raw = sum(match["size"] for match in matches.values())
    if covered != raw:
        raise SystemExit(
            f"data match bytes {raw} != unique coverage {covered} (overlaps or out of span)"
        )
    if covered > DATA_SIZE:
        raise SystemExit(f"linked data {covered} exceeds span {DATA_SIZE}")


def code_progress(matches: dict[str, dict]) -> tuple[int, int]:
    for name, match in matches.items():
        require_span(name, match["address"], match["size"], BASE_ADDRESS, TEXT_END, "function")
    matched = unique_covered_bytes(
        [(match["address"], match["size"]) for match in matches.values()],
        BASE_ADDRESS,
        TEXT_END,
    )
    complete = unique_covered_bytes(
        [
            (match["address"], match["size"])
            for match in matches.values()
            if match.get("complete")
        ],
        BASE_ADDRESS,
        TEXT_END,
    )
    if complete > matched:
        raise SystemExit("complete_code exceeds matched_code")
    if matched > TEXT_SIZE:
        raise SystemExit("matched_code exceeds text span")
    return matched, complete


def data_progress(matches: dict[str, dict]) -> tuple[int, int]:
    for name, match in matches.items():
        require_span(name, match["address"], match["size"], DATA_BEGIN, DATA_END, "data")
    # Placeholder replacements still participate in all catalog validation.
    # Their byte identity alone does not establish source reconstruction.
    matches = {
        name: match for name, match in matches.items()
        if match.get("progress") == "reconstructed"
    }
    matched = unique_covered_bytes(
        [(match["address"], match["size"]) for match in matches.values()],
        DATA_BEGIN,
        DATA_END,
    )
    complete = unique_covered_bytes(
        [
            (match["address"], match["size"])
            for match in matches.values()
            if match.get("complete")
        ],
        DATA_BEGIN,
        DATA_END,
    )
    if complete > matched:
        raise SystemExit("complete_data exceeds matched_data")
    if matched > DATA_SIZE:
        raise SystemExit("matched_data exceeds data span")
    return matched, complete
