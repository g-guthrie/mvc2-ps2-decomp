#include "runtime_span_types.h"
/* RuntimeNode pools for the 16 D_0048EB38 entries. func_0040DBB0 (src/rb89_a.c) gives slot i the
 * 0x100-byte pool &D_0048ECB8[i << 8] through func_0040FDC0(1, pool, 0x100), which stores it as
 * RuntimeQueryContext.pool with capacity 0x100 / 16; func_0040FEF8 then links the 16
 * RuntimeNode entries (next, span cleared). The slot count D_004C247C is bounded by the
 * 16-entry D_0048EB38 table (cleared as 0x180 bytes = 16 * 0x18). The last 0x80 bytes have no
 * reader. */
typedef struct {
    struct RuntimeNode pools[16][16];
    unsigned char unreferenced_1000[0x80];
} DecoderNodePools;
typedef char RuntimeNode_size_check[(sizeof(struct RuntimeNode) == 16) ? 1 : -1];
typedef char DecoderNodePools_size_check[(sizeof(DecoderNodePools) == 0x1080) ? 1 : -1];
DecoderNodePools data_zero_0048ECB8 = { { { { 0 } } } };
