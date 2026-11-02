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
| "Anti-air assists not invincible at startup on PS2" | **The code is the same; the data differs.** The assist request, the partner entry and the attack-immunity timer behave identically on both builds (§7.1). Startup invulnerability that comes from hurtboxes differs in 139 scripts of 22 characters, in both directions (§7.1). `arcade.frame_data` restores the arcade tables. None of them is run by an assist: the assist sweep (§7.3) finds no assist whose startup invulnerability differs. |
| "Counter glitch hits both characters on PS2" | **No PS2 code difference.** The variable-counter request and the routine that brings the partner in match the NAOMI routines instruction for instruction (§7.2). Any remaining difference is in the counter attacks' frame, box and hit data, which `arcade.frame_data` and `arcade.damage` replace. The glitch itself was not reproduced. |
| "One stage's music stops" | **Not a data defect.** All 23 AFS00 ADX streams have sane headers. Every stage-length track has its loop flag set with valid loop points. The 5 non-looping files are 2.6 to 108 s jingles, endings and fanfares. The cut-out is therefore in playback code (ADXT/IOP streaming contending with AFS reads, or a stop call), not in the stream. |
| (Not in the list) **damage** | **Arcade base damage is higher for about 71% of attack records**, and the scaling pipeline is identical. This is the largest gameplay difference found. |

**Important caveat:** NAOMI Rev A is a later arcade revision. The PS2 port
was made from the Dreamcast data (the AFS02 still carries Dreamcast `DTPK` and
`PLxx_VOI` stubs). Some differences, possibly including the damage values, may
be "Rev A against the original/Dreamcast data" rather than PS2-specific edits.
Without a Dreamcast image these cannot be told apart. Before shipping an
"arcade" label, check one move in MAME against PCSX2: first-hit damage and
frame count of, for example, Cyclops script 09/02.

## 5. "Arcade accuracy" option (implemented)

Code: `port/host/arcade.c` (loader, splice, hooks), `port/host/inflate.c`
(raw DEFLATE + CRC-32, so neither build needs zlib), `port/host/fe/fe_arcade.c`
(settings), `port/web/shell.html` (zip intake), `port/tools/pack_personal.py
--naomi`. All toggles are off by default; with all off the game runs the PS2
tables untouched.

| Toggle | Setting / option | What is repointed after `func_0016F2D0` binds the PS2 PAK |
|---|---|---|
| (a) frames + boxes | `arcade.frame_data`, `--arcade a`, `?arcade=a` | `+0x178` TBL, `+0x17C` HIT, `+0x180` HIT_FM, `+0x142` top-table offset |
| (b) damage / hit | `arcade.damage`, `--arcade b` | `+0x184` HIT_DT (NAOMI records, padded to 128 x 28 with the PS2 records beyond them, which are zero) |
| (c) CPU AI | `arcade.cpu_ai`, `--arcade c` | `+0x198` TAIKI, `+0x19C` ATCK, `+0x1A0` WARI, `+0x1A4` YOK, `+0x1A8` LIB |

**Loading.**
- The user's zip is read at boot (`arcade_init`, called from `mvc2_boot`).
  The source is `--naomi PATH` / `arcade.naomi` on the desktop, and
  `/mvsc2.zip` on the web, which the page writes from its picker, its
  IndexedDB cache or the personal build's embedded copy.
- Every member that is present must match the Rev A CRC-32 and size.
  `epr-23085a.ic11` (the file table at cart `0x2085D4`) and `mpr-23058.ic27s`
  are inflated and checked. All 9 x 59 table files live in `mpr-23058.ic27s`,
  so the personal build embeds only those two members (5.6 MB).
- On failure the toggles are cleared and the log says why.

**Splice.** This is a wrapper on `func_0016F2D0` (host_impl.csv); the game's
own body runs first. The merged tables are built once per character and
cached.
- **TBL:** the NAOMI file is used unchanged at offset 0, so all its offsets
  and gotos stay valid. Its top table is rewritten to point at new group
  arrays (each as long as the longer of the two builds' arrays), and the PS2
  TBL is appended.
- **Per-script fallback to the PS2 script:** a (group, strength) entry uses
  the PS2 script when NAOMI has none (PS2-only variants: Sentinel's 11 and
  character 0x0A's 50, for example), when a displayed NAOMI frame's sprite id is not
  in the PS2 sprite bank, or when the NAOMI chain is malformed (its goto
  leaves the file, as in Ryu 0b/00 and 0b/03, or its selection index is
  outside HIT).
  - A fallback is taken only if the PS2 chain itself passes the same check.
    Groups 0x1D+ (effect formats) never fall back.
  - Groups 0x1B/0x1C use the 8-byte record format (`func_001754A0`). The
    others use 20-byte records.
  - Fallback chains are relocated: their gotos move by the PS2 copy's offset,
    and their selections move by the NAOMI HIT count, because the PS2 HIT
    entries are appended after NAOMI's.
  - Rect indices stay as they are, because several readers take them as u8.
    So a fallback frame uses the NAOMI rect of the same index. The log counts
    the PS2 selections whose rects differ.
- **`+0x142`:** set from the scan of the NAOMI TBL (0x100 for all 59,
  Sentinel included).
- **Copies of the player:** effect actors copy the player's
  `[0xEC, 0x1B0)` (ActorState), so they inherit the new pointers and
  `+0x142` together.

**Hash.**
- `arcade_hash()`: FNV-1a 64 over the toggles and every NAOMI table they
  select, for all 59 characters. It is logged as the "session hash" for the
  future netplay handshake.
- Each binding also logs a per-player hash of the merged tables.

**Test hooks.** These are app options, and on the web they go in `?args=`.
- `--arcade-trace` logs every player script run (frames, ticks, and the bound
  table's own count) and every hit (attack id, base damage, health).
- `--arcade-play GG/SS` makes player 0 start that script through the game's
  `func_001757E0` while standing.
- `--p1-team a,b,c` forces side 0's characters (point and both partners)
  as the character select queues their PAKs (`func_0012EF50/80`, called for
  each pick by `func_0012E780` cases 18/20/22; a pick equal to an earlier
  team member's character shares that PAK). The HUD keeps the menu's names.
- `--cpu-team a,b,c` works again: the game's credited pick runs, then the ids
  are forced.
- Either list takes `ID:T` entries (T = 0, 1, 2 for alpha, beta, gamma): the
  assist type is set when the fight binds the PAK (`func_0016F2D0`). Without
  it the CPU gets its default (`D_004405A0[id]`) and the human keeps the menu's.
- `MVC2_ASSIST_CYCLE=1` (with `--arcade-trace`): each time a side-0 partner
  starts its exit (18/04) after an assist, its type (`+0x4DD`) moves to the
  next one, so one fight shows all three assists of both partners (7.3).
  Trace lines carry the start frame and the assist type.

## 6. Verification (browser build, headless Chromium)

Screenshots are under `private/converted/boot/web/arc*`.

| Check | Arcade toggles on | PS2 data (toggles off) | Tool (NAOMI / PS2) |
|---|---|---|---|
| Cyclops 09/02 (a), started on player 0 with `--arcade-play 09/02` | 17 frames, 52 ticks (bound table: 17 records, 51 ticks) | 12 frames, 38 ticks (table: 12 / 37) | 17/51, 12/37 |
| Ryu's attack 0x30 (b), CPU Ryu's first hit on Cyclops | base 28, health 144 -> 123 | base 14, 126 -> 116 | 28 / 14 |
| Ryu's attack 0x0b (b) | base 15 | base 13 | 15 / 13 |
| Game-started scripts, all toggles on | e.g. Cyclops 08/02 11 frames / 31 ticks = table | | |
| Settings path (`?arcade.frame_data=1&arcade.damage=1&arcade.cpu_ai=1`, no `?arcade`) | same results, same session hash `9f9cc9ad0ddbb266` | | |
| Zip picker (page without an embedded set, `?arcade=ab`) | asks for mvsc2.zip, then loads the full 85 MB zip and boots | | |
| Sweep, all toggles on, CPU teams of three plus a forced P1 point, 15 fights of 20 s | all 59 characters bound and fought; no crash or abort (`arc_sweep/run0..14`) | | |

Notes:
- The scripted start lands mid-tick, so its counts are one tick above the
  table. Scripts the game itself starts match the table exactly.
- With arcade data, Sentinel draws and fights normally (`arc_sweep/run13`).

## 7. The two code claims

**Field mapping.** NAOMI `0x1ED` (attack immunity, PLAYER.md) is PS2
`+0x201`; in this region of the struct PS2 = NAOMI + 0x14. This is shown by
twin routines:
- NAOMI `0x0c03f1b0` (src/verified/func_0c03f15c.c) is PS2 `func_001769F0`
  (g2.c). Both have `if (phase < 5 && [0x1dc|0x1F0] && [0x238|0x24C])
  immunity = 2`.
- NAOMI health `0x420` is PS2 `0x434`.

### 7.1 Assist / tag-in startup invulnerability
Compared, NAOMI asm (decomp `tools/inspect_rom.py`) against PS2 C:

| Routine | NAOMI | PS2 | Result |
|---|---|---|---|
| Per-frame player update: timers count down unless in hitstop (`0x1A0`/`0x1B4`), and the "hurtable" flag `0x19D`/`0x1B1` = 0x80 unless immunity != 0, state 1, or state 2 with `0x1F6`/`0x20A` == 0 | `0x0c039af4`, `0x0c039d52` | `func_0027FBB0` (w21a5_m.c; this is Abyss' form-3 variant, twin `0x0C0BB598`; the generic update is `func_00179590`, 10.5) | same |
| Immunity on being hit = HIT_DT byte 0x16 & 0x3F, copied to the partner | `0x0c048412` | `func_0018B500` (xm14_b.c) | same |
| Assist / tag request (A1/A2, counter variants 3/4) | `0x0c046700` | `func_00188860` (r16_00_a.c) | same structure, masks and conditions |
| Partner entry / tag-in checks: sets immunity 2 in three places | `0x0c03b74c` | `func_0017BDA0` (nq184_b.c) | same |
| Immunity 3 when the special entry check fails | `0x0c039244` | `func_003D92F0` (w194_n.c) | same |
| Immunity 1 x3, 4 x2, 16 (Abyss) | `0x0c03afb6..`, `0x0c044216/4a`, `0x0c043760` | `func_0017B300/B3B0/B410`, `func_00185290/85380`, `func_001841E0` | same values |

**Code verdict:** no PS2 change to assist or tag-in immunity, so there is no
host code fix to make.

**Data:** a per-script scan (`startup invulnerable ticks` = ticks before the
first frame with a live hurtbox, groups 0x00..0x1A, all 59 characters) finds
139 scripts in 22 characters that differ. They differ in both directions.
For example:
- Storm 14/00: NAOMI 56 ticks, PS2 0.
- Hulk 18/01: 32 against 0.
- Amingo 15/01: 34 against 0.
- Psylocke 15/0f: 3 against 6.
- Sentinel 15/0a..11: mixed.

These come from the TBL/HIT/HIT_FM tables, so `arcade.frame_data` restores
them. This is broader than §4.3's aligned-only count, which found none for
the six characters. Which script is each character's anti-air assist was not
mapped, so the claim is "plausible for some characters, data-side" rather
than confirmed for a named assist. The assist sweep (7.3) then mapped the
assists: none of the differing scripts is an assist move.

### 7.2 Variable counter "hits both characters"
- **Request:** the variable counter is request kinds 3/4 of the assist
  request (`*q` at `0x25E/0x25F`, PS2; `0x24A/0x24B`, NAOMI). It sets
  `+0x26B` and `+0x2B0 = -1`.
- **Consumer:** the per-frame team routine (q3_s.c) calls `func_00327570`
  for a point character with `+0x2B0` set.
- **Partner entry:** `func_00327570` activates the partner. It requires
  health > 0 and no snap-out timer, and then sets the active flags, state
  0x1C, `0x26A = 7` and `0x269 = 8`, copies the facing and position, clears
  the input words, ORs the side mask and sets the point's `0x26D`.
- **Comparison:** NAOMI `0x0c036dc0` does exactly the same stores with the
  same constants (`0x256 = 7`, `0x255 = 8`, state 28 through `0x0c045248`,
  `0x259 = 1`).

**Verdict:** no PS2 code difference in the variable-counter path. Any
difference in how a counter connects comes from the counter attacks' data,
which (a) and (b) replace. The glitch was not reproduced in either build.


### 7.3 Which script each assist runs (assist sweep)
Mapped by running the game, not by reading 59 characters' state code:
`port/tools/scripts/assist_sweep.txt` (VS mode, the second pad idle, assist 1
and 2 every 250 frames), `--p1-team 0,X,Y` (Guile on point when Ryu is a
partner), `MVC2_ASSIST_CYCLE=1 --arcade-trace`, 28 native runs plus 7
targeted ones (`ID:T` start types). `arcade_diff.py ... --assists LOG...`
then lists, per character and type, the scripts the partner ran between its
jump-in (01/01) and its exit (18/04, 18/02), without stand and hit
reactions, and each script's startup invulnerability (ticks before its
first frame with a live hurtbox) on both builds. Logs and report:
`private/converted/boot/native/assist_sweep/`.

Result: **164 of the 168 assist types (56 characters x 3) were observed; in
none of them does the startup invulnerability differ between PS2 and NAOMI.**
Most assist moves have a live hurtbox from their first frame on both builds
(0/0); the ones with an invulnerable start are equal on both: e.g. char 02
alpha 15/03 8/8, 06 beta 14/02 7/7, 0c beta 15/0c 10/10, 23 beta 15/27 28/28,
24 alpha 15/02 21/21, 37 beta 15/07 13/13, 38 beta 16/08 9/9. The scripts the
data scan of 7.1 found different (Storm 14/00 56/0, Hulk 18/01 32/0, Amingo
15/01 34/0, ...) are not run by any assist: Storm's assists are 15/01
(alpha), 16/00 16/07 15/14 (beta) and 15/15 (gamma); Hulk's 15/16, 15/00
15/02, 15/09..0d; Amingo's 15/0e, 15/0e, 15/07 15/09. One script has no
NAOMI counterpart (char 01 beta 0f/3d, a PS2-only variant).

So, at the data level, no anti-air (or other) assist loses startup
invulnerability on the PS2; with the code identical too (7.1), the claim is
not supported. Assist *timing* (total ticks) does differ for a few, e.g.
char 05 gamma 15/11 55 -> 40, char 09 alpha 15/06 52 -> 68, 06 alpha 15/04
16 -> 30; `arcade.frame_data` restores those.

Not observed (4): char 00 alpha, 1e beta, 27 alpha and 28 gamma. The first
three are the shoto fireball assists (Ryu, Akuma, Ken: script 15/03): in
these native runs the partner finishes 15/03 and then stays in state 0x15
without exiting, so no further assists come (a port bug, since fixed: see 9).

Per character (first script of each assist, `inv` = startup-invulnerable
ticks NAOMI/PS2 where not 0):

| Char | alpha | beta | gamma |
|---|---|---|---|
| 00 | not observed | 15/01 | 15/04 15/06 15/05 15/07 |
| 01 | 15/00 (inv 15/00 3/3) | 0f/3d 0f/1d 0f/1e 0f/1f | 0f/2f 0f/30 01/09 01/03 |
| 02 | 15/03 15/04 03/02 (inv 15/03 8/8) | 15/01 | 15/01 |
| 03 | 15/06 15/09 15/0a | 15/01 | 15/01 |
| 04 | 15/05 | 15/0a | 15/00 |
| 05 | 15/00 15/01 | 15/1c 15/1f 15/23 15/2f (inv 15/1f 6/6, 15/23 12/12) | 15/11 |
| 06 | 15/00 15/04 | 14/02 14/03 14/04 (inv 14/02 7/7) | 15/2d 15/2e |
| 07 | 15/17 15/1a 15/1d 15/20 | 15/00 15/03 15/04 15/06 | 15/08 15/0e 15/0f 01/03 |
| 08 | 15/0c 01/09 15/0e (inv 15/0c 3/3) | 15/00 | 15/00 |
| 09 | 15/06 15/0a | 15/00 | 15/06 15/0a |
| 0a | 15/34 15/0b | 15/02 15/04 | 15/16 15/17 |
| 0b | 15/00 | 15/0a 15/0c | 15/0e |
| 0c | 15/08 | 15/0c 15/0d 01/03 (inv 15/0c 10/10) | 15/01 15/03 15/06 (inv 15/01 5/5) |
| 0d | 15/16 | 15/00 15/02 | 15/09 15/0a 15/0c 15/0d |
| 0e | 15/00 15/04 03/02 | 15/0c 15/0e | 15/10 |
| 0f | 15/03 | 15/05 | 15/00 |
| 10 | 0f/02 | 15/08 | 15/09 |
| 11 | 15/14 15/16 | 15/08 15/0a | 15/10 15/12 |
| 12 | 15/01 | 15/03 | 15/01 |
| 13 | 15/0a 15/0b | 15/0c 15/0d | 15/1e |
| 14 | 15/12 | 15/00 | 15/1a |
| 15 | 15/0e | 15/0e | 15/07 15/09 |
| 16 | 15/01 | 15/04 | 15/0d 15/0f 15/11 15/13 |
| 17 | 15/02 15/04 15/05 | 15/0a 15/0c 15/0d 15/0f (inv 15/0a 4/4) | 15/00 |
| 1b | 15/00 | 15/03 15/1a 03/02 | 15/06 |
| 1c | 15/00 | 15/04 15/07 | 15/00 |
| 1d | 15/00 | 15/03 | 15/03 |
| 1e | 15/01 | not observed | 15/04 15/06 15/05 15/07 |
| 1f | 15/00 | 15/04 15/10 | 15/05 15/0a |
| 20 | 15/01 15/03 15/07 | 15/11 | 15/13 15/16 |
| 21 | 15/00 15/01 | 15/04 15/05 15/06 (inv 15/04 6/6) | 15/00 15/01 |
| 22 | 15/01 15/07 15/09 15/0b | 15/12 15/14 | 15/0d 15/0f |
| 23 | 15/00 | 15/27 15/05 (inv 15/27 28/28) | 15/1b 15/21 |
| 24 | 15/02 15/03 15/05 03/02 (inv 15/02 21/21) | 15/06 15/07 | 15/0a |
| 25 | 15/00 | 15/01 | 15/03 |
| 26 | 15/00 | 15/1a | 15/01 15/02 |
| 27 | not observed | 15/01 | 15/04 15/06 15/05 15/07 |
| 28 | 15/02 | 15/0c | not observed |
| 29 | 15/00 15/03 | 15/07 15/0a | 15/14 15/17 03/02 |
| 2a | 15/01 | 16/00 16/07 15/14 01/09 | 15/15 |
| 2b | 15/01 15/03 04/00 | 15/05 | 15/0b |
| 2c | 15/00 | 15/01 | 15/17 |
| 2d | 15/01 | 15/03 15/06 15/09 15/05 | 15/01 |
| 2e | 15/00 15/02 | 15/0c 15/0e 15/0f | 15/10 |
| 2f | 15/2b 15/2c | 15/38 | 14/07 03/02 |
| 30 | 15/04 15/10 15/11 | 15/2b 15/2e 01/09 01/03 (inv 15/2b 4/4) | 15/3d 15/3e |
| 31 | 15/0a 15/0b | 15/0a 15/0b | 07/02 |
| 32 | 15/00 15/02 | 15/01 15/03 04/00 | 08/02 |
| 33 | 15/00 15/02 | 15/07 15/08 15/09 | 08/02 |
| 34 | 15/00 15/01 | 08/02 | 15/16 |
| 35 | 15/01 15/02 | 15/00 | 15/1b |
| 36 | 15/06 | 15/01 15/04 | 14/05 03/02 |
| 37 | 15/00 15/02 15/04 | 15/07 15/09 03/02 (inv 15/07 13/13) | 07/01 |
| 38 | 15/02 | 16/08 (inv 16/08 9/9) | 15/22 01/0a 15/25 |
| 39 | 14/02 | 14/03 | 14/04 |
| 3a | 15/05 15/06 | 15/04 15/0f | 15/03 15/0e |

Some characters show the same script for two types (e.g. 02 beta and gamma
15/01); those are what the trace recorded, not checked against the menu's
move names.

## 8. Arcade slowdown

Not implemented, because it is not identifiable as code.
- No routine was found in the NAOMI program that slows the logic step on
  purpose.
- Arcade slowdown is a by-product of load: when a frame's SH-4 and PowerVR
  work overruns the vblank wait, the next logic step runs a frame late. This
  is inferred from the main-loop structure (one step per frame, gated on
  vblank), not traced.
- Reproducing it would need a per-frame cost model of the NAOMI hardware.
  Hit stop, super freeze and KO slow motion are ordinary game logic, so the
  port already runs them.

## 9. Open
- Closed (2026-10-31): the assist-to-script map (7.3: no assist's startup
  invulnerability differs); `--p1-team` partners can be forced (5).
- Found by the assist sweep and fixed: Sentinel's third assist crashed the
  port (`D_004C2010`, a function table credited as the raw EE address
  0x003B5F30; host R10 override in host_overrides.py, BOOT_NOTES "R12 robust
  pass").
- Fixed (2026-10-31, BOOT_NOTES "Play-through"): the shoto fireball
  assists (Ryu alpha, Ken alpha, Akuma beta) hung after 15/03. The partner's
  slide (`func_001EB330`) waits for its velocity to change sign through an
  explicit call of the EE soft-double compare `_dpflt`, which was always
  false on the host. They now exit (18/04, 18/02) and can be called again.
- Check one move in MAME against the port (the Rev A against Dreamcast-data
  caveat in §4.3).
- Fallback frames use NAOMI rects of the same index (the count is logged per
  character).
- Code comparison (section 10): closed for `func_0027FBB0` (Abyss' third
  form, the same as its NAOMI twin, 10.5) and for the CPU AI driver; the
  per-character state code is paired and screened (10.5), with the leads
  that were not read by hand listed there.

## 10. Code comparison (gameplay code, NAOMI program against the PS2 game)

Sections 5 to 7 cover the data. This section compares the code that runs
the game: the frame loop, input, the player update, hit handling and the
other gameplay routines. The first pass (10.1 to 10.4) used scratch tools;
the second pass (10.5) rebuilt them in `port/tools/naomi_pair/` (10.5 has
the commands). An SH-4 index of the NAOMI image (function starts from
`config/mapping.json` and `units.json`, call targets, pointer tables) and a
MIPS index of `asm/main.s`; functions are paired by call-graph propagation
from known twins (section 7), by data references, and by address order
inside each object file, scored by constants, size and call count.

### 10.1 Coverage
- **Paired automatically:** 2,063 NAOMI functions.
  - The gameplay core (NAOMI 0x0C03F000..0x0C04C000, PS2
    0x00176000..0x00191000): 346 of 443 NAOMI functions (78 %), 346 of 528
    PS2 functions. The PS2 build splits and reorders some of it (for
    example the player update below is one NAOMI function and two PS2 ones).
  - Character and effect code, NAOMI 0x0C18D000..0x0C1E9000: 1,373 paired.
  - NAOMI 0x0C04C000..0x0C18D000 (about 14,000 small functions, mostly
    per-character state code): under 2 % paired. Not compared.
- **Triage:** every pair was diffed by its float constants and its
  player-field offsets (PS2 = NAOMI + 0x10/0x14). Most hits are compiler
  forms (SH-4 folds `320 - 35` into 285, negates constants for `fsub`).
  Each remaining hit was read on both sides.
- **Read side by side** (NAOMI asm or C against PS2 C):

  | Routine | NAOMI | PS2 | Result |
  |---|---|---|---|
  | Main loop | `0x0C028394` (C) | `func_00170C30` | same order: vsync, per-player repeat, sound, logic, render, loader; PS2 waits for vsync at the end of the loop, NAOMI at the start |
  | Pad read, edges | `0x0C0210CC`, `0x0C0212A8` | `func_0012F0B0` | same record (20 bytes: held, previous, pressed, released, stick) and the same analog-to-direction step; NAOMI runs it in the V-blank interrupt |
  | Button auto-repeat | `0x0C02156C` (C) | `func_0012F3E0` | same (30 / 35 frames) |
  | Logic dispatch | `0x0C02AB50` | `func_003D7030` | same |
  | Player update (input masks, hit stop, timers, state dispatch, edge clamps, hurtable flags) | `0x0C039928` | `func_00179590` | **two PS2-only clauses** (10.2 a, b) |
  | Hit handler (hit stop on both, KO, hit sparks) | `0x0C04B61C` | `func_00190710` | same |
  | Hit reaction (damage call, hitstun type, immunity, dizzy, pushback bytes) | `0x0C048274` | `func_0018B500` | **one PS2-only clause** (10.2 c) |
  | Stage-edge clamps | `0x0C04221C`, `0x0C04231C` | `func_001823C0`, `func_001825F0` | same (35 and 26.67 units) |
  | Flying-screen edge clamp | `0x0C042414` | `func_001827B0` | **different constant** (10.2 d) |
  | Wall / landing velocity resets | `0x0C045CA4` and neighbours | `func_00187840` ... | same |
  | RNG | `0x0C02849A` | `func_00174170` | same (`hi:lo * 3 >> 8`) |
  | Damage scaling, assists, tag-in, counter, immunity | section 2, 7 | | same |

### 10.2 Differences

| | Where | PS2 | NAOMI | Player effect | Toggle |
|---|---|---|---|---|---|
| a | Player update, hit-stop branch: `func_00179590` (src/xl8_a.c) / `0x0C039AA2..` | `if (p[1] == 0x3A && (p[0x216] & 0x80))` clears all eight input words (`+0x354..+0x366`) | no such clause; hit stop only ORs the held buttons into `+0x364/+0x366` (NAOMI `+0x350/+0x352`) | Servbot (0x3A) cannot buffer inputs through hit stop while that flag (NAOMI `+0x202`, "hyper armor" byte in PLAYER.md) is set | `arcade.servbot_hitstop` |
| b | Player update, after the timers: `func_00179590` / `0x0C039CAC..` | `if (g[0xB7] && !p[0x216] && !p[0x406]) p[0x406] = 2` | none | none offline: `g[0xB7]` is copied from the network-mode settings packet (`func_0041FD20`, called only by the mode-5 back end) | none (inactive) |
| c | Hit reaction, health reaches 0: `func_0018B500` (src/xm14_b.c) / `0x0C048320` | KO unless HIT_DT byte 0x12 & 0x20 **or `g[0xAA]`** | KO unless byte 0x12 & 0x20 | none in VS or arcade: `g[0xAA]` = training mode (`g[0x4C] == 2`, y0_m.c), which also refills health (`func_00190130`); the arcade has no training mode | none (PS2 feature) |
| d | Flying-screen edge clamp: `func_001827B0` (src/e080_e.c) / `0x0C042414` | `35 + 16 + bound[0x98]` and `bound[0x9C] - 16 - 35` | `35 + bound[0x98]` and `bound[0x9C] - 35` (only `0x420C0000` in the pool) | while the opponent is the flying-screen "camera follows" character (`+0x249`, NAOMI `+0x235`), the player stops 16 units (about 10 CPS2 pixels) further from each stage edge on the PS2 | `arcade.fs_edge` |
| e | FPU mode: `0x0C028394` | the EE FPU rounds toward zero, no denormals | `fpscr &= ~3`: round to nearest (single precision) | rare 1-ulp float differences that grow into position differences (oracle pass) | the port's default (round to nearest) is the arcade's; `-DMVC2_PS2_FLOAT=ON` gives the PS2's |

Checked and **not** different: the hit stop length (HIT_DT byte 5 on both
players), hit stop input buffering, every per-frame timer of the player
(the same counters with the same zero tests), hitstun and dizzy (the
same random table `D_00446DA0` / `0x0C23C62E`), the stage-edge clamps, the
RNG, the round/KO path and the immunity on hit.

### 10.3 Timing and input lag

| | NAOMI | PS2 retail | Port |
|---|---|---|---|
| Logic rate | 59.94 Hz: the SPG table the program writes (`0x0C215B82`, `0x0C216222`) is 858 x 525 (`0x020C0359`), at the 27 MHz VGA clock | 59.94 Hz (NTSC) | 60.00 Hz (`PLAT_HZ`) |
| Where input is read | V-blank interrupt (`0x0C0215AC`): `pdExecPeripheralServer`, then `0x0C0212A8` -> `0x0C0210CC` (`pdGetPeripheral`) fills the input records; the main loop then returns from `nlWaitVSync` and runs the logic | top of the main loop, `func_0012F0B0` (`scePadRead`), after the previous frame's vsync wait | immediately before every logic step (`plat_poll_input`, `host_pad_set`) |
| Pipeline before the logic sees a press | about 1 frame: the peripheral server parses the previous V-blank's Maple transfer [inferred from the SDK's structure] | 2 frames (the retail executable in the Play! oracle, BOOT_NOTES "Oracle pass"; the IOP pad module's poll plus the EE buffer) | 0 frames: a press is seen in the next step, a tap shorter than a frame is latched |
| Extra buffering in the game | none (hit stop accumulates buttons on both) | none | none |

`arcade.timing` (Port / Arcade / PS2) sets the logic rate (60 or 59.94 Hz)
and delays the game's pads by 0, 1 or 2 steps (`arcade_pad_filter`, the
menus are not delayed). On a 60 Hz display the 59.94 Hz setting repeats one
display frame about every 17 s.

**Verdicts on the community timing gripes:**
- "The PS2 version has input lag": the game code does not add any (the
  input record and its use are the same as the arcade's). The retail PS2
  sees a press one frame later than the arcade (the pad pipeline), and an
  interlaced TV adds display lag. The port reads input with no pipeline,
  so it responds one frame sooner than the arcade and two sooner than the
  PS2; `arcade.timing` restores either.
- "The PS2 runs at a different speed": no. Both run one logic step per
  59.94 Hz frame; the port runs 0.1 % faster at 60 Hz unless
  `arcade.timing` is set.
- "Arcade slowdown": still not code (section 8). Neither program has a
  deliberate slowdown.

### 10.4 Verification
- Web build (headless Chromium), all three set
  (`?arcade.timing=arcade&arcade.fs_edge=1&arcade.servbot_hitstop=1`): title,
  menu, character select, versus, fight with attacks and an assist; the log
  shows `arcade: code toggles d(...) e(...); input pipeline 1 frame(s)`
  (`private/converted/boot/web/naomi_code1/`). The same flow with the
  defaults (all off) fights with an assist and logs no arcade line
  (`naomi_code0/`).
- `func_001827B0` as the web build compiles it (hostified), in a native
  harness with a bound of 100 / 700: left clamp 151, right 649 with the
  toggle off (PS2); 135 and 665 with it on (NAOMI).
- `arcade_pad_filter`: a press set at step 2 reaches the game at step 2, 3
  or 4 for delays 0, 1, 2.
- Not run in a fight: Servbot in hit stop with `+0x216 & 0x80` (the clause
  is a single test; the hostified source shows it guarded).

### 10.5 Second pass (2026-11-02)

**Tools** (`port/tools/naomi_pair/`, committed; they read the user's
`mvsc2.zip` through the NAOMI decomp checkout and the PS2 ELF at run time
and write only addresses and derived numbers):

```
T=port/tools/naomi_pair; N=/home/user/mvc2-naomi-decomp; E=private/disc/x_SLUS_204.86
python3 -I $T/sh4idx.py  $N naomi.pkl            # SH-4 index (21,729 entries)
python3 -I $T/mipsidx.py asm/main.s ps2.pkl      # EE index (21,024 functions)
python3 -I $T/pair.py    $N naomi.pkl ps2.pkl $E pairs.json
python3 -I $T/screen.py  naomi.pkl ps2.pkl pairs.json $E screen.tsv
python3 -I $T/coverage.py $N naomi.pkl ps2.pkl pairs.json screen.tsv [--hits 40]
```

- **Index.** NAOMI entries come from call targets, literal and table
  pointers, `units.json` exports and the mapping's CFG-walk starts. About
  66 KB of the image is unmapped; it is decoded only from an entry inside
  it (several vtable targets live there, Abyss' update among them). EE
  functions are the `glabel`s of `asm/main.s`, split where a data word
  points just after an unconditional jump (the per-state handlers the asm
  runs together after a dispatch `jr`). `$gp`-relative accesses count as
  data references.
- **Pairing** (`pair.py`), strongest first: the per-character init tables
  (NAOMI `0x0C23BCD8`, PS2 `0x00448D00`, 59 entries) and 24 hand-read
  seeds; table walks (a paired table address is walked in step, bounded by
  the PS2 `dlabel`); call-graph alignment (callee sequences anchored on
  known pairs); callee-set matching; and address order (a size-aligned DP
  between consecutive pairs of the monotonic chain, since both compilers
  kept each file's function order). Result: **12,700 function pairs**
  (5,776 from tables, 4,372 address order, 1,916 call graph, 553 callee
  sets, 59 init table, 24 seeds) and 2,640 data pairs. The player-struct
  shift was measured from the pairs: NAOMI offsets below 0x108 are the same
  on the PS2, 0x108..0x17B are +0x10, 0x19C and up +0x14 (0x17C..0x19B is
  where the PS2 adds the AI table pointers).
- **Screen** (`screen.py`): each pair, or the span between two consecutive
  chain pairs when one build split a function (the EE asm splits switches
  into case functions), is compared by float constants (0 and 1 ignored;
  1e-5 relative; the PS2's 448-line scale k*2 against the arcade's k*15/7
  and EE soft-double high words accepted), struct offsets after the shift,
  callee sets, and small constants, with a similarity score of the two token
  sets. A low similarity marks a doubtful pair, not a code difference.

**Coverage by region** (functions of 4 bytes or more; Units = compared
pairs or spans; Clean = no difference; Diff = a difference on a confident
pair, similarity >= 0.8; Doubtful = similarity < 0.6):

| Region | NAOMI | Functions | Paired | Bytes paired | Units | Clean | Diff | Doubtful |
|---|---|---|---|---|---|---|---|---|
| System, boot | 0x0C021000..0x0C028000 | 214 | 111 | 49 % | 101 | 41 | 3 | 52 |
| Game flow, team, round | 0x0C028000..0x0C03F000 | 734 | 334 | 53 % | 305 | 148 | 45 | 78 |
| Gameplay core | 0x0C03F000..0x0C04C000 | 437 | 323 | 84 % | 312 | 177 | 62 | 28 |
| CPU AI, shared | 0x0C04C000..0x0C051C18 | 219 | 75 | 38 % | 70 | 38 | 13 | 9 |
| Per-character state code | 0x0C051C18..0x0C131600 | 9,900 | 8,633 | 88 % | 8,544 | 6,232 | 1,370 | 474 |
| Projectiles, effects | 0x0C131600..0x0C18D000 | 3,940 | 2,848 | 81 % | 2,784 | 1,704 | 329 | 333 |
| Characters and effects (2) | 0x0C18D000..0x0C1E9000 | 4,363 | 324 | 10 % | 294 | 159 | 19 | 79 |
| SDK, libraries | 0x0C1E9000.. | 1,800 | 32 | 2 % | 18 | 3 | 0 | 15 |

Of all 12,428 units: 8,502 clean, 1,068 doubtful pairs, 1,403 whose only
differences are compiler, library or sound forms (a library call inlined
on one side, the NAOMI sound call `0x0C0344A0` against the PS2's own sound
calls and its per-player sound handles at `+0x29C/+0x2A0`, constants the
compilers materialise differently), and 1,455 leads.

**Per character** (`coverage.py`; a character's range runs from its init
function to the next one's):

| Char | NAOMI range | Functions | Paired | Bytes paired | Units | Clean | Diff (sim>=0.8) | Doubtful |
|---|---|---|---|---|---|---|---|---|
| shared | 0x0C04C000 | 219 | 75 | 38 % | 70 | 38 | 13 | 9 |
| 00 | 0x0C051C18 | 138 | 123 | 91 % | 121 | 86 | 22 | 8 |
| 01 | 0x0C05505C | 285 | 242 | 84 % | 240 | 171 | 42 | 14 |
| 02 | 0x0C05BBE8 | 142 | 129 | 88 % | 128 | 94 | 22 | 6 |
| 03 | 0x0C05F2B0 | 233 | 182 | 78 % | 180 | 126 | 23 | 16 |
| 04 | 0x0C0644E4 | 131 | 119 | 93 % | 116 | 87 | 15 | 8 |
| 05 | 0x0C067BC4 | 262 | 237 | 92 % | 235 | 165 | 44 | 10 |
| 06 | 0x0C06D5FC | 174 | 153 | 88 % | 153 | 110 | 22 | 14 |
| 07 | 0x0C0713C0 | 192 | 164 | 90 % | 162 | 107 | 33 | 9 |
| 08 | 0x0C07636C | 164 | 138 | 89 % | 135 | 84 | 25 | 13 |
| 09 | 0x0C07A838 | 101 | 93 | 89 % | 92 | 65 | 16 | 4 |
| 0a | 0x0C07CF9C | 228 | 194 | 90 % | 192 | 160 | 12 | 11 |
| 0b | 0x0C081A6C | 226 | 203 | 90 % | 202 | 162 | 25 | 7 |
| 0c | 0x0C08643C | 184 | 155 | 83 % | 153 | 112 | 20 | 8 |
| 0d | 0x0C08B154 | 163 | 143 | 90 % | 142 | 100 | 28 | 9 |
| 0e | 0x0C08EB38 | 135 | 115 | 81 % | 113 | 86 | 19 | 2 |
| 0f | 0x0C091D98 | 169 | 148 | 86 % | 146 | 106 | 27 | 9 |
| 10 | 0x0C0953CC | 159 | 147 | 94 % | 145 | 96 | 38 | 5 |
| 11 | 0x0C098D54 | 208 | 184 | 93 % | 184 | 137 | 30 | 9 |
| 12 | 0x0C09D874 | 230 | 196 | 91 % | 193 | 147 | 30 | 10 |
| 13 | 0x0C0A2D9C | 193 | 170 | 87 % | 170 | 127 | 22 | 13 |
| 14 | 0x0C0A70F0 | 231 | 204 | 92 % | 202 | 132 | 44 | 14 |
| 15 | 0x0C0AD270 | 124 | 110 | 95 % | 108 | 82 | 15 | 5 |
| 16 | 0x0C0AFF1C | 146 | 133 | 91 % | 132 | 107 | 15 | 5 |
| 17 | 0x0C0B31B4 | 140 | 127 | 92 % | 124 | 85 | 22 | 9 |
| 18 | 0x0C0B65F0 | 90 | 83 | 94 % | 82 | 60 | 16 | 3 |
| 19 | 0x0C0B8180 | 88 | 82 | 92 % | 80 | 65 | 8 | 2 |
| 1a | 0x0C0B98A0 | 123 | 100 | 86 % | 98 | 62 | 19 | 8 |
| 1b | 0x0C0BC47C | 158 | 138 | 88 % | 137 | 107 | 17 | 4 |
| 1c | 0x0C0BFD60 | 267 | 246 | 93 % | 244 | 161 | 51 | 15 |
| 1d | 0x0C0C50D0 | 266 | 247 | 94 % | 245 | 168 | 42 | 15 |
| 1e | 0x0C0C9FF0 | 183 | 165 | 91 % | 162 | 127 | 25 | 9 |
| 1f | 0x0C0CE558 | 159 | 132 | 81 % | 130 | 94 | 26 | 3 |
| 20 | 0x0C0D2724 | 183 | 166 | 90 % | 164 | 121 | 32 | 5 |
| 21 | 0x0C0D6D68 | 133 | 121 | 91 % | 120 | 97 | 15 | 4 |
| 22 | 0x0C0D9FC8 | 175 | 150 | 86 % | 149 | 110 | 32 | 2 |
| 23 | 0x0C0DEF1C | 201 | 182 | 91 % | 182 | 149 | 21 | 8 |
| 24 | 0x0C0E2F04 | 223 | 189 | 87 % | 188 | 138 | 30 | 5 |
| 25 | 0x0C0E8450 | 166 | 145 | 90 % | 145 | 108 | 15 | 8 |
| 26 | 0x0C0EC18C | 181 | 152 | 85 % | 151 | 98 | 29 | 13 |
| 27 | 0x0C0F0DF8 | 163 | 141 | 85 % | 141 | 100 | 27 | 9 |
| 28 | 0x0C0F4A0C | 159 | 137 | 91 % | 136 | 110 | 15 | 5 |
| 29 | 0x0C0F8250 | 83 | 75 | 93 % | 74 | 59 | 10 | 0 |
| 2a | 0x0C0FA384 | 94 | 85 | 91 % | 85 | 69 | 12 | 2 |
| 2b | 0x0C0FCA10 | 140 | 125 | 85 % | 124 | 103 | 17 | 3 |
| 2c | 0x0C0FFF24 | 88 | 77 | 89 % | 76 | 63 | 9 | 2 |
| 2d | 0x0C1021E8 | 150 | 127 | 83 % | 124 | 85 | 20 | 10 |
| 2e | 0x0C1058D4 | 211 | 166 | 79 % | 166 | 115 | 25 | 19 |
| 2f | 0x0C108E1C | 161 | 111 | 71 % | 110 | 63 | 23 | 18 |
| 30 | 0x0C10C2D8 | 171 | 141 | 81 % | 141 | 94 | 20 | 18 |
| 31 | 0x0C10F5D0 | 172 | 144 | 88 % | 142 | 89 | 20 | 12 |
| 32 | 0x0C113188 | 137 | 115 | 90 % | 113 | 79 | 21 | 7 |
| 33 | 0x0C116480 | 164 | 150 | 88 % | 148 | 116 | 20 | 8 |
| 34 | 0x0C119430 | 132 | 118 | 87 % | 117 | 74 | 29 | 4 |
| 35 | 0x0C11C1B0 | 122 | 109 | 92 % | 106 | 91 | 6 | 5 |
| 36 | 0x0C11EA20 | 98 | 85 | 88 % | 83 | 61 | 15 | 5 |
| 37 | 0x0C120D2C | 236 | 209 | 90 % | 206 | 160 | 22 | 9 |
| 38 | 0x0C1260D4 | 122 | 115 | 95 % | 113 | 89 | 19 | 3 |
| 39 | 0x0C129208 | 202 | 174 | 89 % | 173 | 115 | 37 | 11 |
| 3a | 0x0C12E38C | 141 | 122 | 91 % | 121 | 98 | 14 | 2 |
| effects | 0x0C131600 | 3940 | 2848 | 81 % | 2784 | 1704 | 329 | 333 |
| all | | 14059 | 11556 | 85 % | 11398 | 7974 | 1712 | 816 |

**Read by hand in this pass** (NAOMI asm against PS2 C or asm):

| Routine | NAOMI | PS2 | Result |
|---|---|---|---|
| Abyss form 3 (char 0x1A) per-frame update, vtable slot 24 (`p+0x43C`, NAOMI `+0x428`, offset 0x60); `func_00179590` jumps to it for char 0x1A | `0x0C0BB598` (unmapped bytes) | `func_0027FBB0` (w21a5_m.c) | **same**, including `p[0x159] = 0xFF` (NAOMI `0x149`, stored at `0x0C0BB76C`). The note that NAOMI lacks this store came from pairing it with the generic update `0x0C039928`, which stores it on neither build. |
| Generic update, the char 0x18..0x1A head | `0x0C039928` | `func_00179590` | PS2-only: `p[0x24] = 0x1D; p[0x31] = 0x14` for Abyss (f) |
| Draw-order sort of the actors | `0x0C041B8A` | `func_001817E0` | PS2-only Abyss clause (f) |
| Per-frame team routine | `0x0C0362F4` | `func_00326700` | PS2-only calls `func_00327C20`, `func_00190130` (g) |
| Red-health recovery (50 frames per point) | `0x0C04B236` | `func_00190070` | same, plus PS2-only network gates (h) |
| CPU AI driver | `0x0C04CFB4` | `func_00168C10` | **same** (every store and test, with the +0x14 shift; `> 4` round state hands over to `0x0C04DA30` / `func_00169C30`) |
| AI helpers | `0x0C04D0DA`, `0x0C04D17C`, `0x0C04D5E6`, `0x0C04D63C`, `0x0C04D81C`, `0x0C04D86E` | `func_00168D90`, `func_00168E80`, `func_001695A0`, `func_00169600`, `func_001698C0`, `func_00169960` | same (the PS2 duplicates two calls on a second path) |
| Character init at fight start (scale, priority, palette, flags; Abyss scales) | `0x0C0411C8` | `func_00180A30` | same |
| Throw attempt (throw buttons `0x1800` under the `0x3C00` mask, per-character throw-button mask, `func_00185E40` range check, state 0x22) | `0x0C043C66` | `func_00184B30` | **same**; the 59-entry mask tables (`0x0C23C94E`, `D_00447050`) are equal |
| Advancing-guard check | `0x0C0464C4` | `func_001884C0` | same |
| Variable counter request | `0x0C0469F4` | `func_00188C70` | same, plus a PS2-only training branch (g) |
| Flying-screen edge clamp | `0x0C042414` | `func_001827B0` | confirms 10.2 d (the PS2's extra 16) |
| Wake-up / dash entry positions | `0x0C045144`, `0x0C06C1A6` | `func_00186900`, `func_0020E790` | same values (the PS2 stores some floats as integer bit patterns) |
| Sound effect by id (< 64) | `0x0C0344A0` -> `0x0C0343F4` | `func_001E3210` -> `func_001E24E0` | audio: the PS2 drives its own sound system (not gameplay) |

Leads that turned out to be wrong pairs (similarity < 0.6, or a table
walked across two adjacent tables, e.g. the `p[4]` dispatch table at
`0x0C23B8B4` is followed by the `p[4] == 0` table at `0x0C23B8C4`, while
`jtbl_00448A00` on the PS2 is laid out differently): `0x0C043C66` /
`func_001853E0` (its twin is `func_00184B30`, above), `0x0C03AC52` / `func_0017A450` (its twin is
`func_0017AF30`), `0x0C039DCC` / `func_00179B90`.

**Differences added in this pass** (none is active in Arcade or VS mode,
so none is a gameplay toggle):

| | Where | PS2 | NAOMI | Effect | Toggle |
|---|---|---|---|---|---|
| f | `func_00179590` head, `func_001817E0`, `func_001793B0` | Abyss (0x18..0x1A): `p[0x24] = 0x1D` and `p[0x31] = 0x14` every frame, `p[0x24] = 7` in the draw sort and in the state dispatch | no such stores | draw priority (sprite layering) of the final boss only; not gameplay | none |
| g | Training settings `g[0xAA..0xB2]` (`D_004C2840`, copied from the training menu by `func_003D51E0`) | read by `func_00327C20` (per-frame `func_0018C4B0(point, 4)` when `g[0xAE]`), `func_00190130` (training refill), `func_00188C70` (training variable counter, with the RNG), `func_0018AD80` (`g[0xAB]` 1/2), `func_00188430` (`g[0xAC]`), `func_0018B500`, `func_0018D340`, `func_0018FB70`, `func_0018FCA0`, `func_00190540`, `func_001719E0`, `func_0032B690`, `func_003D31A0`, `func_003D8080` (`g[0xAA]`), `func_00161380`, `func_00186A60` (`g[0xB0]`), menu drawing (`g[0xB2]`) | no training mode | training mode only | none |
| h | Network-mode rules `g[0x52..0x58]`, `g[0xB7]` (written only by `func_0041FD20`, the mode-5 back end; `func_0012F860` clears them) | read by `func_00179590` (10.2 b), `func_00190070`, `func_00190130`, `func_001902F0`, `func_0018C510`, `func_0018D340`, `func_0018F8C0`, `func_0018FEB0`, `func_00180360`, `func_003D8440`, `func_003D8540`, `func_003D92F0`, `func_003D94B0` | none | network mode only | none |

**Verdicts.** Priority 1: `func_0027FBB0` is Abyss' third-form update and
matches the arcade; nothing to fix. Priority 2: in the core and game-flow
code read so far (throw attempt, advancing guard, variable counter, assist
and tag-in, hit reaction and hit stop, immunity, red-health recovery,
stage and flying-screen clamps, the team routine and its round-state
gates, the red-health and KO paths), the only gameplay differences are
10.2 a and d (already toggles). Priority 3: the CPU AI driver and its
helpers match; the AI differences are in the tables (`arcade.cpu_ai`).
Priority 4: per-character code is 88 % paired by bytes; 73 % of its units
are clean and none of the hand-read leads was a gameplay change.

**Not done (what remains).**
- 1,455 leads are listed by `screen.py` but not read (the most frequent
  forms left: EE soft-double arithmetic in character code, case functions
  the split did not separate, and PS2 sound and effect helpers).
- Game flow and system code are 50 % paired; the timer and round-end
  routines were not identified and read one by one (the round-state gates
  they set, `D_004D18A0`, are tested identically in the code above).
- Throw tech, super freeze, chip damage, pushback, air recovery,
  snapback, DHC and crossover-counter state handlers were not located by
  name (the throw attempt was, by hand, after its automatic pair proved
  wrong); they
  are among the core and per-character units above (paired and screened,
  not each read).
- The training settings `g[0xAB..0xB2]` are reset by `func_003D5260` only
  when a training session or the whole game starts; whether a value chosen
  in training survives into a later VS fight on the PS2 was not checked.
- NAOMI 0x0C18D000..0x0C1E9000 is only 10 % paired by this pass (the
  first pass paired 1,373 there by address order; its tables were not
  kept).
