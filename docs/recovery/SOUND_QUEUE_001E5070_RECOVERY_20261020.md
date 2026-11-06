# Exact scaled-sound queue insertion

`func_001E5070` is a complete 444-byte native-first C reconstruction, using
modern MWCCPS2 3.0.3 `-O3 -sdatathreshold 8`. It checks the current 20-byte
queue slot, probes an existing entry through the real packed request helper,
and either advances past an unavailable slot or stores a state-3 request.
The new request includes byte-sized channel/sound values promoted to words,
a floating gain converted from its integer argument, and the incoming scale.
The cursor advances and wraps at 36 on both paths.

Native instruction flow establishes the three integer arguments and F12
scale. The typed slot is state byte, three pad bytes, two words, and two
floats. Promoting the loaded state to an int once mirrors the native single
load and comparison; repeatedly comparing a byte field introduced an extra
mask in the discarded candidate. All 111 words match after relocation.
No compiler barriers, assembly, raw instruction lifts, padding, or data credit
are used. The existing `func_001E3320` wrapper explicitly forwards the scale
using its independently verified corrected ABI.
