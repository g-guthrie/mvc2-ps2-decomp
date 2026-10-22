typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004B5668[];
extern s32 D_00446B20[];
extern s32 D_00446B58[];
extern s32 D_00446B5C[];
extern s32 D_00446B70[];
extern s32 D_00446B7C[];
extern s32 D_00446AB0[];
extern void (*D_00446BB0[])(u8 *);

void func_00173020(u8 *p) {
    extern void func_003D7350(u8, u8, s32, u8 *, s32);
    u32 val;
    u8 ones;
    s32 i;
    s32 off;
    s32 flag;
    s32 a;
    s32 q;
    if (*(s8 *)(D_004C2840 + 2) != 5 && (*(s8 *)(D_004C2840 + 0x19) != 0 || *(s8 *)(D_004C2840 + 0x91) != 0)) return;
    if (*(s8 *)(D_004C2840 + 0xA8) != 0) return;
    p[0x550] = p[0x551];
    flag = 0;
    if (p[0x552] < p[0x551]) {
        p[0x550] = p[0x552];
        flag = 1;
    }
    if (p[0x550] < 0x14) {
        D_004C2840[0x2C] = flag;
    } else {
        *(u8 *)(p + 0x4D0) = 4;
        *(u8 *)(p + 0x4D1) = 0;
        *(u8 *)(p + 0x4D2) = 0;
        *(u8 *)(p + 0x4D3) = 0;
        *(s16 *)(p + 0x4D4) = 0x3C;
        *(s16 *)(p + 0x4D6) = 0;
        *(s16 *)(p + 0x4D8) = 0;
        return;
    }
    D_00446BB0[*(s8 *)(p + 0x4D2)](p);
    val = (*(s8 *)(p + 0x538) == 1) ? 0x78 : 0xC;
    a = p[0x550] + 1;
    q = (u8)(a / 10);
    ones = (u8)(a - q * 10);
    if (q != 0) {
        func_003D7350(val, D_004C2840[0xB6], 0xB, D_004B5668, D_00446B20[q]);
    } else {
        func_003D7350(val, D_004C2840[0xB6], 0xB, D_004B5668, D_00446B58[0]);
    }
    func_003D7350(val + 4, D_004C2840[0xB6], 0xB, D_004B5668, D_00446B20[ones]);
    if (p[0x550] < 3) {
        func_003D7350(val + 8, D_004C2840[0xB6], 0xB, D_004B5668, D_00446B70[p[0x550]]);
    } else {
        func_003D7350(val + 8, D_004C2840[0xB6], 0xB, D_004B5668, D_00446B7C[0]);
    }
    i = 0;
    off = 0;
    do {
        if (*(s8 *)(p + 0x4D2) == 5) {
            if (*(s8 *)(p + 0x4D3) != 0) {
                func_003D7350(val + 0x10 + off, D_004C2840[0xB6], 0xB, D_004B5668, D_00446AB0[*(s8 *)(p + 0x544 + i)]);
            } else {
                func_003D7350(val + 0x10 + off, D_004C2840[0xB6], 0xC, D_004B5668, D_00446AB0[*(s8 *)(p + 0x544 + i)]);
            }
        } else if (i != *(s8 *)(p + 0x4D2) || *(s8 *)(p + 0x4D3) != 0) {
            func_003D7350(val + 0x10 + off, D_004C2840[0xB6], 0xB, D_004B5668, D_00446AB0[*(s8 *)(p + 0x544 + i)]);
        } else {
            func_003D7350(val + 0x10 + off, D_004C2840[0xB6], 0xB, D_004B5668, D_00446B5C[0]);
        }
        i++;
        off += 4;
    } while (i < 4);
}
