typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x34 - 7];
    f32 f34, f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60, f64, f68, f6c;
    u8 pad70[0x1B7 - 0x70];
    u8 b1B7;
    u8 pad1B8[0x20D - 0x1B8];
    u8 b20D;
    u8 pad20E[0x430 - 0x20E];
    f32 f430;
} S276;

void func_00276750(S276 *p) {
    extern void func_00175700(S276 *);
    extern void func_00183d50(S276 *);
    extern void func_001757E0(S276 *, s32, s32);
    f32 *a, *b, *c, *d;
    func_00175700(p);
    p->f34 += p->f5c;
    a = &p->f5c;
    p->f5c += p->f68;
    c = &p->f68;
    p->f38 += p->f60;
    b = &p->f60;
    p->f60 += p->f6c;
    d = &p->f6c;
    if (p->f38 < p->f430) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->b20D = 0;
        p->f38 = p->f430;
        func_00183d50(p);
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_001757E0(p, 0x15, (u8)(p->b1B7 + 0x10));
    }
}
