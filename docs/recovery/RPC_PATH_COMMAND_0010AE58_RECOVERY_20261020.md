# Exact guarded RPC path command

`func_0010AE58` matches the entire 240-byte native body with Sony EE GCC 2.9
O2/G0 and SN AS G0. It guards on the native subsystem state, copies at most
252 path bytes, stores the scalar request value, transports the actual
packet length, and returns the native RPC error/result.

A full-length input follows the native conditional terminator write and the
unconditional final-byte write separated by the value store. Both real
writes are retained naturally by the compiler; no barrier, padding,
assembly, volatile qualifier, or invented helper is introduced. Existing
RPC buffer declarations keep their established types. Root independently
recompiled and relocated the entire symbol. No data credit is claimed.
