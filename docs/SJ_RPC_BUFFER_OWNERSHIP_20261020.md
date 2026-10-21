# SJ RPC buffer ownership limit

The main executable proves a bounded set of pointer arguments in the region
0x0048ECB8..0x0048FCB8. It does not yet prove a typed initialized data object.

func_0040DB10 computes a nonnegative configuration count and rejects values
above 16. func_0040DBB0 passes 0x0048ECB8 + (index << 8), with scalar 0x100,
through func_00410898. That wrapper sends the three words {1,address,0x100}
as RPC command 0x422. The loop's count bounds sixteen candidate256-byte
intervals. There is no observed EE load or store through those pointers.
The receiver implementation is absent from this main-executable project,
so the role of 0x100 and the byte-level operations remain unproven.

A scratch 16-by-256 zero-array candidate compiled and matched retail, but
matching zero bytes does not establish content semantics or ownership.
The entire 0x0048ECB8..0x0048FD38 span therefore stays raw and uncredited,
including the 128-byte tail after the candidate pointer intervals. Recovery
requires receiver-side evidence or another native semantic consumer.
