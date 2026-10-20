#ifndef MVC2_SONY29_SIF_DMA_TYPES_H
#define MVC2_SONY29_SIF_DMA_TYPES_H

typedef struct SonySifDmaTransfer {
    void *source;
    void *destination;
    int size;
    int attributes;
} SonySifDmaTransfer;
typedef char SonySifDmaTransfer_size_check[sizeof(SonySifDmaTransfer) == 16 ? 1 : -1];

#endif
