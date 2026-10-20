# Pad APIs and command stream checkpoint

This checkpoint adds 14 complete functions (2,528 code bytes): the 272-byte sprite handoff, seven pad buffer/capability queries, two pad setting RPCs, and four actuator/combination/mode APIs. Each production object was independently compiled and verified with its recorded compiler recipe. The sprite caller contains a genuine static helper implementation for compiler call analysis; it receives no separate credit. The global helper remains in `h8r.c`.

The early and late effect command families add 2,775 reconstructed data bytes in 232 independently compiled and verified replacement objects. Skipped payload and unread gaps remain raw. The family receipts and recovery notes document the actual callback roots and independent boundaries. These inventories are partial: newly located native inputs in remaining raw gaps require separate follow-up.

All 84 tests pass (57 tool tests and 27 tests under `tests/`). Build coverage finds 4,049 credited sources with verification and no unregistered bodies. Hash comparison against the prior proof cache confirms unchanged sources, objects and headers outside the reviewed replacements. The final hybrid ROM (3,941,760 bytes) and reconstructed retail ELF (3,942,320 bytes) are byte-identical to their original targets.

Verified linked code is 1,999,724/3,293,696 bytes (60.7137%); reconstructed data is 186,103/648,064 bytes (28.7168%). This remains a local checkpoint below the next fixed push milestone of 2,014,636 code bytes; 14,912 verified code bytes remain before that normal push. Public main was last confirmed at `e240ba423bcf3eaded1632e1c826530dcd3bb597`.
