/* Queue the incoming RPC call and wake its idle server thread. */
#include "sony29_rpc_server_types.h"
typedef struct {
    SonyRpcHeader header;
    SonyRpcClient *client;
    int number,size;
    void *receive_buffer;
    int receive_size,receive_mode;
    SonyRpcServer *server;
} RpcCallRequest;
extern int func_00104C90(int);
void func_00106DD8(void *data,void *context)
{
    RpcCallRequest *request=data;
    SonyRpcServer *server=request->server;
    SonyRpcQueue *queue=server->queue;
    if (!queue->first) queue->first=server;
    else queue->last->next=server;
    queue->last=server;
    {
        void *packet=request->header.pkt_addr;
        SonyRpcClient *client=request->client;
        server->packet=packet;
        server->client=client;
    }
    server->number=request->number;
    server->size=request->size;
    server->receive_buffer=request->receive_buffer;
    server->receive_size=request->receive_size;
    server->receive_mode=request->receive_mode;
    server->rpc_id=request->header.rec_id;
    if (queue->thread>=0 && queue->active==0) func_00104C90(queue->thread);
}
