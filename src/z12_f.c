typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

s32 func_002E8F60(u8 *p) {
    extern s32 func_0018AA50(u8 *, s32, s16 *, s32);
    extern s32 func_0018A580(u8 *);
    extern void func_00186A60(u8 *, s32);
    s16 buf;
    u32 f;
    if (p[0x2BA] != 0) return 0;
    if (!func_0018AA50(p, 0x140, &buf, 3)) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (((s8 *)p)[0x1E8] != 0) return 0;
            *(s8 *)((s32)p + 0x1E8) += 1;
        }
    }
    if (!func_0018A580(p)) return 0;
    f = *(u16 *)(p + 0x35E);
    if (f & 0x800) p[0x1B7] = 2;
    else if (f & 0x400) p[0x1B7] = 0;
    else p[0x1B7] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x15);
    return 1;
}

void func_002BF1F0(PH *p) {
    extern s8 func_00175700(PH *);
    extern void func_00184540(PH *);
    extern void func_001843A0(PH *);
    u8 *q;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (*(volatile f32 *)&p->f38 <= *(f32 *)((u8 *)p + 0x430)) {
        p->f38 = *(f32 *)((u8 *)p + 0x430);
        ((u8 *)p)[0x20D] = 0;
    }
    if (p->b6 != 0 || func_00175700(p) < 0) {
        if (((u8 *)p)[0x20D] == 2) {
            func_00184540(p);
        } else {
            func_001843A0(p);
        }
        return;
    }
    if (((s8 *)p)[0x151] != 0) {
        p->b6++;
        *(u8 *)((s32)p + 0x151) = 0;
        q = *(u8 **)((u8 *)p + 0x1DC);
        *(PH **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x22;
    }
}
