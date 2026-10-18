typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

void func_00298550(PH *p) {
    extern void func_00185490();
    extern void func_00298390(PH *);
    extern double func_00119058(f32);
    extern void func_00175700(PH *);
    extern void func_001757E0(PH *, s32, s32);
    func_00185490();
    func_00298390(p);
    ((u8 *)p)[0x209] = 2;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_00119058(p->f68 * p->f5c) < 0.0 &&
        (((s8 *)p)[0x211] & (1 << (((u8 *)p)[0x1E6] ^ 1))) == 0) {
        func_00175700(p);
        return;
    }
    p->b6++;
    func_001757E0(p, 0x15, 0x16);
}
