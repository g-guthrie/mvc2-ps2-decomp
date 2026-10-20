# Newlib fseek recovery

`func_0011BF48` is the complete 1,196-byte Newlib `fseek` implementation. The source is adapted from upstream commit `91a8d90babddd48b5ce982eaddeff0c94640d7c8`, `newlib/libc/stdio/fseek.c`; the Berkeley notice and acknowledgement are retained. It preserves buffered relative seeks, append flushing, regular-file block seeks, and ungetc cleanup.

The production recipe is SNCPP, EE GCC 2.96 `-O2 -G0 -ffunction-sections` with no extra flags, then SNAS `-G0`. Standard relocated-object verification checks all 1,196 native bytes. The object has no readonly pool to place or credit.

The shared `FILE._seek` callback accepts and returns signed 64-bit offsets. Native `fseek` uses `daddu`/`dsubu` on current positions, and `0011FAB0` preserves the complete returned value for its failure test, truncating only the cached signed word at FILE+0x50. This agrees with the existing `SdkFile.seek` and reentrant seek definitions. The header correction changes no structure offsets.

The native stat layout follows Newlib's original complete structure: mode at +4, signed 64-bit size at +0x10, and a total of 104 bytes. It uses the actual Newlib fields, including timestamps and spare fields, without a fabricated stack tail. Native fseek uses the default 1,024-byte block size rather than HAVE_BLKSIZE.

The header's complete include closure contains thirteen existing C translation units; no other header includes it. All twenty-two credited functions in that closure were replayed exactly with their production profiles, including `-msoft-float` for dtoa/mprec. The fseek function adds 1,196 code bytes; the callback contract correction adds no separate credit.
