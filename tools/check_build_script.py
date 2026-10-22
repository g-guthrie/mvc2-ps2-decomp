#!/usr/bin/env python3
"""Compiler-free structural check for tools/compile_matching.sh.

CI cannot run the matching build (the compilers are not redistributable), so
mistakes in the build script used to surface only on a private build, often
after it had run for many minutes. This catches the classes seen so far:

* a dangling `\\` continuation that swallows the next stanza's head;
* a verify body or `--source` line whose command head is missing;
* a compiled source that does not exist;
* two commands writing the same object;
* an MWCC command whose source (or a header it pulls in) has a quoted
  `#include` that none of the command's `-i`/`-I` directories resolve.
  mwccps2 does not search the including file's directory, so a header beside
  the source still needs `-i src`.
"""

from __future__ import annotations

import argparse
import re
import shlex
import sys
from pathlib import Path


EXTERN_RE = re.compile(r"\bextern\b[^;(]*?\b([A-Za-z_]\w*_[0-9A-Fa-f]{8})\b\s*(?:\[|;)")
INCLUDE_RE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)


def logical_commands(lines: list[str]) -> list[tuple[int, str]]:
    commands = []
    start, parts = None, []
    for number, line in enumerate(lines, 1):
        if start is None:
            start = number
        parts.append(line.rstrip("\\").strip())
        if not line.rstrip().endswith("\\"):
            commands.append((start, " ".join(parts)))
            start, parts = None, []
    if parts:
        commands.append((start, " ".join(parts)))
    return commands


def structural_errors(lines: list[str]) -> list[tuple[int, str]]:
    errors = []
    for index, line in enumerate(lines):
        stripped = line.strip()
        prev = lines[index - 1] if index else ""
        if line.rstrip().endswith("\\") and index + 1 < len(lines):
            following = lines[index + 1]
            if following.startswith("MWCIncludes=") or following.startswith('"$WIBO"'):
                errors.append((index + 1, "dangling continuation swallows the next stanza"))
        if stripped.startswith('"$BUILD/') and "SLUS_204.86.rom" in stripped:
            if not prev.rstrip().endswith("\\") or "verify_object" not in prev:
                errors.append((index + 1, "verify body without its command head"))
        if stripped.startswith("--source ") and not prev.rstrip().endswith("\\"):
            errors.append((index + 1, "--source line without its command head"))
    return errors


def include_dirs(words: list[str]) -> list[Path]:
    dirs = []
    for index, word in enumerate(words):
        if word in {"-i", "-I"} and index + 1 < len(words):
            dirs.append(Path(words[index + 1]))
        elif word.startswith("-I") and len(word) > 2:
            dirs.append(Path(word[2:]))
    return dirs


def unresolved_includes(source: Path, dirs: list[Path]) -> list[str]:
    missing, seen, pending = [], set(), [source]
    while pending:
        current = pending.pop()
        if current in seen or not current.is_file():
            continue
        seen.add(current)
        for name in INCLUDE_RE.findall(current.read_text(encoding="utf-8", errors="replace")):
            found = next((d / name for d in dirs if (d / name).is_file()), None)
            if found is None:
                missing.append(f"{current}: \"{name}\"")
            else:
                pending.append(found)
    return missing


def command_errors(commands: list[tuple[int, str]]) -> list[tuple[int, str]]:
    errors = []
    outputs: dict[str, int] = {}
    for number, command in commands:
        for match in re.finditer(r"\bsrc/[\w./-]+\.(?:c|S|s)\b", command):
            if not Path(match.group(0)).exists():
                errors.append((number, f"missing source {match.group(0)}"))
        if '"$WIBO"' not in command and "compile_ee96" not in command:
            continue
        try:
            words = shlex.split(command.replace("$", "\\$"))
        except ValueError:
            errors.append((number, "unparseable command"))
            continue
        for index, word in enumerate(words[:-1]):
            if word == "-o" and words[index + 1].endswith(".o"):
                target = words[index + 1].replace("\\$", "$")
                if "$" in target.replace("$BUILD", ""):
                    continue  # loop-generated name; one line covers many units
                if target in outputs:
                    errors.append((number, f"{target} also written at line {outputs[target]}"))
                outputs.setdefault(target, number)
        if "-lang" in words and "c" in words:
            sources = [Path(w) for w in words if w.startswith("src/") and w.endswith(".c")]
            for source in sources:
                for missing in unresolved_includes(source, include_dirs(words)):
                    errors.append((number, f"MWCC cannot resolve {missing}"))
    verified = {
        word.replace("\\$", "$")
        for _, command in commands if "verify_object.py" in command
        for word in shlex.split(command.replace("$", "\\$"))
        if word.endswith(".o")
    }
    for target, number in outputs.items():
        if target not in verified:
            errors.append((number, f"{target} is compiled but never verified"))
    return errors


def data_extern_errors(data_dir: Path) -> list[tuple[int, str]]:
    """Every address-named extern a data unit relocates against needs a label.

    The data verifier resolves relocations only through the labels that
    generate_data_symbol_addrs.py derives from names, so an extern whose name
    that generator does not recognize fails verification with "unmapped data
    relocation target" late in a private build.
    """
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from generate_data_symbol_addrs import SYMBOL_RE

    errors = []
    for source in sorted(data_dir.glob("*.c")):
        text = source.read_text(encoding="utf-8", errors="replace")
        for match in EXTERN_RE.finditer(text):
            name = match.group(1)
            if not SYMBOL_RE.fullmatch(name):
                line = text.count("\n", 0, match.start()) + 1
                errors.append((0, f"{source}:{line}: extern {name} gets no data label"))
    return errors


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("script", type=Path, nargs="?", default=Path("tools/compile_matching.sh"))
    args = parser.parse_args()
    lines = args.script.read_text(encoding="utf-8").split("\n")
    errors = structural_errors(lines) + command_errors(logical_commands(lines))
    errors += data_extern_errors(Path("src/data"))
    for number, message in sorted(errors):
        print(f"{args.script}:{number}: {message}")
    if errors:
        sys.exit(1)
    print(f"{args.script}: build script ok ({len(lines)} lines)")


if __name__ == "__main__":
    main()
