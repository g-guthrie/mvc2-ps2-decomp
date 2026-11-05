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
  scenarios reach Abyss and the end of the run, and walk into the pause
  menu's pages); training, shop, options and versus are still not in the
  scenario model.
- `func_00391990` (`h12.c`) calls `D_00471BF0[p[5]]` with $a1 = a stale
  stack address left by `func_00174470` (its `projected[]` buffer); four of
  the entries read it.  The EE value is a dead frame's contents: not
  reproducible, not seen in a run.
- Sound: the status-gated stop race (seeds 15, 17, 23, 1000111) is handled
  on the "Oracle fuzz: compare sound commands with retail" branch.

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
| 1000110-1000127 (22 blocks) | 635,662 in all | 18 / 18 match (final fixes); 12 reach Abyss and the end of the run; 1000112 crashed at stage 6 on the earlier binary (below) |

The arcade scripts' `start` presses sometimes open the pause menu and the
mash then walks it: COMMAND LIST (seed 1000005), BUTTON CONFIG with the
buttons remapped (1000108, which then never leaves the first fight).  Those
runs match too, so the pause menu and its pages are covered as well.

Final branch head (`491a7cf5`, with run-ahead and the streamlined options
merged from main; run-ahead is off under `MVC2_STATE_DUMP`): seeds 1-6 and
arcade 1000005 match, sound requests identical.

### Sound requests

The PCM is not comparable (the port replaces the IOP sound driver and the
ADX player), but what the game asks for is.  Every call from game code into
the Tamsoft driver (play, stop, change, master volume, banks, stereo, queue
reset) and the ADX streamer (StartAfs, Stop, SetOutVol, Pause, mono) is
compared frame by frame with its non-pointer arguments:
`MVC2_SOUND_TRACE=FILE` on the port (`port/host/sound_trace.c`), `--trace`
on the same entry points on the oracle, minus calls whose return address is
inside the CRI (`0x003F5F88..0x00411C10`) or Tamsoft
(`0x00422BE0..0x00423E30`) libraries.  A sound difference is recorded in
the result (`sound`: counts, first differing frame) and does not stop the
run.  The status queries (`func_00423990`) are logged on the port as well.

Seed 3: 1652 / 1652 requests, identical in every frame; arcade seed
1000100: 10,057 / 10,057 over 36,109 frames.  Seeds 15, 17 and 23 show the
known status race: the game stops a sound before replaying it on one side
only, because its is-active query (`func_00423990`, fno 4) is answered on
the PS2 by the IOP driver on its own free-running 240 Hz timer, about one
tick off from the port's frame-driven driver, near the end of a sound's
silent release tail.  How the comparison treats that (and the
pending-loads query, fno 0xC) is settled on the separate branch
"Oracle fuzz: compare sound commands with retail"; this branch keeps the
plain request comparison so the two can be reconciled at merge, and makes
no change to the port's sound driver.

### Fixes in the second pass

| Found by | Cause | Fix |
|---|---|---|
| arcade 1000005 (g+0x5C / g+0x91 after the pause menu) | `func_003D6530`, the pause menu's COMMAND LIST page, has no credited C: the port linked an empty generated stub | `port/host/pause_menu.c`: the retail code in C |
| (same check) | `func_003F5630` (byte copy) and `func_003F5710` (memmove) were empty generated stubs too: the last three code-less functions | `port/host/game_copy.c` |
| arcade 1000100 (SIGSEGV at 0x0037E0A0, stage 7) | `jtbl_004C1D18` starts inside `data_u32_004C1D10`, credited as 16 bytes: entry 0 stayed the raw EE address | override: 8 bytes + two function pointers; every `jtbl_` alias inside a non-table object checked |
| `n5.c:304` (open item) | handler +0x64 gets $a1 = the object func_0015F8D0 just allocated (or 8 when the pool is empty) | override passes the free-list head read before the call |
| regenerated R12 tables | `wave1b.c` indirect call, `func_00197560` pass-through | table rows |
| arcade 1000112 (SIGSEGV in func_0035D2A0, p = NULL) | `((void (*)(void))D_004C1B60[a[5]])()` in `func_0035D240`: the wrapped-cast form of the missing-argument class, which the first pass's scan did not match | override passes $a0/$a1; scan of every `((T (*)(..))TABLE[i])(..)` call: `func_0019A560` (D_0044A7B0, $a1 = q) fixed too |

