# Toolchain, verification and credit

The build inputs below are supplied locally and are not in the repository; see
[BUILD_INPUTS.md](BUILD_INPUTS.md).

## Inputs

- `toolchain/hitachi-shc-5.1r08/` (supplied): the Hitachi SH C/C++ compiler
  package: compiler passes from SHC 5.1 Release 8, assembler, linker and
  utilities from 5.0 Release 31. Its manifest records every file's size and SHA-256.
- `toolchain/naomi-sdk/lib/` (supplied): Sega's prebuilt NAOMI SDK libraries, in
  Hitachi library format, with a manifest of every file's size and SHA-256. The
  retail ROM links these objects unchanged, so library units link them instead
  of reconstructing their source.
- `orig/mvsc2.zip` (supplied): the 18 reference ROM members, hash-checked
  against `config/target.json`.
- `toolchain/wibo/` (committed): the wibo 1.2.0 Windows runtime for Linux x86_64 and macOS.

| Host | Route |
| --- | --- |
| Linux x86_64 | native |
| macOS Intel or Apple Silicon with Rosetta | native |
| anything else | a Linux x86_64 machine with the inputs |

## Where the options came from

The NAOMI SDK preserved at archive.org (item `NaomiSDK`) holds the Hitachi
compiler releases Sega shipped, `pcv5r10` through `pcv5r32` and `pcv51r01`
and `pcv51r08`, and in `hitachi990119.zip` the file
`doc/english/misc/read_1st.txt`, Sega's tool manual, whose section 1 lists
the options every application must be built with. Those are the `game` set.
Releases 31, 32 and 5.1 agree on most units; release 28 does not.

## Which compiler built retail

5.1 Release 8 (`pcv51r08`, 1999-07-15). Sega's Japanese Dreamcast SDK 1.55J
(July 1999) ships byte-identical binaries, and its SH tools release notes list
the 5.1 updates Sega distributed: r01 (1998-12), r03, r04, r06 and r08. Against
retail:

- 5.0R31, 5.0R32 and 5.1R01 sort switch compares by case value and pool a
  literal 2.0f; retail tests cases in source order and builds 2.0f with
  `fldi1; fadd`, and computes signed `% 2^n` inline. 5.1R08 does all three.
  On the 29 candidates whose code differs between 5.1R01 and 5.1R08, R08 is
  closer to retail on 26.
- 5.1 Release 13, from Sega Library Ver.2.00J (2000-09; its InstallShield 3
  archive decompresses with PKWARE DCL), changes FMAC operand registers in
  five units R08 matches exactly and improves no candidate. It is later than
  retail. SHC 6.0AD ships on the same disc.
- 5.1 Release 11, from Katana SDK R10.1 (InstallShield 5 cabinets,
  `UtlDevHitachi/`), compiles every verified game and library source and
  every single-section candidate to the same code as R08. Retail cannot
  tell R08 and R11 apart; R08 is bundled. Katana SDK R9 ships R08; Katana
  SDK R10, R10.1 and R11b all ship the same R11 binaries.

Every verified source was recompiled with each candidate compiler; only the
units named in `docs/MATCHING.md` needed source changes for R08. The `library` set drops `-extra=a=400` because Sega's libraries
above 0x0c1e9000 were built without it. The compiler runtime routines the
generated code calls are listed with their retail addresses in
`config/runtime.json`, each proven by a verified unit.

## Option sets that were tried and rejected

Other decompilation projects have found one executable built at several
optimization levels, so the same was tested here. Each switch below was added to
the `game` set and a stubborn candidate recompiled; nothing beat the set in
`config/compiler.json`.

| Switch | Effect on a 620-byte candidate | On a 680-byte candidate |
| --- | ---: | ---: |
| none (`game`) | 313/620 equal | 658/680 equal, 5/7 functions |
| `-optimize=0` | 9/620 | 14/680 |
| `-speed` | 316/620 | 522/680, 2/7 functions |
| `-size`, `-inline`, `-noinline`, `-loop`, `-noloop`, `-double=float` | no change | no change |

A unit that will not match is telling you about the shape of its C, not about a
missing switch. Add an option set only with a unit that matches exactly under it
and under nothing else.

## Pipeline

For every unit in `config/units.json`, `tools/build.py`:

1. copies the unit's C file and every header in `src/include/` into `build/work/`;
2. runs `shc.exe` with one of the two option sets in `config/compiler.json`:
   `game` for the game's own code and `library` for Sega's libraries above
   0x0c1e9000, which were built without the `-extra=a=400` nop workaround.
   A unit names its set with `"options"`; the default is `game`.
3. runs `asmsh.exe` on that assembly and `lnk.exe` to place each section at its
   original address, defining the unit's imports at their retail addresses;
4. compares the linked ELF with the main image.

The compiler's own output is what gets assembled. The build never edits
instructions, only section alignment directives.

## Unit registry

```json
{ "id": "mask_tu", "source": "src/candidates/mask_tu.c", "mode": "candidate",
  "sections": [ { "section": "P", "kind": "code", "address": "0x0c047a40", "size": 288,
                  "interior": [ { "address": "0x0c047b2e", "size": 50, "kind": "data" } ] } ],
  "exports": { "_func_0c047a40": "0x0c047a40", "_func_0c047a8c": "0x0c047a8c" },
  "imports": { "_dat_0c2d9300": "0x0c2d9300" } }
```

- `mode` is `verified` or `candidate`. Every verified unit must match exactly or
  the check fails.
- A section is one linked Hitachi section: `P` for code, `C` for constants,
  `D` for initialized data, `B` for BSS, or the `#pragma section` name.
- A pool is its `mov.w` literals, a two-byte zero pad when their count is odd,
  then its `mov.l` literals. The pad is mapped as data like the literals.
- `interior` lists bytes of the other kind inside a section. SHC emits a
  translation unit's literal pool inside its code section, so a code section
  declares its pool as interior data. The mapping keeps calling those bytes
  data; the unit still owns the whole section.
- `exports` are the symbols the unit defines, with their retail addresses.
  Every function is exported.
- `imports` are the symbols it references from elsewhere, with their retail
  addresses. Compiler runtime routines are listed once in
  `config/runtime.json`.
- `options` names the option set, `game` or `library`.

A **library unit** links one prebuilt SDK module instead of compiling C, so it
names a `library` and a `module` in place of a `source`, and takes no `options`:

```json
{ "id": "lib_kamui2_km2ver_kamui2_lib_", "library": "toolchain/naomi-sdk/lib/libkamui2.lib",
  "module": "km2ver_kamui2_lib_", "mode": "verified",
  "sections": [ { "section": "PSG", "kind": "code", "address": "0x0c206780", "size": 64 } ],
  "imports": { "_kmiWriteRegister": "0x0c213200" },
  "exports": { "_kmGetVersionInfo": "0x0c206780" } }
```

The build extracts that one module into a private library, links it at the
declared addresses against a reference object that names only its exports, and
compares the result with retail exactly as it compares a compiled unit. That
byte proof alone does not identify which bytes are instructions. The reviewed
mapping retains its classification. A separate native review can add `interior`
data annotations to exclude literal pools, alignment and unreachable material
from executable credit. The entire section, including those bytes, must still
match; the annotations do not modify the object or relax verification.

The matcher also uses observed internal relocations to locate sections with too
little distinctive content for a byte search. All section-base observations
must agree, fixed bytes must match, and the ordinary complete link comparison
remains the acceptance test. Existing export addresses are tried even for very
short sections. BSS searches retain known registry symbols and stop retrying
when no relevant evidence changes. Each invocation uses private temporary files.
`--output FILE.json` saves the exact descriptors and skipped reasons for review;
the reported total is initialized bytes, not executable-code progress.

## Verification

A unit is exact when the linked ELF has the expected sections and no others,
every section has the declared address, size and kind, every export lands at
its address, every initialized byte equals retail, and the ELF holds no bytes
beyond the declared sections. A matching prefix is not a match.

Each exported function is also compared on its own: its bytes run from its
address to the next export, the next declared interior range, or the end of the
section.

## Credit

- A **verified** unit is credited for every code and data byte once it is exact.
- A **candidate** unit is credited for the bytes of each function and each
  declared pool that matches, provided its section links at the declared
  address and size. Its other functions earn nothing.
- Only verified bytes are written into the rebuilt ROM. Everything else stays
  retail, and the rebuilt ROM must hash to retail.

`build/proof.json` records every comparison. `build/progress.json`,
`build/progress.svg`, `build/active.svg` and `build/index.html` are drawn from
it, and the README bars are rewritten from the same numbers.
`build/work_queue.json` ranks candidates from that same proof. `near_match`
means the section is placed and sized correctly with at least 95% equal bytes;
`review_extent` means the declared bytes match but the linked size or address
does not. These are work suggestions, not matching credit.

## Tools

- `tools/diff_unit.py FILE [--register ID]`: compile one file, compare it with
  retail function by function, and register it. See
  [MATCHING.md](MATCHING.md).
- `tools/twins.py START SIZE`: for each function in a span, the verified
  function of the same instruction shape, with its source. The game stamps
  its state handlers from a few templates, so most units are half twins.
- `tools/clone.py START SIZE OUT.c`: assemble a unit from its verified
  twins, symbols and immediates substituted; functions without a twin become
  stubs carrying their Ghidra draft. `--list` names the units whose every
  function has a twin.
- `tools/libunit.py LIB [--register]`: find every module of a bundled SDK
  library in the retail image, solve the addresses its relocations point at,
  prove the link byte-exact, and register the exact ones as library units.
- `tools/permute.py FILE`: hill-climb over the mechanical rewrites in
  MATCHING.md, scored by equal bytes against retail.
- `tools/float_literal.py 0xBITS`: the decimal spelling SHC parses to those
  float bits.
- `tools/ghidra_draft.py --ghidra DIR`: a Ghidra decompilation draft of every
  reviewed function into `build/drafts/`, pool literals substituted by
  `tools/draft_pools.py`. Ghidra is not bundled: unpack a release such as
  `ghidra_11.3.2_PUBLIC` from its GitHub releases (Java 17 or newer is
  required) and pass the directory. The run takes about half an hour and
  needs no analysis pass; `tools/ghidra/DraftSome.java` drafts a few named
  functions in seconds. Run `tools/ghidra/single_precision.sh DIR` once
  after unpacking: Ghidra's SH-4 model decides float width at run time and
  otherwise fills float code with double-precision noise; the script forces
  single precision, which is how the game runs, and recompiles the language.
- `tools/inspect_rom.py --address A --size N`: disassemble retail bytes.
- `tools/flow_map.py`: walk the control-flow graph from the entry point and every
  reviewed code range and propose new ranges. `--roots FILE` adds candidate
  entry points, for example the BSR destinations from `tools/survey.py`.
- `tools/unit_spans.py`: propose translation-unit extents, runs of code and
  pools that no branch crosses and that start on a function. This is the list
  to hand out.
- `tools/pool_clusters.py`: group reviewed code that reads one literal pool.
  A unit usually holds several.
- `tools/nonexecutable.py`: find runs that decode as no SH-4 instruction.
