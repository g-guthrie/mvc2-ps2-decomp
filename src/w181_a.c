typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 a, b; } P8_a;
extern s32 D_00632140[3];
extern s32 D_00632240[];

void func_004109C0(s32 a, s32 b, s32 c, P8_a *out)
{
    extern s32 func_00409708(s32, s32 *, s32, s32 *, s32);
    s32 y, x;
    D_00632140[0] = a;
    D_00632140[1] = b;
    D_00632140[2] = c;
    func_00409708(0x26, D_00632140, 3, D_00632240, 2);
    x = D_00632240[0];
    y = D_00632240[1];
    out->a = x;
    __asm__ volatile("");
    out->b = y;
}

extern u8 D_004BDA48[];
extern u8 D_00488ED0[];
extern s32 D_00489018;
extern u8 D_004BDA78[];
extern u8 D_004BDAA0[];

s32 func_00409BD0(s32 p)
{
    extern s32 func_0040AAB8();
    extern void func_0040A440();
    extern void func_0010F148();
    extern s32 func_004098D8(void *, u8 *);
    extern void func_0011EB60();
    extern void func_004098A8();
    s32 buf[12];
    s32 r;
    if (p == 0) {
        func_004098A8(p, D_004BDA48);
        return 0;
    }
    func_0040AAB8(p, buf);
    r = buf[1];
    if (r == 0) {
        func_0040A440(p, D_00488ED0);
        func_0010F148(0);
        if (func_004098D8(buf, D_00488ED0) == 0) {
            if (D_00489018 != 2)
                func_0011EB60(D_004BDA78, D_00488ED0);
            func_004098A8(0, D_004BDAA0);
            return 0;
        }
        r = buf[1];
    }
    return r;
}

typedef struct {
    u8 b0, b1, b2, b3;
    s32 f4, f8, fc, f10, f14, f18, f1c;
    u8 pad20[4];
    s32 f24;
} R_o;

extern u8 D_004BDAD0[], D_004BDAF8[], D_004BDB20[], D_004BDB50[], D_004BDB78[], D_00488ED0[];
extern s32 D_00489018;

R_o *func_00409CE8(u8 *a0, s32 a1, s32 a2)
{
    extern R_o *func_00409C90();
    extern s32 func_0040AAB8();
    extern void func_0040A440();
    extern void func_0011EB60();
    extern void func_0010F148();
    extern s32 func_004098D8(void *, u8 *);
    extern void func_004098A8();
    extern void func_00409CC8();
    R_o *s0;
    u8 *s2;
    s32 s3;
    s32 v;
    u8 *msg;
    if (a0 == 0) {
        func_004098A8(a0, D_004BDAD0);
        return 0;
    }
    if (a2 != 0) {
        func_004098A8(0, D_004BDAF8);
        return 0;
    }
    s0 = func_00409C90();
    if (s0 == 0) {
        func_004098A8(0, D_004BDB20);
        return 0;
    }
    s2 = (u8 *)s0 + 0x20;
    s3 = func_0040AAB8(a0, s2);
    if (s0->f24 == 0) {
        func_0040A440(a0, D_00488ED0);
        if (D_00489018 != 2)
            func_0011EB60(D_004BDB50, D_00488ED0);
        func_0010F148(0);
        if (func_004098D8(s2, D_00488ED0) == 0) {
            func_004098A8(0, D_004BDB78);
            func_00409CC8(s0);
            return 0;
        }
        s0->b1 = 0;
    } else {
        s0->b1 = 1;
    }
    v = s0->f24;
    s0->f8 = (u32)(v + 0x7FF) >> 11;
    s0->b0 = 1;
    s0->f4 = v;
    s0->fc = 0;
    s0->f18 = 0;
    s0->f10 = 0;
    s0->f14 = 0;
    s0->b2 = 0;
    s0->f1c = 0;
    if (s3 == 1)
        s0->f8 = 0x7FFFFFFF;
    return s0;
}
