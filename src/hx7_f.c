typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3g;
extern G3g *D_004C2794;

void func_002B6060(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    u8 *o;
    u32 c;
    f32 k;
    q = p + 0x2B8;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*q == 0) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            o = *(u8 **)(p + 0x1C4);
            if (o[3] == 0 && o[0x425] == 0 && (*(u32 *)(o + 0x428) & 0x7000000) == 0) {
                *q = 1;
                (*(u8 **)(p + 0x220))[0x20D] = 0;
                *(f32 *)(*(u8 **)(p + 0x220) + 0x38) = *(f32 *)(p + 0x430);
                *(f32 *)(*(u8 **)(p + 0x220) + 0x34) = *(f32 *)(p + 0x34);
                if (*(s16 *)(p + 0x140) != 0) {
                    k = -106.6666641f;
                    *(f32 *)(*(u8 **)(p + 0x220) + 0x34) -= k;
                } else {
                    k = 106.6666641f;
                    *(f32 *)(*(u8 **)(p + 0x220) + 0x34) -= k;
                }
            }
        }
    }
    if (func_00175700(p) >= 0) {
        c = p[0x15B];
        if (c != 0) {
            p[0x1B5] = c;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
    } else {
        c = p[6];
        p[6] = c + 1;
        *(u32 *)(p + 0x5C) = 0xC1855555;
        *(u32 *)(p + 0x68) = 0x3F3AAAAA;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        p[0x1B5] = 0x4B;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x16, 3);
    }
}
