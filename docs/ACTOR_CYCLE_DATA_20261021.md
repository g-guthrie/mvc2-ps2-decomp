# Bounded actor cycle frames

The table at0044E700 is now reconstructed as two groups of nine CycleFrame
records. Each record has four signed16-bit fields: frame, horizontal offset,
vertical offset and flags. The original144-byte span, data symbol name and
CODE address alias remain unchanged. The legacy data_u32 identifier is kept
for compatibility; its C type is now the recovered record type.

Native constructor001D8580 is called with modes0,1,2 at003AC68C,003AC69C
and003AD2F0. Its cleared allocation starts with state and timer zero. The mode
dispatch table0044E790 sends modes0/1 to the cycle path; mode2 enters another
path. The state table0044E7A0 initializes the timer and then invokes001D8700.
That consumer selects mode*9+timer, loads signed halfwords at offsets0,2,4,6,
and advances the timer modulo9. These paths establish exactly18 eight-byte
records. No following padding or dispatch-table bytes gain new credit.

Root checked623 distinct native instruction PCs in the independent ownership
packet against retail, checked its frozen input manifest, then rebuilt the
whole144-byte DATA object using the production MWCC3.0.3 O3/G0 recipe. All
bytes match. Its output object is identical to the earlier raw initializer,
but the recovered structure, native references and bounded selectors now
support144 bytes of reconstructed DATA credit. The adjacent12-byte and28-byte
symbolic dispatch tables retain their existing credit and sources.

Root's aggregate frozen-input gate passes118 tests, catalog and build coverage,
fresh split, complete loaded-ROM identity and packed-ELF identity. The audit
checks14,934 unchanged source/object pairs, seven rebuilt existing units,
eight new pairs,47 unchanged headers and one new shared ABI header. Linked
matching CODE is2,080,660 /3,293,696 bytes (63.1710%); linked reconstructed
DATA is256,703 /648,064 bytes (39.6107%). This crosses the existing fixed
CODE threshold2,080,510 by150 bytes. After this checkpoint's publication,
the next fixed threshold advances to2,113,447; the surplus is retained.
