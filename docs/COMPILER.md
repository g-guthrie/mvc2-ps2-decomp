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
