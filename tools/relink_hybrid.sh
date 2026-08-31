#!/bin/sh

set -eu

PYTHON=${PYTHON:-python3}
AS=${AS:-mipsel-linux-gnu-as}
LD=${LD:-mipsel-linux-gnu-ld}
OBJCOPY=${OBJCOPY:-mipsel-linux-gnu-objcopy}

TARGET=private/SLUS_204.86.rom
BUILD=build/hybrid
EXPECTED_SIZE=3941760
EXPECTED_SHA1=a425c36425bbc1072114ea091ac4577c98c59a6a
EXPECTED_SHA256=c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f

mkdir -p "$BUILD"

"$PYTHON" tools/write_splat_macros.py config/SLUS_204.86.yaml
"$AS" -EL -march=r5900 -mabi=eabi -I include \
    -o "$BUILD/main_bss.o" asm/data/main_bss.bss.s

"$PYTHON" tools/generate_hybrid_relink.py \
    --target "$TARGET" \
    --compiled-dir build/matching \
    --build "$BUILD" \
    --bss-object "$BUILD/main_bss.o"

"$AS" -EL -march=r5900 -mabi=eabi \
    -o "$BUILD/raw_chunks.o" "$BUILD/raw_chunks.s"
"$AS" -EL -march=r5900 -mabi=eabi \
    -o "$BUILD/compiled_sections.o" "$BUILD/compiled_sections.s"

"$LD" -EL -m elf32ltsmip -T "$BUILD/hybrid.ld" \
    -Map "$BUILD/hybrid.map" \
    -o "$BUILD/SLUS_204.86.hybrid.elf" \
    "$BUILD/raw_chunks.o" "$BUILD/compiled_sections.o" "$BUILD/main_bss.o"

"$PYTHON" tools/verify_hybrid_symbols.py "$BUILD/SLUS_204.86.hybrid.elf"

"$OBJCOPY" -O binary --only-section=.text \
    "$BUILD/SLUS_204.86.hybrid.elf" \
    "$BUILD/SLUS_204.86.hybrid.rom"

actual_size=$(wc -c < "$BUILD/SLUS_204.86.hybrid.rom" | tr -d ' ')
test "$actual_size" = "$EXPECTED_SIZE"
actual_sha1=$(shasum -a 1 "$BUILD/SLUS_204.86.hybrid.rom" | awk '{print $1}')
test "$actual_sha1" = "$EXPECTED_SHA1"
actual_sha256=$(shasum -a 256 "$BUILD/SLUS_204.86.hybrid.rom" | awk '{print $1}')
test "$actual_sha256" = "$EXPECTED_SHA256"
cmp "$BUILD/SLUS_204.86.hybrid.rom" "$TARGET"

printf 'exact hybrid relink: %s bytes\n' "$actual_size"
printf 'sha1:   %s\n' "$actual_sha1"
printf 'sha256: %s\n' "$actual_sha256"
