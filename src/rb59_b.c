/* Native RPC server request dispatch: run the handler, then reply via SIF DMA. */
#include "sony29_rpc_server_types.h"
#include "sony29_sif_dma_types.h"
typedef SonyRpcServer RpcItem;
typedef SonySifDmaTransfer Dma;
extern SonyRpcPacketPool D_004C5480;
extern int func_0010CA20(void);
extern int func_0010CA68(void);
extern void func_00106578(void *, int);
extern unsigned char *func_001068E8(SonyRpcPacketPool *, int);
extern unsigned char *func_001068B8(SonyRpcPacketPool *);
extern int func_001063D0(unsigned int, void *, int, void *, void *, int);
extern int func_001041A0(Dma *, int);

void func_00107380(RpcItem *item)
{
    volatile Dma dma[2];
    unsigned char *reply;
    void *result;
    int size = 0;
    int count, i, r;
    unsigned int *words;

    result = item->function(item->number, item->buffer, item->size);
    if (result) size = item->receive_size;
    if (item->size > 0) func_00106578(item->buffer, item->size);
    if (size > 0) func_00106578(result, size);
    func_0010CA20();
    if (item->rpc_id & 4)
        reply = func_001068E8(&D_004C5480, (unsigned int)item->rpc_id >> 16);
    else
        reply = func_001068B8(&D_004C5480);
    func_0010CA68();
    words = (unsigned int *)reply;
    words[8] = 0x8000000A;
    words[7] = (unsigned int)item->client;
    if (item->receive_mode) {
        while (!func_001063D0(0x80000008, reply, 64, result, item->receive_buffer, size)) ;
        return;
    }
    words[6] = 0;
    words[4] = 0;
    count = 0;
    if (size > 0) {
        count = 1;
        dma[0].source = result;
        dma[0].destination = item->receive_buffer;
        dma[0].size = size;
        dma[0].attributes = 0;
    }
    dma[count].source = reply;
    dma[count].destination = item->packet;
    dma[count].size = 0x40;
    dma[count].attributes = 0;
    count++;
    do {
        r = func_001041A0((Dma *)dma, count);
        if (r) return;
        i = 0x100000;
        do {
            i--;
            __asm__ volatile("nop");
        } while (i != -1);
    } while (r == 0);
}
