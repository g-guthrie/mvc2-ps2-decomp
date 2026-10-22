typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[16]; } M416;

extern M416 D_006327B0[];
extern s32 D_004C2B40;
extern s32 D_004C2B38;
extern M416 *D_004C2B48;

M416 *func_00416D40(f32 *a)
{
    D_004C2B48[D_004C2B38] = D_006327B0[D_004C2B40];
    if (a != 0) {
        a[0] = D_006327B0[D_004C2B40].f[0];
        a[1] = D_006327B0[D_004C2B40].f[1];
        a[2] = D_006327B0[D_004C2B40].f[2];
        a[3] = D_006327B0[D_004C2B40].f[3];
        a[4] = D_006327B0[D_004C2B40].f[4];
        a[5] = D_006327B0[D_004C2B40].f[5];
        a[6] = D_006327B0[D_004C2B40].f[6];
        a[7] = D_006327B0[D_004C2B40].f[7];
        a[8] = D_006327B0[D_004C2B40].f[8];
        a[9] = D_006327B0[D_004C2B40].f[9];
        a[10] = D_006327B0[D_004C2B40].f[10];
        a[11] = D_006327B0[D_004C2B40].f[11];
        a[12] = D_006327B0[D_004C2B40].f[12];
        a[13] = D_006327B0[D_004C2B40].f[13];
        a[14] = D_006327B0[D_004C2B40].f[14];
        a[15] = D_006327B0[D_004C2B40].f[15];
    }
    return &D_004C2B48[D_004C2B38];
}
