# Motion tables, callback contracts and EE records

This checkpoint adds 8,652 complete matching code bytes and 7,312 reconstructed
data bytes. The hybrid build still supplies unmatched spans from the private
retail image. Identical rebuilt images therefore do not establish complete
source decompilation.

## Recovered data

Two character motion tables contain 59 records each. Each record has three
variants of four signed halfword motion components. The reader selects the
character with an unsigned byte and the variant with a signed byte. The two
typed banks account for 2,832 bytes; their raw prefixes and suffixes remain
uncredited. The existing address alias at 0x447AE0 remains in its raw suffix.

The scale resource contains 51 blocks of eight float pairs and a 59-entry
pointer directory. Eight directory entries share existing blocks. Each pair is
eight bytes, each block is 64 bytes, and the base is 32-byte aligned. The native
reader selects a pair and applies its values to actor scale. These 3,500 bytes
replace 26 raw providers while preserving the previously reconstructed prefix
and its aliases. The shared header has exactly two freshly compiled includers.

The GS command resource contributes 19 address/data records, 304 bytes. Native
packet submission covers four contiguous ranges of 1, 1, 11 and 6 records;
each record carries two 64-bit words. The remaining 496 bytes have different
packet and renderer consumers and retain a raw owner. The schema is local to
its single source file.

The EE resource contributes 676 bytes: 13 kernel, 18 default and eight extended
TLB entries, a seven-field TLB information record, two syscall-hook records and
two semaphore IDs. Each TLB entry has four 32-bit fields consumed at a 16-byte
stride. The new hook declarations agree with the actual handler interfaces;
their generic address storage agrees with the existing patch-installation
consumer. Interior legacy names remain address aliases. The copied executable
payload, runtime state slot and gaps remain raw and uncredited. The new TLB
header has exactly four freshly compiled includers.

These layouts establish concrete resource ownership and local access formats.
Valid actor, resource and selector inputs remain ordinary preconditions. This
checkpoint does not claim exhaustive safety of every mutable game state.

## Code and interface repairs

Eighteen complete functions recover sequence, motion, collision-height, phase
and callback behavior. They retain the native byte and halfword narrowing,
ordered and unordered float branches, helper-call order and field reloads.
The coordinate sampler and angle updater use ordinary C double arithmetic
and conversions rather than explicit sequences of arithmetic-runtime calls.
The sampled-height gate explicitly preserves the native unordered branch.

The owner timer callback uses both its incoming timer context and the actor's
substate pointer in their distinct native roles. Its existing shared const
callback table contains real context consumers as well as entries that ignore
context. Five existing source files now express that common interface
consistently; every rebuilt object remains byte-identical.

The math-wrapper declarations now carry their actual two-float inputs and
return contracts. Allocator declarations and callback stores use their actual
provider types. Irrelevant new loop-padding pragmas were removed after proving
that the clean source produces the same objects. Native address-map aliases
are included for normal production verification.

One rebuilt Sony object contains a generated temporary filename in non-loaded
`.mdebug` metadata. Its only permitted file differences are the 32 hexadecimal
filename characters at offsets 324 through 355. Executable sections, data,
symbols, relocations and every other object byte remain identical. This is
checked separately from the unchanged strict relocated-function verifier;
objects are never patched or normalized.

## Verification and accounting

The bank preserves 14,614 unchanged source/object pairs and all 53 existing
headers, freshly compiles 13 changed old and 35 new source units, and retires
31 raw providers. It leaves 14,662 source/object pairs and 55 headers. Both new
headers' complete includer sets are freshly compiled.

Publication requires catalog and build coverage checks, all project tests,
fresh splitting, hybrid placement and byte identity of both the loaded ROM
and packed ELF. Only complete relocated compiler matches receive code credit;
raw data gaps, address aliases and zero-fill annotations add no data credit.
The held callback-interface candidates are excluded.

Totals are 2,113,824 / 3,293,696 code bytes and 373,884 / 648,064 data bytes.
This crosses the fixed code checkpoint at 2,113,447 bytes. The following fixed
checkpoint is 2,146,384 bytes; extra data publications do not reset that grid.
