# Communication and runtime recovery checkpoint

Linked matching code is 2,006,376 / 3,293,696 bytes (60.9156%), covering
17,301 / 20,300 functions. Reconstructed linked data is
188,610 / 648,064 bytes (29.1036%). These totals add 1,588 code bytes
and 1,840 data bytes over checkpoint `5d7caf45`.

Ten new complete C functions cover a mode selector, an effect initializer
with its actual three-argument helper ABI, and Sony thread/DECI2/RPC operations.
Their production compiler recipes were replayed independently. The DECI2
architecture-boundary repair moves an existing 16-byte syscall implementation
to its licensed SDK assembly provider and shared ABI header; it adds no credit.
All 254 functions affected by that boundary change remain exact.

The data work reconstructs bounded renderer vectors/path records and fixed
fields of runtime handle, callback, and service tables. Unproven dynamic list
storage remains raw. The one-branch-different runtime updater is retained only
under `docs/nonmatching`, outside production and progress accounting.

Validation: fresh split; complete hybrid relink; packed retail ELF; all 88
tests; catalog validation; shell syntax; coverage of 4,068 credited production
sources. The unchanged prior source/object hashes and prior headers were also
checked against the previous compiled proof cache, and changed/new units were
recompiled and verified against the immutable retail target.

ROM: 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
Retail ELF: 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

This is a local checkpoint below the next scheduled publication threshold of
2,014,636 code bytes. Another 8,260 verified code bytes are needed to reach it.
Full decompilation remains incomplete.
