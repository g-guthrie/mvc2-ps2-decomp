typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002D49D0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_0016A8B0(u8 *, u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_001864a0(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001E3710(u8 *, s32);
    f32 *a, *c, *b, *d;
    f32 z;
    u32 t;
    u16 fl;
    u8 *q;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    c = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    z = 0.0f;
    if (*a * *b > z) {
        *a = z;
        *b = z;
    }
    fl = *(u16 *)(p + 0x354);
    if (fl & 0xC00) {
        if (fl & 0x400) {
            *(f32 *)(p + 0x34) += 6.666666507720947f;
        } else {
            *(f32 *)(p + 0x34) += -6.666666507720947f;
        }
    }
    if (*(s16 *)(p + 0x1C) == 0) {
        if (*(s8 *)(p + 0x539) != 0) {
            q = *(u8 **)(p + 0x220);
            if (q[0x20D] == 2 || !(*(f32 *)(p + 0x60) < 0.0f)) {
                if (func_0016A8B0(p, q, 0x3D) != 0) {
                    goto S;
                }
            }
        } else if (*(u16 *)(p + 0x35C) & 0x300) {
S:
            *(s16 *)(p + 0x1C) = 1;
            func_001757E0(p, 0x15, 0x10);
        }
    }
    if (func_001864a0(p) != 0) {
        t = p[6];
        p[6] = t + 1;
        *(u32 *)a = 0;
        *(u32 *)c = 0;
        *(u32 *)b = 0;
        *(u32 *)d = 0;
        func_001757E0(p, 1, 4);
        func_00183d50(p);
        func_001E3710(p, 0x34);
    }
}
