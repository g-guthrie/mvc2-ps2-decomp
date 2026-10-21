# Bounded switch-table recovery, 2026-10-20

Recover 1,048 initialized data bytes in 24 existing switch-table units: 262 relocated code-address entries and 190 distinct interior labels. Existing unit ranges and neighboring alignment gaps remain unchanged. No parent-function C credit is claimed.

Each extent is supported by the native dispatch guard and scaled selector. Every retail target was checked for alignment, membership in the owning function, and multiplicity. Sources use const byte-address pointers and registered interior labels, rather than declaring interior instructions as C functions.

The first nine tables contain 134 entries (536 bytes); the other fifteen contain 128 entries (512 bytes). Each source was independently compiled with MWCCPS2 3.0.3, -O3 -sdatathreshold 0, and its relocated object compared with the original initialized bytes. All registered label references pass provenance validation.

Native address intervals are authoritative for owner checks. In particular the assembly listing merges the routine beginning at 0x0041DBA0 into an earlier displayed label; inventory boundaries and the native return, padding, and new frame establish the actual owner interval. No function boundaries were changed for this recovery.

Combined verification includes catalog validation, all 95 tests, hybrid symbol/link validation, loaded-image identity, and packed retail ELF identity. The concurrently imported stage-selector code recovery is accounted for separately.
