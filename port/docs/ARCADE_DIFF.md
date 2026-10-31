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
| Per-frame player update: timers count down unless in hitstop (`0x1A0`/`0x1B4`), and the "hurtable" flag `0x19D`/`0x1B1` = 0x80 unless immunity != 0, state 1, or state 2 with `0x1F6`/`0x20A` == 0 | `0x0c039af4`, `0x0c039d52` | `func_0027FBB0` (w21a5_m.c) | same |
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
