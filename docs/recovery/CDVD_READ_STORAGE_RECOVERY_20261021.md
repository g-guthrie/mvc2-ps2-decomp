# CD/DVD read storage recovery

Four bounded writable objects replace parts of the 4,476-byte zero placeholder
at `[0x00439A04,0x0043AB80)`. They add 212 reconstructed DATA bytes. The remaining
4,264 bytes retain five raw placeholder owners. Neither neighbouring response
word, at 00439A00 or 0043AB80, belongs to this replacement.

| Owner | Address | Bytes | Native role |
| --- | --- | --- | --- |
| Read request | 00439A80 | 24 | Sector, count, destination, four-byte mode, completion and position pointers |
| Read completion | 0043AA80 | 144 | Two signed byte counts, two destinations, two 64-byte edge buffers |
| Current position | 0043AB40 | 4 | One-word DMA/RPC result buffer |
| SIF client | 0043AB50 | 40 | Existing Sony RPC client record |

Native 0010F968 constructs the request and sends exactly 24 bytes. It embeds the
completion and current-position addresses. The native cache operations cover
144 completion bytes and four position bytes; the latter is a real one-word
result buffer, represented as `u32[1]`, not an invented padded object. Two direct
callers corroborate the read operation. No object capacity is inferred from the
size of the original zero gap.

The callback 0010E908 reads signed counts and copies each edge buffer to its
specified destination when its count is positive. Valid completion records have
counts at most 64 and valid corresponding destinations. The data provider and
callback use compatible tagged `CdReadCompletion` definitions with signed counts;
equal layout alone would not make distinct struct types compatible.

The SIF record reuses `SonyRpcClient` from the existing
`src/sony29_rpc_packet_header.h`, including its actual receive record, buffers,
completion function, parameter and server fields. It is compatible with the
owned RPC bind implementation. The address-only declarations in the CD/DVD
callers use the same tag and pass the object's address. An unused byte-array
declaration in another compilation unit is removed. The existing header is
unchanged, and all four affected code objects remain byte-identical.

The public protocol reference is
[PS2SDK at revision 329e2bb43287e16af16c4dde1c614e2662c24468](https://github.com/ps2dev/ps2sdk/tree/329e2bb43287e16af16c4dde1c614e2662c24468).
Its CD/DVD read structures and SIF definitions corroborate the native fields.
The actual owners, accesses, call arguments and lengths were separately checked
against the retail executable. All nine partition objects compile and verify
over their entire spans. Previous credit in the replaced window was zero.

## Animation velocity storage

The separate `[0x0045286C,0x00452930)` placeholder is split into a 100-byte raw
prefix, a 32-byte float table at 004528D0, and a 64-byte raw tail. Only the eight
floats receive DATA credit. They represent two animation banks, two sides per
bank, and x/y velocity components per side.

The reconstructed 252-byte 00240930 callback requires `p[0x1B7] < 2` for its
lookup. Mode byte 0x20D equal to 2 chooses the second 16-byte bank; other modes
choose the first. This explicit valid-selector contract does not claim closure
of every global scheduler path. The table has genuine compatible float storage;
it is not read through a false float declaration over a word-array provider.
Acceleration writes use the actual float members at 0x68 and 0x6C, including
`-1.6071428060531616f`. The whole callback and all three data objects verify
exactly. The 164 raw neighbouring bytes remain uncredited.

## Owner and resource callbacks

Three further whole callbacks add 1,608 code bytes. The 484-byte 003400A0
resource callback receives a two-word `{actor, phase}` context record. Its native
producer places that record on its live stack and passes it through synchronous
00170E60 dispatch. The context is neither a direct actor pointer nor a persistent
allocation. Resource descriptors use the existing compatible types and integer
handle/address APIs, with valid live handles and allocated stream storage.

The 676-byte 003474C0 owner/counterpart callback retains the native unordered
floating comparisons, including the outer negated `<=` and inner negated `<`
conditions. Assuming all positions are finite would change those branches.
The 448-byte 0034CA70 phase callback preserves the actual mixed integer/float
helper inputs, inherited position and facing, cached phase, event and speed.

Its byte lookup at 004C1A20 is an independent native region between the end of
the table at 004C19A0 and the next table at 004C1A28. The unsized const-byte
extern permits the code view with a valid phase index from 0 through 7. Its
section annotation selects the observed GP-relative instruction; the undefined
symbol has size zero and emits no storage. This does not recover an original
ELF section name, a DATA owner or a global phase bound. No DATA credit is assigned
to this lookup. Together with the velocity callback, the batch adds 1,860 CODE
bytes; the two data partitions add 244 DATA bytes, with raw fragments excluded.
