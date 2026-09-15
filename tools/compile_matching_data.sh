#!/bin/sh
# Compile and private-verify each source-owned initialized-data unit.
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"

PYTHON=${PYTHON:-python3}
BUILD=${BUILD:-build/matching}
TARGET=${TARGET:-private/SLUS_204.86.rom}
mkdir -p "$BUILD/data"

# Every compiled data unit must contribute its symbols, or relocation targets
# in units added later resolve to nothing and verification aborts.
"$PYTHON" -c "
from pathlib import Path
import subprocess, sys
sources = sorted(str(path) for path in Path('src/data').glob('*.c'))
subprocess.check_call(
    [sys.executable, 'tools/generate_data_symbol_addrs.py', *sources, 'config/data_symbol_addrs.txt']
)
"

"$PYTHON" - "$BUILD" "$TARGET" "$WIBO" "$MWCCPS2" "$PYTHON" <<'PY'
import csv
import os
import subprocess
import sys
from pathlib import Path

build, target, wibo, mwcc, python = sys.argv[1:]
includes = str(Path(mwcc).parent)
env = os.environ.copy()
env["MWCIncludes"] = includes
Path(build, "data").mkdir(parents=True, exist_ok=True)

with Path("config/data_units.csv").open(newline="", encoding="utf-8") as stream:
    units = list(csv.DictReader(stream))

for unit in units:
    source = Path(unit["source"])
    name = unit["name"]
    object_path = Path(build) / "data" / (source.stem + ".o")
    subprocess.check_call(
        [
            wibo,
            mwcc,
            str(source),
            "-c",
            "-lang",
            "c",
            "-O3",
            "-sdatathreshold",
            "0",
            "-i",
            "src/data",
            "-o",
            str(object_path),
        ],
        env=env,
    )
    subprocess.check_call(
        [python, "tools/verify_data_object.py", str(object_path), target, "--name", name]
    )
PY
