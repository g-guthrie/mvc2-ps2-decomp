typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004B6A50[];

static u8 func_001E3940(u8 *p, s32 n) {
    u32 a, b;
    if (p[1] == 0x14) return 0;
    switch (n & 0xFF) {
    case 4:
    case 5:
    case 6:
    case 0xE:
    case 0xF:
    case 0x10:
        return 0;
    }
    a = *(u32 *)(p + 0x428);
    b = *(u32 *)(p + 0x42C);
    if ((a & 0x1018000) | (b & 0x184000)) n = D_004B6A50[n & 0xFF];
    if (p[0x216] & 0x80) n = D_004B6A50[n & 0xFF];
    return n;
}

extern void func_001E3710(u8 *, u32);

void func_001E3B70(u8 *p, u32 a) {
    u8 r = func_001E3940(p, a);
    if (r != 0) {
        a = r & 0xFF;
    }
    func_001E3710(p, a);
}
