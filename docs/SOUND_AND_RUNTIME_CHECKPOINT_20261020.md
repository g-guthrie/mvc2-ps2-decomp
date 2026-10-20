# Sound and runtime recovery checkpoint

Verified linked code is 2,009,424 / 3,293,696 bytes (61.0082%),
covering 17,313 / 20,300 functions. Reconstructed linked data is
195,314 / 648,064 bytes (30.1381%). This adds 1,424 code bytes
and 1,560 data bytes over `be75855e`.

Six newly complete C functions cover a 220-byte timed actor handoff,
444-byte scaled-sound queue insertion, 272-byte animation-mode dispatcher,
196-byte internal ADXT stream start, and 148-/144-byte RPC server/queue
removal operations. Root independently compiled each new production source
and all changed providers/header consumers under their literal profiles.

The sound wrapper explicitly forwards its native floating-point argument.
The animation dispatcher supplies its actual actor-pointer argument, and
its palette-copy provider explicitly narrows the native word-sized index.
All existing functions in these repaired translation units remain exact.
The decoder helper providers now express their actual pointer ABIs, and
the shared RPC pool header retains unknown fields as unknown storage.

The 40-slot runtime-resource table contributes 39 proven field bytes per
72-byte record; each unproven byte and tail remains raw. All 161 replacement
data objects were independently compiled and verified. The separate sound
queue is BSS and receives no initialized-data credit. A rediscovered
372-byte motion routine was already credited and adds no new progress.
The independently expressed stream-start source discloses prior public API
research; the directly AGPL-adapted GetTime candidate remains held outside
this integration checkout and receives no credit.

Both complete images match retail byte for byte: ROM 3,941,760 bytes,
SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
ELF 3,942,320 bytes,
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 88 tests, catalog validation, shell syntax and production coverage of
4,078 credited sources pass. Existing cached source/object hashes were
checked; explicitly replayed dependency objects and the changed shared RPC
header are covered by their complete native verification results.

This checkpoint is local. The next scheduled publication threshold remains
2,014,636 code bytes, another 5,212 bytes away. Full decompilation
and reconstruction remain incomplete.
