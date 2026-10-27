typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 p0[6]; u8 b6; u8 p7[0x2D]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c;
    u8 p70[0x60]; s32 wd0; u8 pd4[0x7C]; u8 p150; s8 b151; u8 p152[0x94]; u8 b1e6;
} P;
void func_002ACD40(P *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0(P *, s32, s32);
    f32 c;
    f32 z;
    s32 k;
    if (p->wd0 == 0) {
        func_00175700((u8 *)p);
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (p->b151 != 0) {
            p->b6++;
            if (p->b1e6 != 0) c = -0.4166666567325592f; else c = 0.4166666567325592f;
            k = 2;
            p->f68 = c;
            func_001757E0(p, k, k);
        }
    } else {
        z = 0.0f;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (!(p->f68 * p->f5c <= z)) {
            p->b6 += 2;
            func_001757E0(p, 2, 6);
        } else {
            func_00175700((u8 *)p);
        }
    }
}
