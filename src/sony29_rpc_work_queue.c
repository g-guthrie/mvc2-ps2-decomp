/* Interrupt-protected RPC queue removal and its server-thread loop. */
typedef unsigned char u8;
typedef struct RpcItem {
    u8 opaque[0x3C];
    struct RpcItem *next;
} RpcItem;
typedef struct RpcQueue {
    u8 opaque00[4];
    int busy;
    u8 opaque08[4];
    RpcItem *head;
} RpcQueue;
extern int func_0010CA20(void);
extern int func_0010CA68(void);
extern void func_00107380(RpcItem *);
extern int func_00103D00(void);

RpcItem *func_00107328(RpcQueue *queue)
{
    RpcItem *item;
    func_0010CA20();
    item = queue->head;
    if (!item) queue->busy = 0;
    else {
        queue->busy = 1;
        queue->head = item->next;
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
