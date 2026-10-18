typedef unsigned int u32;
typedef signed int s32;
typedef void (*RuntimeTextCallback)(void *, void *);
struct RuntimeTextCallbackSlot { RuntimeTextCallback callback; void *context; };
extern unsigned char D_00496748[];
extern struct RuntimeTextCallbackSlot D_004C2B20;
extern s32 func_00120440(void *destination, const void *source, u32 maximum);
extern s32 func_001200D8(void *destination, const void *source, u32 maximum);
void func_004113D0(const void *first, const void *second)
{
    func_00120440(D_00496748, first, 255);
    func_001200D8(D_00496748, second, 255);
    if (D_004C2B20.callback != 0)
        D_004C2B20.callback(D_004C2B20.context, D_00496748);
}
