typedef unsigned char u8; typedef signed char s8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32;

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
extern u8 *D_004C29A4;

static void func_003816C0(u8 *p)
{
    if (D_004C29A4[1] < 16) {
        s16 t = *(s16 *)(p + 0x1e) - 1;
        *(s16 *)(p + 0x1e) = t;
        if (t <= 0) {
            *(s16 *)(p + 0x1e) = 1;
            D_004C29A4[1]++;
        }
    }
}

void func_00381990(u8 *p) {
    u16 k = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    if (k != 0x1506 && k != 0x1508 && k != 0x1507 && k != 0x1509) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 1;
        return;
    }
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) != 0) return;
    D_004C29A4[3] = 0;
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x1C) <= 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 10;
        *(u32 *)(p + 0x54) = 0x3F800000;
    }
    func_003816C0(p);
}
