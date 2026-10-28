typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct { u8 pad0[3]; u8 b3; u8 pad4[0x3A]; s8 b3e; } G_b;
typedef struct { u8 pad0[0x94]; u32 w94; } H_b;
extern G_b *D_004C2794;
extern H_b *D_004C2840;

void func_0027DBB0(u8 *p)
{

    extern void func_00186A60(u8 *, s32);
    f32 d, s, f;
    switch (p[0x20]) {
    case 0:
    case 2:
    case 4:
        p[5] = 0; p[7] = 0; p[6] = 0;
        d = *(f32 *)(*(u8 **)(p + 0x220) + 0x34) - *(f32 *)(p + 0x34);
        if (p[0x1E6] == 0) d = -d;
        s = *(f32 *)(p + 0x50);
        d -= 160.0f * s;
        f = (f32)(u32)d;
        if (f <= 213.3333282470703f * s && D_004C2794->b3e == p[2] && D_004C2794->b3 == 0)
            p[0x1FD] = 8;
        else if (D_004C2840->w94 & 1)
            p[0x1FD] = 6;
        else
            p[0x1FD] = 7;
        func_00186A60(p, 0x15);
        break;
    case 1:
    case 3:
        p[5] = 0; p[7] = 0; p[6] = 0;
        p[0x1FD] = 10;
        func_00186A60(p, 0x15);
        break;
    }
}
