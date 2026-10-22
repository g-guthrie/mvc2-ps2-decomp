typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G2D;
extern G2D *D_004C2794;

void func_002D3450(u8 *p)
{
    u32 t;
    u8 *o;
    u8 *q;
    extern void func_002D3230(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    extern u8 *func_0039C5B0(u8 *, s32);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00183D10(u8 *);

    t = p[6];
    p[6] = t + 1;
    if (p[0x1FD] != 9)
        func_002D3230(p);
    p[0x2B8] = 0;
    *(s16 *)(p + 0x1C) = 0;
    if (p[0x269] == 3) {
        p[0x1B5] = 0x31;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        p[0x1B5] = 0x30;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 26.66666603088379f;
        *(f32 *)(p + 0x60) /= 17.14285659790039f;
        *(f32 *)(p + 0x6C) /= 137.14285278320312f;
        *(u32 *)(p + 0x68) = 0;
        if (p[0x1B7] == 0)
            func_001757E0(p, 0x15, 3);
        else
            func_001757E0(p, 0x15, 5);
    } else {
        if (p[0x1B7] == 0)
            func_001757E0(p, 0x15, 0);
        else
            func_001757E0(p, 0x15, 2);
    }
    if ((o = func_0039C5B0(p, 2)) != 0) {
        q = o + 0x88;
        if (p[0x20D] == 2) {
            q[0xD] = 1;
            func_0018C4B0(p, 5);
            return;
        }
        q[0xD] = 0;
        func_0018C4B0(p, 5);
        func_00183D10(p);
    }
}
