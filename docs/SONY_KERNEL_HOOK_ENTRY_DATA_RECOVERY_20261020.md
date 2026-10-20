# Sony kernel hook entry data

`func_0010C2F8` treats the 64-byte region at `0x004386A8` as eight 8-byte
`{ service number, handler }` entries. Its native loads at `0x0010C318–0x0010C364`
read both words for entries 0–2. The loop at `0x0010C368–0x0010C390` processes
entries 3–7 with an 8-byte stride but loads only each service number; it obtains
the handler through `func_0010C2D8` instead of reading the stored handler word.

The existing source-matched entries already type all service numbers, entry 0's
handler, and entry 2's handler. This follow-up types the additional four-byte
entry-1 handler at `0x004386B4` as the pointer value `0x80075000`, which the
native code passes to `func_0010C2E8`. The five stored handler words at
`0x004386C4`, `0x004386CC`, `0x004386D4`, `0x004386DC`, and `0x004386E4` remain
raw because this initialization path does not load them.

`data_ptr_004386B4` compiles with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and
matches the retail `SLUS_204.86` image exactly. The data catalog validator passes.
