# Bounded file-request record layout at 00489220

The former 944-byte zero array is split into a 13-record file-request table
(624 bytes) and its independent 320-byte neighboring buffer. The allocator,
queries and cleanup all use 13 records at a 48-byte stride; record release
clears exactly 48 bytes. The table ends at 00489490, the neighboring buffer's
native address. Adjacent scalar objects retain their existing ownership.

Six consumer translation units and the data definition share the tagged
`HtciFileRequest` type. The data source includes the shared header rather than
duplicating it. Known fields describe slot/operation state, open state, file
size, result, handles, transfer count and progress. Unread word-sized spans use
an opaque union with byte and word views, so observed word stores do not write
through declared byte-array subobjects. Byte-wise tests retain character views
of the actual table object.

| Offset | Known field | Bytes |
| --- | --- | ---: |
| 00 | Slot state | 1 |
| 01 | Open flag | 1 |
| 02 | Operation state | 1 |
| 08 | File size | 8 |
| 14 | Service result | 4 |
| 18 | File handle | 4 |
| 1C | Transfer progress | 4 |
| 24 | Requested byte count | 4 |
| 2C | Request handle | 4 |

These fields occupy 31 bytes per record, 403 bytes across the table. The
remaining 17 bytes per record (221 total) retain opaque representations.
Some opaque words are written during initialization but have no audited read;
broad clearing establishes the record extent without establishing field
meaning. The neighboring 320 bytes remain raw.

Both data objects stay `placeholder` in the progress catalog. This is source
layout recovery without a percentage increase; the full 624-byte object is
not counted as semantically reconstructed data.

Every function in all six changed consumer units was independently compiled
with its existing EE GCC 2.96 production profile and verified against native
code. Both complete data spans were independently compiled with MWCCPS2 and
verified byte-exact. A separate probe compiled the actual shared header with
unique field/gap sentinels: all 48 output bytes match the expected consecutive
values, proving every member offset, union location, alignment and total size.
The all-zero data comparison alone would not prove this layout.

The six consumer units contain 39 complete catalogued spans; all remain exact. The table and neighboring buffer retain placeholder progress status.
Fresh split, full loaded-image linkage, packed ELF identity, build coverage,
catalog validation and all 91 tests pass. SHA-256 values remain
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
and `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code is 2,035,336 / 3,293,696 bytes (61.7949%); data remains 30.2566%.
