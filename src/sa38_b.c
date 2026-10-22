typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern s8 D_004C2864, D_004C285C, D_004C286C;
extern u8 D_004BF397[4], D_004BF39B[4];
extern V3 D_004439C0[], D_00442AA0[];
extern u32 D_004C2804;
void func_00148390(u8 *p)
{
    s32 idx;
    s32 m;
    u32 t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
    m = p[0x20];
    if (m == 1) {
        idx = D_004C2864;
    } else if (m == 3) {
        idx = D_004C285C;
    } else {
        idx = D_004C286C ^ 1;
    }
    idx = D_004BF397[m] + idx;
    *(V3 *)(p + 0x34) = D_004439C0[idx];
    *(u16 *)(p + 0xCC) = D_004BF39B[p[0x20]];
    *(u32 *)(p + 0x84) = D_004C2804;
    *(V3 *)(p + 0x50) = D_00442AA0[0];
    *(u32 *)(p + 0xD0) |= 0x420;
    *(u32 *)(p + 0x80) = *(u32 *)(p + 0x7C) = *(u32 *)(p + 0x78) = 0x3F333333;
    *(u32 *)(p + 0x74) = 0x3F800000;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0;
}
typedef struct { u8 pad[0x1C]; s8 f1c; } G1;
extern G1 *D_004C2840;
void func_001DC600(u8 *p, u8 *q)
{
    extern void func_00175670(u8 *);
    s32 a;
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    p[0x13C] = (D_004C2840->f1c + (a = (s8)p[0x22])) & 1;
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        p[4]++;
    }
}
