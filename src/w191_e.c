typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x34 - 8];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad70[0x151 - 0x70];
    s8 b151;
    u8 pad152[0x1E6 - 0x152];
    u8 b1E6;
} P234;

void func_00234E00(P234 *p)
{
    extern void func_00175700(P234 *);
    extern void func_00235020(P234 *);
    extern void func_001757E0(P234 *, s32, s32);
    f32 z = 0.0f;

    func_00175700(p);
    if (p->b151 != 0) {
        func_00235020(p);
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(p->f60 * p->f6c < z)) {
        u32 t = p->b7;
        p->b7 = t + 1;
        *(u32 *)&p->f5c = 0xBFD55555;
        p->f68 = z;
        *(u32 *)&p->f60 = 0x412B6DB6;
        *(u32 *)&p->f6c = 0xBF092492;
        if (p->b1E6 == 0) {
            p->f5c = -p->f5c;
        }
        func_001757E0(p, 0x12, 2);
    }
}
