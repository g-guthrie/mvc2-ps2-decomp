# MvC2 PS2: file and asset loading, archive inventory, audio

Conventions are the same as in `ENGINE_MAP.md`. The inventory below was made
from the user's disc (`private/disc/mvc2.iso`) with
`port/tools/afs_inventory.py`. That script and `port/tools/mvc2_lz16.py`
contain no asset bytes, and nothing was extracted into git-tracked paths.

## 1. Disc layout

| Path | Size | Use |
|---|---|---|
| `/SYSTEM.CNF` | 54 | `BOOT2 = cdrom0:\SLUS_204.86;1`, NTSC |
| `/SLUS_204.86` | 3,942,320 | Main ELF (identical to `private/extracted`) |
| `/PS2/0FLIST.DIR` | 44 | Text list `afs00.afs..afs03.afs`. This is the DVCI file-cache list: the game opens it at boot and caches the LBAs of these 4 files. |
| `/PS2/AFS00.AFS` | 55.5 MB | **23 ADX music streams** |
| `/PS2/AFS01.AFS` | 9.3 MB | **63 Sony HD/BD sound banks** |
| `/PS2/AFS02.AFS` | 137 MB | **983 game data files**, with a name table |
| `/PS2/AFS03.AFS` | 0.6 MB | 1 file: the PS2 memory-card icon (`0x00010000` icon magic, `mvsc2.ico`) |
| `/FONT8_8.TM2` | 9,472 | Loose TIM2 debug font |
| `/MODULES/*.IRX`, `IOPRP255.IMG`, `USBDRV.CNF` | | IOP modules (not needed by the port). `/MODULES/DM12TEX.BIN` is a stray copy of an AFS02 file. |

## 2. Loading stack in the executable

```
game: func_0012DA40(fileId, dst, ptid)        sync load       src/rb24_c.c (placeholder; logic complete)
      func_0012E5E0(ptid|flags, fileId, dst)  async enqueue   src/g11.c   (ring D_004CA6F0[128]; second ring D_004CA210 for queue D_004CAAF0)
      func_0012E640(src, dst, size)           queued memcpy   src/g10b.c  (ring D_004CA610[8])
      func_0012DD90() per frame               loader tick     src/ra34_c.c
        func_0012DE70 / func_0012DF30 (src/rr17_a.c: open/read/poll state machine, 900-frame timeout)
        func_0012E1A0 (src/w21b0_a.c: time-sliced memcpy, budget = 15000 - elapsed T0 ticks)
CRI ADXF (AFS partitions):
      func_003FBE88 ADXF_LoadPartitionNw(ptid, "afs0N.afs", 0, ptinfo)  src/w1_b.c
      func_003FC090 ADXF_GetPtStat (asm)
      func_003FCBC0 = locked ADXF_OpenAfs(ptid, fileId)  src/b10s_0_t.c   (func_003FCB20 = ADXF_OpenAfs)
      func_003FCA60 = locked ADXF_Open(fname, 0)         src/fb13_m.c    (func_003FC9C8 = ADXF_Open)
      func_003FD450 ADXF_GetFsizeSct, func_003FD0F8 ADXF_ReadNw(adxf, nsct, buf),
      func_003FD530 ADXF_GetStat (2 = reading, 3 = done), func_003FCCF0 ADXF_Close
CRI CVFS to DVCI (CD/DVD: sceCdSearchFile + sceCdRead) or HTCI (host:, dev only)
      setup func_00418B80 (src/u2.c), mount func_004189A0 (src/w20b0_o.c)
```

**Partitions** (`D_004A6A60`, `func_004189A0`): ptid 0 = `afs00.afs`,
1 = `afs01.afs`, 2 = `afs02.afs`, 3 = `afs03.afs`. The paths come from
`"%s"`/`"HST:pfs0:%s"` (`D_004BEE18`/`D_004BEE20`, so a dev build can read
from the host). The third word of each table row (0x28, 0x8C, 0x3D7, 0x1)
is a per-partition capacity, not the file count. 0x3D7 = 983 happens to match
AFS02.

**File IDs:** a file is identified by `(ptid, index in that AFS)`. For ptid
0 the queue path can also open by *name* through `D_0043CDA0[index]` and
`ADXF_Open`. That table holds 983 names and matches AFS02's internal name table
1:1. The only difference is entries 981/982: the AFS lists `dm20pol/dm20tex`
twice, while the EXE names them `dm21pol/dm21tex`. The port loader can work in
two ways:
- `load(ptid, index)` reads directly from the AFS (offset/size table at
  `+8`, all entries 2048-aligned);
- for AFS02, `index` is also the name table index, so converted assets can use
  readable file names.

Async request record (`D_004CA6F0`, 8 bytes): `u8 ptid` (bit 7 =
memcpy op), `u8`, `u16 fileId`, `u32 dst`. Destinations are mostly the big
heaps `D_004C28AC/B0/B4/B8/BC` and the table `D_004CA1F0[]` (filled by
`func_0012DC00`).

## 3. AFS format

`"AFS\0"`, then u32 count, then `count x {u32 offset, u32 size}`, then
`{u32 nameTableOffset, u32 nameTableSize}`. The name table has 48 bytes per
entry: 32-byte name, then date and size words. Only AFS02 has one. Data offsets
are 2048-aligned (sector reads).

## 4. Inventory

### AFS00: music (23 x ADX)
All entries start with `80 00 ...` (CRI ADX, `03 12 04 02`: 18-byte frames,
4-bit, 2 channels). Sizes range from 138 KB to 5.8 MB. They are played by
`func_001E3F50(bgm)` (src/x0_d.c) as `ADXT_StartAfs(D_004C2B50, 0, D_004B6A70[bgm])`
(`func_00402C20`). The BGM-to-file table `D_004B6A70` has 48 entries with
values 0..22. Several BGM IDs share a file: for example, IDs 0 and 9 both play
file 0, and IDs 1 and 10 both play file 1. The ADX player is a single stereo
ADXT handle with a 0x301E4-byte work area (`func_00418910`).

### AFS01: sound banks (63 x Sony HD/BD packs)
Each entry has a 0x40-byte header of `{offset, size}` pairs, followed by:
- a Sony `IECS Vers/Head` **HD** (instrument and sample table),
- a **BD** (SPU2 ADPCM "VAG" sample body),
- 1 or 2 further small blocks (sequence/map data, [inferred]).

Index 0..58 is one bank per **character ID** (voices plus move SFX; IDs
0x00..0x3A). Index 59 and 60 (0x3B/0x3C) are the common SE banks, loaded at
boot by `func_001E2050` into bank slots 6 and 7 (`func_001E5870`, asm, which
sends the bank to the IOP). Banks 59 and 60 are 289 KB and 586 KB. Index 61 and 62 are further
common banks (54 KB and 154 KB, not traced). The AFS02 `PLxx_VOI.BIN` entries are 13-byte text
placeholders (`"pl00_voi.bin\n"`), so the real voices live here.

### AFS02: game data (983 files; ID = index = name table index)
| IDs | Name pattern | n | Size | Format (magic) | Loaded by / meaning |
|---|---|---|---|---|---|
| 0 | `font.tm2` | 1 | 66 KB | TIM2 | boot font, `func_0012F4C0` to `func_00418200` |
| 1 | `command.tm2` | 1 | 131 KB | TIM2 | button/command glyphs |
| 2 | `DEBUG.BIN` | 1 | 2 KB | ? | debug |
| 3-61 | `PLxx_FAC.BIN` | 59 | 38-60 KB | offset table + images | character face/portrait pack |
| 62 | `ENDDCTEX.BIN` | 1 | 915 KB | LZ16-compressed TEX pack | ending |
| 63-121 | `PLxx_VOI.BIN` | 59 | 13 B | text stub | unused (voices are in AFS01) |
| 122-123 | `SE_STAF.BIN`, `SE_SYUK.BIN` | 2 | 94-123 KB | `DTPK` | Dreamcast-format sound packs, probably a leftover [inferred] |
| 124-145 | `ADX_*.ADX` | 22 | 24 B | text `"ADX_S000.ADX dummy file"` | unused stubs (music is in AFS00) |
| 146 | `ERR_MES.BIN` | 1 | 3 KB | ? | error message text/image |
| 147 | `KEYBOARD.BIN` | 1 | 24 KB | ? | on-screen/USB keyboard |
| 148 | `VS4.BIN` | 1 | 28 KB | ? | VS screen |
| 149 | `SELTEX.BIN` | 1 | 1.0 MB | LZ16 TEX pack (79 TIM2) | character select graphics |
| 150 | `SELSTG.BIN` | 1 | 233 KB | ? | stage select |
| 151-152 | `SELVMJ/SELVMU.BIN` | 2 | 128 KB | ? | select screen data (J/U) |
| 153-208 | `PLxx_WIN.BIN` | 56 | 15-39 KB | byte-LZ-compressed TIM2 (`41 04 'TIM2'`) [inferred] | win-pose portrait |
| 209-267 | `PLxxPAK.BIN` | 59 | 357 KB-1.27 MB | header of 16 u32 section offsets (first = 0x40) | **character pack**: section 0 = sprite bank (RENDER_PATH §6), the others are bound by `func_0016F1B0` (animation, collision and similar tables) |
| 268-326 | `PLxx_TBL.BIN` | 59 | 11-37 KB | tables | per-character tables |
| 327-385 | `HIT_xx.BIN` | 59 | 1-3.5 KB | | hitboxes |
| 386-444 | `HIT_FMxx.BIN` | 59 | 2 KB | | hitbox frame map |
| 445-503 | `HIT_DTxx.BIN` | 59 | 3.5 KB | | hit data |
| 504-562 | `TAIKIxx.BIN` | 59 | 0.6-2 KB | `0C 00 00 00` offset table | idle/standby ("taiki") data |
| 563-621 | `ATCKxx.BIN` | 59 | 0.6-4 KB | offset table | attack data |
| 622-680 | `WARIxx.BIN` | 59 | 1.4-2.4 KB | offset table | ("wari") |
| 681-739 | `YOKxx.BIN` | 59 | 0.4-3.7 KB | offset table | ("yoko") |
| 740-798 | `LIBxx.BIN`, `LIxxA..F.BIN` | 59 | 0.8-3.5 KB | offset table | per-character library/script variants |
| 799-800 | `EFKYPOL/EFKYTEX.BIN` | 2 | 362 / 187 KB | POL / LZ16 TEX | common effect models and textures |
| 801-834 | `STGxxPOL.BIN` / `STGxxTEX.BIN` (xx = 00..10) | 17+17 | 214-369 KB / 185-598 KB | POL: resource records (`10 00 00 00`); TEX: **LZ16 compressed** | **stages**. `func_00170170` case 1: `D_00446860[stage]` = POL ID (801+2s), `D_00446810[stage]` = TEX ID (802+2s); `func_0016F430` decompresses the TEX pack (`func_00176230`) and builds models |
| 835-898 | `DMxxPOL/TEX.BIN` | 23+23 | | POL / raw TEX pack | 3D menu/demo scenes |
| 859 | `SE_COMN.BIN` | 1 | 931 KB | `DTPK` | (see 122) |
| 860-861 | `DM08CAB/DM08CHR.BIN` | 2 | 0.5 / 1.5 MB | | |
| 878-881 | `NOWLOAD0-3.BIN` | 4 | 36-40 KB | | "Now Loading" graphics |
| 882-885 | `S18/S20/S24/S26RM04.BIN` | 4 | 0.8-1.5 MB | | |
| 886 | `ASK.BIN` | 1 | 584 KB | `"ASK "` | |
| 887 | `ADX_NETW.BIN` | 1 | 3.7 MB | ADX | network-mode music |
| 888 | `PALTEX.BIN` | 1 | 22 B | `"PALT"` stub | |
| 889-892 | `SCE22FT/SCE26FT.BIN`, `SCE*I22/I26.GF` | 4 | 1-3 MB | | |
| 899-912 | `DC2x POL/TEX.BIN` | 7+7 | | POL / TEX | |
| 913-968 | `GALxx.TM2` | 56 | 263 KB | TIM2 | gallery art |
| 969-971 | `COMING.TM2`, `memoryfont.tm2`, `font01.tm2` | 3 | 263 KB | TIM2 | |
| 972 | `stg03.dat` | 1 | 42 KB | | stage 03 extra |
| 973-982 | `dm18..dm21 pol/tex`, `cri_adx.tm2`, `ave_tcp.tm2` | | | | late additions, logos |

`xx` is the character ID (0x00..0x3A, 59 IDs; `WIN` and `GAL` have 56,
so 3 IDs have no win or gallery image).

### AFS03
Index 0 is the 51,544-byte PS2 memory-card icon model. The port does not need it.

## 5. Formats the converter must handle

| Format | Code | Notes |
|---|---|---|
| **TIM2** | `func_003F4C10`/`func_003F4E70`/`func_003F5270`/`func_003F5440`; `func_00418200` | Standard Sony TIM2. Image types 1/2/3/4/5 = 16/24/32/4-bit/8-bit. CLUTs are 16 or 256 entries of 16/24/32 bits, and may be CSM1-swizzled. Alpha 0x80 = opaque. |
| **TEX pack** (`*TEX.BIN`, `SELTEX`) | `func_00415020` + `func_00415250` | Array of 16-byte resource records `{s16 w(>0 = valid), s16 h, u32 attr (high16 = type: 0/1/2/3), u32 dataOffset, u32 ...}`, terminated by a non-positive first field. Offsets are relative and fixed up by `func_0016F4D0`. Type 1 = TIM2 texture. Each record's handle goes into `D_0057FB70` at `slotBase + index`. |
| **LZ16** | `func_00176230` (src/z8_h.c) and `port/tools/mvc2_lz16.py` | 16-bit word LZ: flag word MSB-first; a match token has `cnt = v >> 11` (0 means read the next word), `off = v & 0x7FF` words back; off 0 = zero fill; cnt 0 and off 0 = end. Verified: it decodes STGxxTEX, SELTEX, EFKYTEX and ENDDCTEX into TIM2 packs. |
| **Sprite tile LZ** | `func_00413A80` | Byte LZ: flag byte; a match byte `b` copies `(b & 0xF) + 2` bytes from `dst - ((b >> 4) + 1)`. Used for character tiles. |
| **POL** (meshes) | `func_00415590` (asm) to `func_003EE6F0` | Records starting `10 00 00 00`. Node trees + strip meshes (RENDER_PATH §7). Needs decoding from the asm. |
| **Character PAK** | `func_0016F1B0`, `func_00411C10`, `func_00412260` | RENDER_PATH §6 |
| **HD/BD bank** | TSD/libsd on the IOP | Sony `IECS` HD + VAG body (SPU2 ADPCM) |
| **ADX** | CRI ADXT | Standard CRI ADX: decode with any ADX decoder |

Converter plan: read the ISO, then for each AFS entry write
`<archive>/<id>_<name>` into a private asset directory and apply these
transforms:
- TIM2 to PNG (indexed formats keep their index and palette);
- TEX packs: LZ16-decode, then split into TIM2 records plus a manifest;
- character PAK: decode the sprite bank into an index atlas, 16 palettes and a
  frame table;
- POL: GL-ready mesh files;
- ADX: keep as is (decode at runtime) or convert to OGG;
- HD/BD: decode VAG to PCM and write the program/tone table as JSON.

The game's own loaders still expect the original byte layouts at runtime
(they relocate offsets in place). So the **first port milestone should load
the raw AFS entries unchanged**, using a `ptid/fileId` to host-file mapping,
and convert only what the replaced render and audio layers consume.

## 6. Audio [verified flow; driver internals not traced]

There are two systems:

1. **Music: CRI ADX** (EE decode, IOP output through `CRI_ADXI.IRX` and PS2RNA).
   - Init: `func_00418910` (ADXT_Create(2ch), `func_00402208(adxt, 0x4B)`,
     `func_00402458`), then the partitions are mounted.
   - Play: `func_001E3F50(bgmId)`, which calls `ADXT_Stop` (`func_00401868`),
     `func_004026B0(adxt, 1)` (loop flag) and `ADXT_StartAfs(adxt, 0, D_004B6A70[bgmId])`.
     It is called from 13 places: menus, stage start, win and so on.
   - Volume: `func_001E46E0` (per-frame fade, `ADXT_SetOutVol` = `func_004020D8`).
     Mono/stereo: `func_001E4260` (also `func_00402BC0`).
   - Per-frame: `func_00402498` (ADX server) from `func_0012F460`.
   - Port: decode ADX in-process (the format is public), loop points come from
     the ADX header, and output goes through an SDL audio stream.

2. **Sound effects and voices: Tamsoft Sound Driver** (`TSNDDRV.IRX` on top of
   Sony `LIBSD`/`MODHSYN`/`MODMIDI`). The EE talks to it over SIF RPC IDs
   `0x54534400`/`0x54534401` ("TSD\0", `func_00422DB0`), and the boot message
   is "Connected to TamsoftSoundDriver". Commands are appended to a packet
   (`func_004231D0`, `func_00423240`, `func_004235D0`, `func_00423650`,
   `func_004236C0`, `func_004239D0`, `func_00423AA0`, etc., in 0x423000-0x423E00)
   and flushed each frame.
   - Banks: `func_001E5870(buf, slot)` (asm) uploads an AFS01 HD/BD bank into
     slot 6/7 (common) or a per-character slot.
   - Trigger: `func_001E3320(actor, seId, scale)` calls
     `func_001E5070(channel, sound, gain=128, scale)` (src/sound_queue_001e5070.c).
     That fills a 36-entry request ring `D_004CBE80` (20-byte slots: state,
     channel, sound, gain, scale). The packed request key is
     `(channel<<16)|(sound<<8)|n`. Stop/query goes through `func_00422FB0`,
     volume through `func_004230B0`, and the fade states are handled in
     `func_001E5230`.
   - Global: `func_001E41B0` (master SE volume 0x38), `func_001E41C0`,
     `func_001E46D0`, `func_001E56C0`/`func_004236C0` (mono/stereo).
   - Port: replace the TSD client functions (`func_00422DB0`..`func_00423E30`)
     with a small software mixer. Parse the HD (program/tone to VAG offset,
     pitch, ADSR, pan) and decode the VAG ADPCM from the BD. Map
     `(bank slot, sound id)` to a tone. The exact TSD command semantics
     (priority, voice stealing, which sound IDs are sequences) still need
     tracing through `func_00422740` (src/xl10_a.c) and the command builders.

## 7. Other I/O

- **Pad:** libpad through `func_0012F0B0` (src/input_update_0012f0b0.c). It
  reads 4 device slots and converts them to game button masks
  (`D_004F4480/4494`, 0x2000/0x1000/0x0800/0x0400 = directions). The port maps
  SDL gamepads into the same `DEVICES[]` structure.
- **Memory card:** libmc (`MCMAN`/`MCSERV`), with the icon in AFS03, `mvsc2.ico`
  and `icon_20..22.ico`. Port: files under the user data directory.
- **Clock:** `func_0010FC98` (sceCdReadClock).
- **Network/USB keyboard** (`AVETCP`, `USBKB`, `ADX_NETW`, "BISLPM-65047NET"
  paths) is Japanese-network residue. Stub it out.
