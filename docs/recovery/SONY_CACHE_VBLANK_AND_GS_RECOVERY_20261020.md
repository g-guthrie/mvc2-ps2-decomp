# Console, cache, VBlank and GS recovery

Six complete native-derived functions add 780 matching code bytes with the
production Sony EE GCC 2.9 O2/G0 and SN assembler profile:

| Entry | Bytes | Behavior |
| --- | ---: | --- |
| 00104428 | 116 | Read console channel zero, initializing the console when needed. |
| 001046D8 | 124 | Preserve interrupt state and invoke the cache backend on aligned endpoints. |
| 00104818 | 124 | Apply the second cache backend with the same interrupt-state contract. |
| 00104270 | 144 | Acknowledge, wait for, and acknowledge interrupt-status bit four. |
| 00101DF0 | 136 | Compute packed GS half offsets from signed short inputs and scissor dimensions. |
| 00102058 | 136 | Perform the corresponding operation for the second draw context. |

The cache wrappers align both physical addresses to 64 bytes and restore enabled
interrupts only when the saved COP0 status required it. A small inline MFC0
operation reads that hardware status; the alignment and conditional calls are
compiled C. The range caller now declares the recovered pointer interface and
uses defined unsigned address arithmetic. All nine functions in its source unit
remain exact.

The VBlank wait uses a volatile 32-bit access at 0x1000F000, mask four, and the
actual sync instruction with a memory clobber after each acknowledgement. Both
interrupt save/restore sequences preserve the native behavior. The polling loop
contains ordinary C and reloads the MMIO register on each iteration.

Each GS setter reads the scissor register at context offset 0x30 and writes the
packed XY offset at 0x20. The source union describes the four eleven-bit scissor
coordinates and their five-bit gaps. The setters use X1/Y1, add one before
halving, subtract from the signed short inputs, and scale to four fractional
bits. The vertical field adjustment adds eight when requested. Arithmetic after
widening uses unsigned 64-bit values, retaining the native bit pattern for
negative inputs without shifting a negative signed value.

A shared opaque context declaration gives the existing graphics caller the
same pointer and three signed-short argument types. Its complete 280-byte body
remains exact. The Metrowerks build stanza now explicitly includes src/ so the
new declaration is available during a clean build. The two setters share a C
macro for their identical operations; no runtime helper or new data is emitted.

All six functions pass relocated whole-function comparison. The two changed
caller source units pass across all ten existing functions. Fresh splitting,
full-image hybrid linkage, packed retail ELF comparison and all 91 tests pass.
This batch adds no reconstructed-data credit.
