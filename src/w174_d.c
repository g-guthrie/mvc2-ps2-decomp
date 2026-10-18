typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GA;
extern GA *D_004C2794;


void func_00379960(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u8 c;
    if (p[0x23] % 2 == 0) {
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
    } else {
        p[0x1B0] = 0;
        p[0x1B1] = 0;
    }
    if (q[0x1B7] != 0) {
        c = ((p[0x23] / 2) % 2 == 1) ? 0x44 : 0x45;
    } else {
        c = ((p[0x23] / 2) % 2 == 1) ? 0x30 : 0x38;
    }
    p[0x1B5] = c;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(s32 *)(p + 0x1d8) = 0;
    D_004C2794->f7c[p[2]]++;
}
