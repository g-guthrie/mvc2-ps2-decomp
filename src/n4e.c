typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00169BC0();
extern s32 func_00169AE0();
extern s32 func_0016A250();
extern void func_00169E50();
extern u8 D_004D18A1[];

s32 func_001697B0(u8 *p) {
    u32 s = p[0x451];
    switch (s) {
    case 0:
        p[0x451] = s + 1;
        func_00169E50(p, 1, 1);
    case 1:
        if ((D_004D18A1[0] & 4) == 0) {
            if (func_0016A250(p) != 0) {
                func_00169E50(p, 0, 1);
            }
        }
        return func_00169AE0(p, 1);
    case 2:
        return func_00169BC0(p, 1);
    default:
        return 0;
    }
}

extern u8 *func_001E7FD0(u8 *);

u8 *func_00247960(u8 *p) {
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    u8 *r;
    u32 a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 2; return r; }
        } else if (a == 1 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 3; return r; }
        }
    }
    return 0;
}

extern void (*D_004BF9B8[2])();

void func_001BED20(u8 *p, u8 *q) {
    u32 c = q[0x1E4];
    if (c != 0x15 || (c = q[0x1FD]) != 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        c = *(u16 *)(q + 0x168);
        if (c != 0x1506 && c != 0x1507) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        } else {
            D_004BF9B8[p[5]](p, q);
        }
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_00460D30[];
extern u32 D_004C283C;
extern void func_00343EF0();
extern u8 *func_003DA750();

void func_003440E0(s32 n) {
    u8 *o = func_003DA750(0, 6, 0);
    if (o != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_00343EF0;
        *(s16 *)(o + 0xCC) = n + 0x56;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD0) = 0x800821;
        *(V3 *)(o + 0x34) = D_00460D30[n];
        o[0x20] = n;
        *(u32 *)(o + 0x74) = 0;
    }
}

u8 *residual_002FF2D0(u8 *p) {
    s32 x = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    u8 *r;
    u32 a;
    p[0x22] = x;
    if ((u8)x != 0) {
        a = p[0x212];
        if (a == 0 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 2; return r; }
        } else if (a == 1 && p[0x1B7] == 1) {
            r = func_001E7FD0(p);
            if (r != 0) { p[0x20B] = 1; return r; }
        }
    }
    return 0;
}
