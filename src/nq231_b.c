typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 v; u8 pad[24]; } E28;
extern E28 D_0045EDD8[], D_0045EDDC[], D_0045EDE0[], D_0045EDE4[], D_0045EDE8[], D_0045EDEC[], D_0045EDF0[];
extern E28 D_0045EDF4[], D_0045EDF8[], D_0045EDFC[], D_0045EE00[], D_0045EE04[], D_0045EE08[], D_0045EE0C[];
extern E28 D_0045EE10[], D_0045EE14[], D_0045EE18[], D_0045EE1C[], D_0045EE20[], D_0045EE24[];

void func_0033CC20(u8 *p)
{
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    f32 vx, vy, vz;
    s16 i;

    switch (p[4]) {
    case 0:
        func_0032FEB0((f32)*(s16 *)(p + 0x1C) / (D_0045EE0C[*(s16 *)(p + 0x1E)].v - D_0045EDF0[*(s16 *)(p + 0x1E)].v), &vx, &vy, &vz);
        i = *(s16 *)(p + 0x1E);
        *(f32 *)(p + 0x34) = vx * D_0045EDD8[i].v + vy * D_0045EDF4[i].v + vz * D_0045EE10[i].v;
        *(f32 *)(p + 0x38) = vx * D_0045EDDC[i].v + vy * D_0045EDF8[i].v + vz * D_0045EE14[i].v;
        *(f32 *)(p + 0x3C) = vx * D_0045EDE0[i].v + vy * D_0045EDFC[i].v + vz * D_0045EE18[i].v;
        *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045EDE4[i].v + vy * D_0045EE00[i].v + vz * D_0045EE1C[i].v) / 360.0) & 0xFFFF;
        *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045EDE8[i].v + vy * D_0045EE04[i].v + vz * D_0045EE20[i].v) / 360.0) & 0xFFFF;
        *(u32 *)(p + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045EDEC[i].v + vy * D_0045EE08[i].v + vz * D_0045EE24[i].v) / 360.0) & 0xFFFF;
        i = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = i;
        if ((f32)*(s16 *)(p + 0x1C) < D_0045EE0C[*(s16 *)(p + 0x1E)].v - D_0045EDF0[*(s16 *)(p + 0x1E)].v) {
            break;
        }
        *(s16 *)(p + 0x1C) = 0;
        i = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = i;
        if ((u32)(*(s16 *)(p + 0x1E) + 1) >= 6) {
            p[4]++;
        }
        if ((u32)(*(s16 *)(p + 0x1E) + 1) >= 4) {
            p[5]++;
        }
        break;
    case 1:
        break;
    }
}
