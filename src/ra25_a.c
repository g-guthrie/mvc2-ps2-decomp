typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0041C220(void);
extern void (*D_0043CD0C[])(void);
extern u8 D_004C2B58[8];

void func_0041C200(void) {
    D_0043CD0C[0] = func_0041C220;
    D_004C2B58[0] = 0;
    D_0043CD0C[0]();
}
