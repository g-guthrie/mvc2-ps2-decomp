typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001CFDD0();
void func_001CFD20(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    if (q[0x1E4] != 0x1D) {
        p[4]++;
        func_001CFDD0(p);
        return;
    }
    if (p[5] == 0) {
        if (*(f32 *)(*(u8 **)(p + 0x18) + 0x60) < 0.0f) {
            p[5]++;
            func_001757E0(p, 0x17, (s8)(p[0x20] != 0 ? 0x19 : 0x18));
        }
    }
    func_00175700(p);
}

void func_00272390(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[7]++;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 1, 3);
    }
}

extern u8 *func_0039E470(void *p, s32 n);
extern void func_00184540();
void func_002D5060(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(s8 *)(p + 0x1E8) += 1;
        func_00184540(p);
    } else {
        s8 f = *(s8 *)(p + 0x151);
        if (f & 1) {
            u8 *o;
            p[0x151] = f & ~1;
            o = func_0039E470(p, 3);
            if (o != 0) o[0x21] = 0;
        }
    }
}
