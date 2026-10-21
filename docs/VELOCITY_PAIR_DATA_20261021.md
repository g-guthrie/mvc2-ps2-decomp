# Velocity pairs and timers

The mode-1 child objects constructed by003C12D0 select exactly variants0,1,2.
Its three mode-1 calls in003C13D0 supply those constants; its other call is
mode9 and follows a separate callback family. The other constructors of the
same object class select modes0 and2..8. Their callbacks do not rewrite the
mode or variant bytes. The mode7 path has a dynamic variant but routes through
a separate table and does not reach the velocity reader; no global bound is
claimed for that unrelated dynamic byte.

The only velocity callback roots are00475CB0[1] ->003C1A20 and
00475D10[0] ->003C1A40. The consumer loads signed halfwords at pair offsets0
and2, using a four-byte stride, and reads a signed timer byte at004C20F0.
The supported DATA owners are three signed XY pairs (12 bytes) and three
signed timers (3 bytes). The00475CA2 label remains an interior alias for the
first pair's Y field. The code-entry and dispatcher-head split is unchanged.

Root checked989 native instruction PCs from the independent producer-domain
audit against retail, including constructors, caller chains, dispatcher and
consumer. Root then rebuilt all three resulting whole DATA objects: the
12-byte pairs, their4-byte raw tail, and the3-byte timers. Every byte matches.
The five following timer bytes remain outside the source catalog and are
preserved by the raw hybrid image. Neither those bytes nor the pair tail gain
credit. The containing names/aliases and all neighboring tables stay intact.

Root's aggregate frozen-input gate passes118 tests, catalog and build coverage,
fresh split, complete loaded-ROM identity and packed-ELF identity. The audit
checks14,934 unchanged source/object pairs, seven rebuilt existing units,
eight new pairs,47 unchanged headers and one new shared ABI header. Linked
matching CODE is2,080,660 /3,293,696 bytes (63.1710%); linked reconstructed
DATA is256,703 /648,064 bytes (39.6107%). This crosses the existing fixed
CODE threshold2,080,510 by150 bytes. After this checkpoint's publication,
the next fixed threshold advances to2,113,447; the surplus is retained.
