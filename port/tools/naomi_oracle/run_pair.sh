#!/bin/sh
# Run the port (native i386, headless, arcade options on) and the NAOMI
# arcade oracle (Flycast) on the same scenario, dump both, compare.
#   run_pair.sh OUTDIR FRAMES RESYNC_STATE NAOMI_SCRIPT PORT_SCRIPT [-- naomi_compare.py options]
# The two scripts differ only in the menu part (the arcade starts from its
# attract with a credit, the PS2 game from its title and mode menu); the
# fight part is the same file content (scripts/*.txt, see README).
# Environment:
#   PORT (default build/port-i386/mvc2), FLYCAST (default
#   /tmp/naomi_oracle_src/build/flycast), ISO (private/disc/mvc2.iso),
#   NAOMI_ZIP (the user's mvsc2.zip, MAME set), NAOMI_BIOS (the user's naomi.zip),
#   TEAMS ("--p1-team a,b,c --cpu-team d,e,f", given to both sides),
#   ARCADE (port --arcade letters, default abcde: frames+boxes, damage, CPU
#   AI, flying-screen edge, Servbot hit stop), PAD_DELAY (default 2: the
#   oracle's JVS-to-logic pipeline, see README), PORT_ARGS / NAOMI_ARGS.
set -e
ROOT=$(cd "$(dirname "$0")/../../.." && pwd)
OUT=$1; FRAMES=$2; SYNC=$3; NS=$4; PSC=$5
shift 5; [ "${1:-}" = "--" ] && shift
PORT=${PORT:-$ROOT/build/port-i386/mvc2}
FLYCAST=${FLYCAST:-/tmp/naomi_oracle_src/build/flycast}
ISO=${ISO:-$ROOT/private/disc/mvc2.iso}
NAOMI_ZIP=${NAOMI_ZIP:?set NAOMI_ZIP to your mvsc2.zip}
NAOMI_BIOS=${NAOMI_BIOS:?set NAOMI_BIOS to your naomi.zip}
ARCADE=${ARCADE:-abcde}
mkdir -p "$OUT"
# a fresh NAOMI home per run: EEPROM / NVRAM start from the game's defaults
rm -rf "$OUT/naomi_home" "$OUT/mc"; mkdir -p "$OUT/naomi_home" "$OUT/mc"
ln -s "$(realpath "$NAOMI_BIOS")" "$OUT/naomi_home/naomi.zip"
NSARG=""; [ -n "$NS" ] && NSARG="--script $NS"
PSARG=""; [ -n "$PSC" ] && PSARG="--script $PSC"
"$FLYCAST" --naomi-oracle --game "$NAOMI_ZIP" --home "$OUT/naomi_home" --frames "$FRAMES" \
    --resync "$SYNC" --dump "$OUT/naomi.bin" $NSARG ${TEAMS:-} ${NAOMI_ARGS:-} > "$OUT/naomi.log" 2>&1 &
NPID=$!
MVC2_ARCADE_DELAY=${PAD_DELAY:-2} MVC2_RESYNC="$SYNC" MVC2_STATE_DUMP="$OUT/port.bin" MVC2_MEMCARD="$OUT/mc" \
    SDL_VIDEODRIVER=offscreen SDL_AUDIODRIVER=dummy "$PORT" --hidden --frames "$FRAMES" --draw-every 600 \
    --arcade "$ARCADE" --naomi "$NAOMI_ZIP" $PSARG ${TEAMS:-} ${PORT_ARGS:-} --iso "$ISO" > "$OUT/port.log" 2>&1 || true
wait $NPID || true
rm -rf "$OUT/naomi_home" "$OUT/mc"
python3 "$ROOT/port/tools/naomi_oracle/naomi_compare.py" "$OUT/port.bin" "$OUT/naomi.bin" --sync "$SYNC" "$@" | tee "$OUT/compare.txt"
