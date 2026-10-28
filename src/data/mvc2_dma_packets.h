#ifndef MVC2_DMA_PACKETS_H
#define MVC2_DMA_PACKETS_H
/* Packet templates sent by func_003DECC0: it reads word 0 & 0x7FFF as the qword count,
 * sends (count + 1) qwords, and rewrites word 0 (|0x80000000), word 2 (VIF FLUSHA)
 * and word 3 (VIF DIRECT | count) before the transfer. */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {
    u32 dma_tag;
    u32 dma_addr;
    u32 vif_code[2];
} Mvc2DmaHeader;
#endif
