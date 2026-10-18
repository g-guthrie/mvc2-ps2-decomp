typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_002CA1B0(u8 *p, u8 *b) {
    s8 r;
    u32 c;
    f32 v;
    extern s32 func_00175700();
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001CEA00(u8 *, s32);
    extern void func_0039B7E0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    r = func_00175700(p);
    if (r < 0) {
        c = p[7];
        p[7] = c + 1;
        p[0x20D] = 2;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            v = 15.0f;
        } else {
            v = -15.0f;
        }
        *(f32 *)(p + 0x5C) = v;
        p[0x1B5] = 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        b[5] = 2;
        *(s16 *)(p + 0x1C) = 0x60;
        *(s16 *)(p + 0x1E) = 7;
        *(s32 *)(p + 0x14) = 0;
        func_00176160(p, 0, p[0x25] << 1, 1);
        func_001CEA00(p, 9);
        func_0039B7E0(p, 0);
        func_001757E0(p, 0x15, 0x16);
    }
}
