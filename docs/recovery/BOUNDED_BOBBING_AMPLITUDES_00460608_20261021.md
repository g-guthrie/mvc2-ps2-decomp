# Bounded bobbing amplitudes at 00460608

Root catalog `46b52471` still classified the 0x1C-byte region at
`0x00460604` as raw placeholder data. It contains a four-byte raw prefix, a
three-float amplitude table at `0x00460608`, and a 12-byte raw tail through
`0x00460620`.

Exact caller `func_003420F0` invokes `func_00342130` with indices 0, 1, and 2
(`0x00342100–0x00342118`). The constructor stores the supplied index in
object field `+0x20` (`0x003421BC`) and installs `func_003421E0` as the update
callback. That callback reads the field but does not change it. Its native
load from `D_00460608` scales the index by four and reads a float at
`0x00342254`, establishing exactly three reachable entries and one 32-bit
float per entry.

All three source-owned objects compile with MWCCPS2 3.0.3
`-O3 -sdatathreshold 0 -i src/data` and verify over their full spans against
the pinned retail image. The table row is `status=matching`,
`progress=reconstructed`; prefix and tail remain placeholder. No code CUs
changed.

The existing update callback now reads its baseline from the actual V3
row at 004605E0, selecting its y member. This replaces a flat interior
float-array alias at 004605E4 with stride three. The whole existing
212-byte function still matches retail; this repair adds no code credit.
