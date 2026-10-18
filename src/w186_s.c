typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G31F;
extern G31F *D_004C2794;

void func_0031F5E0(u8 *p, u8 *q) {
    extern void func_001843A0();
    extern s32 func_00175700();
    extern void func_001E3210();
    extern void func_00126400();
    extern void func_00354760();
    extern void func_001757E0();
    s32 r;
    s32 v;
    u8 *w;
    f32 d;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(s16 *)(q + 8) = *(s16 *)(q + 8) + 1;
    p[0x209] = 2;
    if (*(s8 *)(p + 0x1B2) == 0) {
        func_001843A0();
        return;
    }
    r = func_00175700(p);
    if ((s8)r >= 0) {
        v = *(s8 *)(p + 0x151);
        if (v == 0) return;
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x151] = 0;
        v = *(s8 *)(p + 0x150);
        if (v != 0) {
            func_001E3210(p, (u8)((s8)v + 0x1D));
            p[0x150] = 0;
        }
        w = *(u8 **)(q + 4);
        if (w[0x216] == 0) {
            *(f32 *)(w + 0x38) += 4.285714149475098f;
        }
    } else {
        u32 t = p[7];
        p[7] = t + 1;
        func_00126400();
        func_00354760(p);
        d = -80.0f;
        if (p[0x1E6] != 0) d = -d;
        *(f32 *)(p + 0x34) += d;
        *(f32 *)(p + 0x38) += 68.57142639160156f;
        func_001757E0(p, 0x16, 2);
    }
}
