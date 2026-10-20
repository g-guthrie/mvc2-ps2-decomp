#ifndef SDK_DMA_POOL_TYPES_H
#define SDK_DMA_POOL_TYPES_H
#include "../sony29_sif_dma_types.h"
typedef signed int s32;
/* Function-pointer storage only. Targets have heterogeneous C signatures.
 * Native dispatch passes context, source, length in A0/A1/A2 and ignores V0.
 * Do not call through this storage type. */
typedef void (*SdkDmaCallback)(void);
typedef struct {
    s32 resource_handle;
    s32 transfer_index;
    char *source_buffer;
    s32 transfer_length;
    void *progress_counter_base;
    s32 dma_destination_address;
    s32 dma_length;
    SdkDmaCallback callback_a;
    s32 callback_a_context;
    SdkDmaCallback callback_b;
    s32 callback_b_context;
    SonySifDmaTransfer dma;
    s32 transfer_id;
} SdkDmaBody;
typedef char SdkDmaBody_size[sizeof(SdkDmaBody) == 0x40 ? 1 : -1];
#endif
