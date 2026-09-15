#!/usr/bin/env python3
"""Generate an objdiff-v2 report from the conservative PS2 layout inventory.

matched_* is decompiled. complete_* is linked (hybrid-placed matching C).
Catalog overlap is a hard error; percents are unique coverage / span.
"""

import argparse
import csv
import json
from collections import defaultdict
from pathlib import Path

from tools.progress_catalog import (
    BASE_ADDRESS,
    DATA_BEGIN,
    DATA_END,
    DATA_SIZE,
    TEXT_END,
    TEXT_SIZE,
    code_progress,
    data_progress,
    validate_code_catalog,
    validate_data_catalog,
)

CHUNK_SIZE = 0x10000


def progress_measures(
    *,
    total_code: int = 0,
    total_data: int = 0,
    total_functions: int = 0,
    total_units: int = 0,
    matched_code: int = 0,
    matched_functions: int = 0,
    complete_code: int = 0,
    matched_data: int = 0,
    complete_data: int = 0,
    complete_units: int = 0,
) -> dict:
    if total_code and matched_code > total_code:
        raise SystemExit("matched_code exceeds total_code")
    if total_code and complete_code > matched_code:
        raise SystemExit("complete_code exceeds matched_code")
    if total_data and matched_data > total_data:
        raise SystemExit("matched_data exceeds total_data")
    if total_data and complete_data > matched_data:
        raise SystemExit("complete_data exceeds matched_data")
    code_percent = matched_code * 100.0 / total_code if total_code else 0.0
    function_percent = (
        matched_functions * 100.0 / total_functions if total_functions else 0.0
    )
    complete_code_percent = complete_code * 100.0 / total_code if total_code else 0.0
    result = {
        "fuzzy_match_percent": code_percent,
        "matched_code_percent": code_percent,
        "matched_data_percent": matched_data * 100.0 / total_data if total_data else 0.0,
        "matched_functions_percent": function_percent,
        "complete_code_percent": complete_code_percent,
        "complete_data_percent": complete_data * 100.0 / total_data if total_data else 0.0,
        "total_units": total_units,
        "complete_units": complete_units,
    }
    if total_code:
        result["total_code"] = str(total_code)
        result["matched_code"] = str(matched_code)
        result["complete_code"] = str(complete_code)
    if total_data:
        result["total_data"] = str(total_data)
        result["matched_data"] = str(matched_data)
        result["complete_data"] = str(complete_data)
    if total_functions:
        result["total_functions"] = total_functions
        result["matched_functions"] = matched_functions
    return result


def load_functions(path: Path) -> list[dict]:
    result = []
    with path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            address = int(row["address"], 0)
            size = int(row["size"], 0)
            if not (BASE_ADDRESS <= address < BASE_ADDRESS + TEXT_SIZE):
                raise SystemExit(f"function outside text span: {row['name']}")
            if address + size > BASE_ADDRESS + TEXT_SIZE:
                raise SystemExit(f"function crosses text boundary: {row['name']}")
            result.append({"name": row["name"], "address": address, "size": size})
    return result


def load_matches(path: Path) -> dict[str, dict]:
    result = {}
    with path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            if row["status"] not in {"matching", "complete"}:
                continue
            result[row["name"]] = {
                "address": int(row["address"], 0),
                "size": int(row["size"], 0),
                "source": row["source"],
                "complete": row["status"] == "complete",
            }
    from tools.progress_catalog import require_disjoint

    require_disjoint(
        [(row["address"], row["size"], name) for name, row in result.items()],
        "code matches",
    )
    return result


def load_data_matches(units_path: Path, matches_path: Path) -> dict[str, dict]:
    """Load source-owned data only when its catalog range is exact."""
    units = {}
    with units_path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            units[row["name"]] = (int(row["address"], 0), int(row["size"], 0))
    result = {}
    if not matches_path.is_file():
        return result
    with matches_path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            if row["status"] not in {"matching", "complete"}:
                continue
            if row.get("progress") not in {"reconstructed", "placeholder"}:
                raise SystemExit(f"data progress classification missing or invalid: {row['name']}")
            expected = units.get(row["name"])
            found = (int(row["address"], 0), int(row["size"], 0))
            if expected != found:
                raise SystemExit(f"data match range disagrees with catalog: {row['name']}")
            result[row["name"]] = {
                **row, "address": found[0], "size": found[1],
                "complete": row["status"] == "complete",
            }
    ordered = sorted(result.values(), key=lambda item: item["address"])
    for prev, cur in zip(ordered, ordered[1:]):
        if cur["address"] < prev["address"] + prev["size"]:
            raise SystemExit(
                f"overlapping data units {prev['name']} and {cur['name']}"
            )
    return result


def build_report(
    functions: list[dict], matches: dict[str, dict], data_matches: dict[str, dict] | None = None
) -> dict:
    data_matches = data_matches or {}
    functions_by_name = {function["name"]: function for function in functions}
    for name, match in matches.items():
        function = functions_by_name.get(name)
        if function is None:
            raise SystemExit(f"matched function missing from inventory: {name}")
        if (function["address"], function["size"]) != (match["address"], match["size"]):
            raise SystemExit(f"matched function range disagrees with inventory: {name}")

    chunks = defaultdict(list)
    source_functions = defaultdict(list)
    for function in functions:
        chunks[(function["address"] - BASE_ADDRESS) // CHUNK_SIZE].append(function)
        if function["name"] in matches:
            source_functions[matches[function["name"]]["source"]].append(function)

    units = []
    text_chunk_count = (TEXT_SIZE + CHUNK_SIZE - 1) // CHUNK_SIZE
    for index in range(text_chunk_count):
        start = index * CHUNK_SIZE
        size = min(CHUNK_SIZE, TEXT_SIZE - start)
        # Matched source units receive their own tiles. Deduct their exact
        # intersections from each address chunk so totals include every byte once.
        chunk_begin = BASE_ADDRESS + start
        chunk_end = chunk_begin + size
        size -= sum(
            max(0, min(chunk_end, m["address"] + m["size"]) - max(chunk_begin, m["address"]))
            for m in matches.values()
        )
        chunk_functions = sorted(
            (f for f in chunks[index] if f["name"] not in matches),
            key=lambda item: item["address"],
        )
        if not size:
            continue
        chunk_matches = [function for function in chunk_functions if function["name"] in matches]
        matched_bytes = sum(function["size"] for function in chunk_matches)
        complete_bytes = sum(
            function["size"]
            for function in chunk_matches
            if matches[function["name"]]["complete"]
        )
        units.append({
            "name": f"main/text_{start:06x}",
            "measures": progress_measures(
                total_code=size,
                total_functions=len(chunk_functions),
                total_units=1,
                matched_code=matched_bytes,
                matched_functions=len(chunk_matches),
                complete_code=complete_bytes,
            ),
            "sections": [{
                "name": ".text",
                "size": str(size),
                "fuzzy_match_percent": matched_bytes * 100.0 / size,
                "address": str(start),
                "metadata": {"virtual_address": str(BASE_ADDRESS + start)},
            }],
            "functions": [{
                "name": function["name"],
                "size": str(function["size"]),
                "fuzzy_match_percent": (
                    100.0 if function["name"] in matches else 0.0
                ),
                "address": str(function["address"] - BASE_ADDRESS),
                "metadata": {"virtual_address": str(function["address"])},
            } for function in chunk_functions],
            "metadata": {
                "complete": False,
                "source_path": f"asm/main_{start:06x}.s",
                "progress_categories": ["main"],
            },
        })

    for source, recovered in sorted(source_functions.items()):
        size = sum(f["size"] for f in recovered)
        complete_bytes = sum(f["size"] for f in recovered if matches[f["name"]]["complete"])
        units.append({
            "name": source,
            "measures": progress_measures(
                total_code=size, total_functions=len(recovered), total_units=1,
                matched_code=size, matched_functions=len(recovered),
                complete_code=complete_bytes,
            ),
            "functions": [{
                "name": f["name"], "size": str(f["size"]),
                "fuzzy_match_percent": 100.0,
                "metadata": {"virtual_address": str(f["address"])},
            } for f in sorted(recovered, key=lambda f: f["address"])],
            "metadata": {
                "complete": complete_bytes == size,
                "source_path": source, "progress_categories": ["main"],
            },
        })

    validate_code_catalog(functions, matches)
    units_by_name = {
        name: (row["address"], row["size"]) for name, row in data_matches.items()
    }
    validate_data_catalog(units_by_name, data_matches)
    matched_data, complete_data = data_progress(data_matches)
    # Like conventional objdiff reports, expose individual source objects.
    data_sources = defaultdict(dict)
    for name, row in data_matches.items():
        data_sources[row["source"]][name] = row
    for source, rows in sorted(data_sources.items()):
        size = sum(row["size"] for row in rows.values())
        matched, complete = data_progress(rows)
        units.append({
            "name": "main/" + str(Path(source).with_suffix("")).removeprefix("src/"),
            "measures": progress_measures(
                total_data=size, total_units=1, matched_data=matched,
                complete_data=complete, complete_units=int(complete == size),
            ),
            "sections": [{
                "name": name, "size": str(row["size"]),
                "fuzzy_match_percent": (
                    100.0 if row.get("progress") == "reconstructed" else 0.0
                ),
                "metadata": {"virtual_address": str(row["address"])},
            } for name, row in sorted(rows.items())],
            "metadata": {
                "complete": complete == size, "source_path": source,
                "progress_categories": ["main"],
            },
        })
    residual = DATA_SIZE - sum(row["size"] for row in data_matches.values())
    if residual:
        units.append({
            "name": "main/initialized_data_remaining",
            "measures": progress_measures(total_data=residual, total_units=1),
            "metadata": {
                "complete": False, "progress_categories": ["main"],
            },
        })

    complete_units = sum(1 for unit in units if unit["metadata"].get("complete"))
    aggregate = progress_measures(
        total_code=TEXT_SIZE,
        total_data=DATA_SIZE,
        total_functions=len(functions),
        total_units=len(units),
        matched_code=code_progress(matches)[0],
        matched_functions=len(matches),
        complete_code=code_progress(matches)[1],
        matched_data=matched_data,
        complete_data=complete_data,
        complete_units=complete_units,
    )
    return {
        "version": 2,
        "measures": aggregate,
        "units": units,
        "categories": [{
            "id": "main",
            "name": "PS2 main executable",
            "measures": aggregate,
        }],
    }


def svg(function_count: int, matched_bytes: int) -> str:
    percent = matched_bytes * 100.0 / TEXT_SIZE
    fill_width = 824 * percent / 100.0
    return f'''<svg xmlns="http://www.w3.org/2000/svg" width="920" height="220" viewBox="0 0 920 220" role="img" aria-label="MVC2 PS2 matching C progress: {percent:.6f}%">
  <rect width="920" height="220" rx="18" fill="#0d1117"/>
  <text x="48" y="55" fill="#f0f6fc" font-family="-apple-system,BlinkMacSystemFont,Segoe UI,sans-serif" font-size="28" font-weight="700">Marvel vs. Capcom 2 PS2 — Matching C</text>
  <text x="48" y="93" fill="#8b949e" font-family="-apple-system,BlinkMacSystemFont,Segoe UI,sans-serif" font-size="18">NTSC-U · SLUS-20486 · {function_count:,} candidate functions</text>
  <rect x="48" y="132" width="824" height="28" rx="14" fill="#30363d"/>
  <rect x="48" y="132" width="{fill_width:.6f}" height="28" rx="14" fill="#2f81f7"/>
  <text x="48" y="198" fill="#f0f6fc" font-family="ui-monospace,SFMono-Regular,Menlo,monospace" font-size="20">{matched_bytes:,} / {TEXT_SIZE:,} code bytes · {percent:.6f}%</text>
</svg>\n'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--functions", type=Path, default=Path("config/functions.csv"))
    parser.add_argument("--matches", type=Path, default=Path("config/matches.csv"))
    parser.add_argument("--data-units", type=Path, default=Path("config/data_units.csv"))
    parser.add_argument("--data-matches", type=Path, default=Path("config/data_matches.csv"))
    parser.add_argument("--report", type=Path, default=Path("build-report/report.json"))
    parser.add_argument("--svg", type=Path, default=Path("assets/progress.svg"))
    args = parser.parse_args()
    functions = load_functions(args.functions)
    matches = load_matches(args.matches)
    data_matches = load_data_matches(args.data_units, args.data_matches)
    report = build_report(functions, matches, data_matches)
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.svg.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    matched_bytes = int(report["measures"]["matched_code"])
    args.svg.write_text(svg(len(functions), matched_bytes), encoding="utf-8")
    print(
        f"wrote {args.report}: {len(matches)}/{len(functions)} functions, "
        f"{report['measures']['matched_code']}/{TEXT_SIZE} matching code bytes, "
        f"{report['measures']['matched_data']}/{DATA_SIZE} matching data bytes, "
        f"linked code {report['measures']['complete_code_percent']:.4f}% "
        f"linked data {report['measures']['complete_data_percent']:.4f}%"
    )


if __name__ == "__main__":
    main()
