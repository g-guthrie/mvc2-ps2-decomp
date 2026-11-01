#!/bin/sh
# Run the port (native i386, headless) and the oracle (retail game in Play!)
# on the same input script, dump both, compare.
#   run_pair.sh OUTDIR FRAMES RESYNC_STATE [SCRIPT] [-- compare.py options]
# Environment: PORT (default build/port-i386/mvc2), ORACLE (default
# /tmp/oracle_src/build/mvc2_oracle), ISO (default private/disc/mvc2.iso),
# PORT_ARGS / ORACLE_ARGS extra options, DUMP_FROM (default 0).
set -e
ROOT=$(cd "$(dirname "$0")/../../.." && pwd)
OUT=$1; FRAMES=$2; SYNC=$3; SCRIPT=${4:-}
shift 3; [ $# -gt 0 ] && shift
[ "${1:-}" = "--" ] && shift
PORT=${PORT:-$ROOT/build/port-i386/mvc2}
ORACLE=${ORACLE:-/tmp/oracle_src/build/mvc2_oracle}
ISO=${ISO:-$ROOT/private/disc/mvc2.iso}
DUMP_FROM=${DUMP_FROM:-0}
mkdir -p "$OUT"
rm -rf "$OUT/oracle_home" "$OUT/mc"; mkdir -p "$OUT/mc"
SARG=""; [ -n "$SCRIPT" ] && SARG="--script $SCRIPT"
MVC2_ORACLE_HOME="$OUT/oracle_home" "$ORACLE" --iso "$ISO" --frames "$FRAMES" --resync "$SYNC" \
    --dump "$OUT/oracle.bin" --dump-from "$DUMP_FROM" $SARG ${ORACLE_ARGS:-} > "$OUT/oracle.log" 2>&1 &
OPID=$!
MVC2_PAD_DELAY=${PAD_DELAY:-0} MVC2_RESYNC="$SYNC" MVC2_STATE_DUMP="$OUT/port.bin" MVC2_STATE_DUMP_FROM="$DUMP_FROM" MVC2_MEMCARD="$OUT/mc" \
    SDL_VIDEODRIVER=offscreen SDL_AUDIODRIVER=dummy "$PORT" --hidden --frames "$FRAMES" --draw-every 600 \
    $SARG ${PORT_ARGS:-} --iso "$ISO" > "$OUT/port.log" 2>&1 || true
wait $OPID || true
rm -rf "$OUT/oracle_home"
python3 "$ROOT/port/tools/oracle/compare.py" "$OUT/port.bin" "$OUT/oracle.bin" --sync "$SYNC" "$@" | tee "$OUT/compare.txt"
