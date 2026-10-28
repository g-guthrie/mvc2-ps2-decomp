#include "mvc2_dma_packets.h"
/* func_003ED1C0 (src/w199_f.c) fills the A+D data words D_00478CB0, D_00478CD0, D_00478CE0, D_00478CF0,
 * D_00478D00 (u64) and sends &D_00478C90 through func_003DECC0. DMA count 7 -> 0x80 bytes.
 * GIF tag: NLOOP 6, EOP, one A+D register; each entry is {data, GS register}. */
typedef struct { u64 data; u64 gs_register; } GsAdWrite478C90;
typedef struct {
    Mvc2DmaHeader head;
    u64 gif_tag[2];
    GsAdWrite478C90 ad[6];
} DmaPacket478C90;
typedef char DmaPacket478C90_size_check[(sizeof(DmaPacket478C90) == 0x80) ? 1 : -1];
DmaPacket478C90 data_pkt_00478C90 = {
    { 0x70000007u, 0u, { 0u, 0u } },
    { 0x1000000000008006ULL, 0x000000000000000EULL },
    {
        { 0x0000000000000000ULL, 0x47ULL },
        { 0x0000000000000006ULL, 0x00ULL },
        { 0x0000000000000000ULL, 0x01ULL },
        { 0x0000000000000000ULL, 0x05ULL },
        { 0x0000000000000000ULL, 0x05ULL },
        { 0x0000000000000000ULL, 0x47ULL },
    },
};
