/* func_00151350: MW 3.0.3 "-O3 -Op -fp off -sdatathreshold 8", warm-compiled after
 * src/motion_state_callbacks.c (func_00151120, same TU: jtbl_00444510 callbacks)
 * in one mwccps2 invocation (MWWARM@src/motion_state_callbacks.c). */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z, w; } V4a;
typedef struct { f32 x, y, z; } V3a;
typedef struct { u8 pad0[0x18]; u32 f18; u8 pad1[0x40]; s32 f5C; } Ga;

extern Ga D_004D1770;
extern f32 D_004BF418[2];
extern f32 D_004BF420[2];
extern V4a D_004443E0;
extern V4a D_004443F0;
extern V4a D_004443D0;
extern V3a D_004443B8;
extern V3a D_004443A8;


void func_00151350(u8 *p)
{
    extern f32 func_00417440(u32);
    Ga *g;
    s32 a;
    u32 c;
    u32 t;
    g = &D_004D1770;
    t = p[4];
    switch (t) {
    case 0:
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0;
        *(f32 *)(p + 0x34) = D_004BF418[p[0x21] / 2];
        *(f32 *)(p + 0x38) = D_004BF420[p[0x21] & 1];
    case 1:
        a = g->f5C;
        c = p[0x21];
        if (a == c && a != -1 && (g->f18 & (1 << a))) {
            *(V4a *)(p + 0x74) = D_004443E0;
            *(V3a *)(p + 0x50) = D_004443B8;
            *(s16 *)(p + 0x1C) += 5;
            if (*(s16 *)(p + 0x1C) >= 0x168)
                *(s16 *)(p + 0x1C) = 0;
            *(f32 *)(p + 0x38) = D_004BF420[p[0x21] & 1];
            c = (s32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0);
            *(f32 *)(p + 0x38) += (f32)(0.2 * (double)func_00417440(c & 0xFFFF));
        } else {
            if (g->f18 & (1 << c))
                *(V4a *)(p + 0x74) = D_004443F0;
            else
                *(V4a *)(p + 0x74) = D_004443D0;
            *(V3a *)(p + 0x50) = D_004443A8;
            *(f32 *)(p + 0x38) = D_004BF420[p[0x21] & 1];
            *(s16 *)(p + 0x1C) = 0;
        }
        break;
    }
}
