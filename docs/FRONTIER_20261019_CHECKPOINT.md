# Verified frontier checkpoint, 2026-10-19

This checkpoint adds 70 complete C functions (6,300 bytes) after the Grok import, reaching 1,850,068 / 3,293,696 matching code bytes (56.1700%). Reconstructed initialized data reaches 174,377 / 648,064 bytes (26.9074%).

The code includes Sony RPC helpers, collision and animation routines, state callbacks, and 50 short dispatch/accessor functions. The dispatcher entries, sizes, and compiler profiles are listed in [FRONTIER_20261019_DISPATCH_RECOVERIES.csv](FRONTIER_20261019_DISPATCH_RECOVERIES.csv). Wider native inventory spans were partitioned at independently referenced entries; uncovered bytes and alignment remain uncredited. The earlier Grok import ledger remains scoped to its original input commit.

The new eight-byte data recovery is the two-entry integer-returning getter table at 004C21E0. Its consumer, 003D90A0, forwards the selector and returns the callback result. All eight direct native callers pass 0 or 1: 0032FC38, 00330B30, 00330D48, 003366B0, 0033D36C, 0033E910, 00340EB8, and 003448B4. The two getter entries are independently referenced and recovered; the preceding 48-byte pointer range remains a placeholder. Both split objects match retail. Corrupting a relocation addend in a private copy causes verification to fail.

Independent validation used each production compiler recipe, including the older MWCC compiler and Sony EE 2.9 where required. All 38 affected/caller translation units replayed exactly. All 53 tests, catalog validation, shell syntax, and 3,673-source build coverage pass.

The full 3,941,760-byte hybrid image remains byte-identical, SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`. The packed 3,942,320-byte retail ELF remains byte-identical, SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
