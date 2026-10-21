# Newlib 2/pi digit table

Recover the complete 198-element signed 32-bit table at `D_004ABC00`: 792 bytes of base-256 fractional digits used by float argument reduction. The existing 668-byte raw prefix is replaced; another 124 bytes up to `0x004ABF18` were previously unowned. The next table and all following constants remain outside this recovery.

The matching `rem_pio2f` source defines these exact 198 values. Its compiled object gives `two_over_pi` a size of `0x318` bytes, immediately followed by `npio2_hw`. The existing raw prefix, complete source initializer, compiled source table, and all 198 retail words agree independently.

The native caller forms the table address in T1 at `0x001141D4` and calls `func_001154A8` at `0x001141E4`. The table is the sixth argument; T0 carries the fifth argument, precision 2. The matching kernel declares the table argument as `const int32_t *` and consumes the digit words. `D_004ABF14` is both the final digit address and the compiler's one-word-before base for a separate `npio2_hw[n-1]` lookup; it does not extend the recovered table into that next array.

The standalone typed source independently compiles under MWCCPS2 3.0.3, -O3 -sdatathreshold 0 and reproduces the retail span. Whole-image and packed ELF identity, catalog placement, and all tests are checked before linked credit is promoted. No new code credit is claimed for this data recovery.
