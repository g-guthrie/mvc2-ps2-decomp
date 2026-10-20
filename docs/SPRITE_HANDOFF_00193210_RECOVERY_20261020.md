# `func_00193210` source recovery receipt

The standalone `src/sprite_handoff_00193210.c` recovers the native 272-byte owner-to-actor handoff at `0x00193210`. The native span explicitly copies 49 words from owner `+0xEC` to actor `+0xEC`; it then copies the visible owner fields, repeats the flag initialization at `+0x13C`, clears the actor mode byte, copies coordinates, calls the axis/offset helper, and selects the final update from byte `+0x21`.

The source contains a truthful static copy of `func_00193180` so MWCC can model the helper call while compiling this caller. The static copy is codegen-only and receives no matching credit. The existing global helper remains owned by `src/h8r.c`; that source was independently compiled with its production legacy recipe (`MWCCPS2_30 -O3 -Op -sdatathreshold 0`) and verified exactly at 136B. The static helper copy compiles 140B under the caller's distinct O4,p recipe, so only the standalone caller row is eligible for new credit.

Using the original caller profile, `MWCCPS2_30` (3.0-011126) with `-O4,p -sdatathreshold 0`, caller-only verification passes exactly at 272B. No catalog or build-script changes are included; integration should add only `func_00193210` and retain global helper credit with `src/h8r.c`.
