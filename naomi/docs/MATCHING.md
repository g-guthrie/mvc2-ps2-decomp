# Making a function match

> **Not distributed.** `orig/mvsc2.zip`, `toolchain/hitachi-shc-5.1r08/` and `toolchain/naomi-sdk/lib/` are not in this repository; supply them yourself at these paths. See [BUILD_INPUTS.md](BUILD_INPUTS.md).

The compiler is right. SHC 5.1 Release 8 (`toolchain/hitachi-shc-5.1r08/`, the
compiler passes from Sega's NaomiSDK `pcv51r08.zip`; assembler and linker are
still 5.0R31) with the `game` option set reproduces retail
instruction for instruction, register for register, when the source has the
same shape as the original and the unit has the same extent. Every difference
seen so far came from source shape, unit extent or an option, never from the
compiler. The `-extra=a=400` nop and `-macsave=0` were the last two options;
both came from Sega's own tool manual and both are now in
`config/compiler.json`.

## Work at the translation unit

- A function that reads a literal pool or reaches a neighbour with `bsr` or
  `bra` cannot match alone. Pool displacements and branch targets depend on the
  whole unit.
- SHC flushes a pool at the first unconditional branch or return after a
  literal was pending, roughly every 200 to 340 bytes of code, even in the
  middle of a function. The code then jumps over the pool and continues. A
  retail unit therefore holds several pools, and `tools/pool_clusters.py`
  reports one pool at a time. Before writing, find the real extent: walk back
  to a prologue, and forward until no function branches past the last pool.
  Half of the clusters handed out in the first batch were fragments.
- A function ending in an epilogue with no `rts`, followed directly by the
  next prologue, ends with a call to that next function: `next(a);` as the
  last statement, with `next` defined immediately after it in the same file.
- SHC assumes the unit starts 4-aligned. A retail pool with no pad after an
  odd number of words means the unit starts earlier than you think.
- Declare every outside symbol `extern` and name it by address; the diff tool
  imports it. The runtime routines the compiler calls by name are in
  `config/runtime.json`.
- `#pragma section` gives a lone function its own section. Use it only for
  pool-free leaves. Pragma sections also reset the scratch-register rotation
  (below), so a leaf that retail compiled inside a unit may only match there.

## Start from a verified twin

The game stamps its state handlers from a few templates: a dispatcher
`table[a->state](a)`, `if (f(a) < 0) g(a);`, check-then-set-state handlers,
init handlers. `python3 tools/twins.py START SIZE` names, for every function
in a span, a verified function with the same instruction shape and prints its
source. `python3 tools/clone.py START SIZE OUT.c` does the copy and the
substitution of pool symbols and immediates for a whole unit. What it cannot
do is change member offsets: when the twin reads other offsets, add the
members to the struct and rename them in the copied body. Keep the twin's
spelling; it is the one that matched.

## Start from the Ghidra draft

`build/drafts/func_0cXXXXXX.c` holds a Ghidra decompilation of every reviewed
function with the pool literals substituted, produced by
`tools/ghidra_draft.py`. It gives the control flow, the calls and the field
offsets. It is not the shape that reproduces the bytes: rewrite it with struct
members and the rules below, and keep the disassembly open for the details
the draft loses, such as register choice and float literal spelling.

## Iterate with the diff tool

```sh
python3 tools/diff_unit.py src/candidates/new.c
python3 tools/diff_unit.py src/verified/new.c --register new_id
python3 tools/float_literal.py 0x41092492
```

The tool reads the unit off the file: functions are named `func_0cXXXXXX`, so
their addresses are known. A file whose functions each follow a
`#pragma section` line is a set of pool-free leaves, one section each, sized
from the reviewed code range at that address. Any other file is one
translation unit whose section runs from the first function through every
code and data range up to the pool after the last function in the file; each
data range inside is declared as interior. Outside symbols named
`func_0cXXXXXX`, `dat_0cXXXXXX`, `ptr_0cXXXXXX` or `table_0cXXXXXX` are
imported at those addresses, runtime routines from `config/runtime.json`, and
anything else takes `--import SYMBOL=ADDRESS`. Units above 0x0c1e9000 are
Sega library code and take `--options library`.

It prints each section, function and pool with its equal byte count, then
every differing instruction with retail on the left and the compiled result on
the right. Fix the first difference; later ones are usually its consequences.

`--register` writes the unit into `config/units.json`: verified when exact,
candidate otherwise. A file under `src/verified/` must be exact. Registering
releases any section of another unit that the new unit owns, pool or leaf,
from that unit's registry entry and source. Several copies of the tool can run
at once; only `tools/build.py` needs the tree to itself.

For a registered source, `tools/diagnose.py` uses its recorded whole-unit
extent and option set. This matters when the final function continues after an
interior pool: rediscovering from its name alone can stop at that pool and
report a false outgoing branch. Unregistered files still require boundary
review; their extent is inferred from the source and mapping.

## Registers

- **Named locals get r5, r6, r7 and callee-saved registers; anonymous
  temporaries get r1 to r3.** A value retail keeps in r5 across an expression
  is a local variable. `q = p->p20;` gives `mov.l @(20,r4),r5`; the same load
  used inline gives r3.
- **Scratch-register rotation carries across functions inside a section.**
  Which of r1, r2 or r3 the first temporary of a function gets depends on what
  the previous function in the same section allocated. A function that
  differs from retail only by r2 and r3 swapped needs its real predecessor in
  the file. This is the whole explanation of the old mask unit question.
- **Test the assignment.** `if ((p = f()) != 0)` gives `tst r0,r0; bt.s L;
  mov r0,r4`; `p = f(); if (p)` gives `mov r0,r4; tst r4,r4`.
- **`if (!x)` and `if (x == 0)`** allocate differently; try the other one.
- **`switch (b) { case 0: ... }`** gives `extu.b; cmp/eq #0`; `if (b == 0)`
  gives `tst`.

## Source shapes that decide the bytes

| Retail shows | Write |
| --- | --- |
| offsets from the pool or `mov #imm,r0` with `@(r0,Rn)` on each access | member access on a struct pointer (`a->b1a3`), never `a[0x1a3]` or `*(T *)(a + N)` |
| `mov Rm,r0; nop` before a store, compare or return | any code; this is `-extra=a=400`, not a source shape |
| `extu.b` before a truthiness test | the field is `unsigned char`; without `extu.b` it is `char`; `tst #imm,r0` on a byte also means `char` |
| a value compared without reloading it | test the assignment expression: `if ((*out = x) == w)` |
| `mov #N,r2 ... mov.b r2,@(r0,r4); add #-1,r0; mov.b r2,@(r0,r4)` | chained assignment `a->x = a->y = N;` |
| `p->x = p->x + 1` style register use | `p->cur = p->cur + 1`, not `++` |
| loads in the order left then right of `+=` | `s->a += s->b` loads b first; `s->a = s->a + s->b` loads a first |
| the loop test duplicated before the body | `if (c) { do { ... } while (c); }`, not `while (c)` |
| `bra test` at the top, `jsr; tst r0,r0; bt body` at the bottom | `while (f() == 0) { ... }` |
| `movt r0; rts; nop` epilogue | `if (cond) return 1; return 0;` |
| `extu.b r6,r0` as the return | `int f() { unsigned char r = 0; if (c) r = 1; return r; }` |
| `add #-1; store; extu.b; cmp/pl` | `if (--p->b > 0)` on `unsigned char` |
| `add #-1; store; add #1; exts.w; tst` | `if ((p->s28)-- == 0)` |
| a tail call selected by a condition, callee in r3 | two call statements in `if` and `else`, not a ternary argument |
| two identical call sites merged into one `jmp` | exactly two sites, reached by `goto` or fallthrough, never three |
| `bra` to a shared `rts; nop` | a `goto` to a label before the call, see the file for `func_0c12eade` |
| `bra` over a short block to the single epilogue | `if (c) { A; } else { B; }`; an early `return` duplicates the epilogue |
| `extu.w` before a mask test on a word field | the field is `unsigned short` |
| a field address computed early and dereferenced later | `unsigned char *p = &b->field;` then `*p`, not a second `b->field` |
| a call after an early-return block with the target register off by one | try `else if` in place of the sibling `if`, or the reverse |
| `cmp/eq #0; bt.s; ...; cmp/eq #1; bt; cmp/eq #2; bf` into one store | separate `switch` cases with repeated bodies, allowing SHC to merge the tails; signed-byte input avoids `extu.b`. Grouped labels and `||` do not reproduce this shape. |
| `mov r14,r3; add #64,r3; mov.l @r3` next to `@(r0,Rn)` accesses | a one-element array member, `int arr64[1]`, used as `arr64[0]` |
| index computed before the pointer chain | pointer-to-array member: `(*g->p0)[a->b32 + 110]` |
| `mov.l @r5+,r3` on consecutive ints | a walked pointer: `int *p = tbl[i]; x = *p++;` |
| `lds r1,fpul; fsts fpul,fr3` for a float constant | the field is a struct member; a `float[]` element gives `mova; fmov @r0` |
| `mova C; fmov; ...; mova -C; fmov` with no `bra` | `x = C; if (cond) x = -C;` |
| `fldi1 frN; fadd frN,frN` for 2.0 | a plain `2.0f` literal (5.1R08); `tools/compiler_patterns.py` checks one 20-byte retail block |
| `r1 = dst; r2 = src; r0 = size; jsr` | struct assignment `a->s = b->s` with a member of that size; the routine name follows the struct's alignment. Never call the routine by hand |
| `r1 = dividend; r0 = divisor; jsr __modls` | `%` |
| `sts.l macl` around a multiply | any code; that is `-macsave=1`, and the game set has `-macsave=0` |
| a 12-byte frame with `mov r15,r5` passed to a call | `struct { float x, y, z; } v;` passed as `&v`, not `float v[3]` |
| `add #-12,r15` for two floats written | a three-float struct local |
| a byte at 0x159 where a `mov.w` reads 0x158 | a union of the short and two bytes |

Pad arrays run from the end of the previous member, not its start:
`unsigned char pad[0x1a3 - 0x40]` after a `float f3c` is wrong by four and
shows up as pool words off by four with correct-looking code around them.
An `extern short *dat_0cXXXXXX;` is a pointer variable and costs a load; an
`extern short dat_0cXXXXXX[];` is the array itself. Retail's `mov.l @dat,rN`
before the index means the pointer; its absence means the array.

### Guard grouping can change field-store addressing

Nested `if (index == 5) { if (flags & mask) { ... } }` guards recover the
native field-store registers in [tu_0c07d704.c](../src/verified/tu_0c07d704.c)
and [tu_0c11ef44.c](../src/verified/tu_0c11ef44.c). Combining each pair with
`&&` introduces an extra address calculation in its special-mode block.
The nested versions match their complete 312-byte and 344-byte sections.
Check this shape when a guarded constant store alone shifts the remaining unit.

### Preserve the alignment of copied records

`LinkedActorBlock` includes the animation-frame pointer at actor offset `0x154`
(block offset `0x78`). Treating that pointer as padding made the block appear
only two-byte aligned and selected `__slow_mvn` for its 192-byte assignments.
The recovered pointer gives it four-byte alignment, so SHC selects
`__quick_mvn`, matching the retail copier at `0x0c1fb838` without an import
alias. The block remains `0xc0` bytes; target layout contracts check the pointer
and block offsets and size.

A unit can also copy unaligned byte tables through `__slow_mvn` at
`0x0c1fb8f8`. Keep those imports distinct. Redirecting every copy in such a
unit to the word copier does not describe the native operations.

### A compound assignment is not its expanded form

`x ^= 1` and `x = x ^ 1` compile differently when `x` is a struct member at an
offset too large for a displacement. The expanded form loads the offset twice,
once into r0 to read the member and once into another register to build its
address for the store, which is eight bytes longer than the compound form on a
pair of members. Retail uses the expanded form in places. If a unit links
shorter than its declared size and the missing bytes sit around a
read-modify-write, expand it.

## Float literals

SHC truncates a decimal float literal toward zero instead of rounding it to
nearest, so the shortest spelling of a value is usually one ulp low and the pool
differs from retail in its last hex digit. Ask for the spelling that lands:

```sh
python3 tools/float_literal.py 0x44092492      # -> 548.571411133f
```

Before treating a pool float as arbitrary, check it against the screen scales in
[PLAYER.md](PLAYER.md): the game scales CPS2 coordinates to the display, so
1.6666666 (5/3) and 2.1428571 (15/7), their powers of two and their small
multiples run through the whole image. A mantissa ending in `92492` is one of
them.

## Let the permuter search

```sh
python3 tools/permute.py src/candidates/unit.c
```

It applies the mechanical rewrites in the table above one site at a time,
compiles each variant, keeps the one with the most equal bytes, and repeats.
Retail is the oracle: a rewrite only has to reach the bytes. Run it on a
candidate before spending your own attempts on register and spelling
differences; read what it changed afterwards.

## When it will not match

- Try the spellings above and a few of your own with the diff tool, about ten
  per function.
- If a function still differs by a register choice, check the unit extent and
  the preceding function first. Then leave the unit as a candidate: every
  function and pool that matches is already credited, and the comment at the
  top of the file must say what differs and where.
- Functions full of `fipr`, `fschg`, `ftrv`, `pref` or `fmov @Rm+` streams are
  hand-written assembly. Skip them.
- Do not rewrite instructions, add assembler, or change options. That is not a
  match.

## Open questions

- The previously open three-case comparison chain is now reproduced by
  repeated switch bodies, as described above. Two real functions match
  36/36 bytes in a linked comparison; their encompassing 620-byte unit still
  has four unmatched tail-call register bytes and is not fully verified.

- 2.0f materialised as `fldi1; fadd` (106 retail sites) needed an inline
  helper under 5.0R31; 5.1R08 emits it for a plain `2.0f` literal (see below).

- Three shared constants held in r7, r4 and r13 across one function
  (`func_0c16fc14`); SHC keeps at most two in registers.
- Resolved by 5.1R08: switch compares follow case-label source order (5.0R31
  and 5.1R01 sorted them), and a literal `/ 2.0f` compiles to
  `fldi1 frN; fadd frN,frN` in fr0-fr3. Consequences for spelling:
  write labels in the order retail compares them. When retail compares
  0,1,2 but lays out the case-1 body first, use `case 0: goto L;` or
  `case 0: goto L; default: break; case 1: case 2: ...` with `L:` on the
  later body (tu_0c104e14, tu_0c1199e0). A float parameter used directly,
  not copied into a local, keeps 5.0R31's stack slot (tu_0c190578).
- Signed remainder by a power of two inline (`cmp/pz; bf; and #K,r0` /
  `not; add #1; and #K; not; add #1`, 72 sites). `~v+1` reproduces the
  not/add negation, but the bundled SHC calls `__modls` for every `%`
  spelling and never keeps the operand in r0 for the explicit form.
  `if (r >= 0) r &= 3; else { r = ~r + 1; r &= 3; r = ~r + 1; }` gives the
  exact branch layout; only the r0 immediate form is missing. Signed
  division by 2^n (n >= 2) is reachable: `if (n < 0) n += 7; n >>= 3;`
  produces the inline idiom (tu_0c1bb1d0), and plain `x / 2` already
  compiles to retail's `cmp/gt; addc; shar`. The remaining misses there are
  ordinary register choice, not the divide.
- SDK code aligned to 16 or 32 bytes with NOP fill (function starts, loop
  heads, literal pools placed on the next boundary, shared pools after
  several functions). The `library` option set aligns functions to 4 bytes
  and never pads pools, so multi-function units there only match by
  linking the prebuilt object (`tools/libunit.py`).
- Scratch-register choice: a label immediately before a store or call
  (`goto L; L:`) changes which of r2/r3 the next temporary takes, and
  finished several units. It does not reach every pick (func_0c15f61a,
  func_0c162fb0).

## Cross-project compiler evidence

See [TBG learnings](TBG_LEARNINGS.md) before investigating constant-section,
prototype, alias, or write-order mismatches. It distinguishes locally reproduced
SHC behavior from external hypotheses and records isolated flag experiments.

For a concrete behavioral ambiguity in nonmatching integer C, the optional
[paired-execution pilot](../tools/simulator_pilot/README.md) can distinguish
wrong behavior from a code-generation mismatch on tested paths. Its original
code oracle, coverage and deliberate mutants are required controls. Use it
selectively; it neither replaces the byte gate nor adds decompilation credit.
