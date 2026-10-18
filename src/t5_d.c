typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_0045AE60[];

void func_001A9DE0(u8 *p, u8 *q) {
    s16 v;
    p[7]++;
    v = q[0x1E6] ^ 1;
    *(s16*)(p+0x140) = v;
    if (v == 0) *(f32*)(p+0x5C) = -10.0f; else *(f32*)(p+0x5C) = 10.0f;
    *(s32*)(p+0x68) = 0;
    if (*(s16*)(q+0x434) > 0) func_001757E0(p, 0x17, 0xD);
    else func_001757E0(p, 0x17, 0x4F);
}

s32 func_002E1070(u8 *p) {
    s32 r;
    if ((r = func_00189310(p, D_0045AE60, p + 0x388)) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 t = p[0x1E8];
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    p[0x213] = 0;
    return 1;
}

