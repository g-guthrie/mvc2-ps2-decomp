# Runtime-entry prefix fields

The runtime pool contains sixteen slots at stride 0x438. Each slot has a
0x38-byte control prefix followed by sixteen previously reconstructed 64-byte
records. Native allocation and cleanup loops bound the pool to sixteen slots;
release clears exactly 0x4380 bytes.

This recovery adds 30 directly accessed prefix bytes per slot, 480 bytes total:

| Offset | Bytes | Field evidence |
| --- | ---: | --- |
| 0x00 | 1 | Allocation and active-entry flag. |
| 0x02 | 1 | Read-state byte tested and updated by 0040D738. |
| 0x08 | 4 | Input argument stored by creation and forwarded by reading. |
| 0x14 | 4 | Computed request threshold/size. |
| 0x18 | 4 | Total-byte parameter. |
| 0x20 | 4 | Record cursor advanced by completion. |
| 0x24 | 4 | Remaining count tested and decremented. |
| 0x28 | 4 | Request handle opened, used and cleared. |
| 0x2C | 4 | Computed scaled/block count. |

The other 26 bytes per prefix remain raw, including 0x04..0x07. Overall, 416
reserved prefix bytes retain placeholder status. The existing sixteen 0x400-byte
record-body units retain their prior credit. No full-slot or full-pool credit is
inferred from the broad clear operation.

Adjacent known fields are grouped into two-field and four-field structures.
Each prefix therefore has five typed objects and five raw gaps. This produces
160 compiled objects replacing sixteen raw prefixes, without a new build rule.
The first byte object has the same unsigned-byte-array declaration used by its
consumers. Row traversal uses the target's 32-bit integer address arithmetic
before selecting a RuntimeEntrySlot view; it does not index beyond that first
byte array as if it were a complete C array of slots.

All 160 replacement objects were independently recompiled using the production
MWCCPS2 3.0.3 profile and verified across their full spans. An independent
partition check confirms that each prefix is tiled exactly, with 30 reconstructed
and 26 raw bytes. All seven functions in the four changed consumer source units
remain byte-exact under their production EE GCC 2.96 profiles.

A fresh split, full hybrid-image link, packed retail ELF comparison and all 91
tests pass for the integrated code and data.
