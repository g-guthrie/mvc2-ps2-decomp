typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 *a, *b, *c; } T3_c;
typedef struct { u8 pad[0x4E]; s16 f4e[1]; } H_c;
typedef struct { u8 pad[0x8F]; s8 f8f; } K_c;
extern T3_c D_004D18B8[];
extern s16 D_004D18EE[], D_004D18F2[];
extern u32 D_004D190C[];
extern H_c *D_004C2794;
extern K_c *D_004C2840;

void func_00191210(u8 *p)
{
    extern u32 func_001919B0();
    extern void func_001917F0(u8 *, u32, u32);
    u8 *o;
    u32 r;
    s32 h;
    u32 sq;

    o = D_004D18B8[p[2] ^ 1].a;
    p[0x1F3] = 0;
    p[0x289] = 0;
    p[0x28B] = 0;
    *(s16 *)(p + 0x280) = 0;
    *(s16 *)(p + 0x284) = 0;
    if (D_004D18EE[o[2]] != 0) {
        if (D_004D18F2[o[2]] != 0) {
            if ((u8)((D_004D18B8[p[2]].a[0x289] | D_004D18B8[p[2]].b[0x289]) | D_004D18B8[p[2]].c[0x289]) == 0) {
                *(s16 *)(o + 0x274) = 0;
                *(s16 *)(o + 0x278) = 0;
                o[0x286] = 0;
                o[0x28A] = 0;
                o[0x288] = o[0x287];
                o[0x287] = 0;
                if (D_004C2840->f8f == 0) {
                    h = D_004C2794->f4e[o[2]];
                    sq = h * h;
                    if (sq > 1) {
                        r = func_001919B0(sq);
                        if (D_004C2794->f4e[o[2]] >= 3) D_004D190C[o[2]] = r;
                        func_001917F0(o, r >> 20, r << 12);
                    }
                }
                D_004D18EE[o[2]] = 0;
                D_004D18F2[o[2]] = 0;
            }
        }
    }
}
