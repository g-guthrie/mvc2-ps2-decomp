typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
extern void func_001843A0(void *p);

void func_002FD700(u8 *p) {
    u32 *a, *b, *c, *d;
    s16 v;
    func_00175700(p);
    a = (u32 *)(p + 0x5C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    d = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
    }
}

extern u32 D_004C2794;

void func_002BAC20(u8 *p) {
    s8 v = func_00175700(p);
    if (v < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        s16 *e;
        s32 x;
        p[0x151] = 0;
        x = p[0x1B7] ? 0x3B : 0x39;
        p[0x1B5] = x;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        e = (s16 *)((p[2] << 1) + D_004C2794);
        e[0x3E] = e[0x3E] + 1;
    }
}
