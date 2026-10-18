typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00359140(u8 *p, s32 b)
{
    extern void func_00359090(u8 *, s32, s32);
    extern void func_0035A820();
    u8 *q = *(u8 **)(p + 0x18);
    if ((s8)q[0x151] < 0) {
        u16 k = *(u16 *)(q + 0x168);
        if (k == 0x1605) {
            func_00359090(p, b, 0x13);
            return;
        } else if (k == 0x704) {
            func_00359090(p, b, 0xC);
            return;
        } else if (k == 0xB06) {
            func_00359090(p, b, 0x13);
            return;
        } else if (k == 0xB07) {
            func_00359090(p, b, 0xD);
            return;
        } else if (k == 0x904) {
            func_00359090(p, b, 0xE);
            return;
        } else if (k == 0x905) {
            func_00359090(p, b, 0xF);
            return;
        } else if (k == 0x1408) {
            func_00359090(p, b, 0xF);
            return;
        }
    }
    func_0035A820();
}

extern u8 D_00459C90[];

s32 func_002C54F0(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_002CAFC0(u8 *);
    extern void func_00186A60(u8 *, s32);
    if (func_00189310(p, D_00459C90, p + 0x398) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 v = p[0x1E8];
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x398);
    if (p[0x215] != 0) func_002CAFC0(p);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x1D);
    if (*(s8 *)(p + 0x539) != 0) {
        p[7] = *(s8 *)(p + 0x212) << 1;
    } else {
        p[7] = *(s8 *)(p + 0x1B7) + (*(s8 *)(p + 0x212) << 1);
    }
    return 1;
}

typedef struct {
    u8 p0[6]; u8 f6; u8 p00[0x34 - 7]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x160 - 0x70]; s8 b[8]; u8 p5[0x20D - 0x168]; u8 f20d; u8 p6[0x354 - 0x20E]; u16 f354; u8 p7[0x430 - 0x356]; f32 f430;
} P2C94;
typedef struct { u8 pad[0x539]; s8 f539; } Z2C94;

void func_002C9430(P2C94 *p)
{
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001CEA00(P2C94 *, s32);
    extern void func_001757E0(P2C94 *, s32, s32);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->f38 > p->f430) {
        s8 *b = p->b;
        s8 f = b[1];
        s8 *q = b + 1;
        if (f != 0) {
            *q = 0;
            func_001CEA00(p, 7);
        }
        if (((Z2C94 *)p)->f539 == 0) {
            u16 k = p->f354;
            if (k & 0x800) {
                *(u32 *)&p->f5c = 0xC0D55555;
            } else if (k & 0x400) {
                *(u32 *)&p->f5c = 0x40D55555;
            }
        }
    } else {
        u32 t = p->f6;
        p->f6 = t + 1;
        p->f38 = p->f430;
        p->f20d = 1;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0xF);
    }
}
