# Verified frontier checkpoint, 2026-10-19

This checkpoint adds 70 complete C functions (6,300 bytes) after the Grok import, reaching 1,850,068 / 3,293,696 matching code bytes (56.1700%). Reconstructed initialized data reaches 174,377 / 648,064 bytes (26.9074%).

The code includes Sony RPC helpers, collision and animation routines, state callbacks, and 50 short dispatch/accessor functions. The dispatcher entries, sizes, and compiler profiles are listed in [FRONTIER_20261019_DISPATCH_RECOVERIES.csv](FRONTIER_20261019_DISPATCH_RECOVERIES.csv). Wider native inventory spans were partitioned at independently referenced entries; uncovered bytes and alignment remain uncredited. The earlier Grok import ledger remains scoped to its original input commit.

The new eight-byte data recovery is the two-entry integer-returning getter table at 004C21E0. Its consumer, 003D90A0, forwards the selector and returns the callback result. All eight direct native callers pass 0 or 1: 0032FC38, 00330B30, 00330D48, 003366B0, 0033D36C, 0033E910, 00340EB8, and 003448B4. The two getter entries are independently referenced and recovered; the preceding 48-byte pointer range remains a placeholder. Both split objects match retail. Corrupting a relocation addend in a private copy causes verification to fail.

Independent validation used each production compiler recipe, including the older MWCC compiler and Sony EE 2.9 where required. All 38 affected/caller translation units replayed exactly. All 53 tests, catalog validation, shell syntax, and 3,673-source build coverage pass.

The full 3,941,760-byte hybrid image remains byte-identical, SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`. The packed 3,942,320-byte retail ELF remains byte-identical, SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

## Combined follow-up checkpoint

The combined follow-up adds 47 complete functions (12,504 bytes) and 24 bytes of reconstructed initialized RPC state since the 56.1700% checkpoint. The catalog now contains 1,862,572 / 3,293,696 matching code bytes (56.5496%), 174,401 / 648,064 reconstructed data bytes (26.9111%), and 16,661 matched functions.

Thirty-eight functions (10,172 bytes) recover previously held Grok candidates by removing all artificial NOP assembly and using MWCC 3.0's genuine `#pragma padloop on`. Their complete native catalog extents and relocated bytes match; no partial-prefix credit is included. Production profiles and provenance are listed in [GROK_20261019_LOOP_RECOVERIES.csv](GROK_20261019_LOOP_RECOVERIES.csv). The original Grok import ledger remains historical. Fetch and branch audits found `b40ac496` remained the latest Grok integration tip; the older W3, W7 and round-four integration branches introduce no missing source scope.

The remaining nine functions recover Sony event/RPC helpers and actor motion/offset routines. Two-pointer helper declarations and thread-ID syscall fallback contracts were corrected and their complete translation units replayed. Required syscall primitives follow the exception in DECOMP.md; algorithmic behavior remains C. The new initialized data comprises two semaphore IDs, two four-byte RPC response buffers, one command/status word and one semaphore ID. Surrounding raw data remains uncredited, as do the unbounded motion tables and runtime BSS.

Independent replay covered all 58 changed/caller C translation units and all ten changed surviving data objects. A deliberately corrupted RPC response word was rejected by the verifier. All 53 tests, catalog validation, shell syntax and 3,711-source build coverage pass. The full hybrid and packed retail ELF retain the byte-identical sizes and SHA-256 hashes recorded above.

## Next local frontier

The next verified local checkpoint adds 18 functions (3,840 bytes) after `02e0e1a1`, reaching 1,866,412 / 3,293,696 matching code bytes (56.6662%). Initialized-data credit remains 174,401 / 648,064 (26.9111%). This checkpoint is below the next scheduled publication threshold of 1,882,888 code bytes (57.1664%).

The recovered families include actor state, motion and effect callbacks; a runtime directory lookup; an angle helper; an old-MWCC flag lookup; scene setup; and Sony interrupt/DMA wrappers. [FRONTIER_20261019_FAMILY_RECOVERIES.csv](FRONTIER_20261019_FAMILY_RECOVERIES.csv) records the root-owned family entries and recipes. Other functions were added to their existing source units. Four kernel stubs now expose their actual one-integer argument and integer status return; the minimal syscall primitives and all 171 matched functions in their shared translation unit remain exact.

Two newly identified callback entries start four bytes beyond the old residual inventory labels. Their preceding NOP words remain padding with zero C credit. The 002D57F0 callback preserves three initialized offset floats. The 002D5D30 callback preserves retail's initialization of x/y only: dispatcher mode 1 reaches 00156520, whose instruction at 0015659C reads the third component. Its three-float local therefore retains the native uninitialized z component; an eight-byte local would be an incorrect object view. Both full callbacks reproduce the native instructions exactly.

All 17 changed C translation units were independently replayed with their production compiler recipes, including Sony EE 2.9/2.96 and both MWCC releases. All 53 tests, catalog validation, shell syntax and 3,715-source build coverage pass. The final full hybrid image and packed ELF remain byte-identical with the sizes and SHA-256 hashes above. Unproven Grok loop candidates and owner-argument repairs remain uncredited in separate worker worktrees.

## Owner callback integration

The following local batch adds 13 full functions (3,332 bytes) and a four-byte timeout counter after `5e460607`, reaching 1,869,744 / 3,293,696 matching code bytes (56.7674%) and 174,405 / 648,064 reconstructed initialized data bytes (26.9117%). No publication threshold has been crossed; the next remains 57.1664%.

Nine callbacks use the genuine MWCC 3.0 loop-padding option and preserve the native owner pointer. Their identities and production profiles are recorded in [GROK_20261019_OWNER_RECOVERIES.csv](GROK_20261019_OWNER_RECOVERIES.csv). The 0044B050 and 0044E840 tables and their dispatchers now carry the two-argument contract established by the native caller chain. All nine full bodies, all three affected shared C units, and both table objects independently verify exactly. Nonzero prefix instructions remain uncredited, and alignment NOPs receive zero C credit. The remaining callback with an unproven owner producer remains held.

Four additional routines recover direction/animation setup, a launch initializer, signed-byte state updates and deferred actor setup. Float constants and explicit promoted-byte comparisons reproduce the native instructions without synthetic barriers. The deferred setup preserves retail's lack of default initialization beyond its three explicit switch cases.

The timeout counter at 00487340 is a volatile four-byte unsigned value reset, incremented and compared by 00408628. Its 4,044-byte raw tail remains uncredited; both split objects independently match retail. All 53 tests, catalog validation, shell syntax and 3,727-source build coverage pass. The complete hybrid image and packed executable retain the exact sizes and hashes above. These hybrid image checks include raw fallback bytes and do not imply complete source reconstruction.
