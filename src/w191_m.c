typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x7C];
    s16 h7C[2];
} G2142;

extern G2142 *D_004C2794;

static void func_00213FD0(u8 *p)
{
    *(s32 *)(p + 92) = 0x41555555;
    *(s32 *)(p + 104) = 0xBED55555;
    if (p[486] == 0) {
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        *(f32 *)(p + 104) = -*(f32 *)(p + 104);
    }
    *(s16 *)(p + 868) = 0;
    *(s16 *)(p + 870) = 0;
    *(s16 *)(p + 28) = 0;
}

void func_00214200(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern s32 func_0018AB10(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u32 t;

    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x150) != 0) {
            *(s8 *)(p + 0x150) = 0;
            p[0x1B5] = 0x3B;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7C[p[2]]++;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            if (func_0018AB10(p) != 0 || ((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x360) != 0) {
                *(s16 *)(p + 0x1C) = 1;
            }
        }
    } else if (*(s16 *)(p + 0x1C) == 0) {
        p[6] = 5;
        func_001757E0(p, 0x14, 0x10);
    } else {
        t = p[6];
        p[6] = t + 1;
        func_00213FD0(p);
        p[0x1B5] = 0x3D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x14, 0xB);
    }
}

void func_002140C0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern s32 func_0018AB10(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u32 t;

    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x150) != 0) {
            *(s8 *)(p + 0x150) = 0;
            p[0x1B5] = 0x3B;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7C[p[2]]++;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            if (func_0018AB10(p) != 0 || ((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x360) != 0) {
                *(s16 *)(p + 0x1C) = 1;
            }
        }
    } else if (*(s16 *)(p + 0x1C) == 0) {
        p[6] = 5;
        func_001757E0(p, 0x14, 0x10);
    } else {
        t = p[6];
        p[6] = t + 1;
        func_00213FD0(p);
        p[0x1B5] = 0x3C;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        func_001757E0(p, 0x14, 0xA);
    }
}
