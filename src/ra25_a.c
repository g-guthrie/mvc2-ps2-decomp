typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0041C220(s32, s32);
extern void (*D_0043CD0C[])(s32, s32);
extern u8 D_004C2B58[8];

void func_0041C200(s32 state, s32 mode) {
    D_0043CD0C[0] = func_0041C220;
    D_004C2B58[0] = 0;
    D_0043CD0C[0](state, mode);
}
