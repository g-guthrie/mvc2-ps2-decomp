#!/usr/bin/env python3
"""Check the EE data image layout of a host link (Port J, hostify R18).

usage: check_data_layout.py BINARY|LINK.map   (ELF via nm; wasm via the wasm-ld -Map file)
Every layout unit (link_catalog.layout_units) must sit at
host(first) + (EE address - EE address of the first): one contiguous image.
"""
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import link_catalog as L  # noqa: E402


def main():
    binp = sys.argv[1]
    addr = {}
    if binp.endswith(".map"):  # wasm-ld -Map output: "addr off size  symbol"
        for line in open(binp):
            p = line.split()
            if len(p) == 4 and p[0] != "-":
                try:
                    addr.setdefault(p[3], int(p[0], 16))
                except ValueError:
                    pass
    else:
        nm = subprocess.run(["nm", binp], capture_output=True, text=True).stdout
        for line in nm.splitlines():
            p = line.split()
            if len(p) == 3:
                addr.setdefault(p[2], int(p[0], 16))
    lu = L.layout_units()
    hole0 = L.data_holes()[None]
    base_host = addr.get(f"mvc2_hole_{hole0[0]:08X}")
    base_ee = hole0[0]
    bad = 0
    for a, size, name, src in lu:
        h = addr.get(name)
        if h is None:
            print(f"missing {name}")
            bad += 1
            continue
        if h - base_host != a - base_ee:
            bad += 1
            if bad <= 20:
                print(f"{name}: EE +{a - base_ee:#x}, host +{h - base_host:#x}")
    print(f"{len(lu)} units, {bad} misplaced; image {base_host:#x}..")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
