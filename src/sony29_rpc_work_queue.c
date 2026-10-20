/* Interrupt-protected RPC queue removal and its server-thread loop. */
#include "sony29_rpc_server_types.h"
typedef SonyRpcServer RpcItem;
typedef SonyRpcQueue RpcQueue;
extern int func_0010CA20(void);
extern int func_0010CA68(void);
extern void func_00107380(RpcItem *);
extern int func_00103D00(void);

RpcItem *func_00107328(RpcQueue *queue)
{
    RpcItem *item;
    func_0010CA20();
    item = queue->first;
    if (!item) queue->active = 0;
    else {
        queue->active = 1;
        queue->first = item->next;
    }
    func_0010CA68();
    return item;
}

void func_00107548(RpcQueue *queue)
{
    RpcItem *item;
    for (;;) {
        while ((item = func_00107328(queue)) != 0) func_00107380(item);
        func_00103D00();
    }
}
