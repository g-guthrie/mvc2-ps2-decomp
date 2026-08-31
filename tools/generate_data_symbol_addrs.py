#!/usr/bin/env python3
"""Generate source-derived linker labels for encoded MVC2 code addresses."""

from __future__ import annotations

import argparse
import re
from pathlib import Path


SYMBOL_RE = re.compile(r"\b(?:func|lbl)_([0-9A-Fa-f]{8})\b")


def extract_symbols(source: Path) -> list[tuple[str, int]]:
    names = sorted(set(match.group(0) for match in SYMBOL_RE.finditer(source.read_text())))
    return [(name, int(name.rsplit("_", 1)[1], 16)) for name in names]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("sources", type=Path, nargs="+")
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    merged = {}
    for source in args.sources:
        for name, address in extract_symbols(source):
            previous = merged.setdefault(name, address)
            if previous != address:
                raise SystemExit(f"inconsistent symbolic address for {name}")
    symbols = sorted(merged.items())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(
        "".join(f"{name} = 0x{address:08X};\n" for name, address in symbols),
        encoding="utf-8",
    )
    print(f"wrote {len(symbols)} source-derived data symbols")


if __name__ == "__main__":
    main()
