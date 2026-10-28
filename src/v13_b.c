struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0015A1C0(u8 *p) {
    extern f32 func_00154710();
    extern void func_003DAA40(struct Object *);
    extern u8 D_00444F80[], D_00444F90[];
    s16 h = *(s16 *)(p + 0x1C);
    f32 r;
    double d;
    if (h >= 13) {
        func_003DAA40((struct Object *)p);
        return;
    }
    r = func_00154710(D_00444F80, p + 4, h);
    d = r;
    *(u32 *)(p + 0x40) = (u16)((u32)(s32)(d * 65536.0 / 360.0 + 0.5));
    r = func_00154710(D_00444F90, p + 5, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x78) = r;
    *(f32 *)(p + 0x7C) = r;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    *(s16 *)(p + 0x1C) += 1;
}

typedef struct FH {
    u8 pad0[6];
    u8 b6;
    u8 pad1[0x1C - 7];
    s16 h1c;
    u8 pad1b[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad4[0x1B7 - 0x70];
    u8 b1b7;
} FH;

void func_00297740(FH *p) {
    extern void func_00175700();
    extern u8 *func_001C8FD0(u8 *, s32);
    extern void func_001757E0();
    extern void func_002975D0();
    f32 old = p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if ((double)(old * p->f60) > 0.0) {
        func_00175700(p);
        return;
    }
    {
        u32 t = p->b6;
        p->b6 = t + 1;
    }
    func_001C8FD0((u8 *)p, 0);
    p->h1c = p->b1b7 * 2 + 1;
    func_001757E0(p, 0x15, 6);
    func_002975D0(p);
}
