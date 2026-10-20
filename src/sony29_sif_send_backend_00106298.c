/* Build up to two DMA transfers and submit a native SIF command packet. */
#include "sony29_sif_dma_types.h"
typedef unsigned int u32;
typedef struct {
    u32 packet_size : 8;
    u32 data_size : 24;
    void *destination;
    u32 command;
    u32 option;
} CommandHeader;
extern void *D_004C3AE0;
extern void func_00106578(void *,int);
extern int func_001041A0(SonySifDmaTransfer *,int);
extern int func_001041B0(SonySifDmaTransfer *,int);
u32 func_00106298(u32 command,int mode,void *packet,int packet_size,
                 void *source,void *destination,int size)
{
    SonySifDmaTransfer dma[2];
    CommandHeader *header=packet;
    int count;
    if ((u32)packet_size-16u >= 97u) return 0;
    count=0;
    if (size>0) {
        dma[0].source=source;
        dma[0].destination=destination;
        header->destination=destination;
        header->data_size=(u32)size;
        dma[0].size=size;
        dma[0].attributes=0;
        count=1;
        if (mode&4) func_00106578(source,size);
    } else {
        header->data_size=0;
        header->destination=0;
    }
    dma[count].source=packet;
    dma[count].destination=D_004C3AE0;
    dma[count].size=packet_size;
    header->command=command;
    header->packet_size=(u32)packet_size;
    dma[count].attributes=0x44;
    func_00106578(packet,packet_size);
    count++;
    if (mode&1) return func_001041B0(dma,count);
    return func_001041A0(dma,count);
}
