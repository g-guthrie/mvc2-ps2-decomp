# Working on the NAOMI decompilation

**Goal: every byte of the main image reproduced from C.** This file is the
whole process. Nothing here is restated elsewhere; if another document
disagrees with this one, this one wins.

## Start

Everything here runs from `naomi/`, with the build inputs in place
([docs/BUILD_INPUTS.md](docs/BUILD_INPUTS.md)).

```sh
cd naomi
python3 tools/build.py check                      # must pass before you begin; cache hits are reverified
python3 tools/ghidra_draft.py --ghidra DIR        # once per clone, optional
```

The check verifies the ROMs, runs the tests, compiles every unit and rebuilds
the ROM. The draft step needs a Ghidra install patched for single precision (see
[docs/TOOLCHAIN.md](docs/TOOLCHAIN.md)) and writes a decompilation draft of
every reviewed function into `build/drafts/`; without it you read
disassembly instead.

## Loop

1. Run `python3 tools/recovery.py plan --owners current-thread` against the current successful proof.
   Pick from `build/recovery_plan.json`: it ranks candidates and untouched
   reviewed spans by potential new code and disclosed effort estimates. Review
   callback/type/family evidence before spending a spelling budget.
   A unit is a run of functions and their literal pools that no branch or
   PC-relative load crosses; confirm its extent before writing.
2. Run `python3 tools/clone.py START SIZE src/candidates/<id>.c`. It writes
   the functions that have a verified twin and leaves a stub with the Ghidra
   draft for each that does not. Write the stubs from the draft and the
   disassembly (`tools/inspect_rom.py`); `tools/twins.py START SIZE` shows
   what the clone was built from.
   [docs/MATCHING.md](docs/MATCHING.md) says how to shape the C.
   Its linked TBG findings cover compiler/data-layout and decompiler traps;
   distinguish locally reproduced facts from external hypotheses.
3. Iterate with `python3 tools/diff_unit.py <file>` until every function
   matches. `tools/permute.py <file> --hypothesis "native-supported change"`
   bounds and records spelling trials; parked inputs need new evidence.
   Reuse compiler-pattern/twin discoveries across related units; `tools/float_literal.py 0xBITS` gives an exact float spelling.
   Run `python3 tools/diagnose.py <file>` before broad searches. Resolve blocked
   boundaries and known type-contract failures first. Add native-supported
   layout/prototype assertions to `config/type_contracts.json` as facts are
   recovered; unlisted types are not validated.
4. Register with `python3 tools/diff_unit.py <file> --register <id>`: verified
   when exact, under `src/verified/`; candidate otherwise, under
   `src/candidates/`, with a comment at the top saying what differs. Units
   above 0x0c1e9000 are Sega library code and take `--options library`.
   Before writing C for a unit above 0x0c1e9000, try `tools/libunit.py`
   (below): most of that region is Sega's prebuilt SDK objects, and a module it
   places is matched without any source at all.
5. Integrate a coherent batch under one owner. Run the full check at the
   stable batch checkpoint, commit source and configuration together, push,
   and merge to `main`. Measure verified-C gain separately from SDK objects
   and candidate fragments with `tools/recovery.py snapshot` / `measure`.
   CI republishes the README bars from `main`. See `docs/RECOVERY.md`.

## Library modules

The region above 0x0c1e9000 is Sega's SDK, linked into the ROM unchanged from
the prebuilt libraries in `toolchain/naomi-sdk/lib/`. Those bytes are matched
by linking, not by writing C:

```sh
python3 tools/libunit.py toolchain/naomi-sdk/lib/libkamui2.lib            # report
python3 tools/libunit.py toolchain/naomi-sdk/lib/libkamui2.lib --register # register the exact ones
```

For each module the tool links it alone at two different bases; the words that
move are its relocations, and the rest is fixed content it searches for in the
retail image. Having placed the module it reads the real addresses of its
imports off the retail bytes, links it there, and keeps it only if every byte
matches. A module it cannot place uniquely, or whose link differs anywhere, is
reported and skipped. Nothing about this is a shortcut around matching: the
proof is the same byte comparison every other unit passes.

Run it again after adding a library, or after a unit frees a range it was
blocked on. `SKIP` lines say which of the two applies.

Recovery work is single-agent at the owner's request: do not spawn subagents
unless the owner asks for them. Keep unit ownership and
batch integration in the current chat. `diff_unit.py` uses a private work
directory and locks the registry. Full builds use isolated unit directories,
bounded `--jobs`, cached artifacts and an output lock. Keep source inputs stable.
Use `--clean` for independent clean-build evidence; CI always does so. See
`docs/FOUNDATIONS.md` for cache scope, admission checks and remaining limits.

## Rules

- **Only the pinned compiler.** `config/compiler.json` holds the only two
  option sets, `game` and `library`. A unit names one; nothing else is added.
  If your host cannot run it, use a Linux x86_64 machine that has the inputs.
- **C only.** No inline assembly, no assembler input, no byte arrays standing in
  for code. Data is declared with its real type where that is known. The
  compiler's runtime routines (`config/runtime.json`) are reached by writing
  the C that makes the compiler call them, never by calling them.
- **Retail decides.** Addresses and sizes come from the ROM. Nothing in
  `orig/`, `toolchain/` or the verifier is changed to make a unit match.
- **One definition per object.** Shared structs live in `src/include/objects.h`.
  A unit never declares its own copy of an object that is already there.
- **Unreviewed bytes stay unknown.** A range enters `config/mapping.json` only
  after its control flow, delay slots and literal pools were reviewed.
  Survey hits are hints.
- **Registration owns bytes.** Registering a unit releases pool sections and
  swallowed leaves from other units, in the registry and in their sources;
  that is expected. Every registered source must be committed with the
  registry.
- **Coherent commits.** One unit or a closely related batch, with its mapping
  and shared facts, after a passing integration check. Generated files under
  `build/` are never committed; do not run unchanged full suites per spelling.
