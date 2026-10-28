# MvC2 PS2: asset formats and the converter prototype

Conventions follow `ENGINE_MAP.md` / `ASSET_LOADING.md`. Status tags:
**[verified]** = decoded from the user's disc and checked visually or
numerically; **[decomp]** = read from the decomp but not exercised;
**[inferred]** = a guess from data.

The tools are in `port/tools/convert/`. They need Python 3 only (Pillow is
not installed, so `png.py` writes PNGs with zlib). They read the user's own
`private/disc/mvc2.iso`, contain **no asset bytes**, and write only under
`private/converted/`, which is outside git (`/private/` is gitignored and is a
symlink out of the tree).

| Tool | Does |
|---|---|
| `iso.py` | ISO9660 walk; `Iso(path).read('/FONT8_8.TM2')` |
| `afs.py` | AFS list / extract (`afs.py ISO list 2`) |
| `png.py` | stdlib RGBA PNG writer/reader |
| `chars.py` | PLxxPAK sprite bank: palettes, tiles, frame composition → PNG |
| `tim2.py` | TIM2 → RGBA (4/8-bit with CSM1/CSM2 CLUTs, 16/24/32-bit) |
| `textures.py` | `font` (`/FONT8_8.TM2`) or `afs ID...`: TIM2 files, LZ16/raw TEX packs (16-byte records), 12-byte tables (`func_00416180` containers) |
| `adx.py` | AFS00 CRI ADX → 16-bit WAV with an `smpl` loop chunk |
| `hdbd.py` | AFS01 Sony HD/BD bank → one WAV per VAG and a `bank.txt` summary |
| `../mvc2_lz16.py` | LZ16 (`func_00176230`), reused by `textures.py` |

Commands used (run from `port/tools/convert`, `ISO=../../../private/disc/mvc2.iso`,
`OUT=../../../private/converted`):
```
python3 chars.py $ISO 0 $OUT/chars --frames 0-3,86,100,108,140,150,200 --palettes
python3 textures.py $ISO $OUT/tex font
python3 textures.py $ISO $OUT/tex afs 0 149 150 802
python3 adx.py $ISO $OUT/audio 17 15
python3 hdbd.py $ISO $OUT/audio 59      # common SE bank;  0 = Ryu bank
```

## 1. Containers

### 1.1 ISO / AFS [verified]
ISO9660 with 2048-byte sectors. AFS: `"AFS\0"`, u32 count, count x `{u32 off,
u32 size}` (2048-aligned, relative to the archive), then `{u32 nameOfs, u32
nameSize}`. Only AFS02 has a name table (48-byte entries: `char[32]` name,
6 x u16 date, u32 size). Mounted as ptid 0..3 by `func_004189A0`.

### 1.2 TEX resource pack [verified]
Used by `*TEX.BIN`, `SELTEX.BIN`, `EFKYTEX.BIN` (and DMxx, raw). After LZ16
decoding (only when compressed: STGxxTEX, SELTEX, EFKYTEX, ENDDCTEX):
```
struct ResourceRecord {      // include/runtime_resource_record.h, 16 bytes
    s16 w;                   // > 0 = valid; <= 0 terminates the array
    u16 h;
    u32 flags;               // >>16 = kind for func_00415250; &0xF0 = also tag it
    u32 offset;              // relative to pack start; func_0016F4D0 adds the base
    s32 attr;                // >>16 = tag state (func_00415020 / func_00415140)
};
```
kind 0 → `func_00415B00`, **1 → TIM2 (`func_00418200`)**, 2 → `func_00418570`,
3 → `func_00418410`. All records in STG00TEX (12), SELTEX (79) and EFKYTEX (25)
are kind 1, flags 0x10020 or 0x10010. Loaders: `func_0016F430` (stage:
LZ16 into `D_004C28B0`, relocate, `func_00415020(0xC10, ...)`), `func_0016F3C0`.

### 1.3 12-byte table (`func_00416180`) [verified on SELSTG]
`func_00416180(base, n)` (asm) walks 12-byte entries `{s32 tag, u32 size, u32
offset}` until `tag < 0` and returns `base + entry[n].offset` (0 when `n` is
past the end). `SELSTG.BIN` (AFS02 150, loaded by `func_0016FC80`, src/sa28_b.c)
is LZ16 → this table → 19 TIM2 (18 x 128x128 8bpp stage thumbnails, 1 x 64x64).
Entries 0x12 and 0 are then registered as kind-1 resources through
`func_00415140`. The same accessor is used on AFS01-style data in
`func_001E7430/7470` (src/grok_w3_001e.c) and on character data in `func_0016FAA0`.

### 1.4 LZ16 (`func_00176230`) [verified]
See `port/tools/mvc2_lz16.py`: u16 stream, MSB-first flag word, 1 = token
`v`: `cnt = v >> 11` (0 → next word), `off = v & 0x7FF` words back, off 0 =
zero fill, cnt 0 + off 0 = end. No size header; output size is implicit.

## 2. Character sprite bank (section 0 of PLxxPAK.BIN) [verified]

`PLxxPAK.BIN` = AFS02 index `209 + xx` (`xx` = character ID 0x00..0x3A). PAK
header: 16 u32 section offsets (`+0x00` = 0x40 = section 0; zeros = absent).
Section 0 is the sprite bank (`func_0016F1B0` binds it, `func_00413D50` →
`func_00411C10` registers it into one of 16 slots `D_00632610`).

### 2.1 Bank header (0x20 bytes)
| Off | Value (all 59 banks) | Meaning |
|---|---|---|
| +0x00 | 0 | unused on disc |
| +0x04 | 0x20 | **tile table** offset (from bank) |
| +0x08 | 0 | |
| +0x0C | varies | **frame table** offset (from bank) |
| +0x10 | 0 | |
| +0x14 | varies | **palette** offset (from bank) |
| +0x18, +0x1C | 0 | |

Counts are implicit: `nTiles = tileTable[0] / 4`, `nFrames = frameTable[0] / 4`
(the first entry points just past the table). PL00 (Ryu): 1638 tiles, 441
frames; the largest is 0x12 with 5270 tiles; frame counts range 267..1392.
The palette block is always **0x600 bytes = 48 palettes** of 16 colours, but
`func_00411C10` uploads only the first 16.

### 2.2 Tables (offsets are relative to the *table start*, not the bank)
`func_00412260` computes `tileTable + tileTable[i]` and `frameTable + frameTable[f]`.

Frame record:
```
s16 nParts;
struct { s16 dx, dy; u16 flags; s16 tile; } part[nParts];
```
The draw position is **cumulative**: start at (0,0); for each part,
`pos -= (dx, dy)`; the part's top-left is `pos`. Origin = actor position
(feet), y grows downward (standing Ryu spans y = -94..+5).
Part flags: `0x8000` H-flip, `0x4000` V-flip, bits 4..7 = **palette offset**
(`clut = slot.d[((flags >> 4) + palette) & 0xF]`), bit 0 = small UV bias in
`func_00413600` (no visible effect). No other bits occur in PL00.

Tile record:
```
u8 fw8, fh8;   // flip extents in 8-px units (used only for flipped placement)
u8 w8,  h8;    // tile size = w8*8 x h8*8 (8..64 each)
u8 lz[];       // func_00413A80 stream that decodes to w*h/2 bytes of 4bpp
```
### 2.3 Pixel decode (`func_00413A80`, src/p3r.c)
Flag byte, 8 items MSB-first: 0 = literal byte; 1 = byte `b`, copy `(b & 0xF)
+ 2` bytes from `dst - ((b >> 4) + 1)` (overlapping copies allowed). It stops
when `dst >= end`, so it can overrun by up to 16 bytes (the staging buffer
tolerates that). Checked on all 59 banks: each tile's stream ends exactly at
the next tile record.

The decoded bytes are **not** a w x h image. The tile is split into square
sub-blocks of side `s = min(w, h)` along the long axis (`n = max/min`), stored
one after another, each `s x s` 4bpp row-major, **low nibble = left pixel**
(PSMT4). Sub-block `k` is drawn at `pos + k*s` along the long axis.

### 2.4 Flip placement (`func_00412260` + `func_00413600`)
- H-flip: `x0 = pos.x + fw8*8 - s`, the step along x is `-s`, and the texture
  of each sub-block is mirrored (UV corners swapped in `func_00413600`).
- V-flip: the same with `fh8` on y.
`fw8/fh8` equal `w8/h8` for 1041 of 1638 Ryu tiles; otherwise they are the
"used" extent, so a flipped tile anchors on its visible pixels.

### 2.5 Palettes (`func_00411C10`, src/xl14_a.c)
16 x u16 ARGB1555 per palette, 32 bytes per palette:
`R = (c >> 10 & 31) << 3`, `G = (c >> 5 & 31) << 3`, `B = (c & 31) << 3`,
`A = c & 0x8000 ? 0x80 : 0` (GS alpha; 0x80 = opaque → 255 in PNG). No
low-bit replication (`<<3` only). Index 0 is 0x0000 → transparent; the
converter skips index 0 as the GS alpha test would.

### 2.6 Runtime cache (not needed by the port)
`func_00411C10` makes 26 128x128 PSMT4 pages + 0x740 bytes of LRU state.
`func_00413B20(cache, n, key)` returns `page<<6 | cy<<3 | cx` (16-px cells)
for tiles with area <= 0x100, a 32-px-cell variant (`cache+0x400`, 0xA0 slots,
`page<<4 | cy<<2 | cx`) for area <= 0x400, and a third path for larger tiles.
Sub-block placement inside a cell uses `D_004BECD0[s]` → `D_00496850` (float
x,y pairs). The port can replace all of this with a per-character atlas.

### 2.7 Output [verified]
`private/converted/chars/pl00_fNNN_p0.png` (RGBA, cropped to the frame's
bounds; the console prints the origin offset) and `pl00_palettes.png` (16x16,
one row per palette). Checked: f100 (Ryu kicking, 80x96), f200 (standing
guard, 96x99), f108 (crouch, uses H-flip, halves line up), f140 (rolling
ball), f003 (blue fireball trail, palette offset +1 from part flags). The
colours are correct (white gi, red gloves and headband, black belt).

## 3. TIM2 [verified]
Standard Sony TIM2 (see `tim2.py` docstring for the byte layout). Seen so far:
imageType 5 (8bpp) with 256 x 32-bit CLUT in **CSM1** order (clutType 0x03:
swap index bits 3 and 4 when reading the CLUT), and imageType 4 (4bpp) with 16
x 32-bit CLUT (clutType 0x03; 16-entry CSM1 is linear). Alpha 0..0x80 is scaled
×2 (clamped). Pixel data in TIM2 files is linear (not GS-swizzled).
Game parser: `func_003F4C10` / `func_003F4E70` → `func_00418200` (src/s9a_c.c).

Outputs (`private/converted/tex/`):
- `FONT8_8.png` 128x64 8bpp: an 8x8 ASCII debug font, white glyphs with a
  black outline on alpha 0 (2 colours + transparent).
- `000_font.png` (AFS02 0 `font.tm2`) 256x256 8bpp.
- `802_STG00TEX/` 12 textures (128..512, all 8bpp/256), e.g. `001.png` 512x512
  wooden plank wall with riveted metal plates (256 colours, opaque).
- `149_SELTEX/` 79 textures: 23 x 256x256 8bpp (four character portrait
  strips per sheet, e.g. Ryu/Zangief/Guile/Felicia in `000.png`) + 56 x
  256x256 4bpp select-screen sprites (`040.png`: one character in idle pose).
- `150_SELSTG/` 19 stage thumbnails (`003.png` = the carnival clown stage).
Each pack directory has `manifest.txt` (record fields).

## 4. Audio

### 4.1 ADX (AFS00) [verified]
CRI ADX type 3, 18-byte frames, 4-bit, stereo, 48000 Hz, highpass 500 Hz,
header version 3. The data starts at `copyrightOffset + 4` (`"(c)CRI"` sits
just before it). The loop block is at 0x18 (v3): `u32 loopFlag (1), u32
startSample, u32 startByte, u32 endSample, u32 endByte`. 18 of the 23 tracks
loop. Entries 12, 13, 14, 17 and 18 have no loop (flag 0, short
copyrightOffset 0x1C): jingles, results and similar.
Decode: `s = nib*scale + ((c1*h1 + c2*h2) >> 12)`, c1/c2 from the highpass
(see `adx.py`), with `scale` taken as the raw 16-bit word.
Output: `afs00_17.wav` (2.57 s, no loop) and `afs00_15.wav` (8.36 s; `smpl`
loop 18368..400388). Sanity: lag-1 autocorrelation 0.96–0.97, L/R correlation
0.66 / 0.86, no clipping in 17, 2 clipped samples in 15. The values across the
loop seam are continuous (end ≈ 239, start ≈ 426). A wrong predictor would show
noise-like autocorrelation and heavy clipping. **Not listened to.**

### 4.2 Sony HD/BD banks (AFS01) [verified structure; decoded PCM looks sane]
Entry header: up to 8 `{u32 off, u32 size}` pairs. In use: [0] HD, [1] BD,
[2] and [3] small blocks (bank 59: 0x7A8 and 0x510; bank 0: 0x430 and 0x2C0).
These are not decoded; they are probably the TSD sequence or sound-ID map
[inferred].
HD = Sony `IECS` chunks: `Vers`, `Head` (+0x0C hdSize, +0x10 bdSize, +0x14
progOfs, +0x18 ssetOfs, +0x1C smplOfs, +0x20 vagiOfs, the rest 0xFFFFFFFF),
then `Vagi` / `Smpl` / `Sset` / `Prog`. Each holds `u32 size, u32 maxIndex,
u32 ofs[maxIndex+1]` relative to the chunk. `Vagi` entry: `u32 bdOffset,
u16 rate, u8 loop, u8 0xFF`. `Smpl` entries are 0x2A bytes; their fields
(VAG index, note, tune, ADSR, pan) are not decoded yet.
BD = SPU2 ADPCM (see `hdbd.py`). Each sample starts with a 16-byte zero block
and ends on a block with flag bit 0. Bit 1 together with the end flag means
the sample loops, and bit 2 marks the loop start.
- Bank 59 (common SE): 62 VAGs, 78 Smpl, 78 Sset, 81 Prog. The rates are a
  mix (8000, 11025, 16000, 24000, 11032/11049). vag059/060 loop, and their
  Vagi loop byte agrees with the ADPCM flags.
- Bank 0 (Ryu): 23 VAGs at 24 kHz, 0.08–1.0 s (hits and voice).
Sanity: no clipping, plausible RMS. Short SFX are noise-like (lag-1 0.5–0.9).
**Not listened to.**

## 5. Not decoded yet / open questions
- **PLxx_WIN.BIN and NOWLOAD0-3.BIN** use a third compression. It is neither
  LZ16 nor `func_00413A80`. `PL00_WIN` starts `41 04 'TIM2' 04 00 01 00 00 00
  00 01 18 30 04 01 00 00 04 07 10 01 00 30 00 00 01 00 01 03 05 ...`: mostly
  literals with 2-byte tokens (`01 18` stands for 5 zero bytes, `07 10` for 4).
  `NOWLOAD0` starts `84 02` and then a literal ResourceRecord
  (`00 01 00 01 20 00 01 00 20 00 00 00`). The flag encoding is still unknown,
  and so is the decoder function, which has to be found from the loader of
  file IDs 153+ / 878+.
- `VS4.BIN`, `KEYBOARD.BIN`, `ERR_MES.BIN`, `SELVMJ/U`: not identified
  (`VS4` starts with `21 10 8E 28 4D FF FF ...`, which is not LZ16).
- Sprite bank: header words +0x00/+0x08/+0x10/+0x18/+0x1C are zero on disc.
  They may be runtime pointers or counts. Palettes 16..47 (beyond the 16 the
  slot uploads) are probably alternate colour sets that `func_00174BC0` or
  the colour select copies in [inferred].
- PAK sections 2..14 (animation, collision, etc.) are not decoded.
- The third cache path of `func_00412260` (tiles with area > 0x400, i.e. 64x32
  and 64x64) was not read in detail. Its decode and placement are assumed to
  match the first two paths, and the 64x64-heavy Ryu frames render correctly.
- ADX `scale`: some decoders use `scale + 1`. The difference is inaudible and
  needs checking against `func_004xxxxx` (ADX decoder in the CRI block) if
  bit-exactness matters.
- HD `Smpl`/`Sset`/`Prog` field layout, and the BD-side blocks [2]/[3] (likely
  the TSD sound-ID → program map) are needed for the software mixer.
- POL meshes are untouched (see RENDER_PATH §7).
