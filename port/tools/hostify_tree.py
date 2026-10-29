#!/usr/bin/env python3
"""Write hostify.py-filtered copies of decomp sources into a build tree.

usage: hostify_tree.py OUTDIR [--sigs host_sigs.json] SRC...   (SRC relative to the repo root)
       hostify_tree.py OUTDIR [--sigs host_sigs.json] --headers (every src/*.h and src/data/*.h)
--sigs turns on hostify R12-R14 (gen_link_glue.py sigs).
Files are rewritten only when their filtered text changes.
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import hostify  # noqa: E402


def emit(out, rel):
    text = hostify.transform((ROOT / rel).read_text(encoding="latin-1"), rel)
    dst = out / rel
    dst.parent.mkdir(parents=True, exist_ok=True)
    if not dst.exists() or dst.read_text(encoding="latin-1") != text:
        dst.write_text(text, encoding="latin-1")
    # unchanged output keeps its mtime: Ninja restats custom-command outputs
    # and skips recompiling TUs whose filtered text did not change.


def main():
    out = Path(sys.argv[1])
    args = sys.argv[2:]
    sigs = None
    if args[:1] == ["--sigs"]:
        sigs, args = args[1], args[2:]
    hostify.configure(sigs or None)
    if args == ["--headers"]:
        args = [str(p.relative_to(ROOT)) for p in sorted((ROOT / "src").glob("*.h"))]
        args += [str(p.relative_to(ROOT)) for p in sorted((ROOT / "src/data").glob("*.h"))]
    for rel in args:
        emit(out, rel)


if __name__ == "__main__":
    main()
