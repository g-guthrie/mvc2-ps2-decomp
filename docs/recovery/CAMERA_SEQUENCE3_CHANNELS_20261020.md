# Camera sequence 3 parallel float channels

Recover 648 bytes at `data_f32_0043C860`: 27 keys with six native float channels each. The existing exact camera consumer uses the same bounded key index 0..26 and 24-byte stride established for the source key array at `0x0043C5D0`. It reads all six words from the parallel pointer selected by `D_0043CB50[3]`.

This coherent float array replaces 28 generic zero/nonzero chunks. Their full 688-byte span is exactly partitioned into the 648 typed bytes and an uncredited 40-byte raw tail beginning at `0x0043CAE8`. No zeros past the native extent are credited. The existing mode 4 pointer remains at `0x0043CAF0`, now expressed as word 2 of that raw tail; all other targets and the prior header/key recovery are preserved.

The two pointer lists and both resulting data objects independently reproduce retail bytes with MWCCPS2 3.0.3, -O3 -sdatathreshold 0. Linked credit requires the combined hybrid, packed ELF and test gates. No code bytes are added by this data recovery.
