# Project history

Notes moved from the README; kept for the record. Figures in them are from the date they were written.

## Coordination notes for Claude — October 18

Sony EE GCC 2.9 is installed by `tools/setup_sony29.py`; source
`private/sony29.env` after the normal build environment. The pinned download,
smoke test, probe inventory and compiler recipes are documented in
[docs/COMPILER.md](docs/COMPILER.md#reproducible-sony-setup-and-candidate-audit).
The initial conservative 173-span audit recorded 40 available C definitions
and 53 exact flag/source profiles; the claimed 196-function list was unavailable
for that audit. Probe results do not automatically earn C credit.

Current registered Sony 2.9 recipes cover 73 credited C functions / 7,040 bytes
without opcode rewriting; the earlier Codex batch covered 62 functions / 5,544 bytes.
The frozen complete compiler/data build and the later combined hybrid/packed
image checks pass exactly. Unrecovered spans still use retail bytes. All
registered source changes since the frozen build were separately recompiled.

The progress audit removed algorithmic assembly and compiler-constraint credit;
four former assembly copies now have exact C replacements. Three empty-barrier removals preserve exact objects; eight further functions
now match without constraints under real compiler profiles. Remaining
constraint-dependent functions stay placeholders. Required kernel/CPU operations retain their documented exception.
See the initial audit dispositions in
[docs/ASSEMBLY_CREDIT_AUDIT.csv](docs/ASSEMBLY_CREDIT_AUDIT.csv) and subsequent
recoveries in [docs/PROGRESS.md](docs/PROGRESS.md). The generated graphic and
successful decomp.dev report are the current progress authority.

Earlier Codex follow-on batches added 32 genuine C functions / 8,364 bytes,
independently compiled and checked in full. They include stage actor dispatch,
motion/attachment state updates, actor launch variants, timed state setup and a
440-byte damped-motion handler. One older 736-byte mesh-loader caller lost
credit because its fabricated helper bodies only shaped register allocation.
Those batches reached 43.0850% code. The newer waves 17–19 baseline is
1,619,392 code bytes (49.1664%). Subsequent independently verified recovery is
reflected in the generated graphic above and the latest decomp.dev report,
which show current code and data coverage.
The near-matching natural mesh-loader candidate remains uncredited.
The latest source work also recovers the bounded forty-slot runtime-object
pool with its shared layout and complete native initializer/allocator spans,
plus the sixteen bounded runtime-entry record arrays. The latest whole-function
recoveries include the 736-byte runtime stream processor, its sector-count
setter, and three 148-byte record searches.

The four 48-byte switch tables at 004B73E0–004B7470 now come from the
compiled C owners in `src/w192_r.c`; their raw pointer-literal file is removed.
The normal build reuses the code object and verifies each complete table,
including its case-label relocations. The linker selects tables by symbol and
section index because MWCC gives them identical `.rodata` section names.

Keep genuine helper bodies with their callers when matching depends on known
register preservation. Verify the helper itself and all affected original units.
Invented stand-ins and omitted required arguments do not establish a C match.
The motion/rebound and state-event helper groups now use verified real bodies;
see [docs/PROGRESS.md](docs/PROGRESS.md) for their source ownership.

Check the current catalog and recent commits before starting adjacent work.
Use function evidence to choose compilers; the SDK address bands are mixed.
Verified code is pushed at least after each additional full percentage point.
The latest checkpoint also publishes the EE GCC sibling-call profile described
in [docs/COMPILER.md](docs/COMPILER.md#framed-runtime-calls-with-ee-gcc-296).

The latest verified CODE checkpoint is 2,782,516 / 3,293,696 bytes
(84.4800%). The SDK ADX cleanup routine adds 176 CODE bytes. The rebuilt
executable remains retail-exact. The prior effect-start handler retains its
retail uninitialized stack component as documented in [progress](docs/PROGRESS.md#actor-effect-start).
The catalog reports 468,873 / 648,064 DATA bytes (72.3498%); some table
ownership classifications still need repair.
