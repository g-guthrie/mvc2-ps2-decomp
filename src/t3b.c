typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_00453940[];
extern s32 func_00175700();
extern void func_00184540();

s32 func_0025C3B0(u8 *p) {
    if (func_00189310(p, D_00453940, p + 0x378) == 0) return 0;
    if (p[0x20D] == 2) {
        s8 t = p[0x1E8];
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

void func_002FB920(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    s8 r = func_00175700(p);
    if (r < 0) {
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        u8 a;
        p[0x151] = 0;
        *(u8 **)(q + 0x1C8) = p;
        if (p[0x168] == 2) {
            a = 0x22;
        } else if (p[0x168] == 3) {
            a = 0x23;
        } else {
            a = 0x21;
        }
        q[0x1B5] = a;
        p[0x1B5] = a;
        q[0x20A] = 1;
        q[0x1E6] = p[0x1E6];
        q[0x1E6] ^= 1;
    }
}
