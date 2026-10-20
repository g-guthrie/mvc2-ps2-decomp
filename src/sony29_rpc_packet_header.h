#ifndef MVC2_SONY29_RPC_PACKET_HEADER_H
#define MVC2_SONY29_RPC_PACKET_HEADER_H
/* SifRpcPktHeader_t layout, PS2SDK common/include/sifrpc-common.h,
 * revision 329e2bb43287e16af16c4dde1c614e2662c24468. */
typedef struct SonyRpcHeader {
    unsigned int command[4];
    unsigned int rec_id;
    void *pkt_addr;
    unsigned int rpc_id;
} SonyRpcHeader;
struct SonyRpcQueue;
typedef struct SonyRpcPacketPool {
    unsigned int counter;
    unsigned char *buffer;
    int count;
    unsigned int unknown_0c[2];
    unsigned char *reply_buffer;
    int reply_count;
    unsigned int unknown_1c[2];
    int reply_index;
    struct SonyRpcQueue *queues;
} SonyRpcPacketPool;
SonyRpcHeader *func_001067F0(SonyRpcPacketPool *pool);
typedef struct SonyRpcReceive {
    void *packet;
    unsigned int rpc_id;
    int semaphore;
    unsigned int mode;
} SonyRpcReceive;
typedef struct SonyRpcClient {
    SonyRpcReceive receive;
    unsigned int command;
    void *buffer, *callback_buffer;
    void (*end_function)(void *);
    void *end_parameter, *server;
} SonyRpcClient;
int func_00106A40(SonyRpcReceive *receive, void *source, void *destination, int size, int mode);
int func_00106C98(SonyRpcClient *client, int sid, int mode);
void func_00106898(SonyRpcHeader *packet);
#endif
