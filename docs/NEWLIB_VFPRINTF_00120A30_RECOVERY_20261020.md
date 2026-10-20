# Exact Newlib formatted-output core

`func_00120A30` matches all 5,744 bytes with EE GCC 2.96, `-O2 -G0`,
function sections, and SN's assembler `-G0`. This adds 5,744 code bytes.
Five previously credited neighboring functions are consolidated into the
same original translation-unit family without increasing their credit:

| Entry | Bytes | Role |
| --- | ---: | --- |
| 001208B8 | 72 | Flush the pending output vectors |
| 00120900 | 180 | Buffered adapter for an unbuffered stream |
| 001209B8 | 116 | Initialize the stream and enter the reentrant formatter |
| 00120A30 | 5,744 | Reentrant formatted-output core (new credit) |
| 001220A0 | 448 | Convert a floating value to digits |
| 00122260 | 220 | Format an exponent |

The five separate helper files and their compile recipes are removed.
Every selected function is independently verified from the consolidated
object; existing callers and the shared stdio ABI header are unchanged.
The helper definitions retain their genuine bodies and native addresses.
There are no artificial clobber declarations or duplicated progress rows.

## Source and configuration evidence

The source adapts the Berkeley RCS 1.28 Newlib formatter, retaining its
complete 1990 Berkeley redistribution notice. The historical base is the
official Newlib 1.8.2 release at
https://sourceware.org/ftp/newlib/newlib-1.8.2.tar.gz (archive SHA-256
`e52667ed78595dd1919f4a303f8b658b1d57b926e085e8021851b279143cf3ef`;
`newlib/libc/stdio/vfprintf.c` SHA-256
`0c754ff08147f8128348dd164b8594e57f6866460c873f3087a2a239964bfa7d`).
The target adaptation moves `CHECK_INIT` to the outer wrapper and retains
the parenthesized `ALT` test, named native calls and shared ABI types.
Its two floating-output conditions follow the official Newlib 1.10.0 release:

- The `expt <= 0` case emits decimal-point, padding and digit vectors only
  when `expt || ndig` is true.
- The exponential case emits the remaining digit string when the floating
  value is nonzero; its zero case pads with zero characters.

The official release is available at
https://sourceware.org/pub/newlib/newlib-1.10.0.tar.gz . The archive SHA-256 is
`69b62ad4c746a9acaf4f898772549f6da49f228f83a95efce7e88ae1d88c5a84`;
its `newlib/libc/stdio/vfprintf.c` SHA-256 is
`003e3ce3d347d25e64d1e2a705c5f972b20aa02d1769c333797819ac1899cab3`.
The release file identifies itself as RCS 1.34, dated 2000-12-08.
The consolidated source's older conditional RCS string belongs to its
RCS 1.28 seed; it is not a claim that the two floating paths are unchanged.

The target configuration enables floating-point formatting and disables
long-long formatting (`_NO_LONGLONG`). EE GCC's `unsigned long` is 64 bits,
while its pointers and `unsigned int` are 32 bits. Using a 32-bit substitute
for `u_long`, or enabling the separate long-long formatting path, produces
the wrong code. The upstream pointer-to-long conversion is retained; the
compiler's width warning is expected for this ABI. Numeric math helper
names map to the already reconstructed native infinity/NaN predicates with
proper double-argument declarations.

## Verification and constants

Root independently recompiled the canonical source using the canonical
shared ABI header, then verified all six whole-function instruction spans
with the unmodified production verifier. The complete 516-byte read-only
section at 004AC9E0 is validated, including all 89 relocations into owned
function bodies. Its explicit mapping in `config/readonly_sections.csv`
awards no data credit; it remains an uncredited compiler-constant region
in the hybrid image. Eight missing address declarations identify actual
native functions/data and do not introduce progress claims.

A fresh full executable split passes. The linked loaded image remains
exactly 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed retail ELF remains exactly 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Unreconstructed regions remain uncredited.
