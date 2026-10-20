# SDK DMA pool recovery at 0x00487B60

Eight native 0x44-byte slots supply 536 bytes of reconstructed data. Unknown bytes and surrounding storage remain placeholders. The source shares the existing SIF DMA descriptor type and a common body layout header.

## Exact partition and credit

The existing raw unit `data_raw_00487B58` `[0x00487B58,0x00488310)` is represented by exactly 26 disjoint compiled objects:

- 8 raw prefix bytes at `0x00487B58`;
- for each of the eight rows (stride `0x44`): a 3-byte typed header, one raw byte at row `+3`, and a typed 0x40-byte body at row `+4`;
- 0x590 raw suffix bytes `[0x00487D80,0x00488310)`.

The 16 typed objects total 536 bytes (3+64 per row). Eight row `+3` bytes, the 8-byte prefix, and 0x590-byte suffix total 1,440 placeholder bytes. No placeholder bytes are marked reconstructed. The existing next owner `data_u32_00488310` is unchanged.

## Ownership bounds

`func_00409208` rejects selector `>=8` and computes `D_00487B60 + selector*0x44` (native 0x00409208..0x00409228). Allocator `func_00409250` uses the same eight rows and stride, tests row `+0`, then initializes fields (0x004092C0..0x004093C8). Release `func_004093E8` waits on row `+1`, consumes row `+4`, and clears exactly `0x44` bytes (0x00409400..0x00409448). The sweeper `func_00409698` visits selectors 7..0 at 0x44 steps (0x004096C8..0x0040971C); `func_00409810` does likewise (0x00409830..0x00409854). Thus the pool ends at `0x00487D80`; prefix and suffix retain raw ownership.

## Field ledger, per row

| Offset | Type/role | Direct evidence |
|---|---|---|
| +0 | `s8 active` | allocator checks zero at 0x00409300 and stores one at 0x004093B4; service checks at 0x004094F0; sweeps read it |
| +1 | `s8 transfer_state` | initialized zero 0x00409368; cleanup polls 0x00409404/18; asynchronous service reads it at 0x00409490, clears at 0x004094E8 and stores one after transfer submission at 0x004095A8 |
| +2 | `u8 state_02` | set one at 0x004093C0 and reset zero at 0x00409400; no read found, so name remains deliberately neutral |
| +3 | raw byte | no direct read or write found |
| +4 | `s32 resource_handle` | allocator stores result of `func_004090D8` at 0x00409314; cleanup passes it to `func_00409148` at 0x00409428 |
| +8 | `s32 transfer_index` | initialized zero 0x0040935C; compared with external progress dword at 0x004094A0..A8; loaded from it at 0x004094EC; incremented by one at 0x00409538 and written to that external dword at 0x00409544. This is an index/counter, not a byte count. |
| +C | `char *source_buffer` | set from allocator A1 at 0x00409360; used for callbacks/cache operations and descriptor source at 0x004094B8..C4 and 0x00409548..98 |
| +10 | `s32 transfer_length` | set to A3-0x40 at 0x0040934C; used as range length/third callback argument at 0x004094B4..C8 and 0x0040951C..70 |
| +14 | `void *progress_counter_base` | built as `((source + A3 - 0x40) | 0x20000000)` at 0x00409338..58; the service reads and updates the dword at `base+0x3C` (0x004094A4, 0x004094E0, 0x00409544) |
| +18 | `s32 dma_destination_address` | allocator A2 saved at 0x00409354; copied into the SIF descriptor's destination word at 0x0040957C..8C |
| +1C | `s32 dma_length` | allocator A3 saved at 0x00409350; copied into the SIF descriptor's size word at 0x00409580..90 |
| +20 | `SdkDmaCallback callback_a` (storage) | default `func_00409198` stored 0x004093C4; setter `func_00409450` replaces it; indirect call at 0x004094D8. Dispatch passes context, source, length in A0/A1/A2 (0x004094CC..DC). |
| +24 | `s32 callback_a_context` | initialized zero 0x004093B8; setter writes it at 0x00409450..58; passed as A0 at 0x004094D0 |
| +28 | `SdkDmaCallback callback_b` (storage) | default `func_004091A8` stored 0x004093A8..B0; setter `func_00409460` replaces it; indirect call at 0x00409528 |
| +2C | `s32 callback_b_context` | initialized zero 0x004093BC; setter writes it at 0x00409460..68; passed A0 at 0x00409524. |
| +30..+3F | `SonySifDmaTransfer dma` | native masks source buffer address to 24 bits and stores +30; copies row +18 to descriptor +34; copies row +1C to descriptor +38; zeros descriptor +3C and calls `func_001041A0(&row->dma,1)` at 0x00409574..A4. Existing type fields are `source,destination,size,attributes`; do not treat these four words as a pair of `RuntimeSpan`s. |
| +40 | `s32 transfer_id` | stores the integer return from `func_001041A0` at 0x004095A0..AC; it is not read in this service routine. |

Callback fields store function pointers. The native service places context, source, and length in A0/A1/A2 and ignores the return register. This does not establish one C callback signature: `func_004091A8` returns `s32`, `func_00409198` is a counter leaf with no declared inputs, and `func_00410C18` has two declared inputs. `SdkDmaCallback` is therefore a generic function-pointer **storage** type, never used to invoke a callback. No API return type is inferred from an ignored result.

The existing `SonySifDmaTransfer` header is reused directly. The shared body struct is exactly 0x40 bytes, asserted at compile time, with no untyped padding. `+3` is separately emitted as one-byte raw data per row.

## Consumer and layout verification

The accessor and two sweepers compute physical row addresses as unsigned integers before casting to the existing opaque callback interface. This avoids walking a fictitious C array across separately owned data fragments. All eight functions across `sdk0c.c`, `sdk0h.c`, and `w190_h.c` were independently recompiled with their production profiles and match completely. No new code bytes are credited for these changes.

All 26 replacement data objects were independently rebuilt with MWCCPS2 3.0.3, `-O3 -sdatathreshold 0`, and relocated against the retail image. A 16-word marker initializer independently confirms every body field offset, including the descriptor at row +0x30. The body size assertion is 0x40. Full loaded-image linkage, packed retail ELF comparison, and both test suites pass.
