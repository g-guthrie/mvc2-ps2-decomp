typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_a;
extern H_a *D_004C2794;

void func_0037BBF0(u8 *p)
{
    extern void func_0037BDD0();
    extern s32 func_0037BD80();
    extern void func_001E7F60(u8 *);
    extern void func_00175700();
    s16 h;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        p[4] = 3;
        func_0037BDD0(p);
        return;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0 || *(s8 *)(p + 0x1B3) != 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (func_0037BD80(p) != 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        if (*(s16 *)(p + 0x1E) != 0) {
            p[0x1B0] = 0x42;
            p[0x1B1] = 0x42;
            if (p[7] != 0) {
                p[0x1B5] = 0x3E;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]] += 1;
            } else {
                p[0x1B5] = 0x3C;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]] += 1;
            }
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        }
    }
    func_001E7F60(p);
}
