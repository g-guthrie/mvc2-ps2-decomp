#include "cri_sj_ring_buffer_types.h"
#include "runtime_span_types.h"
/* SJCK is the actual node payload; the shared span view stores its address word. */
typedef struct SjPoolNodeView SjPoolNodeView;
struct SjPoolNodeView {
    SjPoolNodeView *next;
    u32 unknown;
    SJCK chunk;
};
typedef char SjPoolNodeView_size_check[sizeof(SjPoolNodeView)==16?1:-1];
void func_0040FEF8(SJ_OBJ *object)
{
    struct RuntimeQueryContext *pool=(struct RuntimeQueryContext *)object;
    SjPoolNodeView *nodes=(SjPoolNodeView *)pool->pool;
    int i;
    pool->moved=(struct RuntimeNode *)nodes;
    for(i=0;i<pool->capacity-1;i++) {
        nodes[i].chunk.len=0;
        nodes[i].chunk.data=0;
        nodes[i].next=&nodes[i+1];
    }
    nodes[i].next=0;
    nodes[i].chunk.data=0;
    nodes[i].chunk.len=0;
    for(i=3;i>=0;i--)pool->entries[i]=0;
}

/* The two totals for each line are get and put byte counts. */
typedef struct SjRingTransferView {
    SJ_OBJ object;
    int active;
    UUID *uuid;
    int readable,writable,write_offset,read_offset;
    signed char *buffer;
    int size,extension;
    int transfer_bytes[2][2];
    SJRBFErrorCallback error;
    void *context;
} SjRingTransferView;
typedef char SjRingTransferView_size[sizeof(SjRingTransferView)==64?1:-1];
int func_0040FD00(SJ_OBJ *object,int line,int operation)
{
    SjRingTransferView *ring=(SjRingTransferView *)object;
    return ring->transfer_bytes[line][operation];
}
void D_0040FD18(void *context,int error)
{
    for (;;) {}
}
