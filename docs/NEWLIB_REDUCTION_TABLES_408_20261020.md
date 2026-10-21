# Double reduction integer tables

Recover 408 bytes from original matching Newlib sources: the 66-word base-2^24 2/pi digit table at `0x004AB8E0`, the 32-word high-word comparison table at `0x004AB9E8`, and the four precision-dependent initial term counts `{2,3,4,6}` at `0x004AC028`.

Source initializers, symbol sizes and contents in the cached exact EE96 production code objects, and retail bytes all agree. Native code passes the digit table as argument six with precision 2 in argument five, uses the adjusted base for the `npio2_hw[n-1]` comparison, and indexes `init_jk` by precision. The emitted 32-word comparison object establishes its complete extent independently of the guarded path that selects entries 0..30.

The first two arrays replace a 392-byte prefix of the old raw unit. Its remaining 80 bytes are retained in an uncredited raw unit at `0x004ABA68`; neighboring owners are unchanged. The 16-byte precision table occupies a previously unowned interval and leaves the rest of that gap untouched.

All four standalone data objects, including the raw suffix, independently compile and match with MWCCPS2 3.0.3, -O3 -sdatathreshold 0. Different compiler probes are not treated as code-match evidence; the data audit uses the cached exact production objects. Generated listing hashes differed between workspaces, so native instruction words were rechecked directly against the pinned retail ROM. Linked credit requires combined placement, image identity and test checks.
