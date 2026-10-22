#!/bin/sh
# Compile and private-verify each source-owned initialized-data unit.
# DATA_JOBS defaults to one worker per CPU; set it to 1 for serial operation.
set -eu

: "${WIBO:?set WIBO to the private wibo executable}"
: "${MWCCPS2:?set MWCCPS2 to the private mwccps2.exe}"

PYTHON=${PYTHON:-python3}
BUILD=${BUILD:-build/matching}
TARGET=${TARGET:-private/SLUS_204.86.rom}
DATA_JOBS=${DATA_JOBS:-auto}
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

if [ "$DATA_JOBS" = auto ]; then
    exec "$PYTHON" tools/run_matching_data.py "$BUILD" "$TARGET" "$WIBO" "$MWCCPS2"
fi
exec "$PYTHON" tools/run_matching_data.py "$BUILD" "$TARGET" "$WIBO" "$MWCCPS2" --jobs "$DATA_JOBS"
