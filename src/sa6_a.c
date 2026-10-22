typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z, w; } V4_a;
typedef struct { f32 x, y, z; } V3_a;
typedef struct { u8 pad[8]; s16 h; } G_a;
typedef struct { u8 pad0[0x34]; f32 x, y, z; u8 pad1[0xD8 - 0x40]; s32 d8; } P_a;
extern V4_a D_00442AB0[];
extern G_a *D_004C2840;

void func_001488B0(u8 *p)
{
    extern void func_0012AD00(u8 *);
    V4_a *v;
    u32 k = p[0x23];
    u8 j = k;
    if (k == 0) {
        *(s8 *)(p + 0x13C) = 1;
        return;
    }
    if (j == 1) {
        v = &D_00442AB0[D_004C2840->h];
        *(V3_a *)(p + 0x34) = *(V3_a *)v;
        ((P_a *)p)->z += 0.01f;
        if (((P_a *)p)->d8 != D_004C2840->h) {
            *(s32 *)((s32)p + 0xD8) = D_004C2840->h;
            *(s16 *)(p + 0x1E) = 0;
        }
        func_0012AD00(p);
    }
}
