# Bounded state-position records

`func_00147580` in verified `src/y9_d.c` creates four `func_00146CD0` entries
with second arguments 0 through 3. The creator stores that argument at record
`+0x20`. Native callback dispatch at `0x00442A50` routes the mode-zero entries
to `func_00147090`; its matched source loads `D_004428C0[p[0x20]]`. A second
mode-zero callback, `func_001471A0`, loads `D_00442980[p[0x20]]`. The only
creator calls are the four bounded entries and one additional mode-four entry
with index zero, so both position views select only indices 0 through 3.

The `func_00147090` view reads the selected first-record fields at
`0x004428C0..0x00442900`: V3, a heading halfword, and a signed byte; each
unread pad byte remains raw. Those four records supply start indices 0, 4, 6,
and 7 to `func_00146D80`. That native walker advances by 16 bytes and stops on
a negative byte at offset `0xF`: start 0 reaches entry 3's sentinel, while
starts 4, 6, and 7 each stop at their own entry. I typed only entries 0–4, 6,
and 7, leaving unselected entry 5 raw. The walker selects 112 bytes in its
separate path table, with the 16-byte entry at `0x00442950` left raw. The
independent V3 view at `0x00442980` contributes 48 selected bytes.

`func_001471A0` copies the complete V4 at `0x00442A10` and uses component
index `p[0x20]` 0–3, while `func_001472B0` selects one of four V3 values at
`0x00442A20`. These separate source/native views add 64 bytes, for 284 typed
bytes total. The 96-byte prefix before the V4 remains raw at
`0x004429B0–0x00442A10`. The first view's per-record pad gaps remain raw at
`0x004428CE–0x004428D0`, `0x004428DE–0x004428E0`,
`0x004428EE–0x004428F0`, and `0x004428FE–0x00442900`.

All 28 resulting objects compile with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0`
and match the retail image exactly; the catalog validator passes.
