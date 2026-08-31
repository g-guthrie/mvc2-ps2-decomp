#!/usr/bin/env python3
"""Generate the initial objdiff-v2 report and README progress graphic."""

import argparse
import json
from pathlib import Path

TOTAL_CODE = 3_941_760
BASE_ADDRESS = 0x00100000


def measures() -> dict:
    return {
        "fuzzy_match_percent": 0.0,
        "total_code": str(TOTAL_CODE),
        "matched_code": "0",
        "matched_code_percent": 0.0,
        "total_functions": 1,
        "matched_functions": 0,
        "matched_functions_percent": 0.0,
        "complete_code": "0",
        "complete_code_percent": 0.0,
        "total_units": 1,
        "complete_units": 0,
    }


def report() -> dict:
    progress = measures()
    return {
        "version": 2,
        "measures": progress,
        "units": [{
            "name": "main/assembly-baseline",
            "measures": progress,
            "functions": [{
                "name": "remaining_loaded_image",
                "size": str(TOTAL_CODE),
                "fuzzy_match_percent": 0.0,
                "address": "0",
                "metadata": {"virtual_address": str(BASE_ADDRESS)},
            }],
            "metadata": {
                "complete": False,
                "source_path": "asm/main.s",
                "progress_categories": ["main"],
            },
        }],
        "categories": [{
            "id": "main",
            "name": "PS2 main executable",
            "measures": progress,
        }],
    }


def svg() -> str:
    return '''<svg xmlns="http://www.w3.org/2000/svg" width="920" height="220" viewBox="0 0 920 220" role="img" aria-label="MVC2 PS2 matching C progress: 0%">
  <rect width="920" height="220" rx="18" fill="#0d1117"/>
  <text x="48" y="55" fill="#f0f6fc" font-family="-apple-system,BlinkMacSystemFont,Segoe UI,sans-serif" font-size="28" font-weight="700">Marvel vs. Capcom 2 PS2 — Matching C</text>
  <text x="48" y="93" fill="#8b949e" font-family="-apple-system,BlinkMacSystemFont,Segoe UI,sans-serif" font-size="18">NTSC-U · SLUS-20486 · full loaded-image denominator</text>
  <rect x="48" y="132" width="824" height="28" rx="14" fill="#30363d"/>
  <text x="48" y="198" fill="#f0f6fc" font-family="ui-monospace,SFMono-Regular,Menlo,monospace" font-size="20">0 / 3,941,760 bytes · 0.000000%</text>
</svg>
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--report", type=Path, default=Path("build-report/report.json"))
    parser.add_argument("--svg", type=Path, default=Path("assets/progress.svg"))
    args = parser.parse_args()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.svg.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report(), indent=2) + "\n", encoding="utf-8")
    args.svg.write_text(svg(), encoding="utf-8")
    print(f"wrote {args.report} and {args.svg}")


if __name__ == "__main__":
    main()
