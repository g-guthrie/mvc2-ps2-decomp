# Embedded compiler switch tables and runtime directory metadata

This change reconstructs 40 initialized data bytes: a 24-byte compiler switch
table in newlib DTOA and the existing 16-byte RuntimeDirectory record. It adds
no code credit. Unknown adjacent storage remains a placeholder.

## Verifying and placing embedded switch tables

Some compilers put a switch table inside a larger readonly section without a
named ELF symbol for the table. The previous standalone data verifier and
hybrid linker required a named symbol at offset zero spanning the whole data
section, so the DTOA table could not use its real C owner's object.

A catalog unit with kind `compiler_switch_table` can now use a bounded slice
of its registered C owner's explicitly anchored readonly section. Both the
data verifier and hybrid generator reuse the same verification path:

- Every registered function in the owner must have matching/complete status
  and reproduce its entire relocated retail function.
- The complete readonly section must reproduce retail, including neighboring
  bytes outside the table. Its source, section, address and size come from
  `config/readonly_sections.csv`.
- The declared table must be positive, word aligned, wholly inside that
  section and inside the loaded retail image.
- Every table word must have exactly one compiler-generated R_MIPS_32
  relocation. Targets must satisfy the existing whole-function label checks.
- The resolved slice must reproduce the exact retail table bytes.

Other kinds retain the standalone whole-symbol/whole-section rule. A switch
owner without a readonly anchor also retains that path, including projects
where the optional readonly map does not exist. Numeric initializer arrays
and arbitrary raw slices gain no matching credit from this support.

The new tests include valid embedded extraction and hybrid placement, CLI
imports, corrupted functions, corrupted table entries and neighboring bytes,
wrong or uncredited owners, incorrect sections, bounds violations, missing
pointer relocations and strict standalone placement. The integration loader
fixture also checks the newly retained source and kind metadata explicitly.
The new module is included in both `make test` and the report workflow.

## DTOA table at 004AC850

`src/newlib_dtoa_0011A108.c` already reproduces both registered functions
(556 and 4,708 bytes) and its full 88-byte readonly section at 004AC810.
Its source normalizes conversion modes to 0..5 and switches on that bounded
value. The compiler emits six relocated case pointers at readonly offset
0x40: 24 bytes at 004AC850. The native dispatch also bounds the index to six.

The catalog now attributes those bytes to the actual C owner. The old
numeric-address placeholder helper is removed. The next table at 004AC870
is outside this owner and remains unchanged; surrounding raw gaps gain no
credit. Compiler binaries, objects, retail inputs and private receipts stay
outside Git.

## RuntimeDirectory at 004895C0

The record reuses `runtime_directory_types.h`: entry pointer, unsigned entry
count, signed span count and signed name length. The native producer at
0040C178 writes all four words, and the clear routine at 0040C798 clears
exactly 16 bytes. Existing consumers independently use these fields. The
producer's native evidence establishes the data layout; its body receives no
new C credit here.

The former raw owner at 00489490 is shortened from 0x140 to 0x130, leaving
its 304 unknown bytes uncredited. The following 16-byte record is represented
by the shared type. Consumers now use that declaration; unused incompatible
two-word declarations are removed. The public lookup wrapper keeps its
existing opaque pointer API and converts locally to the string pointer used
by the four-argument search helper.

The root independently rebuilt 11 production code units (65 whole matching
functions) and seven neighboring data objects. No header changed. Separate
native inspection checked the producer, exact clear, caller and consumers.
The proposed 552-byte neighboring path buffer was rejected: an unbounded
NUL-terminated copy proves its string role, but does not establish capacity
or identify all bytes through the next catalog owner. Those fragments remain
unreconstructed.

## Reproduction

With the existing private environment and pinned retail image installed:

```sh
. private/build.env
. private/sony29.env
make test PYTHON="$PYTHON"
make progress-check PYTHON="$PYTHON"
make split PYTHON="$PYTHON"
make hybrid PYTHON="$PYTHON"
```

`make hybrid` compiles and verifies all registered source owners, then links
and packs the full image. The code compilation script must keep its single
data-build invocation after all code owners. To verify the DTOA data alone
after compiling its owner:

```sh
"$PYTHON" tools/verify_data_object.py \
  build/matching/newlib_dtoa_0011A108.o private/SLUS_204.86.rom \
  --name jtbl_004AC850 --symbols config/symbol_addrs.txt
```

The full hybrid ROM must match all 3,941,760 retail bytes with SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed ELF must be 3,942,320 bytes with SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Matching the whole hybrid image also covers retained retail placeholders;
it does not imply that their source has been reconstructed.

## Verified checkpoint

All 111 tests and build coverage/catalog checks pass. A fresh split and
full relink/pack reproduce the complete ROM and executable hashes above.
Before linkage, the root checked 15,175 unchanged source/object pairs,
17 independently rebuilt existing pairs, the retired numeric table helper,
and all 47 unchanged headers against the preceding verified checkpoint.
The new directory helper was compiled and verified independently. Source,
configuration and tool hashes stayed fixed throughout the successful gate.

Code remains 2,065,128 / 3,293,696 bytes (62.6994%). Complete reconstructed
data is 248,776 / 648,064 bytes (38.3876%). The next fixed code publication
threshold remains 2,080,510 bytes.
