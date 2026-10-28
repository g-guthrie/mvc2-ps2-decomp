typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G75a;
extern G75a *D_004C2794;
extern u8 *D_004C294C;

void func_0034F5C0(u8 *p) {
    extern void func_0034E880(u8 *);
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_0034F7D0(u8 *);
    u8 *g;
    u8 *o;
    f32 f;
    func_0034E880(p);
    func_00175700();
    g = D_004C294C;
    if (g[2] != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        D_004C294C[2] = 1;
        p[0x1B5] = 0x48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        switch (*(s16 *)(p + 0x140)) {
        default:
            f = 15.208333015441895f;
            break;
        case 0:
            f = -15.208333015441895f;
            break;
        }
        *(f32 *)(p + 0x5C) = f;
        func_001757E0(p, 0x17, 0x17);
        func_001E3210(p, 0x21);
        return;
    }
    o = *(u8 **)(p + 0x18);
    if (*(s8 *)(o + 0x13C) == 0) {
        func_0034F7D0(p);
        return;
    }
    if (*(s16 *)(o + 0x434) == 0) {
        func_0034F7D0(p);
        return;
    }
    if (*(s8 *)(g + 1) == 0) {
        func_0034F7D0(p);
    }
}
