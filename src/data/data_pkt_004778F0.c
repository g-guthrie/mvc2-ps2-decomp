#include "mvc2_dma_packets.h"
/* func_003DF0C0 (src/fb38_g.c) passes &D_00477918 / &D_00477920 (values[1], values[2]) to
 * func_003E0DB0, fills D_00477928[0..8] (values[3..11], u64) and sends &D_004778F0 through
 * func_003DECC0. DMA count 7 -> 0x80 bytes. GIF tag: NLOOP 1, EOP, 12 packed registers. */
typedef struct {
    Mvc2DmaHeader head;
    u64 gif_tag[2];
    u64 values[12];
} DmaPacket4778F0;
typedef char DmaPacket4778F0_size_check[(sizeof(DmaPacket4778F0) == 0x80) ? 1 : -1];
DmaPacket4778F0 data_pkt_004778F0 = {
    { 0x70000007u, 0u, { 0u, 0u } },
    { 0xC400000000008001ULL, 0x0000521521521860ULL },
    { 0x000000000000005BULL, 0, 0x0000000000000005ULL, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
