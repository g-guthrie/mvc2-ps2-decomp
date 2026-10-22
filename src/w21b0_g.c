typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 *p; s32 a, b; } E12;
typedef struct { u8 pad[0x18]; E12 e[1]; } G12;
extern G12 *D_004C2794;
extern u8 *D_004C2840;
extern u8 D_004B9430[];
extern u8 D_004B9438[];
extern u8 D_004B9440[];
extern u8 D_004B9450[];

void func_003D9980(s32 a0) {
    u8 *p;
    s32 s;
    p = D_004C2794->e[a0].p;
    s = p[2] * 102 + 6;
    { extern void func_003D7350(u8, u8, s32, u8 *);
    func_003D7350(s, *(s8 *)(D_004C2840 + 0xB6) + 0x19, 0x34, D_004B9430); }
    { extern void func_003D7350(u8, u8, s32, u8 *, s32);
    func_003D7350(s + 0x24, *(s8 *)(D_004C2840 + 0xB6) + 0x19, 0x38, D_004B9438, *(s16 *)(p + 0x342)); }
    { extern void func_003D7350(u8, u8, s32, u8 *);
    func_003D7350(s, *(s8 *)(D_004C2840 + 0xB6) + 0x1E, 0x35, D_004B9440); }
    { extern void func_003D7350(u8, u8, s32, u8 *, s32);
    func_003D7350(s + 0x24, *(s8 *)(D_004C2840 + 0xB6) + 0x1E, 0x38, D_004B9438, *(s16 *)(p + 0x27C) - *(s16 *)(p + 0x290)); }
    { extern void func_003D7350(u8, u8, s32, u8 *);
    func_003D7350(s, *(s8 *)(D_004C2840 + 0xB6) + 0x23, 0x37, D_004B9450); }
    { extern void func_003D7350(u8, u8, s32, u8 *, s32);
    func_003D7350(s + 0x24, *(s8 *)(D_004C2840 + 0xB6) + 0x23, 0x38, D_004B9438, *(s16 *)(((p[2] ^ 1) << 1) + (u32)D_004C2794 + 0x78)); }
}
