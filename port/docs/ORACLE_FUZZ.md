# Oracle fuzz pass

Randomised differential testing of the native port against the retail game.
`port/tools/oracle/fuzz.py` generates fight scenarios from a seed, runs each
one on the port (native i386, `MVC2_PS2_FLOAT` on) and on the oracle (the
retail `SLUS_204.86` in the patched Play! core, `mvc2_oracle`) at the same
time, and compares their per-frame state dumps as they arrive.  It extends
the scripted oracle passes in `BOOT_NOTES.md` ("Oracle pass", "Oracle pass,
part 2") to all 56 characters, all assist types, random CPU teams and
random input.

## Running it

Inputs: your own disc image at `private/disc/mvc2.iso` (2048-byte sectors,
208,695,296 bytes, volume `MARVEL_VS_CAPCOM2`).  The matching build's
compilers are not needed.

```sh
port/tools/oracle/build.sh                      # oracle, ~2 min: /tmp/oracle_src/build/mvc2_oracle
cmake -S port -B build/port-i386 -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo \
      -DCMAKE_TOOLCHAIN_FILE=$PWD/port/cmake/i386-clang.cmake -DMVC2_PS2_FLOAT=ON
ninja -C build/port-i386 mvc2                   # USER_GUIDE.md "Building the desktop app (Linux)"
```

Check the pair first (both must match, see BOOT_NOTES "Oracle pass, part 2"):

```sh
port/tools/oracle/run_pair.sh OUT 8000 1/1/0 port/tools/oracle/scripts/fight_mix.txt -- --quiet-blocks
port/tools/oracle/run_pair.sh OUT 5300 1/1/0 "" -- --quiet-blocks     # attract cycle: 4835 frames
```

Then:

```sh
fuzz.py run --out DIR --jobs J --hours H [--seed S --count N] [--port BIN]
fuzz.py report --out DIR
fuzz.py show SEED                       # the scenario: teams, options, script
fuzz.py one --out DIR --seed S          # one scenario, outputs kept
fuzz.py minimise DIR/SEED               # snapshots at sync, divergence - 1, divergence; snapdiff.txt
fuzz.py scan DIR/SEED --range LO:HI     # first frame each EE word in LO:HI differs
fuzz.py watch DIR/SEED --at F --addr A  # port under gdb: who writes A around port frame F
```

`run` appends one JSON line per seed to `DIR/results.jsonl` and skips seeds
already there, so it resumes after a stop.  Each line records the port
binary (`port`, the resolved path: point `--port` at a symlink and repoint
it between fixes; running pairs keep their binary).  A seed that does not
match keeps `DIR/SEED/` (script, logs, the two diverging records,
`repro.txt`, `result.json`).  A pair costs about one core for the oracle
(25-40 frames/s when the machine is busy) plus a little for the port; on 4
cores `--jobs 3` does about one scenario a minute.

Root-causing a divergence, in the order that worked:
1. `result.json` / `report`: the first differing field (`player[i]+0xOFF`
   is EE `0x004F20B0 + i * 0x5B8 + 0xOFF`).
2. `minimise` + `snapdiff.txt`, filtered to the player/game region
   (`0x004F20B0..0x004F4500`): is it one word or a cascade?
3. `watch --at PORT_FRAME --addr EE_ADDR`: the port's writes with
   backtraces.
4. The oracle side: `mvc2_oracle --trace ADDR --trace-from F --trace-to F`
   prints `$a0..$a3, $t0, $ra, $v0, $v1` at each block start at ADDR, so
   tracing a call's return address gives the callee's return value.  Oracle
   frame = port frame + (oracle_sync - port_sync) (12 in every run here).
5. The retail code: extract `SLUS_204.86` from the ISO (ISO9660 root
   directory) and `llvm-objdump -d --start-address=… --stop-address=…`
   (LLVM's MIPS target; it shows the EE's `sq` as `ext`).

## Scenario model

Everything follows from the seed (`random.Random(seed)`):
- ARCADE from the title (`state 1/1/1` first, so both sides start the
  script on the same frame; `--resync 1/1/0` sets the rand seed, the game
  RNG `D_004C26AC/B0` and the frame counters at the first frame of 1/1/0).
- P1 team: three of the 56 selectable characters (repeats allowed), each
  with a random assist type, picked through the character select with
  `--p1-team` (the cursor resolves to the forced character; the assist type
  is chosen with down presses in the menu).
- CPU team: three characters with assist types (`--cpu-team ID:T`).
- `--cpu-hp` (none / 40 / 1, weights 6/2/2: short fights reach later
  stages) and `--p1-hp` (none / 60 / 144, 2/3/5: P1 survives longer).
- 2000-4000 frames of input after `until 2/1/2`: walks, dashes, jumps,
  super jumps, blocking, crouching, normals, chains, special motions
  (qcf, qcb, dp, rdp, hcf, hcb, charges, dd), supers, assists, tags,
  variable attacks, snap-backs, throws, mashing, shoulder buttons, idle.

The comparison stops at the first frame whose header (pads, game state,
rand seed, game RNG) or player/game region (`0x004F20B0..0x004F4500`, six
player records and the game block) differs, or when either side exits.
BSS hash blocks (1 KB, `0x004C2580..0x00634380`) that newly differ are
recorded with their first frame but do not stop the run.

## Known false differences

By design, masked or recorded without stopping (see also BOOT_NOTES):
- **35 BSS blocks differ from the first compared frame**: libpad, IOP, SIF,
  sound and GS state the port does not keep.  compare.py lists them once
  and ignores them.
- **Words equal to a host address**: the port's dump writes host pointers
  as EE addresses; a word whose untranslated value equals the oracle's is
  not a difference.
- **The actor area `D_004D3800` (render matrices, VU0 macro code)**: 1-2
  ulp floats from Play!'s VU0 model.  Every fight run makes 15 blocks
  there differ at 2/1/1 (the stage load) and up to ~70 more during the
  fight; no gameplay effect (the player/game region stays identical).
- **The heap above ~0x0163xxxx**: CRI/ADX host buffers, pointers shifted
  by 0x284340.
- **The pad mode byte** (0x79 vs 0x73).
- **BSS blocks outside the actor area that differ in every run** (`0x004CA980`
  and `0x004D3580` from 1/1/1, `0x004CB180` and `0x0058C580` in the
  fight, `0x004F1980`): see "BSS blocks" below.

Not false differences: anything in the header or the player/game region.
Every such difference in this pass was a port bug.

### BSS blocks

Over the matched runs every fight makes the same blocks newly differ; the
ones outside the actor area were followed down to the word with `scan`
(seed 40, all frames to the end of the run) and `watch`:

| Block (first word) | When | What | Verdict |
|---|---|---|---|
| `0x004CA980` (`D_004CAB44..D_004CAB60`), `0x004CA580` (`D_004CA610`, `D_004CAB20`) | 1/1/1 from the first frame; fight loads | DMA / packet bookkeeping: buffer addresses, a host pointer, a counter one apart.  The port's GS/VIF path is the host renderer | by design (hardware layer) |
| `0x004CB180` (`D_004CB1D8+4` etc.) | fight, ~+1300..1700 | the text renderer's scratch quad (`func_0016D4B0`, `src/chA_a.c`): UVs of the last glyph drawn.  The text list it draws (`D_0058CC40`) is identical on both sides; the oracle's copy holds the glyph the port drew one call earlier | render scratch, by design |
| `0x0058C580` (`D_0058C7A0`) | fight | the draw list's heap pointers, shifted by the heap layout | by design (heap) |
| `0x004F1980` (`D_004F1CC8`, `D_004F1D28`) | 1/1/1+7, fight | colour words (0xE1FFFFFF, 0xE0FFFF00): the port writes the oracle's value, but the dump's host-pointer translation (`state_dump.c` `fix()`) takes them for addresses in the host EE heap (mapped near 0xE0000000 on i386) and writes 0x0218533F / 0x01185240.  The player/game region compares the untranslated word too; the hash blocks and `scan`'s extra range do not | dump artifact |
| `0x004D3980..0x004E9D80` (`D_004D3800+…`) | 2/1/1 (stage load) and the fight | actor area, VU0 render matrices 1-2 ulp | known (BOOT_NOTES) |

`fuzz.py` kept the first 40 blocks by address in `new_blocks`, which hid
everything above ~0x004EA000; it now keeps the first 80 by frame.

## Sound commands

The comparison above masks the sound and IOP BSS from the first frame, so it
says nothing about audio. Since the "Sound commands" change to
`dump_format.h`, every record also carries the ordered list of calls the game
made since the previous record into its two sound layers. Every frame's list
must match. A difference stops the run like a region difference, and the
report shows both lists:

```
+2392 port 2846 oracle 2858 state 2/1/2: sound commands port [tsd_status(4, 0x12101), tsd_play(0x12101, -1, 64, -1)]
                                         oracle [tsd_status(4, 0x12101), tsd_stop(0x12101), tsd_play(0x12101, -1, 64, -1)]
```

`fuzz.py --no-sound` and `compare.py --no-sound` turn the check off.
`fuzz.py sanity --seed S --count N` runs the oracle against itself on each
scenario.

**Layers.** Two layers exist at the same EE address on both sides, with the
same arguments. The port replaces them there (`host/tsd_host.c`,
`host/cri.c`). Waveforms are out of scope: Play!'s SPU2 output is not
bit-exact, and the decoders are checked in `AUDIO.md`.

| Layer | Entries (EE) | Recorded arguments |
|---|---|---|
| Tamsoft client (effects, voices) | `422EA0` play, `422FB0` stop, `4230B0` change, `4231D0` stop all TQ, `423240` master volume, `4232C0` cmd77, `423480` load bank, `4235D0` unload bank, `423650` stop all, `4236C0` stereo, `423990` status (fno 4 only) | `$a0..$a3`, `$t0..$t2` up to the entry's count. The bank pointers of load bank are EE addresses (the port's dump `fix()`). |
| CRI ADXT (music) | `402C20` StartAfs, `401868` Stop, `4020D8` SetOutVol, `4026B0` Pause, `402BC0` SetOutputMono | The same, without the ADXT handle: a CRI object on the PS2, a host struct on the port. |

**Oracle hooks.** The oracle records a call only when its `$ra` lies outside
the two libraries (`0x3F5F88..0x411C10`, `0x422BE0..0x423E30`): a call
between library functions is not the game's. The port's replacements are
leaves. The EE leaves garbage in argument registers past an entry's count
(`ADXT_Pause` arrives with `$a2 = FFFFFFFF` or a stale pointer), so those
slots are written as 0. Up to 96 entries per frame are kept, and the count is
compared beyond that. Status fno `0xC` (bank DMAs pending) is not recorded:
`func_001E5870` polls it for as long as a DMA takes, which is many calls on
the PS2 and one on the port.

**Sanity pair.** The oracle against itself gives identical lists, with no
noise to mask before comparing the port: seed 1 (5446 frames, 6781 commands)
and seed 17 (4521 frames, 4262 commands, status queries included).

### Status-gated stops: driver timing, by design

| | |
|---|---|
| Seen | Seeds 15, 17, 23, 29, 31 in the first pass (5 of the first 32 seeds), always as an extra `tsd_stop(X)` on the oracle just before `tsd_play(X)` |
| Code | `func_001E59E0` (`src/fb64_a.c`, `AUDIO.md` 4.1). Before a sound plays, it stops X itself (slot >= 0x1E) or the player's other voice lines (ids 0-5, 10-0x1D), each only if TSD status fno 4 says the slot is still active. |
| Port side | The slot had always just ended. The data's sounds are `E0 E1 E2 note-on, wait, note-off, FF`. `FF` ends the slot once the channel is silent, and release rate 0 makes that one tick after the note-off. The port's lifetime is a fixed number of 240 Hz ticks. The port driver runs exactly 4 ticks per frame (headless: 800 samples a frame). Play! also gives exactly 4 per frame (IOP at EE/8 = 36.864 MHz, timer `0x25800`, 60 Hz frames). |
| Retail side | Calibrated over seven seeds (retail stop or no stop, against the port's lifetime L of the same bank/sound/handle): still active at L+0, L+1 and L+2 ticks, finished at L+2, L+3, L+5 and L+7. The PS2 slot ends about 2-3 ticks later, with about ±1 tick of jitter: the same +2 offset is active in seed 23 and finished in seed 1. |
| Cause | The IOP's timer and the driver threads run free of the EE frame. How many ticks fall between two EE calls in different frames depends on where in each frame the EE reaches the call, which depends on the frame's workload. MODHSYN, stripped and untraced beyond key-on and pitch (`AUDIO.md` 4.4), adds its own delay before it reports a keyed-off channel silent. The port has no cycle timing. |
| Effect | None audible. The stop arrives after the note-off, when the voice is already silent. Slot occupancy differs by a few ticks, which matters only when all 16 slots of a bank are busy (stealing). |
| Verdict | **By design** (host timing model). The port driver is unchanged. Retuning its lifetime to Play!'s +2-3 ticks would not remove the jitter, and Play!'s IOP thread and SIF timing is not hardware. |
| Comparison | `compare.snd_match` excuses a `tsd_stop(X)` present on one side only directly after `tsd_status(4, X)`, the status-gated stop. Anything else still stops the run. Results count the excused races (`n_sound_races`, and `sound_races` with frame, side and id). |

### Results, sound commands (2026-11-05)

Native i386 port, `MVC2_PS2_FLOAT` on, the binary at "oracle: record TSD
status queries", with sound comparison on.

| Run | Frames compared | Sound commands | Status-gated races | Result |
|---|---|---|---|---|
| `fuzz.py run` seeds 1-60 (56 characters, 474 P1/CPU pairs) | 282,768 (199,028 fight) | 305,784 | 11 (9 seeds, at most 2 each, all on the oracle side) | 60 / 60 match |
| Arcade seeds 1000001-1000004 (whole runs, stages 4, 6, 6, 6) | 79,955 | 74,250 | 4 | 4 / 4 match |
| `fight_mix.txt` | 7,535 | 11,576 | 0 | match |
| Attract cycle (63 `ADXT_SetOutVol` fades) | 4,835 | 1,790 | 0 | match |
| `training_start.txt` (48 pause-menu `ADXT_Pause`) | 4,535 | 279 | 0 | match |
| **Total** | **379,628** | **393,679** | **15** | **all match** |

Before the race rule, the first pass on the same binary stopped 5 of the
first 32 seeds (15, 17, 23, 29, 31) at a status-gated stop. No
other kind of sound difference was seen. The port's sound-command layer
needed no fix: every command, argument and bank pointer, and its frame,
matches the retail game.

## Results (2026-11-04/05, branch port-fuzz-run)

Native i386 port, `MVC2_PS2_FLOAT` on, Linux x86-64 (4 cores, `--jobs 3`),
oracle at the pinned Play! commit.  The port was rebuilt after each fix;
`results.jsonl` records the binary each seed ran on (v0 = the branch as
started, v9 = the final one).

| | |
|---|---|
| seeds run | 416 (1-416) |
| frames compared | 1,943,285 (1,361,541 in fights) |
| characters / P1-CPU pairs | 56 / 2,098 |
| `--cpu-hp` none / 40 / 1 | 222 / 97 / 97 |
| matched to the end | 406 |
| diverged | 7 (seeds 5, 8, 40, 53, 79, 83, 240) |
| port crashed (SIGSEGV) | 3 (seeds 19, 24, 39) |
| oracle failures, no-sync | 0 |
| v8/v9 (the last ~314 seeds) | 1 divergence (240), fixed |

Regression check on the final binary (v9): seeds 1-45 again (they ran on
v0-v6 the first time and include 5, 8, 19, 24, 39, 40), 45 / 45 match,
210,805 frames; seeds 53, 79, 83, 240 match; `fight_mix.txt` 7535 / 7535
and the attract cycle 4835 / 4835 frames identical.

### Divergences

| Seed (binary) | First difference | Cause | Fix | Re-run |
|---|---|---|---|---|
| 5 (v0) | player[5]+0x1C: 0xB73F vs 0x1F, +2115 | `jtbl_004BFBB8` entry 24 (0x004BFC18) is `D_004BFC18`, the s16 pair (0x20, 0x30) that `func_001F1F60` (`sa12_j.c`) loads as a timer; credited as `func_00300020`, the host stored a host code address (low half 0xB740) | R10 override: the literal word | v2: next divergence (53's) |
| 8 (v0) | player[1]+0x460: 0x0F vs 0x0E, +3412 | `func_00164C50` (script opcode 38) falls off the end after `func_00164E90`; the EE returns that call's 1, so `func_00169600` steps again in the frame; R14 returned 0.  `gen_returns.py` left it because of the explicit early `return 0` | R24: call + explicit `return N;` constants is return-last (`gen_returns.py`; also `func_003B8170`) | v2: match |
| 19 (v1) | SIGSEGV at +3080 in `func_003BC870(p = 0xA)` | `D_004C20B8[p[4]]()` in `func_003BC820`: $a0..$a3 still hold the caller's arguments at the jalr; the C passes none | `r12_indirect.csv` row | v2: match |
| 24 (v1) | SIGSEGV at +3067 in `func_00178F20(owner = 0x2)` | `func_002F6760` reuses its parameter `p` as a byte; R12 passed `p` for `$a1`, which the asm says is the entry value | R12: pass `v__arg` (R19's copy of the entry value) when the C writes the parameter (16 sites changed) | v4: match |
| 39 (v2) | SIGSEGV at +2899 via `func_001A2050(p, q = garbage)` | `(*(void (**)(u8 *))(D_0044AFF0 + …))(a0)` in `func_001A1FC0`: $a1/$a2 are the C's locals a1/a2 at the jalr | override; then all five cast-form table calls checked against the retail table entries (`wave7.c`, `wave1x.c` also fixed) | v4: match |
| 40 (v2) | player[1] hit state (+0x164 …), +2467 | not separate: fixed by the v3-v4 changes | - | v4: match |
| 53 (v3), 5 (v2) | player[0]+0x1B4 / +0x210 (bytes 0x1B7, 0x211), Storm | `func_002D92E0` passes `&v` (a u16 local) to `func_0018A990`, which reads `*(u16 *)(q + 6)`: on the EE the caller's saved `$s0` upper half (0); on the host stack garbage | override: a 4-halfword buffer with 0 at +6 | v5: match (both) |
| 79 (v6) | player[4]+0x34: 0xC41D9EEE vs 0xC41D9EEF (1 ulp), +4428 | `func_002271E0` reads `D_004517C0[p[0x151]]` (8 floats) at index 16; words 8..63 are jump-table code addresses = denormals on the EE, flushed to 0; on the host a host code address is a normal ~1e-34 and the round-toward-zero add moved x | override: indices 8..63 read 0.0 | v8: match |
| 83 (v6) | player[1]+0xF8: 1 ulp, +2511 | projected screen depth, VU0 macro matrices (`vu0_macro_math.S`) through the render path; Play!'s VU0 vs the port's | by design: compare.py tolerates 2 ulp at player +0xF0/F4/F8 (`RENDER_WORDS`) | v7: match |
| 240 (v8) | player[4]+0x04 / +0xA8, CPU Storm, +3899 | `func_00185640(a, b)` calls the character handler `*(a + 0x43C) + 0x28` with $a1 = b; Storm's `func_002E3920(p, q)` writes q | override; then every `+0x43C` handler call checked against the 53 per-character tables | v9: match |

Found by scanning, not (yet) by a seed: `jtbl_004C1BF0` entries 6-7 are
`D_004C1C08[4]` (s16 speeds, `residual_00361A00`); `wave7.c` and
`wave1x.c` cast-form table calls without their register arguments.

### Classes

- **Data credited as code** (seeds 5, 79; `jtbl_00475ABC` in the oracle
  pass): a word in a jump table that is really data, or a data table read
  past its end into one.  The host keeps host code addresses there.  Scan
  used: entries of `src/data/*` tables that a TU also declares as sub-word
  data (`s16`/`u8`/`f32` …); 15 candidates, 2 real.
- **Register arguments the C does not pass** (19, 24, 39, 240): indirect
  calls with fewer arguments than the entries read, and the C reusing a
  parameter as a local.  Scans used: the five cast-form table calls and the
  ~30 character-handler calls, against the retail tables.
- **Return values** (8): R24 now covers call + explicit-constant returns.
- **EE stack contents** (5, 53): a read past a local into the caller's
  frame.

### Open (after the first pass; see "Second pass" for what was closed)

- `n5.c:304`: closed in the second pass (the EE's $a1 is the object just
  allocated).
- `r12_returns.csv` / `r12_indirect.csv` hand edits: closed (regenerated
  against the retail asm, identical rows).
- Coverage beyond stage fights: closed for the arcade path (arcade
  scenarios reach Abyss and the end of the run); menus other than the
  arcade path (training, shop, options, versus) are still not in the
  scenario model.

## Second pass (2026-11-05)

### Build and tables

- **emsdk 6.0.13** (`/home/user/emsdk`) for the signature scan, as the
  earlier passes had: the stubs' signatures come from emcc and the C
  library gets real prototypes (21 functions).  `build/port-i386-em`.
- **Retail asm.** `asm/main.s` split from the private inputs' ELF (identical
  to the disc's `SLUS_204.86`) with splat 0.50 and a de-duplicated copy of
  `config/symbol_addrs.txt`: 236 addresses there carry two names and splat
  rejects that, on `main` too.  The R12 generators then reproduce the
  first pass's hand-edited rows exactly and add: `D_004C20C0[..]()` in
  `func_003BCAE0` (`wave1b.c`, the twin of seed 19's call) and the
  `func_00197560` register pass-through for four callers.  Not applied: a
  `(float, float)` widening of the soft-float compare wrappers
  `func_00100240..` (they take doubles) and the differences that only come
  from the de-duplicated names.
- Seeds 1-45 on the emsdk build: 45 / 45 match, 210,805 frames.

### Arcade scenarios

Seeds from 1,000,000 are whole ARCADE runs (`scenario_arcade`: the team
pick, then per stage random input and a ~1200-frame attack mash with
start/cross presses; CPU 1 HP, P1 144).  The game stays in 2/1/2 across
stages, so `stages` in a result is the stage counter `0x004F4385`; seeds
from 1,000,100 run 22 stage blocks (~36,500 frames), enough for Abyss and
the end of the run (2/1/4 Abyss beaten, 2/1/5, 2/1/6, then the title).

| Seeds | Frames compared | Result |
|---|---|---|
| 1000001-1000009 (12 blocks) | ~20,000 each | 8 match, 1000005 diverged (pause menu, below) and matches after the fix |
| 1000100-1000108 (22 blocks) | ~35,000 each | 8 match; 6 reach Abyss and the end of the run; 1000100 crashed at stage 7 (below) and matches after the fix (36,109 frames) |

### Sound requests

The second pass first compared sound with a text trace: `MVC2_SOUND_TRACE=FILE`
on the port (`port/host/sound_trace.c`) and the oracle's `--trace` on the same
entry points, recorded in the result without stopping the run.  Seed 3
matched (1652 / 1652 requests), and so did arcade seed 1000100 (10,057 / 10,057 over
36,109 frames).  Seeds 15, 17 and 23 showed the status race.  That
comparison is replaced by the per-frame records of "Sound commands" above,
which stop the run on a difference and excuse only the status-gated stop.
The port's `MVC2_SOUND_TRACE` is kept as a debugging aid; `fuzz.py` no
longer traces the oracle's sound entries.  A one-tick start delay for new TQ
slots (`MVC2_TSD_DELAY`) was tried and reverted: the port's sound driver is
unchanged.

### Fixes in the second pass

| Found by | Cause | Fix |
|---|---|---|
| arcade 1000005 (g+0x5C / g+0x91 after the pause menu) | `func_003D6530`, the pause menu's COMMAND LIST page, has no credited C: the port linked an empty generated stub | `port/host/pause_menu.c`: the retail code in C |
| (same check) | `func_003F5630` (byte copy) and `func_003F5710` (memmove) were empty generated stubs too: the last three code-less functions | `port/host/game_copy.c` |
| arcade 1000100 (SIGSEGV at 0x0037E0A0, stage 7) | `jtbl_004C1D18` starts inside `data_u32_004C1D10`, credited as 16 bytes: entry 0 stayed the raw EE address | override: 8 bytes + two function pointers; every `jtbl_` alias inside a non-table object checked |
| `n5.c:304` (open item) | handler +0x64 gets $a1 = the object func_0015F8D0 just allocated (or 8 when the pool is empty) | override passes the free-list head read before the call |
| regenerated R12 tables | `wave1b.c` indirect call, `func_00197560` pass-through | table rows |

