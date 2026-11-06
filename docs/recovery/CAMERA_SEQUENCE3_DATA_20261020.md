# Camera sequence 3 durations and key channels

Recover 760 bytes: a 112-byte signed duration-word table at `0x0043C560`, and 648 bytes of float key channels at `0x0043C5D0`. The duration table replaces two old raw fragments and attributes 96 previously unowned bytes. The key array ends at `0x0043C858`; its eight following zero bytes remain raw and uncredited.

The existing exact `func_001234D0` selects the duration and channel bases through `D_0043CB10` and `D_0043CB30`. For selector 3, the first signed word is 26. The native key starts at zero and increments only while below that value, so it selects keys 0 through 26. Native address arithmetic multiplies the key by 24, then reads six float words. The source array therefore contains 27 six-channel keys, or 162 floats.

The duration source contains the leading bound followed by 27 durations: twenty-six values of 6 and a final 3000. The last duration is read when the active branch advances key 25 to 26 before computing its duration address. It is a typed table word, not alignment space.

Both existing pointer lists retain their bytes. Their selected target declarations now agree with the reconstructed signed and float arrays. The code consumer's declarations agree with the lists' const void-pointer interface and use const read views; the complete 644-byte function still matches under its production MWCCPS2 3.0 recipe, -O3 -sdatathreshold 0. This adds no code credit. All changed data objects independently match under MWCCPS2 3.0.3, -O3 -sdatathreshold 0. Linked credit follows the combined image and test gates.
