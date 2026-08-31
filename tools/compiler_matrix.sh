#!/bin/sh
set -eu

: "${WIBO:?set WIBO to a private wibo executable}"
: "${COMPILER_ROOT:?set COMPILER_ROOT to private extracted compiler directories}"

PYTHON=${PYTHON:-python3}
BUILD=build/compiler-probes
mkdir -p "$BUILD"

for version in \
  mwcps2-2.4-001213 \
  mwcps2-3.0-011126 \
  mwcps2-3.0.1-020123 \
  mwcps2-3.0.3-020716
do
  compiler="$COMPILER_ROOT/$version/mwccps2.exe"
  MWCIncludes="$COMPILER_ROOT/$version" "$WIBO" "$compiler" \
    tools/probes/real.c -c -lang c -O3 -sdatathreshold 0 \
    -o "$BUILD/real_$version.o"
done

"$PYTHON" tools/function_bytes.py "$BUILD"/real_mwcps2-*.o
