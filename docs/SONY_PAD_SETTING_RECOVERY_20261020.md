# Sony pad setting requests

Two complete setting requests match 420 native bytes with Sony EE GCC 2.9 O2/G0 and SNAS G0:

- `0010E020` (216 bytes): sends command 8 with six actuator-setting bytes and reads the reply status at offset 20.
- `0010E370` (204 bytes): sends command 11 with twelve parameter bytes and reads the reply status at offset 28.

Both use the existing 128-byte pad RPC buffer and existing RPC client, call command 1 synchronously, and return zero on negative transport failure. A successful status of one invokes the existing port/slot request-state setter at 0010DA40 with value two, then reloads the actual reply status.

The source gives each native packet a typed local view over the existing raw byte buffer. Both begin with three 32-bit command/port/slot words. The direct request's six-byte payload is followed by the naturally aligned status at 20. The parameter request has a twelve-byte payload, an unaccessed word at 24, and status at 28. These are observed protocol offsets, not new allocated records or data credit. Byte accesses through these views preserve the actual payload ownership and avoid describing an indexed payload as unrelated scalar objects.

Sony's genuine fixed-size builtin `memcpy` generates the twelve-byte unaligned transfer. The six-byte request uses the native bounded byte loop. The final object contains exactly the complete 216-byte and 204-byte functions, with no allocated readonly, data or BSS payload. Both standard object-verifier checks pass; no helper body, assembly lift or forced volatile is used.
