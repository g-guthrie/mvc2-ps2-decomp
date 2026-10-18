typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[1]; u8 b1; u8 p1[2]; u8 b4; u8 p2[0x43]; s32 i48; u8 p3[4]; f32 f50; f32 f54; u8 p4[0x84]; s32 iDC; u8 p5[0x3E]; s16 s1E; } A_0037B100;

void func_0037B100(u8 *a, u8 *b, u8 *c)
{
    extern void func_0037B400(u8 *, u8 *);
    extern void func_00175700(u8 *);
    extern void func_0037B3E0(u8 *);
    f32 t;
    s16 h;
    if (a[1] != (*(u8 **)(a + 0x18))[1]) {
        func_0037B400(a, b);
        return;
    }
    if (*(s32 *)(c + 8) != 0) {
        a[4] = 5;
        return;
    }
    *(s32 *)(a + 0xDC) = *(s32 *)(a + 0xDC) % 2;
    if (*(s32 *)(a + 0xDC) != 0) t = 0.8999999761581421f; else t = 1.0f;
    *(f32 *)(a + 0x50) = t;
    if (*(s32 *)(a + 0xDC) != 0) t = 0.8999999761581421f; else t = 1.0f;
    *(f32 *)(a + 0x54) = t;
    *(s32 *)(a + 0xDC) = *(s32 *)(a + 0xDC) + 1;
    *(s32 *)(a + 0x48) = *(s32 *)(a + 0x48) + 0x1F4A;
    if (*(s16 *)(a + 0x1E) != 0) {
        func_00175700(a);
        h = *(s16 *)(a + 0x1E) - 1;
        *(s16 *)(a + 0x1E) = h;
        *(f32 *)(a + 0x118) -= 0.05000000074505806f;
    } else {
        a[4] = 5;
        func_0037B3E0(a);
    }
}
