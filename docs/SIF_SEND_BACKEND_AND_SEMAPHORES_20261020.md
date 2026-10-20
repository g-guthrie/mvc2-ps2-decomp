# SIF send backend and semaphore initialization

Two complete native-derived functions add 380 matching code bytes:

- `00106298` (308 bytes) validates the command packet size, builds at most two
  DMA descriptors, performs the required cache operations and submits them.
- `0010CA80` (72 bytes) creates two semaphores with maximum and initial count
  one, storing the returned IDs in the existing globals.

The send backend accepts command packets from 16 through 112 bytes. A positive
payload size adds a first descriptor and fills the packet's 24-bit data-size
field and destination. The command packet becomes the final descriptor, with
attributes 0x44. The descriptor array has two entries: its selected packet slot
is zero or one, and the submitted count is one or two. Mode bit four requests
payload writeback; packet writeback always precedes submission. Mode bit one
selects the interrupt DMA syscall.

The command header uses the native 8-bit packet-size / 24-bit payload-size
layout. Unsigned arithmetic expresses the packet-size guard for all input bit
patterns. The descriptors reuse SonySifDmaTransfer; the compiled function uses
EE GCC 2.9 O2/G0 with strict alias analysis disabled for the packet views.
All code, including descriptor construction and error paths, compiles from C.

The normal DMA primitive already exposes its pointer/count and integer result.
The interrupt primitive now has the corresponding typed interface and explicit
syscall-result capture. All 156 functions in that compilation unit remain
byte-exact; the 16-byte primitive contributes no additional matching credit.

The initializer reuses SonyEeSemaParams and two distinct local records. It
preserves the native partial initialization: only max_count and init_count are
assigned in each record. The recovery makes no claim about kernel treatment of
the remaining uninitialized members. Both CreateSema calls use the existing
pointer interface and return their IDs through the native integer result.

Both complete functions pass relocated object comparison with the production
compiler profiles. Fresh splitting, full-image hybrid linkage, packed retail
ELF comparison and all 91 tests pass. All previously cached source/object pairs
outside the changed syscall unit and all forty headers remain unchanged.
