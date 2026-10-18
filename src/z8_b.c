typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad[0x36]; s8 f36[1]; } G18;
extern G18 *D_004C2794;

void func_0018DCF0(u8 *p, u8 *q) {
    extern void func_0018DC10();
    extern void func_0018CDF0();
    u32 c = (u8)(p[0x2B3] ? p[0x2B3] : q[0x1B7]);
    if (D_004C2794->f36[p[2]] >= 2 || p[0x425] != 0 || c == 0) {
        p[0x2B3] = 0;
        func_0018DC10(p, q);
    } else {
        p[0x248] = 1;
        if (p[0x2B3] == 0) p[0x2B3] = c;
        p[0x249] = 0;
        p[0x247] = 12;
        func_0018CDF0(p, q);
    }
}
