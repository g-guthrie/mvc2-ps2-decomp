#include "sdk_dma_pool_types.h"
typedef signed char s8;
typedef unsigned char u8;
/* 8 DMA slots of 0x44 bytes. func_00409208 (0x00409208) bounds the index at 8
 * and scales it by 0x44 (i*17*4); func_00409810 (0x00409810) walks the table
 * with stride 0x44 testing the s8 at +0 (lb 0x004092FC / func_004093E8 reads
 * +1). func_00409250 (0x004092F0-0x004093C8) fills a slot: byte +0/+1/+2
 * (lb/sb), words +4..+0x2C (sw), callbacks at +0x20/+0x28; func_004093E8
 * clears the slot with func_0011D8F8(slot, 0, 0x44). Byte +3 is never read; it
 * is alignment padding between the 3-byte header and the word body. */
typedef struct {
    s8 active;
    s8 transfer_state;
    u8 state_02;
    u8 pad_03;
    SdkDmaBody body;
} SdkDmaSlot;
typedef char SdkDmaSlot_size[sizeof(SdkDmaSlot) == 0x44 ? 1 : -1];
SdkDmaSlot data_rec_00487B60[8] = { { 0 } };
