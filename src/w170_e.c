typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x64]; f32 fD4; } SE;

void func_00374740(SE *q) {
    extern void func_00175700();
    u8 *p = (u8 *)q;
    func_00175700(p);
    *(s32 *)(p + 0x48) += 0x1200;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    if (!(q->fD4 < q->f38)) {
        q->f38 = q->fD4;
        p[6]++;
        *(u32 *)(p + 0x5C) = 0xC0555555;
        *(u32 *)(p + 0x68) = 0x3C555555;
        if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) {
            *(u32 *)(p + 0x5C) = 0x40555555;
            *(u32 *)(p + 0x68) = 0xBC555555;
        }
        *(u32 *)(p + 0x60) = 0x40AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBE700000;
    }
}
