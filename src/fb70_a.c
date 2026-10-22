typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18D8[];
extern u8 D_004D18A0[];
extern s16 D_004BF820[4];

#define SET(n) do { *(s32 *)(a + 0xD0) = a[6]; *(s32 *)(a + 0xD4) = a[7]; a[6] = (n); a[7] = 0; } while (0)

void func_001AC3F0(u8 *a, u8 *b)
{
    extern s32 func_001AC360(s16, s16);
    extern int func_00174470(const void *);
    extern f32 func_001AC390(u8 *, s32);
    u8 cnt;
    s32 n;
    f32 d;
    cnt = 0;
    *(s16 *)(a + 0x1E) = 4;
    if (b[0x1E4] == 0x1D && b[0x1FD] == 5) {
        SET(0xF);
        return;
    }
    if (b[0x1E4] == 0x1D && b[0x1FD] == 4) {
        SET(0x11);
        return;
    }
    if ((b[0x425] != 0 && b[0x269] == 0) || (func_001AC360(D_004D18D8[0], b[2]) != 0 && D_004D18A0[0] >= 5)) {
        SET(1);
        return;
    }
    if (b[0x1E4] == 0x1C && b[0x26A] == 0) {
        SET(6);
        return;
    }
    if (func_00174470(a) == 0) {
        SET(4);
        return;
    }
    if (*(s16 *)(b + 0x280) >= 3) {
        SET(0x10);
        return;
    }
    if (b[0x1E4] == 0x15 && b[0x1FD] == 3) {
        SET(0xA);
        return;
    }
    if (*(u16 *)(b + 0x168) == 0x1803) {
        SET(0xE);
        return;
    }
    if (*(s32 *)(b + 0x2F8) != 0) {
        SET(0x12);
        return;
    }
    if (b[0x1E4] == 0x16) {
        *(s32 *)(a + 0xD0) = a[6];
        *(s32 *)(a + 0xD4) = a[7];
        n = b[0x20];
        switch (n) {
        case 0:
        case 2:
        case 5:
        case 6:
        case 7:
            a[6] = 8;
            break;
        case 8:
        case 9:
        case 10:
            a[6] = 0xD;
            break;
        case 1:
        case 3:
        case 4:
            a[6] = 0xC;
            break;
        }
        a[7] = 0;
        return;
    }
    if (*(s16 *)(b + 0x434) <= 0) {
        SET(0xC);
        return;
    }
    if (b[0x1E4] == 0xE && *(f32 *)(b + 0x60) > 17.14285659790039f) {
        SET(9);
        return;
    }
    d = func_001AC390(b, 0x38) - *(f32 *)(a + 0x34);
    if (*(f32 *)(b + 0x38) >= *(f32 *)(a + 0x38) + 102.85713958740234f) cnt++;
    if (d < 0.0f) d *= -1.0f;
    if (d >= 66.66666412353516f) cnt += 2;
    SET(*(s8 *)((u8 *)D_004BF820 + cnt * 2));
}
