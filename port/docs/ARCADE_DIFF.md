# PS2 vs NAOMI arcade: per-character gameplay data

This note checks the community claims that the PS2 build differs from the arcade
in gameplay data. Those claims are missing animation frames, altered hitboxes,
anti-air assists that lose startup invincibility, a counter glitch, and one
stage's music cutting out. It records where the data lives on each side, the
formats as the code reads them, what actually differs, and a plan for an
optional "arcade accuracy" mode.

- **Compared builds:** PS2 SLUS_204.86 (`private/disc/mvc2.iso`) against the
  NAOMI `mvsc2` set (Export/Korea **Rev A**, `epr-23085a`) from
  `/home/user/mvc2-naomi-decomp/orig/mvsc2.zip`.
- **Tool:** `port/tools/arcade_diff.py`. It contains no asset bytes. It reads
  both images at run time and prints only derived numbers.
- **Extracted copies:** these were placed under `/tmp/arcdiff/` and
  `/tmp/naomi_rom/` only, and nothing was written to git-tracked paths.
- **Tags:** [verified] means read in code on both sides. [inferred] means
  deduced from data or field use.

```
python3 -I port/tools/arcade_diff.py private/disc/mvc2.iso private/disc/filelist.txt \
    /path/to/mvsc2.zip [--chars 00,17,2c,2a,34,06] [--detail] [--summary] [--json out.json]
```

## 1. Where the data lives

### PS2 [verified]
- `PLxxPAK.BIN` (AFS02 id 209+xx) is the only per-character file the game
  loads. `func_0012EF50`/`func_0012EF80` (src/grok_w5_0012.c) queue
  `209 + p[0x540]` into `jtbl_004CA000[slot]`.
- `func_0016F1B0` (src/resource_section_bind_0016f1b0.c) relocates the 15
  section offsets in the header:

  | Section | Player field | Content |
  |---|---|---|
  | 0 | `+0x16C` | sprite bank (RENDER_PATH §6) |
  | 2 | `+0x174` | palettes |
  | 3 | `+0x188` | (0x10000 bytes) |
  | 4 | `+0x18C` | |
  | 5 | `+0x178` | **TBL** |
  | 6 | `+0x17C` | **HIT** |
  | 7 | `+0x180` | **HIT_FM** |
  | 8 | `+0x184` | **HIT_DT** |
  | 9 | `+0x198` | TAIKI |
  | 10 | `+0x19C` | ATCK |
  | 11 | `+0x1A0` | WARI |
  | 12 | `+0x1A4` | YOK |
  | 13 | `+0x1A8` | LIB |
  | 14 | `+0x1AC` | |

- **Sections 5 to 13 are byte-identical to the loose AFS02 files**
  (`PLxx_TBL` 268+xx, `HIT_xx` 327+xx, `HIT_FMxx` 386+xx, `HIT_DTxx` 445+xx,
  `TAIKIxx` 504+xx, `ATCKxx` 563+xx, `WARIxx` 622+xx, `YOKxx` 681+xx,
  `LIBxx` 740+xx). This holds for all 59 characters (the tool checks it on
  every run). The loose files are unused copies.

### NAOMI [verified]
- **Cart image:** `epr-23085a.ic11` at 0, then each mask ROM at
  `0x800000 * n` in the MAME order (ic17s, ic18, ... ic30s, ic31, ic32s).
- **File table:** `{u32 cart_offset, u32 size}[787]` at main RAM
  `0x0C2285D4` (cart `0x2085D4`). The users are the loader at
  `0x0C0230C6`/`0x0C0232EA`, which calls `0x0C022E32`.
- **Per-character u16 file-index tables:** these are at `0x0C22A0FC` (PAK
  197+c), `0x0C22A264` (TBL 256+c), `0x0C22A2DC` (HIT 315+c), `0x0C22A354`
  (HIT_FM 374+c), `0x0C22A3CC` (HIT_DT 433+c), `0x0C22A444` (TAIKI),
  `0x0C22A4BC` (ATCK), `0x0C22A5AC` (WARI), `0x0C22A534` (YOK) and
  `0x0C22A624` (LIB).
- **Index mapping:** NAOMI index = PS2 AFS02 index - 12 for ids 209..798.
  NAOMI pads each file to 32 bytes.
- **NAOMI PAK:** it has only 4 sections (`0x20` header): graphics, ?,
  palettes and a 0x10000 block. Its palettes and 0x10000 block are
  identical to PS2 sections 2 and 3 for all 59 characters. The gameplay
  tables are separate files, bound to player `+0x168` (TBL), `+0x16C` (HIT),
  `+0x170` (HIT_FM) and `+0x174` (HIT_DT).
- **Field offsets:** the PS2 player struct is the NAOMI one shifted by
  +0x10 in this region. For example, the frame copy is at PS2 `+0x150` and
  NAOMI `+0x140`, and the current-record pointer is at PS2 `+0x164` and NAOMI
  `+0x154`.
- **Source names:** the cart padding contains leaked CVS `Entries` lines
  (`plXX_tbl.s`, `hit_XX.s`, `hit_dtXX.s`, `atckXX.s`, `taikiXX.s`,
  `wariXX.s`, `yokXX.s`, `libXX.s`, `s_plXX.c`, `pl_dmg.c`, Dec 1999). This
  confirms the same source tables on both sides.

## 2. Formats (as read by code)

| File | Format | Readers |
|---|---|---|
| **TBL** (animation scripts) | See the field list below this table | PS2 `func_001757E0` (start), `func_00175700` (step), `func_00175910`, all in src/animation_frames.c. NAOMI `func_0c02a0c4` and `func_0c02a026` (src/verified/tu_0c02a0c4.c, tu_0c029fc4.c). The logic is identical. [verified] |
| **HIT** (box selection) | 16 bytes per entry: `s16 slot[8]`. **slot0 = attack rect**. slot1 low byte = body/throw rect, high bits are flags. **slot2..5 = hurt rects** (slot5 is optional). Byte 14 = height (PS2 `func_00178EB0`). | NAOMI `func_0c15dc08` checks a's slot2 against b's slot0. `func_0c09c85c` checks slot1 against the other side's slot2..5. Slot roles are [inferred] from these checks and from standing frames having slot0 = 0. |
| **HIT_FM** (rects) | 256 x 8 bytes: `{s16 x, half_w, y, half_h}` in CPS2 units (x*5/3, y*15/7 at use). A rect with `half_w` or `half_h` of 0 never collides. | NAOMI `func_0c15dc08` [verified] |
| **HIT_DT** (attack data) | 28-byte records indexed by `attack_id & 0x7F`. NAOMI has n records and PS2 is padded to 128. See the byte list below this table. | PS2 `func_0018B500` (src/xm14_b.c), `func_0018B890` (src/xl6_a.c), `fb34_c.c`. NAOMI `0x0C048274` and `0x0C048520`. [verified] |
| **TAIKI / ATCK / WARI / YOK / LIB** | Offset tables and byte tables. These are **CPU AI** data: probability tables indexed by difficulty and `rand & 0x1F`. | PS2 `func_00169CE0` (src/y11_g.c) and `src/ra24_a.c`, `src/g7.c` |

TBL layout:
- **Top table:** u32 offsets at `base + p[+0x142]` (0x100 for every
  character except PS2 Sentinel, where it is 0x200). One entry per animation
  group.
- **Group array:** u32 offsets, one per "strength"/variant, each pointing to a
  script.
- **Frame record:** 20 bytes: `u8 b0, b1; s8 duration; u8 attr; u32 sprite;
  u8 b8..b17; u16 hit_selection`.
- **Goto:** when `attr & 0x80`, the next 4 bytes are a goto target (loop or
  branch).
- **Copied fields:** `b10` is copied to PS2 `+0x15A` / NAOMI `+0x14A`
  ("anim_flags"; 0x80 = the opponent may proximity-block and the frame can be
  special-cancelled, per marvelous2 notes). `b12` is a command byte
  (sound/effect, `func_001E3370`).

HIT_DT bytes:
- **byte 0 = base damage.** NAOMI `mov.b @r13` at 0x0C0482B0 passes it to the
  scaling function. PS2 `r[0]` goes to `func_0018B890`.
- byte 1 & 0x1F = hit type, byte 2 = flags (0x20 selects the alternate
  scaling table), byte 3 goes to `+0x245`/`+0x231`.
- byte 4 = stun, bytes 6/7 = hitstun-related, bytes 8/9 go to `+0x242`/`+0x243`.
- bytes 15/23 = meter gain, byte 0x12 = flags (0x10 = no combo count, 0x20 =
  cannot kill), byte 0x16 = effect.

**The damage pipeline is the same on both builds:**
- **Same steps:** `base x hit-count scaling table x defender defense table
  (per character) x low-health table x damage-level option`.
- **Same tables:** they are byte-identical. NAOMI `0x0C23C7C6` (hits),
  `0x0C23C862` (defense), `0x0C23C842` (HP thresholds) and `0x0C23C77E`
  (damage level) match PS2 `D_00446F00`, `D_00446F90`, `D_00446F80` and
  `D_004BF4B0`.
- **Same health:** max health is 0x90 on both (NAOMI `0x0C04103C`, PS2
  `initialize_stage_actor_001804F0.c`).
- **PS2-only factor:** a handicap multiplier `D_004BF4B8[p+0x557]`, which is
  1.0 at the default.

So any difference in byte 0 is a real difference in base damage.

## 3. Method

For each character:
1. Parse TBL on both sides. Pair scripts by (animation group, strength
   index) and walk each script until its goto or loop.
2. Compare the per-frame durations, sprite ids, flags and selection indices.
3. For scripts whose duration lists are identical (frame-aligned), resolve
   each frame's selection to rects and compare the attack, body and hurt
   boxes.
4. Mark a frame "invulnerable" when it has no live hurt rect.
5. Compare HIT_FM rects and HIT selections index by index, and HIT_DT
   records index by index.

Caveat: pairing is by table index. Where a group's array length differs, or
PS2 Sentinel's top table moved, a few pairs are not like for like. The very
large outliers in the totals (for example char 0x20 script 1b/07 at 4806
ticks) are scripts that run into a bad goto, not real lengths.

## 4. Results

### 4.1 The six requested characters

| Char | Scripts compared | Timing differs | Fewer / more frames on PS2 | Rects changed | Selections changed | Invulnerability differs | Attack records changed (damage lower / higher on PS2) |
|---|---|---|---|---|---|---|---|
| 00 Ryu | 232 | 5 | 0 / 4 | 0 | 0 | 0 | 49 of 64 (44 / 3) |
| 17 Cable | 233 | 24 | 10 / 6 | 6 | 6 | 3 frames (17/13, PS2 only) | 44 of 52 (35 / 5) |
| 2C Magneto | 243 | 8 | 0 / 2 | 4 | 1 | 0 | 40 of 44 (33 / 2) |
| 2A Storm | 292 | 13 | 3 / 5 | 1 | 1 | 0 | 34 of 46 (31 / 2) |
| 34 Sentinel | 196 | 49 | 18 / 21 | **51** | 7 | 23 frames (18/03 NAOMI only, 15/0b PS2 only) | 30 of 32 (28 / 0) |
| 06 Cyclops | 249 | 14 | 8 / 3 | 5 | 0 | **0** | 41 of 56 (30 / 8) |

Examples. N = NAOMI and P = PS2 frame durations in 60 Hz ticks.
- **Ryu 15/17:** N `6,6,6,4,...` (50 ticks), P `4,4,4,4,...` (44). Script
  15/0e is the same 60 ticks, but one 3-tick frame is split 1+2 on PS2.
- **Ryu 0b/00:** the NAOMI goto points past the file, so the arcade data
  looks broken there, and PS2 adds a 5-tick third frame.
- **Ryu HIT and HIT_FM:** identical. Ryu has no hitbox change at all.
- **Cyclops 09/02:** 17 frames / 51 ticks on N against 12 frames / 37 ticks
  on P. Five 2-tick frames are removed and the tail is retimed (`10,4` becomes
  `7,3`).
- **Cyclops 07/02:** 48 ticks becomes 40, and 0f/02 goes from 58 to 52.
- **Cyclops rects:** rects 101/112/117/118 are empty on NAOMI and live on PS2,
  and 114 is moved. These are only reached by frames whose durations changed.
- **Cable 15/03:** 31 ticks becomes 21. 15/13 goes from 53 to 34
  (`14,9,8,8` becomes `8,4,4,4`), and 15/05 from 25 to 41.
- **Cable boxes:** rect 13 x moves from 3 to -50 and rect 161 doubles in size.
  284 aligned frames have different hurtboxes, and NAOMI group 1a has 28
  variants that PS2 lacks.
- **Magneto 02/00:** 22 ticks becomes 19 (first frame 6 becomes 3).
  08/01 goes from 27 to 32 and 0a/01 from 25 to 31.
- **Magneto body rect 96:** NAOMI `(-9,33,-60,60)`, PS2 `(-22,17,-23,26)`.
  It is used by 381 aligned frames, including the stand.
- **Storm 14/02:** N `3,8,0,8,8,8` (35 ticks) against P `2,2,2,2,2` (10).
  14/04 goes from 21 to 39.
- **Storm boxes:** rect 51 shrinks from h 46 to 23.
- **Sentinel:** the most changed character.
  - Stand 00/00 is 2 frames / 8 ticks on N and 6 frames / 56 ticks on P.
  - The PS2 TBL has a larger header (top table at 0x200).
  - 51 of 256 rects differ.
  - Its animation set is regrouped (11 PS2-only and 17 NAOMI-only
    variants). This fits the PS2 Sentinel special case in the renderer
    (`stride 512`, `func_0016F2D0`).
- **Animation-flag byte (`b10`):** it is the most common per-frame change
  (Ryu 23, Storm 218 and Sentinel 186 frames). It is typically arcade `0x40`
  against PS2 `0x80` on recovery and super frames. This changes which frames
  allow proximity block and cancels [inferred].

### 4.2 All 59 characters (`--summary`)

- 15,010 scripts were paired. **914** have different frame timing.
  - **288** have fewer frames on PS2, 204 have more, and 422 have the same
    count with different durations.
  - 351 are shorter in total on PS2 and 370 are longer.
- 350 HIT_FM rects differ.
- 500 aligned frames change invulnerability. Most of these are in the Abyss
  forms (0x18/0x19/0x1A, 448).
- **2,839 of 3,498 attack records differ.** Base damage is **lower on PS2
  in 2,483** and higher in 168.
  - The common pairs are 6 to 4, 5 to 4, 10 to 7, 8 to 4, 16 to 13 and
    24 to 16.
  - Sentinel's normals go from 10/15/20 to 6/6/10.
- CPU AI tables differ for every character but one file.

### 4.3 Verdict on each claim

| Claim | Finding |
|---|---|
| "Frames of animation removed" | **Confirmed, but mixed.** About 6% of scripts are retimed. 288 lose frames (for example Cyclops 09/02 loses 5 frames / 14 ticks, Cable 15/13 loses 19 ticks, Storm 14/02 goes from 35 to 10 ticks), and about as many gain frames. Many changed scripts are specials, supers and their recoveries, so combo timing changes are plausible. |
| "Altered hitboxes" | **Confirmed for many characters, but not all.** Ryu has none. Magneto has a much smaller body box. Cable, Storm and Cyclops have a few rects each. Sentinel has 51 rects. Across the cast 350 rects differ. |
| "Anti-air assists not invincible at startup on PS2" | **Not found in data for the characters checked.** Cyclops has 0 invulnerability-status differences, and none of the 6 characters loses startup invulnerability on PS2 in an aligned script. Invulnerability can also come from code (the player immunity timers, NAOMI `+0x1ED`, set by assist/tag routines), so the remaining place to look is the assist entry code. This is open. |
| "Counter glitch hits both characters on PS2" | **Not verified.** The variable-counter path was not located in either binary within this pass. The next step is to find the tag-in handler that sets the partner's immunity and compare it with NAOMI. |
| "One stage's music stops" | **Not a data defect.** All 23 AFS00 ADX streams have sane headers. Every stage-length track has its loop flag set with valid loop points. The 5 non-looping files are 2.6 to 108 s jingles, endings and fanfares. The cut-out is therefore in playback code (ADXT/IOP streaming contending with AFS reads, or a stop call), not in the stream. |
| (Not in the list) **damage** | **Arcade base damage is higher for about 71% of attack records**, and the scaling pipeline is identical. This is the largest gameplay difference found. |

**Important caveat:** NAOMI Rev A is a later arcade revision. The PS2 port
was made from the Dreamcast data (the AFS02 still carries Dreamcast `DTPK` and
`PLxx_VOI` stubs). Some differences, possibly including the damage values, may
be "Rev A against the original/Dreamcast data" rather than PS2-specific edits.
Without a Dreamcast image these cannot be told apart. Before shipping an
"arcade" label, check one move in MAME against PCSX2: first-hit damage and
frame count of, for example, Cyclops script 09/02.

## 5. "Arcade accuracy" option: plan

1. **Runtime source:** the user points the port at their own `mvsc2.zip`.
   Verify the ROM CRCs or SHA-1s listed in the decomp's
   `config/target.json`. Build the cart image in memory (§1 layout), read the
   file table at cart `0x2085D4`, and take files 256+c, 315+c, 374+c and
   433+c (and optionally the AI tables at 492+, 551+, 610+, 669+ and 728+).
   Nothing is redistributed.
2. **Splice:** after `func_0016F1B0` binds the PS2 PAK, repoint player
   `+0x178` (TBL), `+0x17C` (HIT), `+0x180` (HIT_FM) and `+0x184` (HIT_DT) to
   buffers that hold the NAOMI files. Their formats are identical (offsets are
   relative to the file base, little-endian). Pad HIT_DT to 128 x 28 bytes
   with zeros, as the PS2 does.
   - Sprite ids must stay valid for the PS2 sprite bank. Check that every
     NAOMI frame's `sprite` value exists in the PS2 bank's frame table, and
     fall back per script to PS2 frames that are missing (Sentinel will need
     this).
   - Keep the PS2 `p+0x142` top-table offset logic. Sentinel's NAOMI TBL
     uses 0x100, so set `+0x142` from the loaded TBL with the same scan the
     tool uses.
3. **Granularity:** use separate toggles for (a) frame data and boxes
   (TBL/HIT/HIT_FM), (b) damage and hit properties (HIT_DT), and (c) CPU AI.
   Netplay requires both sides to have the same toggles, so hash the loaded
   tables into the session handshake.
4. **Code-side items:** assist invulnerability, the counter glitch and
   music. Locate the PS2 assist entry and variable-counter routines, diff
   them against the NAOMI decomp, and patch them in C behind the same option.
   For music, the port's own ADX player removes the IOP streaming path, so
   check the cut-out on the port before patching anything.
5. **Validation:** for each character, run `arcade_diff.py --json` against
   the port's live tables. They should report 0 differences when the option
   is on. Spot-check in MAME and in the port, comparing damage and frame
   counts for the scripts listed in §4.1.
