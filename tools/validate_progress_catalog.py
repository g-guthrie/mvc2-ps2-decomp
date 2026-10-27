#!/usr/bin/env python3
"""Fail if code/data catalogs would publish lying decomp.dev stats."""

import csv
import re
from pathlib import Path

from tools.objdiff_report import load_data_matches, load_functions, load_matches
from tools.progress_catalog import (
    DATA_SIZE,
    TEXT_SIZE,
    code_progress,
    data_progress,
    validate_code_catalog,
    validate_data_catalog,
)


# These small COP0 primitives fall under DECOMP.md's required CPU-operation
# exception. Other instruction-stream lifts must remain placeholders.
CPU_ASSEMBLY_PRIMITIVES = {
    ("src/s0h.c", "func_0010CA20"),
    ("src/k5h.c", "func_0010CA68"),
    ("src/k2s.c", "func_001048B0"),
}


def function_bodies(text, names):
    """Select definitions, preserving offsets while ignoring comments/literals."""
    masked = re.sub(
        r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\n]*|/\*.*?\*/',
        lambda match: re.sub(r"[^\n]", " ", match.group()),
        text, flags=re.DOTALL,
    )
    for name in names:
        for match in re.finditer(r"\b" + re.escape(name) + r"\s*\(", masked):
            position, depth = match.end(), 1
            while position < len(masked) and depth:
                depth += (masked[position] == "(") - (masked[position] == ")")
                position += 1
            while position < len(masked) and masked[position].isspace():
                position += 1
            if position == len(masked) or masked[position] != "{":
                continue
            start, depth = position, 1
            position += 1
            while position < len(masked) and depth:
                depth += (masked[position] == "{") - (masked[position] == "}")
                position += 1
            if depth:
                raise SystemExit(f"unclosed credited function body: {name}")
            yield name, text[start:position]


def validate_codegen_forcing(name, body, source):
    # Tokenize rather than matching prose or quoted examples as executable code.
    tokens = [(match.group(), match.start()) for match in re.finditer(
        r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|'
        r'[A-Za-z_]\w*|[^\s]', body, re.DOTALL,
    ) if not match.group().startswith(("//", "/*"))]
    values = [value for value, _ in tokens]
    for index, value in enumerate(values):
        if value not in {"asm", "__asm", "__asm__"}:
            continue
        cursor = index + 1
        if cursor < len(values) and values[cursor] in {"volatile", "__volatile__"}:
            cursor += 1
        if cursor < len(values) and values[cursor] == "{":
            depth = 1
            cursor += 1
            while cursor < len(values) and depth:
                value = values[cursor]
                if value == "nop":
                    raise SystemExit(f"manual asm nop credited as C: {name} ({source})")
                depth += (value == "{") - (value == "}")
                cursor += 1
            continue
        if cursor >= len(values) or values[cursor] != "(":
            continue
        cursor += 1
        start = cursor
        while cursor < len(values) and re.fullmatch(r'"(?:\s|\\[nrtvf])*"', values[cursor]):
            cursor += 1
        if cursor > start and cursor < len(values) and values[cursor] == ")":
            raise SystemExit(f"empty asm codegen barrier credited as C: {name} ({source})")

    # A fixed local read by C or an actual asm operand is distinct from an
    # unused destination introduced only to select a particular load register.
    code = " ".join(values)
    declarations = list(re.finditer(
        r'\bregister\b[^;{}]*?\b(\w+)\s+(?:asm|__asm|__asm__)\s*'
        r'\(\s*"[^"\n]+"\s*\)[^;{}]*;', code,
    ))
    for declaration in declarations:
        variable = declaration.group(1)
        remaining = code[:declaration.start()] + " " + code[declaration.end():]
        remaining_tokens = re.findall(
            r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|[A-Za-z_]\w*|[^\s]',
            remaining,
        )
        read = False
        for index, value in enumerate(remaining_tokens):
            if value != variable:
                continue
            following = remaining_tokens[index + 1:index + 3]
            assignment = (following[:1] == ["="] and following != ["=", "="])
            dereference = index > 0 and remaining_tokens[index - 1] == "*"
            if not assignment or dereference:
                read = True
                break
        if not read:
            raise SystemExit(f"unused fixed-register local credited as C: {name} ({source})")


def validate_source_credit(matches, root=Path(".")):
    """Reject instruction streams presented as reconstructed C functions."""
    by_source = {}
    for name, row in matches.items():
        by_source.setdefault(row["source"], set()).add(name)
    for source, credited in by_source.items():
        text = (root / source).read_text()
        for name, body in function_bodies(text, credited):
            validate_codegen_forcing(name, body, source)
        lifted = set()
        if re.search(r"#define\s+FN\([^\n]*__asm__", text):
            lifted.update(re.findall(
                r"^\s*FN\(\s*(func_[0-9A-Fa-f]{8})\s*,", text, re.MULTILINE
            ))
        # MWCC also accepts whole assembly functions in a .c file. An exact
        # object match does not turn those bodies into reconstructed C.
        code = re.sub(
            r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\n]*|/\*.*?\*/',
            lambda match: " " + "\n" * match.group().count("\n"),
            text,
            flags=re.DOTALL,
        )
        lifted.update(re.findall(
            r"\b(?:asm|__asm|__asm__)\s+(?:[A-Za-z_]\w*[\s*]+)+"
            r"([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{",
            code,
        ))
        for name in sorted(credited & lifted):
            if (source, name) not in CPU_ASSEMBLY_PRIMITIVES:
                raise SystemExit(f"assembly instruction stream credited as C: {name} ({source})")


def main() -> None:
    root = Path(".")
    functions = load_functions(root / "config/functions.csv")
    matches = load_matches(root / "config/matches.csv")
    data_matches = load_data_matches(
        root / "config/data_units.csv", root / "config/data_matches.csv"
    )
    units = {}
    with (root / "config/data_units.csv").open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            units[row["name"]] = (int(row["address"], 0), int(row["size"], 0))
    validate_code_catalog(functions, matches)
    validate_data_catalog(units, data_matches)
    matched_code, complete_code = code_progress(matches)
    matched_data, complete_data = data_progress(data_matches)
    for source in {row["source"] for row in matches.values()} | {
        row["source"] for row in data_matches.values()
    }:
        if not Path(source).is_file():
            raise SystemExit(f"catalog source missing: {source}")
    validate_source_credit(matches)
    print(
        f"catalog ok: linked code {complete_code}/{TEXT_SIZE} "
        f"({complete_code * 100.0 / TEXT_SIZE:.4f}%), "
        f"linked data {complete_data}/{DATA_SIZE} "
        f"({complete_data * 100.0 / DATA_SIZE:.4f}%), "
        f"matched code {matched_code}, matched data {matched_data}"
    )


if __name__ == "__main__":
    main()
