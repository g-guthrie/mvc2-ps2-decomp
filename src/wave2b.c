typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern void func_00161760(u8 *);
extern void func_00161690(u8 *);
void func_00161630(u8 *p) {
    switch (*(s8 *)(D_004C2840 + 0x9C) & 0xF) {
    case 0: break;
    case 4: func_00161760(p); break;
    default: func_00161690(p); break;
    }
}

extern u8 *D_004C2794;
void func_001EC2D0(u8 *p) {
    u32 offset;
    u8 c = p[0x15B];
    if (c != 0) {
        p[0x15B] = 0;
        p[0x1B5] = c;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
}

extern u8 *D_004C2794;
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2840;
extern s32 D_004C2920;
extern u8 D_00583B9B[];
extern s32 func_0032C180(s32);
extern void func_0013BEF0(s32);
void func_0032CE60(void) {
    if (func_0032C180(1) == 0) {
        *(s8 *)(D_004C2840 + 4) = *(s8 *)(D_004C2840 + 4) + 1;
        D_00583B9B[0] = 0;
        func_0013BEF0(D_004C2920);
    }
}

extern void (*D_004C1980[2])(u8 *);
static void func_00345FE0(u8 *p) {
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
}
void func_003462C0(u8 *p) {
    func_00345FE0(p);
    D_004C1980[p[5]](p);
}

extern u8 *D_004C2840;
extern s32 D_004C2B50;
extern void func_004026B0(s32, s32);
void func_003D3080(s32 a) {
    *(u8 *)(D_004C2840 + 0x5C) = a;
    func_004026B0(D_004C2B50, a);
}
