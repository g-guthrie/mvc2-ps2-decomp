/* s8f: MW 3.0.3, ./try.sh src/s8f_a.c "-O3 -Op -sdatathreshold 0". func_0018E970 is a static verbatim copy of the real callee credited in src/wave33.c. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00446C40[];
extern s8 D_00446D40[];
typedef struct G18E970 { u8 p0[0x1CC]; struct G18E970 *w1cc; u8 *w1d0; u8 p1[0x47]; u8 b21b; u8 p2[4]; struct G18E970 *w220; u8 p3[0x1F]; s8 b243; } G18E970;
static u8 func_0018E970(G18E970 *p) {
    s8 n = p->b243;
    if ((p->w1d0[0x12] & 4) == 0) {
        G18E970 *t = p->w1cc;
        if (t == 0) t = p->w220;
        n = n + D_00446D40[(p->b21b - t->b21b + 7) & 0xF];
        if (n < 0) n = 0;
        if (n > 15) n = 15;
    }
    return n;
}

void func_0018EA00(u8 *a, u8 *b) {
    extern void func_0018ED90(u8 *, s32);
    extern void func_0018EE50(u8 *, s32);
    extern void func_0018ED20(u8 *, s32);
    extern void func_0018EB00(u8 *, s32);
    u32 i;
    u32 h;
    f32 k;
    i = func_0018E970((G18E970 *)a);
    *(u16 *)(a + 0x1C2) = *(u16 *)(b + 0x1C0);
    k = 1.6666666269302368f;
    *(f32 *)(a + 0x234) = k * (f32)D_00446C40[i] / 256.0f;
    *(f32 *)(a + 0x238) = 1.9791666269302368f;
    if (a[0x1E6] == 0) {
        *(f32 *)(a + 0x234) = -*(f32 *)(a + 0x234);
        *(f32 *)(a + 0x238) = -*(f32 *)(a + 0x238);
    }
    h = *(u16 *)(a + 0x1C2);
    if (h & 0x10) {
        func_0018ED90(a, i);
        return;
    }
    if (h & 0x1000) {
        func_0018EE50(a, i);
    } else if (*(u8 *)(*(u8 **)(a + 0x1D0) + 1) & 0x40) {
        func_0018ED20(a, i);
    } else {
        func_0018EB00(a, i);
    }
}
