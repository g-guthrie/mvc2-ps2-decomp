typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_0044B450[])(void *, void *);
void func_001A7820(u8 *p, u8 *q) {
    p[0x24] = 0xD;
    if (q[0x169] != 0x13) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        D_0044B450[p[5]](p, q);
    }
}

extern s8 func_00175700(void *p);
void func_00228C50(u8 *p) {
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0xC0892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
void func_001C6560(u8 *d, u8 *s) {
    u8 *q = s + 0x2B8;
    if (s[0x2C3] == 0 || q[0xA] != 0) {
        *(s16 *)(d + 0x140) = *(s16 *)(s + 0x140);
        *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34);
        *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38);
        d[7] = 5;
        d[0] = 1;
        d[0x13C] = 1;
        *(s16 *)(d + 0x1C) = 0x20;
        func_001757E0(d, 0x19, 0x11);
    }
}

extern s32 func_001E7FD0();
s32 func_00214960(u8 *p) {
    s32 v = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    p[0x22] = v;
    if ((u8)v != 0 && p[0x212] == 1 && p[0x1B7] == 1) {
        s32 r = func_001E7FD0();
        if (r) {
            p[0x20B] = 1;
            return r;
        }
    }
    return 0;
}
extern u8 D_00583B90[];
extern u8 D_00583BC6;
void func_00138710(u8 *p) {
    if (p[0x22] == 7) {
        u32 t = p[5];
        p[5] = t + 1;
        D_00583B90[p[0x20]] = 3;
        if (p[0x20] != 0) {
            D_00583BC6 &= 0xD;
        } else {
            D_00583BC6 &= 0xE;
        }
    }
}
extern void func_00186A60(void *p, s32 a);
extern void func_0018ED20(void *p, s32 a);
void func_0018F6B0(u8 *p) {
    p[5] = 3;
    p[7] = 0;
    p[6] = 0;
    p[0x24C] = 0;
    func_00186A60(p, 0x20);
    p[0x24A] = 0;
    p[0x247] = 0x16;
    p[0x242] = 0;
    p[0x243] = 10;
    p[0x248] = 1;
    func_0018ED20(p, p[0x243]);
    p[0x20D] = 2;
    p[0x1B4] = 1;
}
extern void func_00289570(void *p);
extern s8 func_00175700(void *p);
extern void func_0028D810(void *p, void *a);
extern void func_0028D8B0(void *p);
extern void func_001C09A0(void *p, s32 a);
extern void func_00385EE0(void *p, s32 a);
extern u8 D_00455CF0[];
void func_00289490(u8 *p) {
    func_00289570(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        func_0028D810(p, D_00455CF0);
        func_0028D8B0(p);
        func_001C09A0(p, 5);
        func_00385EE0(p, 2);
    }
}
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001D2130(void);
void func_001D20B0(u8 *p, s32 a, s32 b) {
    u8 *o = func_003DA750(0, 3, 1);
    if (o) {
        *(s16 *)(o + 0x26) = 0x2B00;
        o[0x20] = a;
        o[0x21] = b;
        o[0x22] = p[0x1E4];
        *(s16 *)(o + 0x1C) = p[0x1FD];
        *(void (**)(void))(o + 0x10) = func_001D2130;
        *(u8 **)(o + 0x18) = p;
    }
}
