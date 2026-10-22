typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x14]; u8 *f14; } G283C;
extern G283C *D_004C283C;

void func_00340000(u8 *p)
{
    extern void func_00170E60(u8 *, u8 *, s32, s32, void *, void *);
    extern void func_003400A0();
    u8 *q;
    u8 *r;
    s32 a[2];
    if (*(u8 *)(*(s32 *)(p + 0x18) + 4) > 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) += 4;
        if (*(s16 *)(p + 0x1C) >= 0x168) *(s16 *)(p + 0x1C) = 0;
        q = *(u8 **)(p + 0x84);
        a[0] = (s32)p;
        a[1] = 0;
        r = *(u8 **)(q + 0x1C);
        func_00170E60(D_004C283C->f14, *(u8 **)(r + 0x54) + 0x190, *(s32 *)(q + 0x14),
                      *(s32 *)(r + *(s16 *)(p + 0xCC) * 4), func_003400A0, (void *)((s32)a));
    }
}
