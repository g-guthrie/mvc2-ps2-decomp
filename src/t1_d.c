typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;

extern s32 func_00175700(u8 *p);
extern void func_002F1DF0(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_002F1D90(u8 *p);
extern u8 *D_004C2794;

void func_002EE930(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_002F1DF0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x1B2] = 0;
        if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x200) != 0) {
            s16 *q;
            s16 v;
            *(u16 *)(p + 0x366) = 0;
            p[0x1B5] = 0x1C;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            q = (s16 *)((u8 *)(p[2] << 1) + (u32)D_004C2794);
            v = *(s16 *)((u8 *)q + 0x7C) + 1;
            *(s16 *)((u8 *)q + 0x7C) = v;
            func_001757E0(p, 9, 3);
            func_002F1D90(p);
        }
    }
}

extern void func_001266A0(u8 *p, s32 a, s32 b);
extern void func_001E3210(u8 *p, s32 a);
extern u8 *D_004C2840;

void func_0020E3C0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    p[0x13C] = 0;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[6];
            p[6] = t + 1;
            p[0x13C] = 1;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            func_001266A0(p, 7, 7);
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            if (*(s8 *)(D_004C2840 + 0x45) == 0) {
                func_001E3210(p, 0xF);
            }
            func_001757E0(p, 0x16, 0x20);
        }
    }
}
