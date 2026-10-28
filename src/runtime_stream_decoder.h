#ifndef MVC2_RUNTIME_STREAM_DECODER_H
#define MVC2_RUNTIME_STREAM_DECODER_H
#include "runtime_decode_descriptor.h"
/* Verified field offsets; allocation and input/output bounds remain unproved. */
typedef struct RuntimeStreamChunk {
    const void *input;
    int reserved[4];
    short *output;
    int reserved18;
    int stride;
    int start;
} RuntimeStreamChunk;
typedef struct RuntimeStreamDecoder {
    unsigned char reserved[8];
    RuntimeDecodeDescriptor *descriptor;
    unsigned char reserved0c[0x3c];
    RuntimeStreamChunk chunk;
} RuntimeStreamDecoder;
#endif
