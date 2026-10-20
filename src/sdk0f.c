#include "sony29_rpc_server_types.h"
SonyRpcServer *func_00106B98(int key, SonyRpcPacketPool *pool) {
    SonyRpcQueue *queue;
    SonyRpcServer *server;
    for (queue = pool->queues; queue; queue = queue->next)
        for (server = queue->servers; server; server = server->link)
            if (server->sid == key) return server;
    return 0;
}
