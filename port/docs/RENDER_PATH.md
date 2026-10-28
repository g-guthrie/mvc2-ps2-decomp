# MvC2 PS2 rendering path, and how to replace it

Read `ENGINE_MAP.md` first for conventions ([verified]/[inferred], "C:" file
names, address mapping).

## 0. Summary

- All graphics are built by an **in-house render library**
  (`0x003DB000-0x003F0FFF`, plus helpers at `0x00411C10-0x00421300`). It sits on
  top of Sony libgraph/libdma, and its API looks like the Dreamcast Ninja/Kamui
  API (`SetRenderState(id, value)`, Dreamcast-style src/dst blend factors,
  1-based texture handles carrying a palette in the high 16 bits). Game code
  talks only to this API.
- **One DMA channel is used per frame: VIF1 (ch 1).** Every packet goes into the
  queue `D_0062BBA0`:
  - 2D primitives, GS register writes and texture uploads go as **VIF1 DIRECT
    (PATH2)** GIF packets.
  - 3D meshes go to VU1 microcode (UNPACK + MSCAL, XGKICK = PATH1).

  The GIF queue `D_0062BBD0` is never used. Only the display-environment
  writes at flip go through an immediate GIF DMA (`func_003DBBF0`).
- **Characters are 2D:** 4-bpp tiles, LZ-compressed in the character PAK,
  are decompressed on demand into an LRU cache of 128x128 PSMT4 GS pages, then
  drawn as textured **GS SPRITE** primitives with a 16-colour CLUT.
  The drawer is `func_00412260`, which is **asm, 0x12B0 bytes**.
- **Stages, menus and 3D demos are meshes** (`STGxxPOL/TEX`, `DMxxPOL/TEX`,
  `DCxxPOL/TEX`): triangle strips with per-strip materials. They are drawn by
  `func_003F0500` using one of 49 VU1 programs chosen from the vertex format.
- Framebuffer: 640x224 PSMCT32, double-buffered, NTSC interlaced in FRAME mode,
  Z32. The game's logical coordinate space is **640x480**: Y is halved when the
  packet is built.

**Recommendation:** replace the render library at its *API* (the functions in
§3 and §6), not at the GIF/VIF packet level. Details and trade-offs are in §9.

---

## 1. Display and framebuffer [verified, asm `func_003EC160`, `func_003ECD00`]

| Item | Value | Where |
|---|---|---|
| Mode | `sceGsResetGraph(0, SCE_GS_INTERLACE, SCE_GS_NTSC, SCE_GS_FRAME)` | `func_001002D8` called from `func_003EC160` |
| Draw buffer | 640 x 224, PSMCT32, 2 buffers (`sceGsSetDefDBuff`, `func_001020E0`) | `D_0062BC50` |
| Z | PSMZ32 (`D_0062BC20=0x30`), `D_0062BC30 = 16777000.0f` (Z scale) | init |
| Half-height flag | `D_0062BC00 = 0`, so every 2D Y is multiplied by 0.5 (`func_003E0C40`) | init |
| XY offset | `D_0062BF84/88` (GS XYOFFSET centre), scroll origin `D_0062BF8C/90` | flip, prims |
| Flip | wait for VSINT, select the odd/even DISPFB packet `D_00478B60/70` using CSR.FIELD, write BGCOLOR `D_00478C60` from `D_0062BF80`, DISPLAY regs `D_00478B80..BB0`, swap `D_0062BFD8`, kick the next chain | `func_003ECD00` (asm) |
| Scissor | `func_003E00D0(x,y,w,h,ctx)` writes SCISSOR_1/2 (0x40/0x41), full screen by default from `func_003DF7D0` | src/fb2_b.c |

The game draws in **640x480 space**. Sprites subtract 16 from Y (for example
`func_00153AB0`, `func_0016D4B0`), so the visible area is about 640x448. For
the port, use a 640x480 virtual canvas, drop the 0.5 Y scale (render at full
height), and letterbox or scale to the window.

## 2. Packet heap, DMA queue and frame pipeline [verified]

| Function | File | Role |
|---|---|---|
| `func_003DD160(size, align)` | src/s7b_a.c | Bump allocator in the per-frame packet heap: 0x80000 bytes per buffer, double-buffered by `D_0062BFD8`. On overflow it hangs |
| `func_003DD0D0` | src/wave33.c | Resets the heap at flip (`D_0062BFE4/E0`) |
| `func_003DC2F0(word, queue)` | src/nq26_a.c | Appends a 32-bit **queue word** to the VIF1 ring for the current buffer (interrupts disabled around it) |
| `func_003DC720` | src/fb55_f.c | At flip: starts DMA of the first queued entry of the *built* buffer |
| `func_003DC3C0(ch)` | src/gr22_d.c | DMAC end-of-transfer interrupt handler: pops the next queue word and starts `sceDmaSend` |
| `func_003DC950` / `func_003DC9C0` | src/wave20.c / src/q8_o.c | Wait until the other buffer's chain has drained / force a drain |
| `func_003DECC0(pkt)` | src/rt14_a.c | Copies a template packet (DMA tag + GIF tag + data) into the heap, patches `FLUSHA; DIRECT n`, and queues it as type 3 |
| `func_00421200(tag)` | src/submit_quadword_packet_00421200.c | Same, for an in-place packet built by the batch writer |
| `func_003DBBF0(src, n)` | src/rt21_a.c | **Immediate** GIF (ch 2) A+D send through scratchpad, with busy-wait. Used only for display regs |

Queue word top nibble (`func_003DC3C0` and `func_003DC720`):

| Type | Meaning | Producer |
|---|---|---|
| `0x0xxxxxxx` | DMA chain at addr, sent as is | GS register packets (`func_003E06D0` etc.), microcode upload (`func_003F0500`) |
| `0x1xxxxxxx` | Texture upload chain | `func_003EA660`, `func_00412260` |
| `0x2xxxxxxx` | Pointer to `{chain, src, size, dst}`: first `memcpy(dst, src, size)` (the vertex staging copy, `func_003EF980` to `func_003DCDC0`), then send the chain | `func_003F0500` |
| `0x3xxxxxxx` | DIRECT GIF packet | `func_003DECC0`, `func_00421200` |

Frame N's queue is executed by the DMAC (driven by interrupts) while the CPU
fills frame N+1. Port equivalent: build a display list of draw commands in
memory, then execute it in GL at `func_003ECD00`. Or draw immediately: game
code never reads GPU results, so nothing observable depends on the delay.

VIF codes used: `FLUSHA 0x13000000`, `DIRECT 0x51000000|qwc` (PATH2),
`DIRECTHL 0x50..`, `STCYCL 0x01000404`, `UNPACK V4-32 0x6C..` (`func_003DBB60`),
`MSCAL 0x15000000|addr` (`func_003DBB20`), `MPG`, `BASE/OFFSET` (double
buffering, set by each microcode packet). The DMA tag builders are
`func_003DBA00` (CNT), `func_003DBA30` (NEXT), `func_003DBA90` (REF) and
`func_003DBAF0` (END/raw).

## 3. Render-state API: `func_003DF850(id, value)` (src/xm21_a.c) [verified]

This is the only way game code changes GPU state. A port implements the same
switch.

| id | Meaning | Storage / GS effect |
|---|---|---|
| 1, 2, 0xC, 0x12, 0x15, 0x5C, 0x61, 0x65 | Mode flags (cull/side select etc.) | bits in `D_004C2AD4` (read by the mesh path) [semantics inferred] |
| 4 (5-7) | **Current texture** = `(paletteHandle<<16) \| textureHandle` | `D_004C2AEC`, `D_004C2A98[]` |
| 0xD | Blend modifier bits 0x400/0x800 (0x400 = subtractive variant) | `D_004C2AD0 & 0xC00`, then `func_003E06D0` |
| 0x5D | **Blend factors** (low nibble = src, high nibble = dst, see below) | `D_004C2AD0 & 0xFF`, then GS ALPHA_1 |
| 0xE | Material/diffuse colour ARGB8888 (used by the VU path) | `D_004C2AC0` |
| 0xF | Fog colour ARGB, written to GS FOGCOL (0x3D) | `func_003E0A90` |
| 0x10, 0x11 | Fog float params | `D_004C2ACC`, `D_004C2AC8` |
| 0x14 | Background/clear colour, used by flip BGCOLOR | `D_0062BF80` |
| 0x16 | View matrix (64 bytes) | `D_0061C720` |
| 0x17 | Projection matrix; also builds the derived matrices `D_0061BE20`, `D_0061BE60` | `D_0061C6E0` |
| 0x18 | Viewport/projection params `{4 ints, 2 floats}` | `func_003DD4E0(0x22, ...)` |
| 0x19..0x38 | **32 matrix slots** (0x19 = current model/world matrix, used by every draw) | `D_0061B8A0[id]` (= `0x0061BEE0` for 0x19), dirty mask `D_004C2AA0` |
| 0x39..0x58 | **32 material slots**, 76 bytes each (texture handle at +0x44) | `D_0061A334[id]` = `0x0061B420 + 76*n` |
| 0x59..0x5B | **3 directional lights**, 100 bytes each (direction, colour, ambient) | `0x0061B2F0 + 100*n` |
| 0x5F | ? | `D_004C2AB8` |
| 0x62 | Texture filter: `0x10000` = nearest, otherwise bilinear (TEX1_1 MMAG/MMIN) | `func_003E0B50` |
| 0x63 | Texture wrap: `0x20000` = REGION_CLAMP to the texture size, else repeat | `D_004C2AD0 & 0x60000`, applied in `func_003E0DB0` |
| 0x66 | Global colour modulate (alpha halved for some materials) | `D_004C2ABC` |
| 0x6B | Z write enable (0 means ZMSK=1), GS ZBUF_1 | `func_003E0530` |
| 0x6C | Z test: 0 = never, 1 = GEQUAL, 3 = GREATER, 7 = ALWAYS; alpha test is always "alpha != 0" | GS TEST_1 (`D_004779D0..E8`), `func_003E0390` |

Default state (`func_003DF7D0`, src/wave33b.c): `D_004C2AD4=0x102`,
`D_004C2AD0=0x38B032` (blend 0x32, Z GEQUAL), full-screen scissor. Per frame,
`func_00170D30` sets blend 0x32 and filter nearest.

### 3.1 Blend encoding (`func_003E06D0`, src/fb2_c.c) [verified]

`value = src | dst`. Each factor is: `0` = ZERO, `1` = ONE, `2` = SRC_ALPHA,
`3` = INV_SRC_ALPHA, `4` = DST_ALPHA, `5` = INV_DST_ALPHA. Src uses the low
nibble and dst uses the high nibble. These are Dreamcast PVR blend factors,
and they map **directly onto `glBlendFunc`**. The GS ALPHA register cannot do
every combination: the code silently ignores the ones it cannot do, and the
port should do the same for fidelity.

| src\|dst | GS ALPHA (A,B,C,D,FIX) | GL |
|---|---|---|
| 0x32 | (Cs-Cd)*As+Cd | `SRC_ALPHA, ONE_MINUS_SRC_ALPHA` (default) |
| 0x12 | Cs*As+Cd | `SRC_ALPHA, ONE` (additive) |
| 0x01 / 0x0A8 | Cs (FIX 0x80) | `ONE, ZERO` |
| 0x11 | Cs+Cd (FIX) | `ONE, ONE` |
| 0x21 | Cs+Cd*As | `ONE, SRC_ALPHA` |
| 0x31 | Cs-Cd*As | reverse-subtract variant (GL `FUNC_REVERSE_SUBTRACT`) |
| 0x11 with 0x400 | Cs-Cd | subtract |
| 0x00..0x50 with src 0 | Cd, Cd*As, Cd*(1-As)... | `ZERO, x` |
| 0x23 | (Cd-Cs)*As+Cs | `ONE_MINUS_SRC_ALPHA, SRC_ALPHA` |

Alpha range: the GS treats alpha 0x80 as 1.0. Colours are converted from
8-bit ARGB by `func_003E0CB0` (`0xFF` becomes `0x80`, otherwise `x>>1`). In
GL, use normalised 0..1 directly (`a/255`). For textured prims the GS
MODULATE mode is `out = tex * vertex * 2`, so vertex colour 0x80 is identity.
The port's shader is `tex * vcolor` with vcolor in 0..1 (255 = identity),
plus TEXA rules for 16-bit textures.

## 4. Textures, palettes and GS VRAM [verified]

**Tables** (the game holds handles, the library maps them to GS VRAM):
- `D_006207A0[]`: texture records, 64 bytes, 1-based handle in the low 16 bits.
  Fields: `+0x00` owner/cache id, `+0x04` format code, `+0x08` byte size,
  `+0x0C` fmt idx, `+0x10` VRAM block size, `+0x12` **TBP0**, `+0x14/16` **TW/TH
  log2**, `+0x18/1A` **width/height**, `+0x1C` **GS PSM**, `+0x20` swizzle flag,
  `+0x24/26` alternate w/h, `+0x28` handle of the pixel data in main RAM,
  `+0x2C` used flag.
- `D_0061C7A0[]`: palette records (same layout, `+0x12` CBP, `+0x1C` CPSM),
  handle in the high 16 bits.

**Creation** (`func_00415250` dispatches resource records by type):
- `func_00418200(tim2, 4)` (src/s9a_c.c): **TIM2 file to texture (+ palette)**.
  `func_003F4C10` parses the picture header (TIM2: `+0x10` pictFormat, `+0x11`
  mipmaps, `+0x12` clutType, `+0x13` imageType, `+0x14/16` w/h; image type
  1 = 16-bit, 2 = 24, 3 = 32, 4 = 4-bit, 5 = 8-bit). `func_003E8C00` fills the
  texture record: format 0 = PSMT4 (0x14), 1 = PSMT8 (0x13), 2 = PSMCT16, 3 = PSMCT24,
  4 = PSMCT32. Sizes must be powers of two from 32 to 1024. The pixel data is
  copied into a pool handle, optionally re-arranged by `func_003EB210`. The CLUT
  goes through `func_003F4E70`, `func_003E9110` and `func_003E9250`.
- `func_00418410`, `func_00418570`, `func_00415B00`: the other resource types
  (palette-only or raw variants, not traced in detail).
- `func_003E8B30(params, owner)` / `func_003E9010`: create a blank texture or
  palette (used by the character cache).

**Upload at draw time** (`func_003EA660(n, handleList)`, src/s9b_a.c):
For each texture and palette in the list, `func_003EBA40` checks whether it is
already resident. If not, `func_003EBE70` / `func_003EBF30` (asm) allocate or
evict GS blocks (LRU list `D_004C2AB4`). `func_003DBD80` (src/fb17_g.c) then
builds a VIF1 DIRECT IMAGE transfer (BITBLTBUF 0x50, TRXPOS 0x51, TRXREG 0x52,
TRXDIR 0x53, then IMAGE GIF tags in chunks of 0x70000 bytes) and queues it as
type 1. One TEXFLUSH packet (`func_003DC120`) follows.

**Binding to a primitive** (`func_003E0DB0(texId, &TEX0, &CLAMP, flags)`, src/sa32_e.c):
- TEX0 = `TBP0 | TBW<<14 | PSM<<20 | TW<<26 | TH<<30 | TCC=1 | TFX=MODULATE`,
  plus `CBP<<37 | CPSM<<51 | CLD=4` when the record has a CLUT.
- CLAMP = 0 (repeat) or REGION_CLAMP to (w-1, h-1) when state 0x63 = 0x20000.

**Port:** keep the handle tables. Turn each texture record into a GL texture:
- PSMT4/PSMT8 become an `R8` index texture plus a palette texture, combined with
  a palette lookup in the shader. Doing the lookup in the shader keeps palette
  swaps cheap (characters change palettes for hit flashes and colour select).
- PSMCT16/24/32 become RGBA8.

Upload on first bind instead of GS VRAM management, so the
`func_003EBE70/3EBF30` allocator disappears. PS2 CLUT entries are 32-bit RGBA
with 0x80 = opaque. 256-colour CLUTs use the GS CSM1 index swizzle (swap bits 3
and 4 of the index): undo it at conversion time if the TIM2 data is stored
swizzled.

## 5. 2D primitive path (PATH2 GIF packets) [verified]

All 2D prims take **pre-transformed screen coordinates** (640x480 space) and go
through a **template packet** in `.data`, filled and copied by `func_003DECC0`:

| Function | File | Template | Primitive | Input layout |
|---|---|---|---|---|
| `func_003DF0C0(v)` | src/fb38_g.c | `D_004778F0` REGLIST `PRIM,TEX0,CLAMP,(RGBAQ,ST,XYZ2)x3`, PRIM=0x5B | **textured gouraud triangle**, alpha-blended, perspective ST (Q = v.w) | `v+0x00/10/20`: xyz,w per vertex (16 B each); `+0x30/34/38`: ARGB; `+0x3C..0x50`: (u,v) x3 normalised |
| `func_003DEE00(v)` | src/fb54_c.c | `D_00477890` `PRIM,(RGBAQ,XYZ2)x3`, PRIM=0x4B | **flat-textureless gouraud triangle** | same, no UV |
| `func_003DF490(v)` | src/fb55_g.c | `D_00477970` `PRIM,TEX0,CLAMP,RGBAQ,ST,XYZ2,ST,XYZ2`, PRIM=0x56 | **textured SPRITE** (axis-aligned rect) | `+0..0x1C`: (x,y,z,w) x2; `+0x20`: ARGB; `+0x24..0x30`: (u,v) x2 |
| `func_003ED1C0` | src/w199_f.c | `D_00478C90` A+D: `TEST, PRIM=6, RGBAQ, XYZ2, XYZ2, TEST` | **untextured fill rect** with the depth test overridden | fade/flash overlays |
| `func_00420BF0(writer, quad)` | src/s9a_d.c | batch writer `D_0058C7A0` (`func_00420980/A50/AB0/B30/BA0`, `func_00421270`): one big REGLIST packet `0x521521D21D21` | **textured quads** (strip of 4: XYZ2,XYZ2,XYZ3,XYZ3 kicks) | font/text quads from `func_0016D4B0` |

Coordinate transform in all of them: `X = (x - D_0062BF8C + XYOFF) * 16`,
`Y = ((y - D_0062BF90) * 0.5 + XYOFF) * 16`, `Z = -(z - 1) * 0.5 * D_0062BC30`
(z in [-1,1] maps to 32-bit Z, where larger Z is nearer). Colour goes through
`func_003E0CB0`.

Game-side users:
- Text: `func_0016D4B0` (src/chA_a.c). Glyph metrics are at `D_004B4F40`, and
  the font is a 16x16 cell grid in `font.tm2`.
- Generic sprites and portraits: `func_00153AB0` / `func_00153D20` (src/s8c_a.c),
  which bind `func_003EA660`, set state 4 and draw `func_003DF490`.
- Fades: `func_00152660`, `func_001527F0`, `func_001529A0`.
- HUD/effects: `func_00417AE0`, `func_00421FB0`, `func_0016DA30`.

**Port:** implement these entry points as GL batch appends (one dynamic VBO,
one textured shader). They are leaf functions with flat, documented inputs.

## 6. Character sprite renderer [verified skeleton, details inferred]

Data comes from `PLxxPAK.BIN` (character ID `xx` = 0x00..0x3A). It is loaded
into `p+0x53C`, and `func_0016F1B0` (src/resource_section_bind_0016f1b0.c)
binds 15 sections from the PAK header (u32 offsets at `+0x00..+0x38`, made
absolute). Section 0 (`p+0x16C`) is the **sprite bank**. It is registered as
one of 16 slots `D_00632480[idx*20]` through `func_00413D50`, which calls
`func_00411C10`.

`func_00411C10(bank, 1)` (src/xl14_a.c) sets up the per-slot cache. For slot
`s` (`D_00632610[s]`, 16 bytes):
- `b` = handle to 0x740 bytes of "SSCACHE" tile-to-page LRU state (zeroed);
- `c` = 26 (0x1A) blank textures, 128x128 **PSMT4**;
- `d` = 16 CLUTs (16 colours, 32-bit), converted from **ARGB1555** palettes at
  `bank + *(u32*)(bank+0x14)` (16 palettes x 16 colours x 2 bytes).
  Conversion: `A = bit15 ? 0x80 : 0`, `R5 G5 B5` scaled by `<<3`.

Sprite bank layout (as read by `func_00412260`):
- `+0x04`: offset to the **tile table**: u32 offsets (from the bank) to tile records.
- `+0x0C`: offset to the **frame table**: u32 offsets to frame records.
- `+0x14`: offset to the palettes (above).

Frame record: `s16 nParts`, then `nParts` entries of 8 bytes:
`s16 dx, s16 dy, s16 flags (0x8000 = H-flip, 0x4000 = V-flip), s16 tileIndex`.

Tile record: `u8 ?, u8 ?, u8 w/8, u8 h/8`, then compressed 4-bpp pixels.
Bytes 0 and 1 (in 8-pixel units) are used for the flipped origin.

Pixel compression (`func_00413A80`, src/p3r.c) is a small LZ: a flag byte,
then 8 items MSB-first. Bit 0 copies a literal byte. Bit 1 reads byte `b` and
copies `(b & 0xF) + 2` bytes from `dst - ((b >> 4) + 1)`.

Draw call chain:
```
func_00152D20 / func_00152FB0  (src/fb34_b.c / src/fb39_b.c: sprite-object draw for actor kinds 1..4)
  func_00417980                 world-to-screen projection (640x480)
  func_00174F60(obj)            (src/e080_b.c) builds the matrix in slot 0x19 from the object:
                                position obj+0xF0/F4/F8, scale obj+0xFC/100, rotation obj+0x114,
                                facing obj+0x120 (flip by pi around Y), alpha obj+0x118,
                                palette obj+0x13E, sprite id obj+0x154 (0x8000 = alt mode)
    func_00413DF0(slotObj, frameId, palette, 0xAAFFFFFF)   (src/prepare_runtime_request_00413DF0.c)
      func_003DE640(m, 0)        copies the current matrix (slot 0x19)
      func_00412260(slot, frameId, m, rgba, palette, 0)    ASM, 0x12B0 bytes
```

`func_00412260`:
1. Copies the slot's 0x740-byte cache state into the work buffer `D_004C250C`.
2. Builds a SPRITE REGLIST template at `D_00632550`:
   `0x70000007` DMA, GIF `NREG=8 PRIM,TEX0,CLAMP,RGBAQ,ST,XYZ2,ST,XYZ2`,
   PRIM=0x54/0x56, RGBA = `(c+1)>>1` per channel. Depth comes from matrix `m[14]`.
3. For each part of `frame[frameId]`:
   - computes the part rectangle from `dx/dy`, tile `w*8 x h*8`, the H/V flip and
     the matrix scale;
   - looks the tile up in the LRU cache (`func_00413B20(cache, 0x100, tileKey)`,
     age 0x18 frames);
   - on a miss, **decompresses** it (`func_00413A80`) into staging
     `D_004C2514`, uploads it into its cell of one of the 26 PSMT4 pages
     (`func_003DBD80` plus TEXFLUSH; cell placement uses the tables
     `D_004BECD0`/`D_00496850`), and queues it as type 1;
   - writes TEX0 for page + CLUT (`func_00413510`, palette = `slot.d[palette]`)
     and the two sprite corners;
   - submits with `func_003DECC0`. Large tiles take a second, near-identical
     path (the code is duplicated for `area > 0x100`).

**Port:** re-implement `func_00412260` natively. This is the main reason to
intercept above the packet level:
- At asset conversion time (or lazily on first use), decode every tile of a
  bank into a per-character **8-bit index atlas** (4-bpp values 0..15) with UV
  rectangles. MvC2 banks are small enough, and the cache logic is no longer
  needed.
- Upload the 16 palettes as a 16x16 RGBA texture row set. Palette animation
  (`func_00174BC0` and the per-frame palette buffers `D_004F54D0`) only rewrites
  the palette texture.
- Draw each part as a quad: `pos = M * (dx, dy)`, flips, colour/alpha
  multiplier, `index -> palette[pal][idx]`, alpha test idx != 0 (the PS2 CLUT
  index 0 is transparent, A=0), blend from state 0x5D.

This gives pixel-identical sprites with point sampling at native or integer
scale, and makes filtering/upscaling options trivial.

## 7. 3D mesh path (VU1) [verified pipeline; per-program semantics inferred]

Source data: `xxxPOL.BIN` resource packs, built by `func_00415590` (asm,
0x46C), which calls `func_003EE6F0` and `func_003EE8C0` to create mesh objects
in `D_005BF2F0[]`. Stage textures come from `xxxTEX.BIN` (TIM2 records, §4).
The loader chain is `func_00170170` (stage select switch), then
`func_0016F430`/`func_0016F530`, then `func_00415020` (resource records),
`func_00415320` and `func_00415590`.

Draw: game objects (kinds 6, 13, ...) call `func_00152180` (src/fb18_d.c),
which calls `func_001538B0(obj, nodeTree, matrix)` (src/sa34_e.c). That
function walks a Ninja-style node hierarchy (child `+0x10`, sibling `+0x0C`,
local matrix `+0x54`), sets state 0x19 (model matrix) and calls
**`func_003F0500(meshHandle)`** (src/fb47_g.c) for each node.

`func_003F0500`:
1. On the first draw, or when the mode flags `D_004C2AD4` change, it rebuilds the
   VU packet:
   - `func_003EE930` reads the mesh header (0x24 bytes);
   - `func_003EE8C0` calls `func_003E0F60` (src/fb69_d.c) to **pick one of 49
     microcode descriptors** from (format word `wC`, key `w4|w8`);
   - `func_003EE9A0`/`func_003EEC30` (src/rb81_c.c, src/nq243_a.c) split the
     strips into VU1 batches;
   - `func_003EF9A0` converts per-material data;
   - `func_003F01B0` maps material slots to TEX0/CLAMP.
2. Uploads textures (`func_003EA660`).
3. Calls the descriptor's **setup callback**, which writes the VU1 constant block:
   - model-view-projection and screen matrices (`D_0061BEE0` x `D_0061BE20` /
     `D_0061BDE0`);
   - material colour (state 0xE) x scale (128 or 255);
   - 3 light directions transformed into model space and normalised on the CPU;
   - light colours, ambient sum, fog params, GIF tag template;
   - MSCAL.
4. If the program differs from the one resident on VU1, DMAs the microcode
   packet (`desc+0x00`, a `dmatag end` + `MPG`).
5. Queues `{chain, vertexSrc, size, staging}` as type 2.

Mesh format (strip list, from `func_003EE9A0`): u16 `count & 0x3FFF` per strip
(triangle strip, so `count-2` triangles). Flag `0x400000` adds a u16 material
index per strip, `0x100000` adds 2 u16 words, `0x1000` adds per-vertex u16s.
Vertex attributes are qwords. The descriptor's `idx_478E10` points to
`D_00478E10[i] = {bytesPerVertex, attrMask}`: `{0x30,0xB} {0x40,0xF} {0x20,0x3}
{0x30,0x7} {0x20,0x9} {0x30,0xD} {0x10,0x1} {0x20,0x5} {0x50,0x3B} {0x60,0x3F}`.
attrMask bit0 = position, bit1 = normal, bit2 = colour, bit3 = UV, bit4/5 =
extra (second set/weights) [inferred].

### 7.1 Format to descriptor selection (`func_003E0F60`) and VU1 programs

Key `w4|w8`: `0x21035`/`0x421035` = textured, `0x21025`/`0x421025` = untextured
(colour scale 255 instead of 128), `0x121235`/`0x521235` = a third vertex type
with 2 extra attributes.

Format low bits [inferred from which constants each setup uploads]:
- `0x100`: has normals (lit by the 3 directional lights + ambient).
- `0x002`: no per-vertex colour (material colour only).
- `0x004`: specular/extra light terms.
- `0x20000`: global colour modulate (state 0x66).
- `0x8000`: fog (uses states 0x10/0x11).
- `0x4000`: extra vector from matrix slot 0x1A (env/UV transform).
- `0x40`: **full clipping** program (large polygons crossing the near plane).
- Top byte `0x01`/`0x06`: special types.

All programs share one structure (disassembly in `src/vu/*.vsm`, analysed with
a scripted op histogram):
- per vertex `MULAx/MADDAy/MADDAz/MADDw` (4x4 transform);
- `DIV`/`Q`, which divides by w;
- `CLIPw` plus `FCAND` for trivial-reject/ADC flagging (or a real clipper with
  `FCOR` and 5x `CLIPw`);
- `FTOI4` for screen XY/Z, `FTOI0` for colour, `MINII` to clamp colour to 128/255;
- `XGKICK` to the GS (PATH1), double-buffered through BASE/OFFSET.

Lighting is a dot product of N with the three model-space light vectors, plus
ambient, times material and vertex colour. The 0x106 programs add `RSQRT`
(per-vertex normalisation, specular).

| desc | VU1 packet | setup fn | fmt (low) / key | lit | vtx attrs | notes |
|---|---|---|---|---|---|---|
| 0 | 0x004250C0 | 003E1B20 | 0x102 / tex | Y | pos,nrm,uv | basic lit textured |
| 1 | 0x00425470 | 003E1FD0 | 0x102 / 0x121235 | Y | +2 extra | 19 MULAx, multi-matrix |
| 2 | 0x004259F0 | 003E1B20 | 0x102 / untex | Y | pos,nrm | colour x255 |
| 3,4 | 0x00425D60, 0x00426580 | 003E5090 | 0x20102 | Y | | + global modulate |
| 5 | 0x00427760 | 003E2B70 | 0x106 / tex | Y + spec | | RSQRT x5 |
| 6 | 0x00428510 | 003E24B0 | 0x106 / 0x121235 | Y + spec | | |
| 7,8 | 0x00428E60, 0x004291D0 | 003E1B20 | 0x100 | Y | +vertex colour | |
| 9,10 | 0x00429510, 0x0042A460 | 003E5090 | 0x20100 | Y | | |
| 11,12 | 0x0042B210, 0x0042B4D0 | 003E31D0 | 0x000 | N | pos,col,uv | **unlit prelit** (most stage geometry) |
| 13,14 | 0x0042B780, 0x0042BA90 | 003E31D0 | 0x002 | N | pos,uv | unlit, material colour |
| 15-18 | 0x0042BD80..0x0042C630 | 003E5680 | 0x20000/0x20002 | N | | + modulate |
| 19 | 0x0042C950 | 003E7FD0 | 0x142 | Y | | **clipping** |
| 20,22 | 0x0042DAF0, 0x0042E290 | 003E33F0 | 0x8102/0x8100 | Y | | + fog |
| 21,25 | 0x0042DEB0, 0x0042ED10 | 003E59E0 | 0x28102/0x28100 | Y | | fog + modulate |
| 23,24 | 0x0042E660, 0x0042E990 | 003E38D0 | 0x8000/0x8002 | N | | fog |
| 26,27 | 0x0042F0D0, 0x0042F410 | 003E5FF0 | 0x28000/0x28002 | N | | |
| 28,30 | 0x0042F7C0, 0x0042FF40 | 003E3B20 | 0x4102/0x4100 | Y | | + slot 0x1A vector |
| 29,31 | 0x0042FB60, 0x004302C0 | 003E6370 | 0x24102/0x24100 | Y | | |
| 32,34 | 0x00430640, 0x00430CC0 | 003E4050 | 0x4002/0x4000 | N | | |
| 33,35 | 0x00430970, 0x00430FA0 | 003E69D0 | 0x24002/0x24000 | N | | |
| 36,38 | 0x00431290, 0x00431A80 | 003E42F0 | 0xC102/0xC100 | Y | | fog + 0x1A |
| 37,39 | 0x00431670, 0x00431E60 | 003E6DA0 | 0x2C102/0x2C100 | Y | | |
| 40,42 | 0x00432230, 0x004329B0 | 003E4850 | 0xC002/0xC000 | N | | |
| 41,43 | 0x004325D0, 0x00434410 | 003E7430 | 0x2C002/0x2C000 | N | | |
| 44 | 0x00434770 | 003E7830 | 0x28040 | N | | clipping |
| 45 | 0x00435850 | 003E7BC0 | 0x2C040 | N | | clipping |
| 46 | 0x004369A0 | 003E8490 | 0x2C140 | Y | | clipping |
| 47 | 0x00437C90 | 003E4B20 | type 0x01 / untex | N | | special (loi 0.5/1.0) |
| 48 | 0x00424200 | 003E4D50 | type 0x06 / 0x121235 | Y | | largest; RSQRT, 3 DIV |

Six packets are not in the descriptor table (`0x00426100`, `0x00426950`,
`0x004298D0`, `0x0042A7C0`, `0x00432D00`, `0x00433980`). They use
`.resume_mpg`/split uploads, are probably second halves or alternates, and
need tracing. The whole table is `src/data/data_mcdesc_004779F0.c`.

**Port:** do not emulate VU1. Instead:
- At load time, convert each mesh's strips into a GL VBO/IBO (positions,
  normals, colours, UVs) plus per-strip material IDs.
- Write **one uber-shader** with feature flags taken from the format word:
  lit (3 directional + ambient), vertex colour vs material colour, colour scale
  128/255, fog (linear, states 0x10/0x11/0xF), global modulate (0x66), and
  matrix slot 0x1A extras.
- Let GL do clipping, which also replaces the clip variants.

The setup callbacks (all C) give the exact uniform math: port each one as a
"fill uniforms" function.

## 8. Data structures a port renderer consumes

| Structure | Location | Notes |
|---|---|---|
| Render state | `func_003DF850` ids (§3) | Reproduce exactly |
| Matrix slots 0x19..0x38, view 0x16, projection 0x17/0x18 | `0x0061B8A0 + 64*id`, `D_0061C720`, `D_0061C6E0` | Row-major 4x4 floats (VU0 layout); math helpers `func_003DD260` (identity), `func_003DE160` (mul), `func_003DDAD0/DB20/DC30/DD00` (translate/scale/rotate) |
| Lights x3 | `0x0061B2F0 + 100*i` | dir `+0x34..`, colours `+0x04..`, ambient `+0x24..` [offsets inferred from the setup code] |
| Materials x32 | `0x0061B420 + 76*i` | `+0x44` texture handle |
| Texture/palette records | `D_006207A0`, `D_0061C7A0` (64 B) | §4 |
| Resource handle table | `D_0057FB70[4096]` with slot base `D_0057ED70[]`, tags `D_0057E570[256]` | game code looks textures up here (e.g. `func_00153AB0`) |
| Character slots | `D_00632480[16]` (20 B), caches `D_00632610[16]` | §6 |
| Mesh objects | `D_005BF2F0[]` | §7 |
| 2D vertex structs | §5 table | |
| Text records | `D_0058CC40[0x80]` (x, y, attr, string) | debug and menu text |

## 9. Where to intercept: recommendation

**Option A: translate GIF/VIF packets** (run the library as is and write a
GS/VU1 interpreter that consumes the type 0-3 queue words).
- Pros: nearly zero changes to library C; exact GS semantics (alpha
  test/ALPHA/TEX0/CLAMP, CLUT swizzle).
- Cons: you are building a GS emulator, plus a **VU1 interpreter for 55
  programs**. The VU1 path cannot be avoided because PATH1 output only exists
  after the microcode runs. Other costs:
  - The character path still requires PS2 VRAM layout emulation (PSMT4 page
    swizzle, CLUT CSM1 layout, local-memory addressing).
  - Fixed 640x224 with Y/2 makes resolution increases messy.
  - Packet heap and DMA chain emulation are needed.
  - It is close to "emulation", which the project goal rules out.

**Option B: replace the render library at its API (recommended).**
Re-implement about 40 entry points in `port/render/`. Keep every game-side
call unchanged.

| Group | Functions to re-implement |
|---|---|
| State | `func_003DF850`, `func_003DF7D0`, `func_00170D30`/`func_00170D70` (begin/end), `func_003E00D0` (scissor), `func_003E00B0` (clear colour) |
| Frame | `func_003EC160` (init: window/GL context), `func_003ECD00` (present), `func_003DD160` (keep as a plain arena for game-built packets, or remove), `func_003DC2F0` (becomes a no-op or a GL command list) |
| Textures | `func_00418200`, `func_00418410`, `func_00418570`, `func_00415B00`, `func_003E8B30`, `func_003E9010`, `func_003E8C00`/`func_003E9110`/`func_003E8DF0`/`func_003E9250`, `func_003EA660` (to "ensure GL texture"), `func_003E9580`/`func_003E95E0`/`func_003EA070`/`func_003EA0D0` (lock/unlock pixels for CPU edits) |
| 2D | `func_003DF0C0`, `func_003DEE00`, `func_003DF490`, `func_003ED1C0`, `func_00420980..func_00421270` (batch writer) and `func_00420BF0` |
| Characters | `func_00411C10`, `func_004120A0`, `func_00412260` (native atlas drawer), `func_00413D50`/`func_00413DA0` |
| Meshes | `func_00415590` (build GL meshes), `func_003F0500` (draw with the uber-shader), `func_003EE6F0` (mesh create) |
| Matrix/VU0 math | `func_003DD260`, `func_003DE160`, `func_003DE680`, `func_003DE480` etc. (already C: just compile them, removing VU0 inline asm where present) |

Pros:
- No GS or VU emulation. The interface is small and was designed as a portable
  API: it mirrors Dreamcast Ninja, so states and blend factors map 1:1 to GL.
- Resolution independence (640x480 virtual space, scale freely).
- Characters become a clean atlas renderer.
- WebGL2/GLES3 friendly: one 2D shader, one palette shader, one mesh uber-shader.

Cons:
- Some semantics must be matched by hand: the GS MODULATE x2 colour scale,
  alpha test `a != 0`, inverted Z (GEQUAL/GREATER with z in [-1,1]), REGION_CLAMP,
  and point vs bilinear sampling.
- Two important functions are asm-only today (`func_00412260` character draw,
  `func_00415590` mesh build) and must be hand-translated. Their algorithms are
  bounded and described above.
- The VU1 lighting equations must be read from each `.vsm` program to match
  exactly (start with descs 11/12, which are unlit, and 0, which is lit).

Fallback for verification: keep a debug build that also writes the original
GIF packets to a file and diffs prim counts and coordinates against an
emulator capture.
