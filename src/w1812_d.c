typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00456D40[];
s32 func_0028DFC0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    u8 *q = p + 0x2B8;
    if (p[0x2C0] == 0) {
        if (func_00189310(p, D_00456D40, p + 0x398) == 0) return 0;
        if (p[0x20D] == 2 || q[5] != 0 || q[6] != 0 || *(s8 *)(q + 7) != 0) {
            return 0;
        } else {
            func_0018A990(p, p + 0x398);
            p[5] = 0;
            p[7] = 0;
            p[6] = 0;
            p[0x1FD] = 6;
            func_00186A60(p, 0x15);
            return 1;
        }
    }
    if (func_00189310(p, D_00456D40, p + 0x398) == 0) return 0;
    if (p[0x20D] == 2) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t & !p[0x210]) return 0;
        p[0x1E8] = t + 1;
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 *D_004C2794;
extern u32 D_004C1480, D_004C1484, D_004C1488, D_004C1498, D_004C149C, D_004C14A0;
void func_00301200(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C1480;
        else *(u32 **)(p + 0x408) = &D_004C1498;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C1484;
        else *(u32 **)(p + 0x408) = &D_004C149C;
        p[0x1BB] = 1;
        break;
    case 2:
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C1488;
        else *(u32 **)(p + 0x408) = &D_004C14A0;
        p[0x1BB] = 2;
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 6;
            p[0x1B5] = 0x12;
        }
        if (*(u16 *)(p + 0x20E) & 0x1000) {
            p[0x168] = 7;
            p[0x1B5] = 0x13;
        }
        break;
    default:
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
    func_001757E0(p, 0xB, p[0x168]);
    if (*(s8 *)(p + 0x1EA) & 0xF) p[0x1EA] = *(s8 *)(p + 0x1EA) - 1;
}

extern u32 D_004C1140, D_004C1144, D_004C1148, D_004C1158, D_004C115C, D_004C1160;
void func_002E9A40(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C1140;
        else *(u32 **)(p + 0x408) = &D_004C1158;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C1144;
        else *(u32 **)(p + 0x408) = &D_004C115C;
        p[0x1BB] = 1;
        break;
    case 2:
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C1148;
        else *(u32 **)(p + 0x408) = &D_004C1160;
        p[0x1BB] = 2;
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 6;
            p[0x1B5] = 0x12;
        }
        if (*(u16 *)(p + 0x20E) & 0x1000) {
            p[0x168] = 7;
            p[0x1B5] = 0x13;
        }
        break;
    default:
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
    func_001757E0(p, 0xB, p[0x168]);
    if (*(s8 *)(p + 0x1EA) & 0xF) p[0x1EA] = *(s8 *)(p + 0x1EA) - 1;
}
