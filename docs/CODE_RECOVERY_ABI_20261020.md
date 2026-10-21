# Code recovery and ABI evidence, 2026-10-20

This independent code-lane batch starts at `6ce0e6ba` and adds 1,080 bytes
across eight complete compiled functions. No initialized-data credit changes.

| Entry | Bytes | Source | MWCCPS2 3.0.3 recipe |
| --- | ---: | --- | --- |
| 0032BDF0 | 204 | stage_select_input_0032BDF0.c | O3, G8 |
| 003D7350 | 176 | text_pool_append_003D7350.c | O3, G8 |
| 003B4120 | 284 | linked_effect_children_003B4120.c | O3, G8 |
| 00323610 | 60 | context_dispatchers_20261020.c | O3, G8 |
| 0034FB40 | 52 | context_dispatchers_20261020.c | O3, G8 |
| 00366090 | 52 | context_dispatchers_20261020.c | O3, G8 |
| 00368000 | 52 | context_dispatchers_20261020.c | O3, G8 |
| 00414E30 | 200 | initialize_runtime_tables_00414E30.c | O4,p, G8 |

`G8` means `-sdatathreshold 8`. Production commands are in
`tools/compile_matching.sh`. Each function passes whole-function relocated
byte comparison; this table excludes held candidates.

## Formatting return value and variadic arguments

The existing 84-byte helper `00122340` returns the `int` result of
`001209B8` (vfprintf). Native code uses V1 for the final FILE buffer pointer,
preserving V0. The newly recovered `003D7350` consumes this length to place
its final NUL. The helper and its two already credited caller units were
independently rebuilt after correcting the declarations. This repair adds
zero progress bytes.

`003D7350` has four named parameters: byte x, byte y, a byte attribute widened
to a halfword, and a format pointer. T0 through T3 contain its initial
variadic arguments. Its argument-list initialization follows the pointer
EABI definition in GCC 2.95.2's
[va-mips.h](https://github.com/gcc-mirror/gcc/blob/releases/gcc-2.95.2/gcc/ginclude/va-mips.h),
lines 81–86 and 113–117. The supported `__builtin_args_info(2)` reports the
named GPR argument count; the register-save slots are eight bytes. The C
expression uses these compiler interfaces instead of assuming a stack
offset. The earlier failing `args_info(0)` probe used a different operand.

Native code proves the record stride of 64 bytes, the count limit of 128,
the two coordinate bytes, the attribute halfword, and text beginning at +4.
The source represents that layout directly. `0032BDF0` passes five actual
arguments to this helper: x, 22, zero, the format string at 004B7668, and
the stage byte at 004C27D0. It reads pad halfwords based at 004C291C and
wraps the stage index modulo 17.

## Child allocation

`003B4120` creates an initial child and attempts five further allocations.
The callback at 003B4240 receives an actor pointer. Native stores in the
second loop deliberately address the first child at +88/+8C; the recovered
C preserves those stores.

An initial allocation failure leaves the pool unchanged: 003DA750 returns
NULL when signed count 004C27A4 is nonpositive; 003DA780 returns NULL when
signed count 004C27A0 is zero. These failure paths have no writes or
callbacks. Consequently a failed first call cannot become a successful
later call within this synchronous routine's own failed-call path. The
matching source does not depend on undefined behavior to force codegen.

## Dispatcher boundaries

The four recovered dispatch entries terminate at their computed tail jumps
and delay slots. Their former 64-byte residual ranges included trailing
alignment. Only the compiled 60/52/52/52 bytes receive credit; the remaining
4/12/12/12 zero bytes are recorded as gaps. The fixed text denominator is
unchanged. No static branch, jump, or stored absolute code pointer targets
those alignment bytes.

00323610 is rooted by the entry at 0045DE20. Existing exact constructors
0034FA80, 00365F60, and 00367F90 install the other three callbacks. Their
declarations now describe the actor parameter, and both affected constructor
units were rebuilt and verified. The three entries snapshot the parent
pointer before publishing their context pointers, matching native aliasing
and load order. The existing jtbl_00462460 binding is reused.

## Runtime initialization

00414E30 initializes 4,096 unsigned packed-handle words, 256 slots containing
a signed handle and unsigned state, two counts, and the 0xE00-byte lookup
table. Existing cleanup consumers establish the packed unsigned handle
representation and the runtime-slot layout. The C retains ordinary bounded
loops; `-O4,p` performs the native unrolling. No section qualifiers are
needed for this match.

## Validation and exclusions

All changed source units were rebuilt with their production recipes and
relocated against retail. The other 14,048 cached source/object pairs and
all 45 existing headers were unchanged. The complete loaded image and packed
ELF remain byte-identical to retail, and all 95 tests pass.

002603C0 remains uncredited: a two-float local differs in stack placement;
enlarging its local array matches bytes but lacks native extent evidence.
003DC2F0 and 0033C6E0 also remain uncredited near matches. No assembly lifts,
NOP padding, forced registers, or artificial local extents receive credit.

### SJ chunk and pool methods: 1,212 new C bytes

Recovered SJMEM UngetChunk, SJRBF GetChunk/UngetChunk, pool reset, the transfer
count accessor and the separate error callback. The old 52-byte assembly lift
is replaced by the actual 24-byte accessor and 28-byte callback; adjacent padding
remains uncredited. The shared 48-byte pool prefix and canonical constructor
remain intact. Cumulative byte counts use unsigned arithmetic for wraparound;
chunk address validation uses the target's 32-bit address representation.

Five production units verify 16 spans, including the unchanged 88-byte VU
placeholder, which receives no new C credit. All 95 tests and build/catalog
gates pass; both complete rebuilt image hashes match retail. No DATA sources
or DATA credit changed. Frozen evidence:
`private/code-lane/sdk-methods-integration/FINAL_VERIFICATION.json`.

### Inherited actor setups: 1,168 new C bytes

Recovered D9290/448, DA890/356 and CE070/364 in one production unit. Native
callback tables establish the true entries and owner arguments. The 28 leading
alignment bytes remain padding. The compiler's complete 24-byte switch section
verifies against the existing DATA owner without changing its source or credit.
All 95 tests, build/catalog gates and both complete retail image comparisons
pass. Frozen evidence: `private/code-lane/round13/early-integration/FINAL_VERIFICATION.json`.

### Actor launch, randomized start and owner resume: 2,012 new C bytes

Recovered 3A16D0/660, 3A1970/604, 3B84C0/464 and DC820/284. The two launch
patterns share one source unit. DC820 uses the genuine one-argument DC940
callee and forwards the owner only to the actual two-argument DC9D0 callee.
Twelve leading alignment bytes remain uncredited. DCA50 also forwards its
actually consumed owner explicitly. No heterogeneous adapter head is changed.

The randomized-start mode table is declared as 16 four-byte signed-char records;
its native byte-zero load does not establish a 32-bit enum type. No overlapping
DATA definition or DATA credit is added. PollSema now captures and returns its
real kernel result; FlushCache accepts its actual operation input. The 30FF90
wrapper calls the genuine one-argument target with one actor. These repairs
add zero credit; the wider callback-table ISO C limitation remains documented.

Six complete production units verify 212 functions. All 95 tests, build/catalog
gates, fresh split, loaded ROM and packed ELF comparisons pass. Frozen evidence:
`private/code-lane/round14/root/FINAL_VERIFICATION.json`.
