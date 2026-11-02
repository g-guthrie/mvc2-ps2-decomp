#!/bin/sh
# Run the port (native i386, headless) and mvc2_av (retail game in Play! with
# its GS renderer and SPU2) on the same input script; collect the pictures,
# the sound command logs and the mixed audio of both, then compare.
#   run_av.sh OUTDIR FRAMES [SCRIPT]
# Environment: PORT (default build/port-i386/mvc2), AV (default
# /tmp/oracle_av/build/mvc2_av), ISO, PORT_ARGS / ORACLE_ARGS (e.g.
# "--p1-team 0x36,0x34,0x00 --cpu-team 0x27,0x1E,0x34" on both),
# EVERY (picture every N frames, default 15), SYNC (default 1/1/0),
# OFFSET (oracle frame - port frame for the same picture: the 12 frames
# the PS2 boot takes longer + 1 frame of display latency = 13),
# NOIMG=1 (sound only, much faster), KEEP=1 (keep the shots), PORTONLY=1
# (rerun only the port against the oracle output already in OUTDIR).
set -e
ROOT=$(cd "$(dirname "$0")/../../.." && pwd)
OUT=$1; FRAMES=$2; SCRIPT=${3:-}
PORT=${PORT:-$ROOT/build/port-i386/mvc2}
AV=${AV:-/tmp/oracle_av/build/mvc2_av}
ISO=${ISO:-$ROOT/private/disc/mvc2.iso}
EVERY=${EVERY:-15}; SYNC=${SYNC:-1/1/0}; OFFSET=${OFFSET:-13}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
rm -rf "$OUT/oracle_home" "$OUT/mc" "$OUT/port_img"
[ -n "$PORTONLY" ] || rm -rf "$OUT/oracle_img"
mkdir -p "$OUT/mc" "$OUT/port_img" "$OUT/oracle_img"
SARG=""; [ -n "$SCRIPT" ] && SARG="--script $SCRIPT"
GARG="--gs-dir $OUT/oracle_img --gs-from $OFFSET --gs-every $EVERY"
PSHOT="--shot-every $EVERY --shot-dir $OUT/port_img"
if [ -n "$NOIMG" ]; then GARG=""; PSHOT=""; fi
OPID=""
[ -n "$PORTONLY" ] || MVC2_ORACLE_HOME="$OUT/oracle_home" "$AV" --iso "$ISO" --frames $((FRAMES + 12)) --resync "$SYNC" \
    --snd-log "$OUT/oracle.snd" --wav "$OUT/oracle.wav" $GARG $SARG ${ORACLE_ARGS:-} > "$OUT/oracle.log" 2>&1 &
[ -n "$PORTONLY" ] || OPID=$!
MVC2_RESYNC="$SYNC" MVC2_SND_LOG="$OUT/port.snd" MVC2_AUDIO_WAV="$OUT/port.wav" MVC2_MEMCARD="$OUT/mc" \
    SDL_VIDEODRIVER=offscreen SDL_AUDIODRIVER=dummy "$PORT" --hidden --frames "$FRAMES" $PSHOT \
    $SARG ${PORT_ARGS:-} --iso "$ISO" > "$OUT/port.log" 2>&1 || true
[ -z "$OPID" ] || wait $OPID || true
rm -rf "$OUT/oracle_home"
C="/usr/bin/python3 $ROOT/port/tools/oracle_av/compare_av.py"
$C snd "$OUT/port.snd" "$OUT/oracle.snd" --sync "$SYNC" > "$OUT/snd.txt" || true
$C audio "$OUT/port.wav" "$OUT/port.snd" "$OUT/oracle.wav" "$OUT/oracle.snd" --sync "$SYNC" > "$OUT/audio.txt" || true
if [ -z "$NOIMG" ]; then
    $C img "$OUT/port_img" "$OUT/oracle_img" "$OUT/port.snd" "$OUT/oracle.snd" --sync "$SYNC" --lat $((OFFSET - 12)) \
        --out "$OUT/worst" --worst 12 > "$OUT/img.txt" || true
    [ -n "$KEEP" ] || rm -rf "$OUT/port_img"
fi
echo "results: $OUT/snd.txt audio.txt img.txt"
