typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0025F3E0(u8 *p) {
    extern void func_0036BFF0();
    extern void func_001757E0();
    extern void func_00175700();
    if (*(s8 *)(p + 0x151) == 0xE) {
        p[0x151] = 0;
        func_0036BFF0(p, 8, 0x13, 8);
    }
    if (*(s8 *)(p + 0x153) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 0x1C);
    }
    func_00175700(p);
}

extern const u32 jtbl_00475DD0[11];
void func_003C4140(u8 *p, u8 *q) {
    s8 v;
    ((void (*)(u8 *, u8 *))jtbl_00475DD0[8 + p[6]])(p, q);
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0) p[0x24] = 0;
}

void func_002B1610(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    u32 v[3];
    s32 f;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    f = *(s8 *)(p + 0x151);
    if (f & 1) {
        f &= ~1;
        *(s8 *)(p + 0x151) = f;
        {
            u32 t = p[6];
            p[6] = t + 1;
            p[0x404] = 0;
            p[0x405] = 0;
            v[0] = 0x41555555;
            v[1] = 0x42F44924;
            v[2] = 0;
            func_001830D0(p, v, 1, t + 1);
        }
    }
}

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x20]; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; } F2C;

void func_002C2DD0(u8 *p) {
    extern void func_001757E0();
    extern void func_00185490();
    F2C *q = (F2C *)p;
    s16 h;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    p[0x209] = 1;
    p[0x159] = 0xFF;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        q->f5c = 0;
        p[0x13C] = 1;
        func_001757E0(p, 0x15, 6, 1);
        func_00185490(p);
    }
}


void func_002980D0(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    F2C *q = (F2C *)p;
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2BAAAAA;
        v[1] = 0x42C96DB6;
        v[2] = 0;
        func_001830D0(p, v, 1, t + 1);
    }
}

void func_00238640(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_00238B70();
    extern void func_00238A10();
    F2C *f = (F2C *)p;
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    (*(u8 **)(p + 0x1DC))[0x208] = 2;
    f->f34 += f->f5c;
    f->f5c += f->f68;
    f->f38 += f->f60;
    f->f60 += f->f6c;
    if ((s8)func_00175700(p) < 0) {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            u32 t = p[7];
            p[7] = t + 1;
            func_001757E0(p, 0x16, 0x24);
        }
    }
    func_00238B70(p, q);
    func_00238A10(p, q);
}
