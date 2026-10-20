# Original SDK semaphore syscall boundary

Five existing 16-byte providers at `00103DE0/DF0/E00/E10/E20` now use the
original PS2SDK normal-mode `SYSCALL_SPECIAL` assembly macro. The macro is
retained from revision `329e2bb43287e16af16c4dde1c614e2662c24468`, with its
copyright and complete existing AFL 2.0 license. Selector constants and the
integer-result / parameter ABI follow the pinned kernel headers, including
the negative interrupt-context selector for iSignalSema.

The earlier C definitions were parameterless void functions containing
inline syscall instructions. Removing those five definitions gives each
symbol an architecture implementation without a conflicting C return type.
The shared header exposes the real V0 integer result and 24-byte semaphore
parameter layout. Existing callers are unchanged; other 156 legacy syscall
providers are untouched and are not claimed to have completed an ABI audit.

This is an architecture-specific SDK boundary, not newly recovered portable
C. The same five complete ledger rows only move source ownership: 80 bytes
remain 80 bytes, with no new functions or progress credit. Root independently
preprocessed and assembled the new provider and verified all five symbols.
All 156 remaining legacy functions / 2,496 bytes recompile exactly with
modern MWCC O3/G0. The complete macro, not a target instruction lift or
synthetic padding, supplies the native syscall and return sequence.

A regression check protects unique ledger ownership, unchanged 16-byte
extents, production verification registration, integer-return declarations,
and absence of duplicate C definitions. In-memory negative controls confirm
that a duplicate definition or a void-return regression is rejected without
mutating source files.
