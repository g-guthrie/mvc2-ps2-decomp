typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x34]; f32 f34, f38; } M3;

void func_003671D0(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 flags;
    u32 a2;
    u8 *a3;
    f32 v;
    a3 = *(u8 **)(p + 0x1DC);
    flags = *(u32 *)(a3 + 0x428);
    if ((flags & 0x80000000) && *(s8 *)(p + 0x160) == 7) {
        func_001757E0(q, 0x10, 0xB);
        if (*(s16 *)(p + 0x140) != 0) v = -33.333332f; else v = 33.333332f;
        ((M3 *)p)->f34 += v;
        ((M3 *)p)->f38 += 34.285713f;
    } else if ((flags & 0x20000000) && *(s8 *)(p + 0x160) == 7) {
        *(s32 *)(q + 0x48) = 0;
        func_001757E0(q, 0x10, 0x12);
        if (*(s16 *)(p + 0x140) != 0) v = 30.0f; else v = -30.0f;
        ((M3 *)p)->f34 += v;
        ((M3 *)p)->f38 += 55.714283f;
    } else {
        a2 = *(u32 *)(a3 + 0x42C) & 0x1000;
        if (a2 && *(s8 *)(p + 0x160) == 8) {
            func_001757E0(q, 0x10, 2);
            ((M3 *)p)->f38 += -25.714285f;
        } else if (a2 && *(s8 *)(p + 0x160) == 9) {
            func_001757E0(q, 0x10, 0xD);
            if (*(s16 *)(p + 0x140) != 0) v = -30.0f; else v = 30.0f;
            ((M3 *)p)->f34 += v;
            ((M3 *)p)->f38 += -49.285713f;
        }
    }
}
