typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, s32);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_001863F0(u8 *);
extern s32 func_00175700(u8 *);
extern void func_002E1520(u8 *, s32);
extern void func_003A15E0(u8 *, u8);
void func_002E2F30(u8 *p) {
    if (p[6] == 0) {
        p[6]++;
        func_0018C4B0(p, 2);
        func_00185490(p);
        func_00175C00(p, 0);
        p[0x1B5] = 0x36;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_001757E0(p, 0x15, 0x12);
        p[0x1EA] = 0;
        *(f32 *)(p + 0x5C) /= 8.0f;
        *(f32 *)(p + 0x68) /= 8.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 8.0f;
    }
    if (p[0x20D] != 2) {
        func_001863F0(p);
    } else if (*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38)) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if ((s8)func_00175700(p) < 0) {
        func_002E1520(p, 2);
        return;
    }
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        p[0x2C4] = 1;
        p[0x28F] = 0;
        p[0x28E] = 0x10;
        func_003A15E0(p, 0);
    }
}
