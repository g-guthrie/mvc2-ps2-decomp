typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1a;
extern G1a *D_004C2794;

void func_001AA9D0(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    f32 k;
    s16 h;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) == 0) {
        k = -6.666666507720947f;
        if (*(f32 *)(p + 0x5C) < k) {
            *(f32 *)(p + 0x5C) = k;
            *(s32 *)(p + 0x68) = 0;
        }
    } else {
        k = 6.666666507720947f;
        if (!(*(f32 *)(p + 0x5C) <= k)) {
            *(f32 *)(p + 0x5C) = k;
            *(s32 *)(p + 0x68) = 0;
        }
    }
    func_00175700(p);
    if (*(s8 *)(q + 0x151) == 0 || q[0x1E4] != 0x1D || q[0x1FD] != 4) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x17, 0x45);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        if (*(s16 *)(p + 0x1C) == 0) {
            *(s16 *)(p + 0x1C) = 10;
            if (*(s16 *)(p + 0x140) == 0) {
                *(u32 *)(p + 0x5C) = 0x40200000;
                *(u32 *)(p + 0x68) = 0xBED55555;
            } else {
                *(u32 *)(p + 0x5C) = 0xC0200000;
                *(u32 *)(p + 0x68) = 0x3ED55555;
            }
        }
    }
    h = *(s16 *)(p + 0x1C);
    if (h != 0) {
        h = h - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            p[0x1B5] = 0x3A;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    func_001E7F60(p);
}
