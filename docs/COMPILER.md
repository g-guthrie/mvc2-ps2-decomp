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

`0x00102C58` target words:

```text
lw v0,0(a0); sw a1,0(a0); srl v0,v0,8; jr ra; andi v0,v0,1
```

The natural unsigned C probe at O3 emits the identical five instructions but
orders the middle pair as `srl; sw`. It is 3/5 exact by instruction position
(60%) and is not counted as matching C.

Private scratch artifacts include locally downloaded compiler binaries and must never be copied into this public repository.
