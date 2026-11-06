# Selector-bounded switch prefixes, 2026-10-20

Recover 552 initialized bytes across eighteen native switch consumers: thirteen complete six-entry tables (312 bytes) and five twelve-entry prefixes (240 bytes). Native unsigned selector guards, matching scaled indices, and indirect dispatch establish each credited extent.

The prefix owners are jtbl_004AD190, jtbl_004B9380, jtbl_004B3830, jtbl_004B10A0, and jtbl_004AD140. Their remaining 216 bytes are split into five raw placeholder units and receive zero reconstructed credit. Each original extent is exactly partitioned; adjacent gaps remain unchanged.

Sources use typed const byte-address pointers to 109 distinct registered interior code locations. Every selected target is an aligned native instruction inside its owner, with occurrence counts checked against retail data. No parent-function source credit is implied.

All 23 resulting sources, including uncredited tails, independently compile with MWCCPS2 3.0.3, -O3 -sdatathreshold 0 and match the relocated retail spans. Final verification also checks all registered consumers, catalog extents, hybrid placement, retail loaded-image identity, packed ELF identity, and all 95 tests.
