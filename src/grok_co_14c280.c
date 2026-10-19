typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern V3 D_004440E8;
extern V3 D_004440F8;
extern V3 D_00444108;
extern u8 *D_004CAE80[][20];
extern s32 func_0014C1D0(s32, s32);
extern void func_0014C100(u8 *);

void func_0014C280(s32 a, s32 b, s32 c)
{
    V3 t0;
    V3 t1;
    V3 t2;
    s32 r;
    u8 *obj;
    s8 adj;

    t0 = D_004440E8;
    t1 = D_004440F8;
    t2 = D_00444108;
    r = func_0014C1D0(a, b);
    obj = (u8 *)D_004CAE80[a][b];
    if (r > 0 && r < 4)
        adj = (s8)(r + ((s8 *)&t0)[c]);
    else {
        adj = ((s8 *)&t1)[c];
        *(f32 *)(obj + 0x34) = ((f32 *)&t2)[c];
    }
    obj[4] = ((s8 *)&t0)[c];
    obj[5] = adj;
    obj[6] = 1;
    obj[7] = (u8)a;
    *(void (**)(u8 *))(obj + 0x10) = func_0014C100;
}
