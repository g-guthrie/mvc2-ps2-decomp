#include "../runtime_span_types.h"
#include "../sony29_sif_dma_types.h"
typedef struct {
    void *input_object;
    void *secondary_object;
    struct RuntimeSpan input_span;
    struct RuntimeSpan secondary_span;
    SonySifDmaTransfer transfer;
    s32 transfer_id;
    s32 words_30_through_3c[4];
} HandleWords_0048791C;
typedef char RuntimeSpan_size_check_0048791C[sizeof(struct RuntimeSpan) == 8 ? 1 : -1];
typedef char HandleWords_size_check_0048791C[sizeof(HandleWords_0048791C) == 0x3C ? 1 : -1];
HandleWords_0048791C data_sdk_handle_words_0048791C = { 0, 0, { 0, 0 }, { 0, 0 }, { 0, 0, 0, 0 }, 0, { 0 } };
