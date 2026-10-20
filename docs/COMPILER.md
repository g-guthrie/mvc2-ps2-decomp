# MVC2 PS2 MWCCPS2 compiler probe

Source-safe, reproducible compiler-in-the-loop notes. This directory contains
no compiler binary, game binary, SDK file, or extracted game asset.

## Strongest current identification

- Target ELF comment: `MW MIPS C Compiler (2.4.1.01)` / `PlayStation2`.
- Candidate `mwcps2-3.0b38-030307` emits `(3.0.0)` and is excluded.
- Candidate archives 2.4, 3.0, 3.0.1, and 3.0.3 all emit `(2.4.1.01)`.
- The target executable's ISO timestamp is `2002-09-12 04:27:28`.
- The target function at `0x00102548` contains the two consecutive short-loop
  scheduler padding nops characteristic of `mwcps2-3.0.3-020716`. The same
  loop probes compiled by 2.4, 3.0, and 3.0.1 omit them.

Therefore `mwcps2-3.0.3-020716` is the best-supported product build. This is a
strong narrowing, not yet a proof from an exact nontrivial function match.

## Flags

Target scheduling and filled return delay slots require optimization level 3
or above. The isolated-probe baseline is:

```text
-c -lang c -O3 -sdatathreshold 0
```

`-O4,p` produces the same code for the smallest probes and remains a live
translation-unit-level alternative.

`-sdatathreshold 0` is only used here so undefined probe symbols are not
classified as small data. It is **not** established as the retail setting.
The target uses many `%gp_rel` small globals, and this compiler documents 8 as
its default threshold, so the actual project baseline should retain default/8
until translation-unit evidence narrows it.

## Public tool inputs

- Compiler archives: the `compilers` release of `decompme/compilers`.
- Wibo 1.2.0: `decompals/wibo`.

Example setup (paths shown only; do not commit the extracted compiler):

```sh
curl -L https://github.com/decompme/compilers/releases/download/compilers/mwcps2-3.0.3-020716.tar.gz | tar xz -C "$PRIVATE_COMPILER_DIR"
curl -L -o "$PRIVATE_TOOL_DIR/wibo-macos" https://github.com/decompals/wibo/releases/download/1.2.0/wibo-macos
chmod +x "$PRIVATE_TOOL_DIR/wibo-macos"
MWCIncludes="$PRIVATE_COMPILER_DIR" "$PRIVATE_TOOL_DIR/wibo-macos" \
  "$PRIVATE_COMPILER_DIR/mwccps2.exe" tools/probes/real.c \
  -c -lang c -O3 -sdatathreshold 0 -o probe.o
```

## Current function evidence

Seven global-address getters have exact 12-byte C reconstructions (84 bytes):

```text
0x00100468 -> 0x00438190
0x00105F48 -> 0x004C3AD8
0x0011C960 -> 0x004AC870
0x00406430 -> 0x0062FD48
0x0040AED8 -> 0x00489020
0x0040CB20 -> 0x004895D8
0x0040CB90 -> 0x004896E0
```

For example:

```c
extern unsigned char D_00438190[];
void *func_00100468(void) { return D_00438190; }
```

All four candidate compilers at O3 emit
`lui v0,%hi(sym); jr ra; addiu v0,v0,%lo(sym)`, with `R_MIPS_HI16` at +0 and
`R_MIPS_LO16` at +8. Resolving `sym=0x00438190` gives the target bytes exactly.
This is a 100% instruction-and-relocation match, though not a version
discriminator.

An additional generated leaf batch contributes 395 exact functions and 3,160
bytes under MWCCPS2 3.0.3 with `-O3`: 247 empty stubs, 53 zero returns, 12
immediate returns, 57 field getters, 20 field setters, and 6 byte zeroers.
Every function is independently compared with the retail loaded image by
`make match`.

A second straight-line batch contributes 177 exact functions and 3,396 bytes:
153 byte-counter increment/clear-field leaves, 12 byte-counter increments, and
12 paired-word stores.

A relocation-aware tail batch adds 631 functions and 5,600 bytes; 54 indirect
table dispatchers add 1,728 bytes with reviewed HI16/LO16 table relocations; 19
GP-relative dispatchers add 532 bytes; and 430 signed-result handlers with real
stack/control flow add 25,800 bytes. Six further exact batches add sequential
calls, reset-on-negative handlers, and 2,077 boundary-split dispatcher heads
while retaining every residual assembly byte. The cumulative checkpoint is
3,905 functions and 113,908 bytes.

`0x00102C58` target words:

```text
lw v0,0(a0); sw a1,0(a0); srl v0,v0,8; jr ra; andi v0,v0,1
```

The natural unsigned C probe at O3 emits the identical five instructions but
orders the middle pair as `srl; sw`. It is 3/5 exact by instruction position
(60%) and is not counted as matching C.

Private scratch artifacts include locally downloaded compiler binaries and must never be copied into this public repository.

## Object-list loop scheduling

`src/object_pool.c` uses MWCCPS2 3.0.3 with `-O3 -Op -sdatathreshold 8`.
The `-Op` speed preference reproduces the otherwise missing loop-exit nop
in `func_003DA9D0`; ordinary `-O3` emits 100 bytes rather than the retail
104. All seven functions in the unit match with the selected flags, including
the six previously recovered allocation, release, and insertion routines.

## Deferred animation setup

The sixteen handlers in `src/deferred_move_setup.c` match with MWCCPS2
3.0-011126 and `-O3 -sdatathreshold 8`. MWCCPS2 3.0.3 emits an additional
instruction for the recovered selection/reset sequence. Each handler keeps
retail's initialization only for selector values 0, 1, and 2; no defensive
default assignments have been inserted into the matching source.

## Animation record management

All four functions in `src/animation_frames.c` match with MWCCPS2 3.0.3
and `-O3 -Op -sdatathreshold 0`. The indexed seek needs the speed preference
to reproduce its final sprite-selection scheduling; the other three routines
remain exact with the same flags. The five-word record copy uses four float
word transfers followed by the final word, preserving packed control bytes.

## Shared animation records and strict bounds

The four animation record routines use MWCCPS2 3.0.3 with
`-O3 -Op -sdatathreshold 0`; the speed preference reproduces indexed seek
scheduling while retaining all other exact matches in the unit.
The two additional scale handlers use strict `index > last_frame` checks.
Equivalent `index >= frame_count` checks use a different comparison scratch
register and do not match their retail instruction encoding.

## Floating callback constants

`src/float_callbacks.c` uses MWCCPS2 3.0.3 with `-O4 -Op -sdatathreshold 0`.
All 26 wrappers match their immediate floating constants, data addresses,
integer arguments, and tail calls. `-O3` instead emits literal-pool loads.

Eighteen effect callbacks in `effect_state_callbacks.c`,
`effect_followup_callbacks.c`, and `effect_choice_callbacks.c` reproduce
1,280 retail bytes with MWCCPS2 3.0.3 and `-O4 -Op`. The state and follow-up
units use `-sdatathreshold 0`; the choice unit uses threshold 8 for the
GP-relative threshold counter. The state callbacks copy the signed shared
state plus 17 into an effect variant byte before dispatch. Choice callbacks
preserve both branches, including the callback whose branches use the same
effect object, to reproduce the retail control flow exactly.

The new input gates, relative record walks, interpolation, and animation
position families use MWCCPS2 3.0.3 -O3 -Op with small-data threshold 0.
Other recovered motion and owner-state handlers use -O3; constant fade
and displacement handlers use -O4 -Op. The conditional animation updates,
accepted interaction resets, and owner-latch families require 3.0-011126
-O3 for their return scheduling. Shared phase globals use threshold 8.
The build script records each source's verified choice.

Three wrapped degree phases establish the software double helpers fptodp,
litodp, dpmul, dpdiv, dpadd, and dptoul at their cataloged retail addresses.
A local double temporary preserves conversion before constant materialization;
-O3 -Op compiles the degree-to-fixed-turn formula and signed modulo exactly.
A one-case switch preserves the retail entry control flow.

`mode_stance_move_setup` and `child_owner_stance_dispatch` use MWCC 3.0.3 `-O3 -sdatathreshold 8`. `live_interaction_stance_gates`, `free_slot_interaction_commits`, `selected_target_interactions`, and `live_target_selection` use MWCC 3.0 `-O3 -sdatathreshold 0`. Nested final guards preserve the selector's shared zero-return branch; each variant preserves its original byte-store order.

`linked_parameter_child_spawns` and `owner_angle_child_spawns` use MWCC 3.0.3 `-O3 -sdatathreshold 0`; `uniform_key_motion_steps` adds `-Op`. Use the strict greater-than frame bound to retain the retail AT-register comparison, and preserve each variant's copied byte/angle offsets.

`live_interaction_phase_commits` uses MWCC 3.0 `-O3 -sdatathreshold 0`; `planar_floor_motion` uses MWCC 3.0.3 with those flags; `directional_target_gates` adds `-Op`. `contact_effect_dispatch` uses MWCC 3.0.3 `-O3 -sdatathreshold 32` to preserve GP addressing for the actual six/four/four-entry callback arrays. Nested direction/stance guards share the retail zero-return path.

`unoccupied_stance_mode_commits` uses MWCC 3.0 `-O3 -sdatathreshold 0`; `owner_stance_animation_waits` uses MWCC 3.0.3 with those flags. The native height clamp formerly in `dupcluster_00191F50` uses a typed partial layout with MWCC 3.0 `-O4 -Op -sdatathreshold 0`; the native fade increment formerly in `dupcluster_00278F50` uses MWCC 3.0.3 with those flags. Both replace assembly placeholders and are now credited only after exact linked-image verification.

`elevated_position_effect_spawns` uses MWCC 3.0.3 `-O3 -Op -sdatathreshold 8`. A typed three-float position copy recovers the retail load/store sequence; `-Op` materializes the height constant directly. All three complete native functions and the linked retail image match.

`preset_vector_effect_spawns` and `preset_position_effect_spawns` use MWCC 3.0.3 `-O3 -sdatathreshold 8`. Typed three-float aggregate copies reproduce the retail grouped loads and stores without guessed register constraints. All eight native functions and the linked image match.

`signed_axis_mode_updates` and `owner_generation_dispatch` use MWCC 3.0.3 `-O3 -sdatathreshold 0`. Two explicit switch cases recover the retail axis-mode comparisons; typed two-argument callbacks preserve the owner argument during generation checks. All six native functions and the linked image match.

`positioned_zero_motion_effects` and `indexed_angle_effect_spawns` use MWCC 3.0.3 `-O3 -sdatathreshold 8`; `owner_planar_offset_spawns` uses `-O3 -sdatathreshold 0`; `stance_flip_launch_effects` adds `-Op` to materialize the launch-position constants. Shared typed effect vectors require `-i src/data`. All fifteen native functions and the linked image match; reconstructed unit-scale and encoded-angle data also match their consumers.

`owner_generation_child_spawns`, `animation_first_floor_commits`, and `owner_two_parameter_spawns` use MWCC 3.0.3 `-O3 -sdatathreshold 0`. `preset_effect_followup_spawns` uses `-O3 -sdatathreshold 8`; assigning the spawn result inside the condition emits the retail return-register check and argument-register copy in its branch delay slot. All thirteen native functions and the linked image match.

`countdown_position_restores` uses MWCC 3.0.3 `-O3 -sdatathreshold 8`; `owner_phase_countdown_gates` uses `-O3 -sdatathreshold 0`. Short countdown expressions preserve the retail truncation and sign-extension sequences; typed two-argument callbacks retain the owner parameter. All six native functions and the linked image match.

The native replacement in `dupcluster_003ABFE0` uses MWCC 3.0.3 `-O4 -Op -sdatathreshold 0`. Computing the opponent height address through unsigned address arithmetic preserves the retail branch-delay member-pointer calculation; ordinary byte-pointer arithmetic folded it into the store offset and did not match. The complete function and linked image match.

The native replacement in `dupcluster_001863F0` uses MWCC 3.0.3 `-O4 -Op -sdatathreshold 0`. Testing the acceleration as a float truth value rather than explicitly comparing it against zero recovers the retail float-register allocation without changing zero or unordered-value behavior. The complete native function and linked image match.

`owner_animation_selector_sync` uses MWCC 3.0.3 `-O3 -sdatathreshold 0`. `global_phase_frame_hooks` and `owner_stance_state_dispatch` use `-O3 -sdatathreshold 8 -i src/data`, sharing explicit no-argument phase and two-argument owner callback contracts with their reconstructed tables. All nine native functions, the six typed tables, and the linked image match.

`side_inhibit_state_dispatch` uses MWCC 3.0.3 `-O3 -sdatathreshold 8`. The byte inhibit mask is explicitly declared in its actual `.bss` section with `__attribute__((section(".bss")))`, keeping absolute address relocations while the two-entry callback arrays remain GP-relative. All three native dispatchers and the linked image match exactly.

`inhibit_owner_phase_gates` uses MWCC 3.0.3 `-O3 -sdatathreshold 0`. Direct references to the global mask let common-subexpression elimination preserve the retail register allocation; a separate cached byte local did not match. `inhibit_state_controls` adds `-Op` to materialize the slowdown factors. Casting the shifted side bit to a byte before merging it reproduces the mask initializer. All five native routines and the linked image match.

`inhibit_owner_motion_sync` uses MWCC 3.0.3 `-O3 -sdatathreshold 8`, with the same explicit ordinary-BSS mask placement as the side dispatchers. Separate early-return and owner-active branches reproduce the retail epilogues; signed byte copies preserve facing and motion flags. Both native routines and the linked image match.

`inhibit_character_state_dispatch` uses MWCC 3.0.3 `-O3 -sdatathreshold 8`, with the side mask declared in ordinary BSS. A cached byte mask retains the retail byte truncation before the side-bit test; the explicit fallback return preserves the shared epilogue. The complete native routine and linked image match.

`linked_child_list_destroy` and `fixed_entry_updates` use MWCC 3.0 (`011126`) `-O3 -sdatathreshold 0` with `#pragma padloop on`. This compiler setting reproduces the retail padding before loop backedges: one NOP after a variable-bound comparison, two after a fixed-bound comparison. MWCC 3.0.3 did not reproduce those padded loops with the same pragma. Explicit guarded do-while loops and index declaration order recover the destruction loops without inline assembly. All twenty-one native routines and the linked image match.

`entry_group_updates` uses MWCC 3.0 `-O3 -sdatathreshold 0` with `#pragma padloop on`. This setting also retains the entire two/three-argument call setup inside each backedge, even when no extra padding instruction is needed. The mode-filtered loops explicitly narrow the input to a signed byte and pass its promoted integer value to helpers. All three native routines and the linked image match.

`indexed_owner_child_spawns` uses MWCC 3.0 `-O3 -sdatathreshold 0`. The two/eight/ten-child do-while loops use `#pragma padloop on`; the four-child byte-counter for-loop uses `padloop off` to retain the retail test and exit on allocation failure. Typed callbacks and owner pointers recover the stored object relationships. All four complete native routines and the linked image match.

The side-inhibit callback tables share `mvc2_side_inhibit_callbacks.h` with `side_inhibit_state_dispatch`; the consumer now adds `-i src/data`. The table objects use typed two-argument function pointers and preserve the dispatchers' small-data accesses. All table bytes, relocations, consumers, and final image match.

`owner_facing_animation_gate` and `owner_generation_parameter_spawns` use MWCC 3.0.3 `-O3 -sdatathreshold 0`. `owner_state_snapshot` uses MWCC 3.0 with `#pragma padloop on`; declaration order and separate pointer initialization reproduce its 49-word copy loop. `fixed_launch_effect_initializers` uses MWCC 3.0.3 `-O3 -Op -sdatathreshold 0`, with a two-float offset array explicitly aligned to 16 bytes, as observed in the retail stack frame; its helper reads only those two floats. All nine native functions and the linked image match.

Owner-generation callback tables share `mvc2_owner_generation_callbacks.h` with `owner_generation_dispatch`, which now adds `-i src/data`. Their four-entry two-argument contracts are supported by the exact native dispatchers and owner-consuming callback bodies. All data relocations, consumers, and linked bytes match.

`owner_substate_animation_entry` uses MWCC 3.0.3 `-O3 -sdatathreshold 0`. Keeping the owner and embedded substate pointers explicit reproduces the retail callee-saved registers and the substate-address calculation in the animation call's delay slot. All four native routines and the linked image match.

`positioned_timed_effect_spawns` uses MWCC 3.0.3 `-O3 -sdatathreshold 8`. The context pointer receives its retail GP-relative relocation; typed three-float position copies reproduce the grouped FPU loads/stores. All three native routines and the linked image match.

`positioned_unit_scale_spawns` uses MWCC 3.0.3 `-O3 -sdatathreshold 8`. Typed three-float position copies and shared unit scale reproduce the retail loads, stores, and GP-relative context access. All three native routines and the linked image match.

## SN runtime compiler identification

The early runtime accessor at `0x0011B370` and signed absolute-value routine
at `0x00119D88` both reproduce exactly with SN GCC 2.95.2 (SN BUILD v2.73a),
`-O2 -G0 -ffunction-sections`, using its original assembler with `-G0`. Metrowerks 2.4, 3.0, and
3.0.3 accessor probes selected `$at` instead of retail `$v1`; SN selects `$v1`
and reproduces the complete relocated accessor. This proves those two units'
compiler recipe, not the compiler identity of every nearby function.

The compiler, preprocessor, and assembler come from
[the archived toolchain](https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_2.0/tree/f0146c8107a8ed5cf7d5bac1ae2db29151947adb),
paths `usr/local/sce/ee/gcc/lib/gcc-lib/ee/2.95.2/{cpp,cc1}.exe` and
`usr/local/sce/ee/gcc/bin/ee-as.exe`. The owner-authorized public input bundle
now includes these three files with pinned hashes. Bootstrap smoke-tests the
preprocessor/compiler/assembler chain and exports `SNCPP`, `SNCC1`, `SNAS`.
Use the preprocessor before invoking `cc1`; direct `cc1` input must already be
preprocessed, including removal of C comments.

SN units use `-ffunction-sections` to retain independent section ownership in
the hybrid linker. This leaves the verified function instructions unchanged.
## SN Systems GCC runtime accessors

Twelve runtime-global accessors at `0x0040A2A8`, `0x0040A2B8`, `0x0040A2E8`,
`0x0040CBA0`, `0x0040CBB0`, `0x0040CBC0`, `0x003FD8E0`, `0x00408608`, and
`0x00408618`, `0x00408790`, `0x0040B3A0`, and `0x00409AC8` match with SN Systems GCC 2.95.2
`-O2 -G0 -ffunction-sections`
and its assembler `-G0`. Separate function sections keep the scattered
retail entries independently placeable in the hybrid link. Their non-volatile
global accesses place the store or load in the `jr`
delay slot. The signed-byte accessor at `0x00408608` requires a signed global
type. Volatile declarations prevent this scheduling and do not match. The
target addresses are `D_00489018`, `D_0048831C`, `D_004895D0`, `D_004895D4`,
`D_0047B580`, `D_004872F1`, `D_00487324`, `D_004872F2`, `D_004891AC`, and
`D_004891B0`, `D_00488314`, and `D_00488318`; all twelve relocated objects
compare byte-for-byte with retail.

Five indexed-field accessors at `0x003FF5F0`, `0x00404CA8`, `0x004052F8`,
`0x00405308`, and `0x0040EE98` also match with SN Systems GCC 2.95.2
`-O2 -G0 -ffunction-sections`. The two routines that keep the scaled index in
`a1` express the 32-bit address addition in index-first order; the others use
byte-pointer arithmetic. Each complete object matches its retail bytes.

Seven compact runtime helpers at `0x00400B98`, `0x00400BB8`,
`0x00400CE8`, `0x00408EC8`, `0x004052C0`, `0x004044B0`, and `0x0040C070` match with SN Systems GCC 2.95.2
`-O2 -G0 -ffunction-sections`. The first copies two word fields to caller
outputs and returns 1; the second writes two fields and returns 1; the third
scales an input into the fifth word; the reset helpers clear fields and set
their state bytes, and one conditionally clears its word field when it equals 3.
The signed-byte normalizer returns the sign-extended byte, except it maps
`0x5C` to 47.
Each relocated object matches the retail bytes.

Two indexed pointer-table readers at `0x0040EF70` and `0x0040EF88` return
adjacent fields from the selected object. `0x0040FCE8` writes a field selected
by a combined pair of indices. All three match with SN Systems GCC 2.95.2
`-O2 -G0 -ffunction-sections` and pass full relocated-byte comparison.

## EE GCC 2.96 math-wrapper probe

The Linux `2.96-ee-001003-1` compiler reproduces all seven complete native
wrappers at 0x001173A0, 0x001173B8, 0x001173D0, 0x001173E8,
0x00117400, 0x00117418, and 0x00117430 with `-O2 -G0 -ffunction-sections`.
The compiler emits the retail 64-bit saves and tail jumps, while SN 2.95.2,
SN 2.95.3, and the Sony 2.9 probe emit longer call/return sequences.
GNU R5900 assembly plus relocation-aware comparisons verify all 140 bytes.
The native wrappers forward three double and four float signatures; callees'
register use confirms the argument widths. The seven wrappers are now source-owned and linked. This does not prove
every nearby runtime function's compiler.

Archive: [ee-gcc2.96.tar.xz](https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz)
SHA-256: `0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a`. A separate x86-64 Colima profile `mvc2-probes` runs the
32-bit Linux executable on the Mac, with guest `libc6-i386`; the existing
default Docker context is unchanged. `compile_ee96.py` now provides both native Linux and Mac VM build paths; both
paths reproduce all seven wrapper objects exactly. Bootstrap supplies the
pinned compiler, exports `EE96CC1`, and smoke-tests the compiler/assembler
pipeline.

Six additional EE96 wrappers have supported signatures: five argument-free
32-bit scalar getter/counter forwards and one unsigned state setter.
`ee96_scalar_thunks.c` uses the existing EE96 runner and GNU assembler recipe.
The generic argument-free wrapper experiment remains uncredited; wrappers
with unknown signatures need caller/callee argument evidence before adoption.
Six scalar tail thunks at `0x003FD9A8`, `0x00400ED8`, `0x00400EC0`,
`0x00405100`, `0x00405118`, and `0x0040D568` match with EE GCC 2.96
`-O2 -G0` and GNU as `-EL -march=r5900 -mabi=eabi -G0`. Their targets are
scalar getters, counter updates, or the value-taking state setter at
`0x0040A2C8`; return and argument types follow those target contracts. All
function sections and jump relocations compare exactly with retail.

Six no-argument constant-selection thunks at `0x003FE4F8`, `0x003FE510`,
`0x003FE528`, `0x003FE540`, `0x003FE558`, and `0x003FEAD0` also match with
EE GCC 2.96 and the same assembler flags. Their targets replace `a0` with a
fixed selector before calling the shared state handler; that handler reads
`a0`, ignores the other argument registers, and returns an `s32` status.

Nine EE GCC callback and state thunks at `0x003FE9B0`, `0x003FECF8`,
`0x003FE9C8`, `0x003FED10`, `0x004086B8`, `0x00410F68`, `0x00402818`,
`0x003FEAB8`, and `0x003FE5C0` also match with `-O2 -G0` and the same
assembler flags. The callback dispatchers load their argument from GP-relative
callback state, so they take no arguments and preserve the returned `s32`
status. `0x00402818` and `0x003FE5C0` forward an `s32 (*)(void *)` callback
and its context pointer to state installers; the first wrapper's caller and
the second wrapper's target body establish those roles. `0x003FEAB8` forwards
an opaque context pointer to a handler that passes it to a registered callback.

Three cleanup thunks at `0x00400130`, `0x003FECA8`, and `0x003FEBF8` also match
under EE GCC 2.96. Their target bodies only update global runtime state and
call helpers using global data; neither consumes the caller's argument
registers. The first is directly invoked as a cleanup step.

`func_00400EA8(const char *)` is an EE96 tail thunk to `func_0040ADC8`.
The target passes the input alongside a static string to a byte/word compare
routine and returns its nonzero result, supporting a string-pointer argument.

The EE96 thunk at `0x003FEF90` forwards two signed integer coordinates to the
runtime validator at `0x0040DB10`. Its range checks and global state writes
support the `s32, s32` signature; the relocated jump matches retail.

The EE96 string chain at `0x003FFEF8` and `0x00402C08` forwards a `const
char *` to `0x003F8240` and preserves its `s32` result. That target passes the
string to the native aligned byte/word length routine.

## SD/LD spills with sixteen-byte stack slots (October 18 audit)

Spill width and slot spacing do not establish a unique compiler release.
A controlled, unpatched `-O2 -G0` compile of the same ordinary C input gives:

```c
extern int f(int);
int probe(int x, int y) {
    int a = f(x);
    int b = f(y);
    return f(a) + b;
}
```

| Compiler | Saved s0 / s1 / ra | Stack offsets |
| --- | --- | --- |
| SN 2.95.2 v2.73a | sq / sq / sq | 0 / 16 / 32 |
| SN 2.95.3 v1.36 | sq / sq / sd | 32 / 16 / 0 |
| Sony 2.9-ee-991111 | sd / sd / sd | 0 / 16 / 32 |

The corresponding loads use lq or ld. Thus Sony 2.9 reproduces the claimed
SD/LD sixteen-byte-slot pattern natively. This disproves the inference that
only an unavailable later SN release can produce it. It does not establish
that all claimed 196 functions were built with Sony 2.9; that count and the
original opcode-substitution experiment have not been independently reproduced.
Changing SQ/LQ opcodes in a compiled object is a diagnostic, not matching C
credit. Compiler output must match without such substitutions.

Both additional tools were downloaded from the decomp.me compiler archive,
checksum-verified, extracted under ignored private inputs, and executed through
wibo. They require no change to the existing default build environment:

- [SN 2.95.3 v1.36 archive](https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.3-136.tar.gz),
  SHA-256 `3b6ae6897229ad005aaf1b0afaa1f3cb46e74b4c21a42e01130c07c0c598067f`.
  Extract into `private/toolchain/compilers/sn-gcc-2.95.3-136`;
  backend `lib/gcc-lib/ee/2.95.3/cc1.exe`.
- [Sony 2.9-ee-991111 archive](https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111.tar.gz),
  SHA-256 `9ebbb042eb1e5d33d772293c5e9286a54dbec29865a3d7fbb398c97436f33583`.
  Extract into `private/toolchain/compilers/ee-gcc-2.9-991111`;
  backend `lib/gcc-lib/ee/2.9-ee-991111/cc1.exe`.

For a preprocessed input `probe.i`, invoke either backend with:

```sh
"$WIBO" "$COMPILER_CC1" probe.i -O2 -G0 -quiet -o probe.s
```

A first Sony 2.9 probe of retail `func_001023C8` reproduced the SD/LD
sixteen-byte layout and exact 92-byte size but differed at +0x28 in branch
layout. It remains uncredited; the spill result alone is not a whole-function
match. No executable or instruction substitutions are part of this audit.

### Reproducible Sony setup and candidate audit

After the existing private-input bootstrap, run:

```sh
. private/build.env
"$PYTHON" tools/setup_sony29.py
. private/sony29.env
"$PYTHON" tools/probe_sony29.py
```

The installer downloads the checksum-pinned archive above, preserves different
existing tools, smoke-tests the actual SD/LD sixteen-byte spill layout, and
writes only the optional `EE29CC1` export to `private/sony29.env`. It does not
replace `private/build.env`, Metrowerks, SN GCC, or EE GCC 2.96. `--archive PATH`
uses a local copy of the same pinned archive.

The probe tool writes `build/sony29-probes/report.json`. Its default inventory
is conservative: at least two distinct SD saves of callee-saved registers or
RA to contiguous sixteen-byte stack slots within the first 32 instructions,
before the first direct jump/call. This scan is not the unprovided original
196-function list. Supply that list as a CSV with `name,address,size` using
`--inventory PATH` to test that exact inventory instead. Every candidate is
reported, including those without C definitions. Available source definitions
are compiled with unmodified Sony GCC `-O2 -G0` and `-O2 -G8`, assembled with
SNAS, and compared as complete relocated function spans. Neither instruction
patches nor new matching credit are applied by this tool. An exact probe must
be isolated into an appropriate source/build unit and reverified before credit.

For a registered source unit using this compiler, use the optional environment
variable explicitly and verify the resulting object as usual:

```sh
: "${EE29CC1:?run tools/setup_sony29.py and source private/sony29.env}"
"$WIBO" "$SNCPP" -P src/UNIT.c build/matching/UNIT.i
"$WIBO" "$EE29CC1" build/matching/UNIT.i -O2 -G0 -ffunction-sections -quiet -o build/matching/UNIT.s
"$WIBO" "$SNAS" -G0 -o build/matching/UNIT.o build/matching/UNIT.s
"$PYTHON" tools/verify_object.py build/matching/UNIT.o private/SLUS_204.86.rom --source src/UNIT.c
```

The complete 72-byte `func_00102A08` in
`src/runtime_flag_reset_00102a08.c` is another verified control for this
layout. The unmodified compiler emits `sd s0,0(sp)` and `sd ra,16(sp)` in
a 32-byte frame and reproduces every retail instruction with the production
recipe above. A later unavailable SN release is therefore not required for
this function. This result does not establish the compiler or matching status
of every function with similar saves; those still need whole-span verification.

### First exact Sony 2.9 SDK recovery

`sony29_thread_lifecycle.c` contains two complete native matches using Sony
2.9 `-O2 -G0 -ffunction-sections` and SNAS: `func_0010FF48` (64 bytes) closes
and resets a nonnegative thread handle, and `func_00110770` (68 bytes) registers
its alarm callback with the current thread ID and sleeps. The nested argument
evaluation in the latter preserves the callback across GetThreadId, and the
void final call produces the native tail jump. All save slots and function
bodies match without postprocessing. Whole-object relocation verification
passes for both functions. Full-current-main relinking is a separate gate.

The first two functions were also placed as isolated compiled sections at their
retail addresses, with every other span retained from the target image. That
batch link produced raw-image SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
packed-ELF SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
This proves these two replacements; it is not a complete-current-main compiler
or linkage run. `docs/SONY29_CANDIDATES.csv` preserves the 173-span conservative
inventory used by the audit. Its remaining spans need C recovery before they
can receive a source/compiler comparison.

`sony29_interrupt_state.c` adds the complete 92-byte `func_0010E670`:
a guarded state replacement preserves the old value while conditionally
restoring the prior interrupt state. Unpatched Sony GCC O2/G0 and SNAS reproduce
all instructions and relocations. A three-span batch link, including the
previous two Sony recoveries (224 bytes total), reproduces the full loaded
image and packed retail ELF with the hashes above. All other spans in this
batch proof remain retail placeholders; it is not a full-main rebuild.

A fourth native Sony match, `func_0010D090` (40 bytes), preserves its scalar
argument across the no-argument synchronization helper and tail-forwards it.
The helper's native implementation consumes no incoming argument registers.
All four new Sony functions (264 bytes) pass complete relocated-object checks
and the isolated four-span image/packed-ELF comparison, without instruction
substitutions. This remains a batch proof, separate from a full-main rebuild.

The fifth new Sony function, `read_rom_version_001004E0.c` (160 bytes),
reads and closes the ROM version file, then converts and compares its version.
It matches unmodified Sony GCC with either G0 or G8; the registered profile
uses G0. Independent recompilation and the isolated five-span link prove all
424 newly recovered bytes and the packed retail ELF. No prior matching
function was duplicated. The rest of main still requires its own full-build
verification; the report/catalog and the five-span proof are different gates.

`update_runtime_mode_state_00101D50.c` adds a sixth complete Sony match
(160 bytes), preserving the previous mode, event registration/removal and
state-parameter updates. Its O2/G0 object was independently recompiled and
compared. The six new functions total 584 bytes; their isolated compiled
sections reproduce the same loaded-image and packed-ELF hashes. This batch
proof does not claim a full current-main compiler rebuild.

### Sony 2.9 variadic argument stream

The two logger wrappers use the target MIPS EABI argument-save layout. With
one named argument, seven eight-byte GP argument slots precede the overflow
stack cursor: `(register_word *)__builtin_next_arg(context) - 7` selects that
save area. The compiler-generated 144-byte frame stores a1 through t3 at
frame offsets 88 through 136; offset 144 is the caller's overflow-argument
area. The native consumer advances by eight bytes, including beyond the
seven saved registers. No manual register binding or opcode rewriting is used.
This agrees with the EABI GP offset computation in the
[GCC MIPS va_start implementation](https://gcc.gnu.org/legacy-ml/gcc-patches/1999-09n/msg00347.html)
and the compiler's documented
[varargs support](https://gcc.gnu.org/onlinedocs/gcc-2.95.3/gcc_17.html).
Whole-object verification covers the actual Sony prologues and forwarding.
The logger's void return declaration is shared by its recovered C callers.

### Internal function-section references

Sony's assembler can encode local calls and function pointers using unnamed
STT_SECTION symbols. The object verifier now resolves these from consistent
known-address anchors, matching the linker’s existing address calculation.
Inference is limited to selected executable function sections whose entire
section equals the declared, expected function span. Unselected sections,
extra pool/padding bytes, missing addresses, and conflicting bases cannot
supply an inferred anchor. Ordinary function sizes and final relocated-byte
comparison remain mandatory. Tests cover successful local calls, distinct
HI/LO keys, missing anchors, conflicting bases and extra section bytes.

The three routines in `sony29_event_callbacks.c` exercise this path: lazy event
registration, callback/argument replacement with interrupt-state restoration,
and guarded callback dispatch. All three complete bodies verify directly
against retail with unchanged Sony compiler and assembler output.


### Constraint-free wrapper profiles and larger gameplay loops

Eight formerly constrained wrappers now match ordinary C: Sony 2.9 O2/G0
handles two status resets, the CR/LF callback, and the semaphore wait wrapper;
EE GCC 2.96 O1/G0 handles four framed call wrappers. The latter optimization
profile preserves the native call/epilogue where O2 generated a shorter sibling
call. Correct kernel return contracts are supported by the
[PS2SDK kernel declarations](https://raw.githubusercontent.com/ps2dev/ps2sdk/master/ee/kernel/include/kernel.h).
The obsolete constrained definitions were removed and every affected original
object recompiled, alongside the newly registered source units.

The 436-byte paired-timer routine at 0x00190130 uses MWCC3.0.3 O3/Op/G8.
Its do-while loops keep independent record offsets; comparisons on signed-short
assignment results preserve the retail sign extensions. Speed preference Op
provides the native join padding without embedded NOPs or instruction changes.


### Framed runtime calls with EE GCC 2.96

`src/runtime_framed_calls_0040.c` uses EE GCC 2.96 with
`-O2 -G0 -ffunction-sections -fno-optimize-sibling-calls`. The option preserves
normal call frames and return sequences for the nine runtime wrappers in that
unit. The compiler output matches each complete retail function, totaling
1,076 bytes: 00400F98, 00405DC8, 004067B8, 00407FC8, 0040A440, 0040C7C0,
0040CAA0, 0040CD38, and 0040D738. The old empty-assembly definitions were removed from
seven mixed-profile units and the obsolete single-function w0_z.c was deleted.
All remaining functions in the affected original units were recompiled and
verified with their original profiles.

The normal matching build includes the compile-and-verify recipe. To run this
unit separately after sourcing `private/build.env`:

```sh
"$WIBO" "$SNCPP" -P src/runtime_framed_calls_0040.c build/matching/runtime_framed_calls_0040.i
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --opt O2 \
    --extra-flags=-fno-optimize-sibling-calls \
    build/matching/runtime_framed_calls_0040.i build/matching/runtime_framed_calls_0040.s
"$WIBO" "$SNAS" -G0 -o build/matching/runtime_framed_calls_0040.o build/matching/runtime_framed_calls_0040.s
"$PYTHON" tools/verify_object.py build/matching/runtime_framed_calls_0040.o private/SLUS_204.86.rom \
    --source src/runtime_framed_calls_0040.c
```

The 0040D738 helper review established the real return contracts and pointer
arguments for 00400BE0, 00400BB8, 00400658, and 004006E8. The corrected source
passes the same complete 272-byte comparison and now owns that span. The other
constrained functions remain subject to full source and compiler verification.


### Additional framed SDK calls and runtime-object storage

`runtime_framed_calls_003f.c` uses EE GCC 2.96 `-O2 -G8` with
`-fno-optimize-sibling-calls`. Seven complete functions match in this unit,
totaling 600 bytes: 003FEF20, 003FEF48, 003FDE10, 003FD2A0, 003FCCF0,
003FEAE8, and 003FEEA8. The last two arguments of 00411720 are 32-bit values,
as confirmed by its complete native implementation. The shared task-ID slots
at 004C2330/004C2334 retain volatile accesses: the asynchronous shutdown
routines 003FE7F0/003FE780 clear those slots while the task loop uses them.
The empty assembly barriers are removed. The old comment-only p2e8.c and
b10s2_f.c files and their obsolete compile entries were deleted.

`runtime_object_storage.c` uses EE GCC 2.96 `-O2 -G8`. Its 96-byte initializer
at 00400148 and 172-byte allocator at 004001A8 reproduce complete functions
that the old catalog had split at 0040015C and 004001BC. Native direct calls
enter at the two real starts; neither interior address has a direct call or
initialized function pointer. Both full returns are included. The two merges
preserve every catalog byte. The existing 172-byte allocator 00400258 also
matches in the shared unit.

The shared header fixes the 64-byte slot layout, including the signed active
byte and the constructor's descriptor, base offset, length, and sector fields.
The 00400AF8 processor scans exactly forty slots, and 004000F8 clears exactly
0xA00 bytes. The typed forty-object initialized pool now owns 00484AC0–004854C0;
its complete 2,560-byte object matches retail. The raw ranges on either side
remain placeholders. A negative control changing the first slot's initial
active flag is rejected by the whole-data verifier.


### Runtime sector-count calculation

`set_runtime_sector_count_004007A0.c` compiles with EE GCC 2.96
`-O2 -G0 -ffunction-sections -fno-schedule-insns`. The complete 64-byte
function matches retail, including the signed division and its delay-slot
store. A negative count derives the sector count from the object's byte
length, rounding upward only for a positive remainder; other counts are
stored directly. The shared 64-byte runtime-object layout supplies the
length at offset 0x14 and sector count at offset 0x30. No instruction
rewriting or assembly barriers are used. The normal matching build includes
the preprocessing, compiler option, assembly, and full-function verifier.

`finish_runtime_entry_0040D8F8.c` uses EE GCC 2.96 `-O2 -G0` with
`-fno-optimize-sibling-calls`. Its complete 340-byte body releases the active
object, preserves the first 39 bytes of the current filename in the aligned
40-byte temporary buffer, advances the signed ring index, and optionally
requeues the captured arguments. The compiler's ordinary builtin `memcpy`
expansion reproduces the unaligned doubleword and aligned word/halfword/byte
copy. The buffer alignment follows its actual 0x006320C0 address; neither
buffer data nor the still-unmatched enqueue routine earns new credit.

`config/readonly_sections.csv` can declare an exact compiler-generated
readonly section by source, section name, retail address, and size. Both the
function verifier and hybrid extractor validate the entire section before
using its base for anonymous relocations. Jump-table relocations must resolve
inside a whole selected function, and every resolved constant byte must match
retail. Partial, writable, ambiguous, changed, and out-of-range sections are
rejected. These anchors supply relocation evidence without adding data credit;
the normal data catalog remains the authority for compiled data replacements.

The Newlib 1.10.0 `dtoa.c` adaptation in `newlib_dtoa_0011A108.c` retains
its 556-byte quotient helper in the same source unit. EE GCC 2.96
`-O2 -G0 -msoft-float` produces the complete 4,708-byte conversion routine.
Its 0x58-byte readonly section at 0x004AC810 contains compiler literals and
six local jump-table entries; the production verifier checks all resolved
bytes before using that base. The checked `_reent` view extends only through
`_result` and `_result_k` at 0x40/0x44, with no data or opaque-tail credit.

The signed double-to-integer libcall `dptoli` resolves to 0x00119BC0;
the unsigned `dptoul` resolves to 0x00119CE8. The earlier shared signed alias
has been removed after auditing all 52 affected native calls in 39 source
units. Bounded phase conversions now convert to signed 32-bit before unsigned
masking; five calls with unbounded float inputs explicitly invoke the real
signed helper, preserving its truncation, NaN and saturation behavior.
`w1911_k.c` keeps unsigned 32-bit casts for both halves of its 64-bit result
and uses the compiler-generated `dptoul` symbol directly. Its object no longer
needs symbol renaming. See `SIGNED_DOUBLE_HELPER_BINDINGS_20261020.md` for the
source and native-call audit. The complete 280-byte function and Newlib unit
continue to verify in full.

`read_adx_header_fields_003F9AF0.c` uses EE GCC 2.96 `-O2 -G0` for two
complete 128/120-byte header readers. They retain the big-endian magic check,
signed header-offset checks, and native error returns before extracting the
16-bit field at byte 16 or the bytes at 18/19. Native callers at 0x003F7EE4
and 0x003F7E98/0x003F9C14 prove the three- and four-argument interfaces,
including separate byte outputs for the latter. No header-data credit is added.

The same ADX header unit also recovers the complete 308-byte function at
0x003F9BE8. It calls the verified version reader, retains the signed offset
and version-dependent length checks, and decodes the four halfwords at bytes
24–31 into two output pairs. Older versions clear both pairs. The native call
at 0x003F7F00 passes the header, length and two distinct stack-backed output
arrays. All three functions in the shared unit match under the same EE GCC
2.96 `-O2 -G0` recipe, including the internal call relocation.

The same EE GCC 2.96 O2/G0 header unit also reconstructs `func_003F9F80`
(92 bytes): validate a 16-byte minimum and `0x8001` magic, then return the
big-endian header offset plus four through its `u16` output. The native call
at `0x00403394` supplies the buffer, length, and stack output pointer and
checks its status. All four complete functions in this source verify exactly.

`func_0036EE40` preserves two real callback inputs while positioning its effect.
Its verified dispatcher `func_0036E6F0` sets A1 to the owner at `p + 0x18`
at `0x0036E70C`, and A2 to `p + 0x88` at `0x0036E720`, before invoking
`D_00463DA0[p[5]]`. The callback forwards those same byte pointers to
`func_0036EF10`; that consumer reads the owner at offset `0x220` and the
state's first word. The three-argument type agrees with `src/h8.c`.

`func_0020CB80` uses MWCC 3.0.3 `-O3 -Op -sdatathreshold 0`. The parent
`func_0020BC30` sets A1 to `p + 0x2B8` at `0x0020BC3C`; table entry
`0x00450894` selects `func_0020CB00`, which preserves that input into
`jtbl_004508C0[p[7]]`. Its second entry selects this callback. The existing
initializer `residual_0020CB20` also forwards the same state pointer directly
at `0x0020CB60`. The inner table and dispatcher now retain this real argument.
A double temporary merges the facing-dependent target calculation before
its float conversion; subtraction from the actor position remains float,
then division by 32 uses double as in retail.

`func_002FEDA0` uses the same MWCC 3.0.3 O3/Op/G0 profile. Its real state
input comes from `func_002FF2A0`, which sets A1 to `p + 0x2B8` at
`0x002FF2B0`. Slot `0x0045C1CC` selects the context-preserving head
`func_002FEF40`; inner slot `0x0045C1AC` selects this callback. Both typed
tables already retain that argument. The inverted less-or-equal test
preserves the retail unordered floating-point path.

`func_001D6D40` is a table callback with an unused second argument. Its
verified dispatcher `func_001D6D10` loads the signed byte pointer from
`p + 0x18`, copies its byte at offset `0x24`, then calls
`jtbl_0044E600[p[0x20]](p, q)` at `0x001D6D34`. Retail slots `0x0044E600`,
`0x0044E608`, and `0x0044E60C` point to `func_001D6D40`. The handler does not
read its second argument, but the dispatcher passes the real pointer in A1. Both
split functions compile exactly in `grok_w5_001d.c` under the unit's MWCCPS2 3.0.3 `-O3 -sdatathreshold 0`
recipe, with a four-byte NOP gap between them.


### Actor action reset views

`src/actor_action_event.h` models the real action byte at actor offset `0x1B5`
with a compile-time offset check. It is a partial code view, not a reconstructed
data object or a full actor layout. The inline event helper retains the typed
action write, frame reset, and per-player counter update seen in retail.

The complete `0x00255950` (1,668-byte) and `0x00274060` (228-byte) routines match
with MWCCPS2 3.0.3 `-O3 -Op -sdatathreshold 8 -i src`. A raw-byte self-assignment can
eliminate native action-byte reads and writes under this profile. Preserve the
field's checked type and ordinary byte-oriented caller view; do not add volatile
accesses, padding, or opcode patches. The first routine's complete 52-byte compiler
jump table is checked through `config/readonly_sections.csv` and remains uncredited
data until it has a separate source-ownership proof.
`func_001F3E50` and `func_001F3E90` are separate callbacks in
`jtbl_0044F8E0`: slots `0x0044F8E8` and `0x0044F8EC` point to the dispatcher
and its adjacent handler, respectively. The outer dispatcher at
`0x001F2D60` indexes this table by `p[6]` while retaining the actor in A0. The
`0x001F3E50` handler sets launch fields and then calls
`jtbl_0044F8F0[p[7]](p)`; `func_001F3E90` consumes only A0 and forwards it to
the status and error handlers. Their complete split bodies
match in `grok_w5_001f.c` under MWCCPS2 3.0.3 `-O3 -sdatathreshold 8`.


For manual object builds, create the output directories first, for example
`mkdir -p build/matching/data`. A missing output directory was confirmed to cause
`wibo-macos` to report its missing `FormatMessageA` import while attempting to
format the compiler's file error. The same compiler commands succeeded once the
directories existed; check the output path before diagnosing a toolchain failure.
`func_001F28E0` is the first handler in `jtbl_0044F8C0` at slot
`0x0044F8C0`. The outer state dispatch at `0x001F2D30` calls that table with
A0 holding the actor. This handler only reads and updates A0. The adjacent
`func_001F28A0` initializes launch fields and dispatches through
`jtbl_0044F880[p[7]]`; the two ordinary-C functions match as a 52-byte head,
a 12-byte NOP gap, and an 88-byte handler under the existing MWCCPS2 3.0.3
`-O3 -sdatathreshold 8` recipe.


`func_001F7020` is selected by outer table slot `0x0044F6A0`; it dispatches
`p[0x20b] & 0x3f` through `jtbl_0044FB10`. The first inner slot at
`0x0044FB10` selects `func_001F7050`, whose tail call forwards the field at
`p + 0x1dc` as A0 and p as A1 to `func_00178F20`. Both are recovered as a
36-byte dispatch head and a 12-byte tail-call handler, with the original
four-byte leading and 12-byte separating gaps retained in the boundary map.


`func_001F03A0` is selected by table slot `0x0044F68C`. It calls
`func_003D92F0(p)` first, reports a failure through `func_001843A0(p)`, and on
success dispatches through `jtbl_0044F710[p[32]](p)`. The 92-byte C body
matches in `grok_w5_001f.c` under the existing MWCCPS2 3.0.3
`-O3 -sdatathreshold 8` recipe, after a four-byte leading gap in the recovered
boundary.

The Sony event helpers `00104C90` and `00104DA8` use EE GCC 2.9 `-O2 -G0 -ffunction-sections`. Their required syscall primitive declares V0/V1 clobbers; queue updates and fallback control flow remain C. The fallback wrappers `00103D20` and `00103D60` take a thread ID and return an integer kernel status, consistent with the [PS2SDK kernel declarations](https://github.com/ps2dev/ps2sdk/blob/master/ee/kernel/include/kernel.h). Both wrappers and their complete caller translation unit reproduce retail exactly.

The 38 follow-up Grok loop recoveries use MWCC 3.0 (`011126`) with `#pragma padloop on`: 35 sources use `-O3 -sdatathreshold 0`, two use `-O3 -sdatathreshold 8`, and one uses `-O4,p -sdatathreshold 0`. Each production recipe verifies the full catalogued function; artificial inline NOP blocks are absent. See `GROK_20261019_LOOP_RECOVERIES.csv` for per-source profiles.

### Conditional moves also occur in exact Metrowerks output

The recovered `func_001CFBB0` in `src/payload_phase_initializers_001a9720.c` is a complete 356-byte match with MWCCPS2 Version 3.0 (runtime built November 26, 2001), `-O3 -Op -sdatathreshold 8`. Retail instruction 0x001CFCEC is `movz a2, zero, v0`. The ordinary C selector `(s8)(p[0x20] ? 23 : 0)` reproduces it, including the subsequent sign extension and helper call. A `movz` instruction alone therefore does not distinguish Sony GCC from Metrowerks. Use complete relocated object matches and multiple independent compiler traits when assigning a compiler family. This counterexample does not establish the provenance of unrelated functions.

## Exact 2.4 profile for owner tag guard

`src/owner_tag_guard_003562d0.c` matches all 84 native bytes at `003562D0`
with `mwcps2-2.4-001213`, `-O4,p -sdatathreshold 8`. The same source under
3.0, 3.0.1 and 3.0.3 produces 80 bytes: it moves the state value load into
an otherwise empty branch delay slot. This is evidence for this translation
unit's production recipe; it does not identify the compiler of other units.
The C contains no padding, assembly, volatile access or artificial operation.

The production build requires `MWCCPS2_24` alongside the existing compiler
variables. Extract the public archive into a private directory and export its
executable path before running `make hybrid`:

```sh
curl -L https://github.com/decompme/compilers/releases/download/compilers/mwcps2-2.4-001213.tar.gz | tar xz -C "$PRIVATE_COMPILER_DIR"
export MWCCPS2_24="$PRIVATE_COMPILER_DIR/mwcps2-2.4-001213/mwccps2.exe"
```

Set the path to the actual extracted executable if the archive's directory
layout differs. Compiler binaries remain private.
