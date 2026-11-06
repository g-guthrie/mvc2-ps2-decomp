# Bounded service data, strings and callback state

Native producers and consumers establish nine initialized objects totaling41
new reconstructed bytes. The assigned interval contained26 placeholder rows
(616 bytes); this change replaces eight rows covering80 bytes. It leaves39
of those bytes as separate raw fragments and leaves the other rows untouched.

| Address | Meaning | Reconstructed bytes |
| --- | --- | ---: |
| 004C23B8 | `CDV` service key, including NUL | 4 |
| 004C23C0 | `HST` service key, including NUL | 4 |
| 004C2428 | `(c)CRI` file signature, including NUL | 7 |
| 004C2440 | signed RPC service ID | 4 |
| 004C2460 | two signed callback arguments | 8 |
| 004C246C | callback context pointer | 4 |
| 004C2490 | allocation byte count | 4 |
| 004C24D0 | signed resource reference count | 4 |
| 004C2508 | space string, including NUL | 2 |

The service keys are passed to native string registry/lookup routines. The
copyright signature is measured and compared with file data. The existing
four-byte pointer at004C2430 now names that complete string directly, replacing
its offset into the retired integer-array representation; its bytes and prior
credit are unchanged. Its MIPS32 relocation resolves to004C2428.

The RPC value is passed as the integer service ID to server registration and
client lookup. The callback setter and dispatcher share the two integer words;
a separate setter and error callback share the context pointer. The byte count
is computed from the pool capacity and passed to the allocator. The reference
count is incremented/decremented around resource setup/teardown; its following
28 bytes remain raw. The space string is used by bounded concatenation, and
its two following zero bytes remain uncredited.

The remaining gaps, prefixes and tails receive zero reconstruction credit.
The version-banner address at004C2414 still lacks a closed pointer-use or
return-type contract. Its load leaves the word in V0, but no observed typed
caller establishes how that value is used. Unbounded index tables
and compiler switch tables without complete matching C owners stay deferred.

All15 affected objects, including raw fragments and the rebased existing
pointer, independently compile and verify against retail. The native proof
pins735 distinct producer/consumer instruction addresses to the reference
image (775 excerpt entries checked). All118 tests, catalog/build coverage,
fresh split and both complete retail
image comparisons passed. The verified rows now receive linked credit. The
cache audit pins14,815 unchanged source/object pairs and47 unchanged headers;
eight old owners are retired, one pointer owner rebuilt and14 new pairs added.

Local reconstructed data reaches256,369 /648,064 bytes (39.5592%). Local code
remains2,076,552 /3,293,696 (63.0463%). The next fixed code publication grid
is still2,080,510, with3,958 bytes remaining.
