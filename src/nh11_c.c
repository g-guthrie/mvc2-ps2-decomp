typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
typedef struct { u8 pad0[7]; u8 b7; u8 pad8[0x34-8]; f32 f34, f38; u8 pad3c[0x5C-0x3C]; f32 f5c, f60; u8 pad64[4]; f32 f68, f6c; u8 pad70[0x151-0x70]; s8 b151; } S;
typedef signed short s16;
static void func_00230020(u8 *p, u8 *work_unused) {
    f32 a = 5.0f;
    f32 b = -0.1041666641831398f;
    if (*(s16 *)(p + 320) == 0) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 92) = a;
    *(f32 *)(p + 104) = b;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
}
void func_002301C0(S *p, u8 *q)
{
    extern void func_00175700(S *);
    func_00175700(p);
    if (p->b151 != 0) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    } else {
        u32 t = p->b7;
        p->b7 = t + 1;
        q[0x15] = 0;
        func_00230020((u8 *)p, q);
    }
}
