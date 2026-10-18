typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1;
extern G1 *D_004C2794;

void func_00358890(u8 *p, u8 *q) {
    switch (q[0x1B5]) {
    case 0: case 6: p[0x1B5] = 0x43; break;
    case 1: case 7: p[0x1B5] = 0x44; break;
    case 2: case 8: p[0x1B5] = 0x45; break;
    case 0x3F: p[0x1B5] = 0x46; break;
    case 0xD: p[0x1B5] = 0x47; break;
    case 0xE: p[0x1B5] = 0x48; break;
    }
    { u8 v = *(volatile u8 *)(p + 0x1B5); p[0x1B5] = v; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    q[0x1B5] = p[0x1B5];
    q[0x1B2] = *(u16 *)(q + 0x1C0) = 0;
    *(u32 *)(q + 0x1D8) = 0;
    D_004C2794->f7c[q[2]]++;
}
