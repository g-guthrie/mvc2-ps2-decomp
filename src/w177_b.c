typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x22-8]; u8 b22; u8 p23[0x38-0x23]; f32 f38; u8 p3c[0x430-0x3C]; f32 f430; } PA;
extern f32 D_004F1FE8;
s32 func_002BD410(PA *p, f32 *q) {
    extern void func_002BD610(PA *, f32 *);
    extern void func_001757E0(PA *, s32, s32);
    f32 t;
    if (p->b22 == 8) return 0;
    t = (double)D_004F1FE8 - 240.0;
    if (p->f38 > p->f430 && p->f38 > t) return 0;
    p->b7 = 2;
    func_002BD610(p, q);
    *(u32 *)((u8 *)q + 8) = 0x43700000;
    func_001757E0(p, 0x16, 0);
    return 1;
}
typedef struct { f32 x, y, z; } V3Q;
typedef struct { u8 p0[1]; u8 b1; u8 p2[2]; u8 b4; u8 b5; u8 p6[0x24-6]; s8 b24; u8 p25[0x34-0x25]; f32 f34; f32 f38; f32 f3c; u8 p40[0x118-0x40]; f32 f118; u8 p11c[0x13C-0x11C]; u8 b13c; u8 p13d[0x151-0x13D]; s8 b151; } PN;
void func_001BA780(PN *p, PN *q) {
    extern s8 func_00175670(PN *);
    extern void func_001BAD70(PN *, PN *);
    u32 t = p->b5;
    s32 r;
    p->b5 = t + 1;
    r = p->b5 % 2;
    p->f118 = (r != 0) ? 1.0 : 0.8;
    *(V3Q *)((u8 *)p + 0x34) = *(V3Q *)((u8 *)q + 0x34);
    if (p->b1 != q->b1) {
        func_001BAD70(p, q);
        return;
    }
    if (func_00175670(p) < 0) {
        p->b4 = 2;
        p->b13c = 0;
    } else if (p->b151 == 2) {
        p->b24 = q->b24;
    }
}
