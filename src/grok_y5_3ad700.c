typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_003AE8A0(u8 *);
typedef void (*DispatchFn)(u8 *);
extern DispatchFn D_00473B00[2];

void func_003AD700(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0x20] == 0) {
        if (*(u16 *)(q + 0x168) != *(s16 *)(p + 0x1C) || q[0x1E4] != 20) {
            func_003AE8A0(p);
            return;
        }
    } else if (*(u16 *)(q + 0x168) != *(s16 *)(p + 0x1C) || q[0x1E4] != 21) {
        func_003AE8A0(p);
        return;
    }
    D_00473B00[p[4]](p);
}
