# Runtime-service arrays

Native dispatcher004118B8 sets a signed word at00496728+4*mode to1 while
calling a registered callback, then returns it to0. It increments the word
at00496708+4*mode once per dispatch. Seven direct wrappers supply the seven
constant modes0..6. The adjacent callback API also uses a native mode limit
of7. These establish seven running flags and seven execution counters,
28 bytes each. No absolute function-pointer cells or relative branches to
the dispatcher were found in the retail image; the complete service window
[004118B8,00411B98) is pinned instruction-by-instruction to retail.

The initializer00411B28 clears exactly28 flag bytes. Its counter loop clears
only the first four words; the last three counters are still real accessed
state, with zero initial values present in the retail initialized-data image.
The separate counter reader00411B00 accepts only unsigned indices below5.
The DATA reconstruction preserves these distinct observed behaviors.

The containing raw zero owner is split at the two independently identified
arrays. Its2256-byte prefix, four-byte gap and268-byte tail stay uncredited.
Only56 typed state bytes gain reconstructed credit. Root compiled every one
of the five resulting whole objects with the production MWCC3.0.3 O3/G0
recipe and verified each complete section against retail. No CODE changes
or credit are part of this DATA recovery; existing external address views
retain their native bindings.

Root's aggregate frozen-input gate passes118 tests, catalog and build coverage,
fresh split, complete loaded-ROM identity and packed-ELF identity. The audit
checks14,934 unchanged source/object pairs, seven rebuilt existing units,
eight new pairs,47 unchanged headers and one new shared ABI header. Linked
matching CODE is2,080,660 /3,293,696 bytes (63.1710%); linked reconstructed
DATA is256,703 /648,064 bytes (39.6107%). This crosses the existing fixed
CODE threshold2,080,510 by150 bytes. After this checkpoint's publication,
the next fixed threshold advances to2,113,447; the surplus is retained.
