#!/bin/sh

set -eu

PYTHON=${PYTHON:-python3}
AS=${AS:-mipsel-linux-gnu-as}
LD=${LD:-mipsel-linux-gnu-ld}
OBJCOPY=${OBJCOPY:-mipsel-linux-gnu-objcopy}

TARGET=private/SLUS_204.86.rom
BUILD=build/relink
EXPECTED_SIZE=3941760
EXPECTED_SHA1=a425c36425bbc1072114ea091ac4577c98c59a6a
EXPECTED_SHA256=c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f

mkdir -p "$BUILD"

"$PYTHON" tools/write_splat_macros.py config/SLUS_204.86.yaml
perl tools/rawify_splat_asm.pl asm/main.s "$BUILD/main.raw.s"

"$AS" -EL -march=r5900 -mabi=32 -I include \
    -o "$BUILD/main.raw.o" "$BUILD/main.raw.s"
"$AS" -EL -march=r5900 -mabi=32 -I include \
    -o "$BUILD/main_bss.o" asm/data/main_bss.bss.s

"$LD" -EL -m elf32ltsmip -T config/relink.ld \
    -Map "$BUILD/relink.map" \
    -o "$BUILD/SLUS_204.86.relinked.elf" \
    "$BUILD/main.raw.o" "$BUILD/main_bss.o"

"$OBJCOPY" -O binary --only-section=.text \
    "$BUILD/SLUS_204.86.relinked.elf" \
    "$BUILD/SLUS_204.86.relinked.rom"

actual_size=$(wc -c < "$BUILD/SLUS_204.86.relinked.rom" | tr -d ' ')
test "$actual_size" = "$EXPECTED_SIZE"

actual_sha1=$(shasum -a 1 "$BUILD/SLUS_204.86.relinked.rom" | awk '{print $1}')
test "$actual_sha1" = "$EXPECTED_SHA1"

actual_sha256=$(shasum -a 256 "$BUILD/SLUS_204.86.relinked.rom" | awk '{print $1}')
test "$actual_sha256" = "$EXPECTED_SHA256"

cmp "$BUILD/SLUS_204.86.relinked.rom" "$TARGET"

printf 'exact relink: %s bytes\n' "$actual_size"
printf 'sha1:   %s\n' "$actual_sha1"
printf 'sha256: %s\n' "$actual_sha256"
