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
| `mesh.py` | POL mesh packs (§6): structure dump, OBJ + MTL + texture PNGs, and an independent software render with the battle camera |
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
python3 mesh.py $ISO $OUT/mesh 0 --info # STG00POL structure
python3 mesh.py $ISO $OUT/mesh 0 --roots 0 --render   # OBJ/MTL/PNG + stg00pol_ref.png
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
- POL meshes: decoded, see §6. Open: chunk type `0x3DF00` (`func_003F3190`, no C
  yet) and the `0x2000` sub-chunk never occur in the 17 stages; the type-0x40000001
  node records carry more fields after +0x46 (filled with 0xCC) that nothing reads.

## 6. POL mesh packs (`STGxxPOL`, `DMxxPOL`, `DCxxPOL`, `EFKYPOL`) [verified]

Loaded by `func_0016F430` (stages: `func_00170170` case 1 → AFS02 `801 + 2s` /
`802 + 2s`, i.e. `D_00446860[s]` / `D_00446810[s]`) or `func_0016F530` (menus,
effects). The file is used in place; `func_0016F4D0` only relocates the first
three words. Checked on all 17 stages: every chunk walks to its declared size,
every strip index is in range, and the textures line up with the TEX pack.

### 6.1 Header and containers
```
u32 off[3];   // + file base (func_0016F4D0)
  off[0] -> model container     (func_003F1F10 masks: 1 meshes, 2 materials, 4 texture table)
  off[1] -> node container      (chunk type 0 = root list, other chunks = nodes)
  off[2] -> u32 drawFlags[nMeshes]   (read by func_00415590 -> func_00415A00, and at draw time)
container / chunk header: { u32 type_or_mask, u32 count, u32 size }  // size includes the 12 bytes
```
A container lists `count` chunks back to back (`func_003F1F10` matches the mask,
`func_003F1F90` matches an exact type). `func_003F13A0`: when the node container's
mask has bit 31 set, the reported count is `count - 1`.

### 6.2 Mesh chunk (`func_003F19B0`; parsed by `func_003F2EB0` / `func_003F2BF0`)
`type & 0xFF == 2`; `type & 0xFFC3FF00` names the sub-chunks present:
`0xDF00` = strips + materials + per-strip material + positions + normals + UV +
colour (vertex kind 0x35, 36 bytes in the build), `0x9F00` = the same without UV
(kind 0x25). `0x3DF00` goes to `func_003F3190` (not seen on the stage discs).
Sub-chunks, each `{u32 type, u32 count, u32 size}` + data:

| type | data | reader |
|---|---|---|
| 0x100 | `count` strips: `u32 n | flag<<31`, then `n` u32 vertex indices | `func_003F20A0` (n), `func_003F21F0` (flag), `func_003F2350` (index) |
| 0x200 | `count` u32 material indices (into the material table) | `func_003F1E10` / `func_003F1E70` |
| 0x400 | `count` u32 per-strip local material slots | `func_003F2060` |
| 0x800 | `count` x {f32 x, y, z} | `func_003F24D0` |
| 0x1000 | `count` x {f32 nx, ny, nz} | `func_003F2510` |
| 0x4000 | `count` x {f32 u, v} (GS ST, top-left origin) | `func_003F2550` |
| 0x8000 | `count` x {f32 r, g, b, a}, 0..255 | `func_003F2590` |

- Strips are **triangle strips**, `n - 2` triangles each. The strip flag becomes
  0x8000/0x4000 in the build but `func_003EEC30` ignores it (it uses `w & 0x3FFF`),
  and the GS does no culling, so winding does not matter. Each strip is its own
  GS strip: the first two vertices carry ADC (`0x8000` in the position w).
- Per-strip material slots are used only when they differ (`func_003F3700` → flag
  0x400000); otherwise every strip uses slot 0. A strip's material is
  `matlist[slot]`, loaded into render state `0x39 + slot` by `func_00415590`.
- Colour: `func_003F2EB0` packs `fixunssf(a)<<24 | r<<16 | g<<8 | b` without masking;
  `func_003EEC30` unpacks bytes and stores **byte * 0.5** for textured meshes (255 →
  127.5, `ftoi0` → 127) and byte (alpha * 0.5) for untextured ones.
- Values: positions are world units (1 unit ≈ 1 pixel at z = 0 under the battle
  camera); floors are at y = 0, y up, the set extends towards -z.

### 6.3 Material (mask-2 chunk, record + 0xC; `func_003F1C10` → 76-byte slot)
```
f32 c0[4]      +0x00 -> slot+0x24  (multiplies ambient in the lit programs)
f32 diffuse[4] +0x10 -> slot+0x04  (material colour programs: min(128, d*128), alpha d.a*128)
f32 c2[4]      +0x20 -> slot+0x14
f32 power      +0x30 -> slot+0x48 (int)
u32 textured   +0x34
...                    (0xCC fill)
u32 texIndex   +0x100 -> index into the texture table (mask-4 chunk)
```
Texture table chunk: `{u32 id, u32 w, u32 h, ...}`; `id` is the record index in the
matching TEX pack (`func_00415320`: `D_0057ED70[0xC10 + id]` → handle). On STG00 all
12 ids/sizes match STG00TEX records 0..11.

### 6.4 Node trees (`func_003F1730`, `func_003DEAF0`, walked by `func_001538B0`)
Root list: chunk type 0, `count` u32 node indices (16 on STG00, up to 83).
Node record (chunk type 0x40000001, record + 0xC):
```
u16 id; u16; u16; u16;
s32 child;         +0x08  (-1 none)
s32 sibling;       +0x0C
f32 scale[4];      +0x10
f32 rot[4];        +0x20  radians; rotate X, then Y, then Z (func_003F3BE0)
f32 trans[4];      +0x30
u16 mesh;          +0x40  index into the mesh list (0xFFFF none) -> node+0x180
u16 ?;             +0x44  -> node+6
```
Local = scale * Rx * Ry * Rz, translation in row 3 (row vectors, `v' = v * M`).
The draw walk (`func_001538B0`) is not a full hierarchy walk: the first node uses
the object matrix as is, a child uses `local * previous`, and a node without a
child continues at its sibling with `local * object matrix` (it never climbs back).
On the stages all locals are identity. **Root 0 is the static set in world
coordinates**; the other roots are object-local models that per-stage scripts
place and animate (`func_003D0FA0`: `D_00477010[stage]` lists indices into the
handler table `D_00476DB0[stage][]`) - not reproduced by the viewer.

### 6.5 Per-mesh draw flags (`off[2]`)
| bit | effect | where |
|---|---|---|
| 0x1 | vertex colour (state 0x15 = 1); else material colour (0x15 = 2) | `func_00415A00` |
| 0x2 | UV matrix (state 0x61 → format 0x4000, matrix slot 0x1A); scrolled by `o+0xE0/E4` when the object has 0x20000 | `func_00415A00`, `func_001537D0` |
| 0x4 | fog (format 0x8000) when bit 1 is set and `D_004C2B34 & 4` | `func_00415A00` |
| 0x1 + 0x2 | clipping program (format 0x40, plus fog) when `D_004C2B30` | `func_00415A00` |
| 0x100 | blend from bits 16-18 / 19-21 via `D_00444880` / `D_004448A0` (0x2C0106 → 0x32, 0xC0102 → 0x12); without it blend 0x01 (opaque) | `func_001537D0` → `func_00153A40` |
| 0x200 | halves the alpha of state 0x66 while drawing | `func_001538B0` |

Always: state 0x65 = 1 (format 0x20000, global modulate). States 1 and 2 are 0
at stage load, so **stage meshes are unlit**: format 0x2C040 (flags 7) → desc 45,
0x2C002 (flags 6 / 0x2C0106) → desc 41, 0x24002 (0xC0102) → desc 33, 0x20002
(flags 0) → desc 17/18, untextured vertex-colour meshes → desc 16. Across the 17
stages (`mesh.py --info`): desc 45 everywhere (37-156 meshes per stage), 41 on
STG00/02/0B, 33 on STG00 only, 16/18 for the untextured meshes (some are empty).
Descriptors 11/12 and the lit 0 are never used by stage geometry. An untextured mesh
with a clipping/fog format has no descriptor and is not drawn.

### 6.6 Per-stage tables read from `SLUS_204.86`
- Fog `D_00477060[stage]`, 12 bytes `{s32 id, f32 far, u8 pad, r, g, b}`
  (`func_003D1040` → `func_0016D2A0`): id -1 = off; else state 0x11 = far,
  0x10 = far / (((id & 0xF) + 16) * 2^(id >> 4) / 16), 0xF = id<<24 | rgb.
- Far plane: 2 200 000 for stages 1 and 0xA, else 120 000 (`func_00122FE0`).

### 6.7 Output [verified]
`private/converted/mesh/stgNNpol/`: `stgNNpol.obj` (+ vertex colours as `v x y z r g b`),
`.mtl`, `texNNN.png`, `stgNNpol_ref.png` (pure-Python render: battle camera,
near-plane clipping, GS colour maths, no fog, nearest). All 17 stages render to
coherent scenes; STG00 = the airship deck (SELSTG thumbnail 000), STG01/0A = the
desert, STG06/0F = the clock tower, STG0B = the grid stage, STG10 = the river.
