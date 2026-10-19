typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern f32 D_004440E8[3];
extern f32 D_004440F8[3];
extern f32 D_00444108[3];
extern u8 *D_004CAE80[];
extern s32 func_0014C1D0(void);
extern void func_0014C100(u8 *);

void func_0014C280(s32 a, s32 b, s32 c)
{
    f32 t0[3];
    f32 t1[3];
    f32 t2[3];
    s32 r;
    u8 *obj;
    s8 adj;

    t0[0] = D_004440E8[0];
    t0[1] = D_004440E8[1];
    t0[2] = D_004440E8[2];
    t1[0] = D_004440F8[0];
    t1[1] = D_004440F8[1];
    t1[2] = D_004440F8[2];
    t2[0] = D_00444108[0];
    t2[1] = D_00444108[1];
    t2[2] = D_00444108[2];
    r = func_0014C1D0();
    obj = *(u8 **)((u8 *)D_004CAE80 + a * 80 + b * 4);
    if (r > 0 && r < 4)
        adj = (s8)(r + ((s8 *)t0)[c]);
    else {
        adj = ((s8 *)t1)[c];
        *(f32 *)(obj + 0x34) = t2[c];
    }
    obj[4] = ((s8 *)t0)[c];
    obj[5] = adj;
    obj[6] = 1;
    obj[7] = (u8)a;
    *(void (**)(u8 *))(obj + 0x10) = func_0014C100;
}
