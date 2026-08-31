#!/usr/bin/env python3
"""Generate an objdiff-v2 report from the conservative PS2 layout inventory."""

import argparse
import csv
import json
from collections import defaultdict
from pathlib import Path

BASE_ADDRESS = 0x00100000
TEXT_SIZE = 0x324200
DATA_SIZE = 0x9E380
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
) -> dict:
    code_percent = matched_code * 100.0 / total_code if total_code else 0.0
    function_percent = (
        matched_functions * 100.0 / total_functions if total_functions else 0.0
    )
    complete_code_percent = complete_code * 100.0 / total_code if total_code else 0.0
    result = {
        "fuzzy_match_percent": code_percent,
        "matched_code_percent": code_percent,
        "matched_data_percent": 0.0,
        "matched_functions_percent": function_percent,
        "complete_code_percent": complete_code_percent,
        "complete_data_percent": 0.0,
        "total_units": total_units,
        "complete_units": 0,
    }
    if total_code:
        result["total_code"] = str(total_code)
        result["matched_code"] = str(matched_code)
        result["complete_code"] = str(complete_code)
    if total_data:
        result["total_data"] = str(total_data)
        result["matched_data"] = "0"
        result["complete_data"] = "0"
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
    return result


def build_report(functions: list[dict], matches: dict[str, dict]) -> dict:
    functions_by_name = {function["name"]: function for function in functions}
    for name, match in matches.items():
        function = functions_by_name.get(name)
        if function is None:
            raise SystemExit(f"matched function missing from inventory: {name}")
        if (function["address"], function["size"]) != (match["address"], match["size"]):
            raise SystemExit(f"matched function range disagrees with inventory: {name}")

    chunks = defaultdict(list)
    for function in functions:
        chunks[(function["address"] - BASE_ADDRESS) // CHUNK_SIZE].append(function)

    units = []
    text_chunk_count = (TEXT_SIZE + CHUNK_SIZE - 1) // CHUNK_SIZE
    for index in range(text_chunk_count):
        start = index * CHUNK_SIZE
        size = min(CHUNK_SIZE, TEXT_SIZE - start)
        chunk_functions = sorted(chunks[index], key=lambda item: item["address"])
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

    units.append({
        "name": "main/initialized_data",
        "measures": progress_measures(total_data=DATA_SIZE, total_units=1),
        "sections": [{
            "name": ".data",
            "size": str(DATA_SIZE),
            "fuzzy_match_percent": 0.0,
            "address": str(TEXT_SIZE),
            "metadata": {"virtual_address": str(BASE_ADDRESS + TEXT_SIZE)},
        }],
        "metadata": {
            "complete": False,
            "source_path": "asm/main_data.s",
            "progress_categories": ["main"],
        },
    })

    aggregate = progress_measures(
        total_code=TEXT_SIZE,
        total_data=DATA_SIZE,
        total_functions=len(functions),
        total_units=len(units),
        matched_code=sum(match["size"] for match in matches.values()),
        matched_functions=len(matches),
        complete_code=sum(
            match["size"] for match in matches.values() if match["complete"]
        ),
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
    parser.add_argument("--report", type=Path, default=Path("build-report/report.json"))
    parser.add_argument("--svg", type=Path, default=Path("assets/progress.svg"))
    args = parser.parse_args()
    functions = load_functions(args.functions)
    matches = load_matches(args.matches)
    report = build_report(functions, matches)
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.svg.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    matched_bytes = sum(match["size"] for match in matches.values())
    args.svg.write_text(svg(len(functions), matched_bytes), encoding="utf-8")
    print(
        f"wrote {args.report}: {len(matches)}/{len(functions)} functions, "
        f"{matched_bytes}/{TEXT_SIZE} matching code bytes"
    )


if __name__ == "__main__":
    main()
