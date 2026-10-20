/* Reply metadata is snapshotted before the allocator packet is written. */
#include "sony29_rpc_server_types.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct {
    SonyRpcHeader header;
    void *client;
    u32 command;
    void *server, *buffer, *callback_buffer;
    u32 unused[4];
} RpcReply;
typedef struct {
    SonyRpcHeader header;
    SonyRpcReceive *receive;
    void *source, *destination;
    int size;
} OtherRequest;
typedef struct {
    SonyRpcHeader header;
    SonyRpcClient *client;
    int sid;
} BindRequest;
extern u8 *func_001068B8(SonyRpcPacketPool *);
extern SonyRpcServer *func_00106B98(int,SonyRpcPacketPool *);
extern u32 func_00106410(u32,void *,int,void *,void *,int);
void func_001069E0(void *data,void *context)
{
    OtherRequest *request=data;
    RpcReply *reply=(RpcReply *)func_001068B8(context);
    void *packet=request->header.pkt_addr;
    SonyRpcReceive *receive=request->receive;
    reply->header.pkt_addr=packet;
    reply->client=receive;
    reply->command=0x8000000cu;
    func_00106410(0x80000008u,reply,64,request->source,request->destination,request->size);
}

void func_00106BE8(void *data,void *context)
{
    BindRequest *request=data;
    RpcReply *reply=(RpcReply *)func_001068B8(context);
    SonyRpcServer *server;
    void *packet=request->header.pkt_addr;
    SonyRpcClient *client=request->client;
    reply->client=client;
    reply->header.pkt_addr=packet;
    reply->command=0x80000009u;
    server=func_00106B98(request->sid,context);
    if (!server) {
        reply->server=0;
        reply->buffer=0;
        reply->callback_buffer=0;
    } else {
        reply->server=server;
        reply->buffer=server->buffer;
        reply->callback_buffer=server->callback_buffer;
    }
    func_00106410(0x80000008u,reply,64,0,0,0);
}
