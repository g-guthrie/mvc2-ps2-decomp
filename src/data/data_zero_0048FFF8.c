/* Static EE-side buffer of a DMA slot (SdkDmaSlot, data_rec_00487B60). func_0040E288 (src/rt21_b.c)
 * clears all 0x8D0 bytes, rounds (base + 0x40) down to 64 bytes (D_004C24AC = base + 8) and passes
 * that 0x880-byte window to func_00409250(1, window, iop_buffer, 0x880), which requires the
 * 64-byte alignment and records window as SdkDmaBody.source_buffer with transfer_length
 * 0x880 - 0x40 and progress_counter_base = (window + 0x840) | 0x20000000 (uncached). The bytes
 * before and after the window are alignment slack. */
typedef struct {
    char alignSlack[8];
    char transfer[0x840];
    char progressBlock[0x40];
    char tailSlack[0x48];
} SdkDmaStaticBuffer;
typedef char SdkDmaStaticBuffer_size_check[(sizeof(SdkDmaStaticBuffer) == 0x8D0) ? 1 : -1];
SdkDmaStaticBuffer data_zero_0048FFF8 = { { 0 } };
