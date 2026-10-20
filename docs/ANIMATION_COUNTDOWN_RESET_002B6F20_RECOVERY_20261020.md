# Exact animation-command countdown reset

`func_002B6F20` matches all 224 bytes with MWCCPS2 3.0.3 using the literal
`-O4 -Op -sdatathreshold 8` profile. Root independently replayed that exact
production recipe and the entire native function after relocation.

The chained halfword/signed-byte reset is retained in an integer local,
matching the native value extension at definition. The initial word reset
uses its direct field view, and a pointer to that word is taken afterward
for the later conditional reset. This models the actual field accesses and
lifetimes rather than deferring a byte-local extension until its later use.
The signed halfword counter, command consumption, timer transition and
animation helper calls retain the native order and real arguments.

There are no compiler barriers, volatile qualifiers, assembly, padding,
or new data credits. The previous three-instruction near-match remained
uncredited until all 56 native words matched.
