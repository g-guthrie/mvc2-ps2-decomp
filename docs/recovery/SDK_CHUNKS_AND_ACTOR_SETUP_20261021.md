# SJ chunk methods and actor setup recovery

This checkpoint adds 4,392 exact code bytes in 13 whole functions:

| Group | Functions | Bytes |
| --- | ---: | ---: |
| SJ memory/ring chunk methods, shared pool reset, transfer count and error callback | 6 | 1,212 |
| Inherited actor setup callbacks | 3 | 1,168 |
| Actor launch patterns, randomized start and owner resume | 4 | 2,012 |

Code reaches 2,069,520 / 3,293,696 bytes (62.8328%). Reconstructed data
remains 248,776 / 648,064 (38.3876%). The next fixed publication threshold
remains 2,080,510 code bytes; 10,990 remain.

The SJ implementations preserve the shared interface and UUID contracts,
actual SJCK payload layout and unsigned counter/address arithmetic. The
24-byte transfer-count accessor ends at 0040FD18. The following 28-byte
error callback is separately installed by the shared-pool constructor and
is reproduced by a normal C infinite loop with native compiler padding.
The old handwritten accessor/spin-loop placeholder is removed. Other
assembly placeholders gain no C credit.

Actor callbacks retain real owner arguments and native unordered floating
comparisons. One-argument callees receive their actual single actor argument;
owner-aware callees receive their owner explicitly. PollSema captures and
returns the actual V0 kernel result, and FlushCache accepts its actual
operation argument. These call-contract repairs add no extra code credit.

Four native callback entries are proven by existing retail table pointers.
Their leading 40 alignment bytes remain uncredited. The root confirmed
those words are zero and scanned 797,346 cataloged code words for direct
branch/jump targets, plus all cataloged initialized data pointers: none
enter the proposed padding. The new actor switch section at 004B5B30 is
verified as a complete 24-byte readonly owner, without data credit here.

Root independently rebuilt 11 production units and verified all 230 current
registered functions, including existing bodies and remaining placeholders.
The shared-pool constructor was independently reverified as well. All 111
tests and coverage/catalog checks pass. A fresh split, full hybrid relink
and ELF pack reproduce all retail bytes and the expected ROM/executable
SHA-256 identities. All 47 headers and 15,188 other cached source/object
pairs remain unchanged against the preceding verified checkpoint.

The root compared new production objects with the CODE lane's immutable
receipts. Loadable sections, relocations, symbols and section headers agree.
Some Sony objects differ only in .mdebug build-path metadata; each root
object still receives its own complete retail instruction/relocation proof.
No compiler, SDK, executable or object file is committed.
