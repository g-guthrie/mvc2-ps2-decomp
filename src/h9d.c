typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004C1410[2];
extern void func_00176160(void *, s32, s32, s32);
extern void func_00175C00(void *, s32);
void func_002FC5B0(u8 *p, s8 *q) {
    u32 v = D_004C1410[q[0]];
    if (v != 0xFF) {
        func_00176160(p, 0, v + (p[0x25] * 32 + 7), 1);
    } else {
        func_00175C00(p, 0);
        q[2] = 0;
    }
    if ((((u8 *)q)[1] & 3) == 0) {
        q[0] = q[0] + 1;
    }
}
