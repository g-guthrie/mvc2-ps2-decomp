#include "mvc2_dma_packets.h"
/* func_003DF490 (src/fb55_g.c) copies the first 0x28 bytes of &D_00477970 to scratchpad
 * (func_003DCDC0) and builds the register values there. DMA count 5 -> 0x60 bytes.
 * GIF tag: NLOOP 1, EOP, 8 packed registers. */
typedef struct {
    Mvc2DmaHeader head;
    u64 gif_tag[2];
    u64 values[8];
} DmaPacket477970;
typedef char DmaPacket477970_size_check[(sizeof(DmaPacket477970) == 0x60) ? 1 : -1];
DmaPacket477970 data_pkt_00477970 = {
    { 0x70000005u, 0u, { 0u, 0u } },
    { 0x8400000000008001ULL, 0x0000000052521860ULL },
    { 0x0000000000000056ULL, 0, 0x0000000000000005ULL, 0, 0, 0, 0, 0 },
};
