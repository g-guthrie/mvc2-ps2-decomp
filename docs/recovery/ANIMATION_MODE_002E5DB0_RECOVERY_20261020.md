# Exact actor animation-mode dispatch

`func_002E5DB0` is a complete 272-byte C match using MWCCPS2 3.0-011126
`-O4,p -sdatathreshold 8`. It passes the actual actor pointer to the existing
`func_003D92F0` state predicate, cancels a completed special action, and
switches on the actor mode. The native order is the older compiler's switch
lowering; a series of hand-written goto comparisons did not match.

Mode zero updates the actor, checks the embedded animation flag, and issues
the appropriate palette-copy index. That index is computed as one grouped
expression. The old candidate omitted the predicate's pointer argument and
separated the arithmetic, giving incorrect register use.

`func_00176160` now explicitly accepts the native word-sized index and narrows
it to u16 inside its provider before use. Its native body performs that
narrowing itself; this preserves behavior for every input and represents the
actual caller/callee word transfer. Both existing functions in `y11_d.c`
(408 bytes) remain exact with the original modern O3,p/G0 profile. The
new caller correctly declares the helper's void return and four arguments.
No assembly, synthetic clobbers, or padding are added.
