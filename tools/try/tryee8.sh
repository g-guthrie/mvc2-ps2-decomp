#!/bin/sh
# EE GCC 2.96 at small-data threshold 8. Thin wrapper over tryee.sh.
# usage: tools/try/tryee8.sh src/f.c [gnu|sn] [O0|O1|O2|O3]
set -eu
cd "$(dirname "$0")/../.."
exec tools/try/tryee.sh "$1" "${2:-gnu}" 8 "${3:-O2}"
