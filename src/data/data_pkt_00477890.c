#include "mvc2_dma_packets.h"
/* func_003DEE00 (src/fb54_c.c) fills D_004778B8[0..5] (u64) and sends &D_00477890 through
 * func_003DECC0. DMA count 5 -> 0x60 bytes. GIF tag: NLOOP 1, EOP, 7 packed registers
 * (PRIM, RGBAQ, XYZ2, RGBAQ, XYZ2, RGBAQ, XYZ2) = 7 u64 values, then one pad u64. */
typedef struct {
    Mvc2DmaHeader head;
    u64 gif_tag[2];
    u64 values[7];
    u64 pad;
} DmaPacket477890;
typedef char DmaPacket477890_size_check[(sizeof(DmaPacket477890) == 0x60) ? 1 : -1];
DmaPacket477890 data_pkt_00477890 = {
    { 0x70000005u, 0u, { 0u, 0u } },
    { 0x7400000000008001ULL, 0x0000000005151510ULL },
    { 0x000000000000004BULL, 0, 0, 0, 0, 0, 0 },
    0,
};
