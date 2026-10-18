typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0034E880(void *a);
void func_001757E0(void *p, s32 a, s32 b);
extern s8 *D_004C294C;
void func_0034E800(u8 *a0) {
    a0[36] = 0;
    func_0034E880(a0);
    a0[432] = 66;
    a0[433] = 66;
    D_004C294C[2] = 0;
    D_004C294C[1] = -1;
    a0[332] = 56;
    a0[333] = 56;
    a0[334] = 80;
    a0[335] = 32;
    func_001757E0(a0, 23, 27);
}
