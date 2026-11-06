# Bounded signed-byte lookup at 0045EEA8

`func_0033D2C0` allocates a type-6 object with initializer 1 and installs exact
callback `func_0033D270`; it does not write the callback's `h1C` selector.
The allocator path clears the complete object before initialization, and
initializer 1 only links the object. The callback reads `h1C`, loads a signed
byte with `lb` at `0x0033D280`, then increments the selector and resets it when
the new value is not below 15 (`0x0033D294–0x0033D2B4`). Starting from zero,
its complete selector range is therefore 0–14.

The table has a one-byte stride and exactly 15 reachable entries at
`0x0045EEA8–0x0045EEB7`. The following raw bytes remain untyped. The prior
0x8C-byte raw owner at `0x0045EEA4` is partitioned into a four-byte raw prefix,
the signed-byte table, and a 0x79-byte raw tail with no lost bytes or overlap.
