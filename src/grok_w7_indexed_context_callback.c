typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*ContextCallback)(u8 *, void *);
extern const u32 jtbl_004C1418[] __attribute__((section(".sdata")));
void func_002FC640(u8 *p, void *context)
{
    u8 *q = (u8 *)context;
    u8 index;

    if (*(u16 *)(p + 0x168) == 0x1C000)
        return;
    if (p[0x1E4] == 21)
        goto done;
    if (p[0x1E4] == 29)
        goto done;
    q[1]++;
    index = q[2];
    ((ContextCallback)jtbl_004C1418[index])(p, context);
done:
    ;
}
