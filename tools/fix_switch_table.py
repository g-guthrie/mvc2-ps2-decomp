"""Redirect a compiler-generated switch-table load at the retail jump table.

EE GCC emits a switch dispatch as `lw $R,$LNN($R2)` against a table it places in
.rdata. The relocation is against the .rdata *section* symbol rather than a named
`@N` symbol, so `objcopy --redefine-sym` (the usual recipe) cannot reach it.
Rewriting the reference to a named jtbl_ symbol makes the load resolve to the
retail table address instead, and leaves the compiler's own copy unreferenced.

The label number depends on the file's contents, so match the pattern rather
than a literal `$L29`, and require exactly one candidate so a silent
mis-rewrite is impossible.
"""
import argparse
import re
import sys

LOAD = re.compile(r'^(\s*lw\s+\$\d+,)\$L\d+(\(\$\d+\)\s*)$')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source")
    ap.add_argument("symbol", help="e.g. jtbl_004BC800")
    args = ap.parse_args()

    with open(args.source) as f:
        lines = f.readlines()

    hits = [i for i, l in enumerate(lines) if LOAD.match(l)]
    if len(hits) != 1:
        sys.exit(
            f"{args.source}: expected exactly one switch-table load, found {len(hits)}"
        )

    i = hits[0]
    lines[i] = LOAD.sub(rf"\1{args.symbol}\2", lines[i])
    with open(args.source, "w") as f:
        f.writelines(lines)
    print(f"{args.source}: switch-table load -> {args.symbol}")


if __name__ == "__main__":
    main()
