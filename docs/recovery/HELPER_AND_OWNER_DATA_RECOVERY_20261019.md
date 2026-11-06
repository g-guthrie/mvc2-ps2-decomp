# Helper integrity and owner data recovery

Three additional whole functions add 1,244 bytes: 001F11B0, 00172760, and
00143A60. Their native entry/caller paths are 001F0EA0 through 0044F7A0[4],
003D1F68, and 00143C80 respectively. The existing 003D7310 queue interface now
uses its genuine void(void) handler type. All eleven changed/new code units
in this import pass production compiler and relocated-byte verification.

The static-helper audit found incorrect local implementations whose callers
nevertheless passed instruction checks. Genuine canonical behavior replaces
ten local helper bodies across q0, m15e, y4_a, q7_b, y7_k, q4_c, v3_a, and
m3k. The fixes restore timer updates, owner-state copies, command transitions,
counter increments, and motion calculations. All credited functions in those
units remain exact; these repairs add no credit. The q0 timer helper is a
genuine algorithm variant under this unit's small-data profile, not an
additional exact credited definition. Other audit findings remain under review;
caller byte checks alone do not establish local helper source correctness.

Typed tables 0044A2A0 and 0044B770 use genuine actor/owner callback interfaces.
Known direct callers and handlers now agree on the two arguments, including
handlers that ignore the second input. This recovers 72 bytes. The twenty bytes
at 0044B7B0 are demoted to a readonly raw placeholder because the event-level
owner provenance is unproved. Raw addresses preserve bytes without claiming a
completed callback interface.

Ten twelve-byte records at 0044B7D0 contain one signed header byte, a float at
offset four, and two signed halfwords at offsets eight and ten. Native 001AC860
consumes that layout; independent callback ownership begins at 0044B850.
Ninety meaningful bytes are reconstructed; thirty alignment bytes and the
eight-byte tail remain placeholders.

Two sixteen-entry signed coordinate-pair arrays at 00462A40 and 00462A80 add
128 bytes. Exact consumer 00353140 selects their four-byte records. The next
independent callback table begins at 00462AC0; the 272-byte prefix remains
opaque. No universal selector bound is asserted. The net data gain is 270 bytes.

Root checks all 52 changed/new physical data objects and neighboring boundaries,
including unread padding and the demoted table, against the private image.
Fresh splitting, catalog checks, build coverage, and 57 tests pass. Code and
data credit remain distinct from raw bytes retained in the hybrid image.

The final loaded image and packed retail ELF reproduce their pinned SHA-256
hashes exactly after the helper repairs and fresh split.
