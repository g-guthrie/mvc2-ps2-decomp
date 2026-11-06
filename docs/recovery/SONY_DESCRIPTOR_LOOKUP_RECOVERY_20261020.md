# Sony descriptor lookup

Two complete native routines match 200 bytes with Sony EE GCC 2.9 O2/G0 and SNAS G0. `00107588` (92 bytes) initializes the two existing mutexes only when the first ID is -1, using the existing native semaphore layout and initializing precisely its limit, initial count and option fields. `00107670` (108 bytes) acquires the descriptor-table mutex, checks the unsigned index against 32, releases the mutex on both paths, and returns either null or the actual sixteen-byte descriptor pointer.

The table view contains its observed handle, active flag and two remaining words. Neither the table nor mutex storage is defined or credited here. The final object contains exactly these two complete functions and no allocated readonly, data or BSS payload. The standard verifier passes both complete relocated spans. The separate near-matching asynchronous request probe and its proposed caller-interface correction remain private and are excluded.
