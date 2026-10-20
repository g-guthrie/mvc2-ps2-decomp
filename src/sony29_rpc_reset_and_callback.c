/* Native RPC compatibility reset and interrupt callback adapter. */
typedef unsigned int u32;
typedef void (*RpcCallback)(void *);
typedef struct {
    RpcCallback callback;
    void *argument;
} RpcCallbackRecord;

extern int D_004382FC;
extern char D_004C6C28[];
extern void *func_0011D8F8(void *, int, u32);

int func_00107E58(void)
{
    D_004382FC = 0;
    func_0011D8F8(D_004C6C28, 0, 4);
    return 0;
}

void func_00107B90(void *event, void *context)
{
    RpcCallbackRecord *record = context;
    if (record->callback) record->callback(record->argument);
    /* Complete preceding memory operations before re-enabling interrupts. */
    __asm__ volatile("sync\n\tei" ::: "memory");
}
