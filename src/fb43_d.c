typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18D8[];
extern u8 D_004D18A0[];
extern s16 D_004BFA20[4];

#define SET(n) do { a[0xD6] = a[6]; a[0xD7] = a[7]; a[6] = (n); a[7] = 0; } while (0)

void func_001C3A80(u8 *a, u8 *b)
{
    extern s32 func_001C39F0(s16, s16);
    extern s32 func_00174470(u8 *);
    extern f32 func_001C3A20(u8 *, s32);
    u8 cnt;
    u8 *c;
    s32 n;
    s32 sw;
    f32 d;
    c = b + 0x2B8;
    *(s16 *)(a + 0x1E) = 4;
    cnt = 0;
    if (b[0x425] != 0 || (func_001C39F0(D_004D18D8[0], b[2]) != 0 && D_004D18A0[0] >= 5)) {
        SET(1);
        return;
    }
    sw = c[0xB];
    if (sw != 0) {
        switch ((u8)sw) {
        case 2:
            SET(0xC);
            break;
        case 4:
            SET(0xD);
            break;
        case 6:
        default:
            SET(0xE);
            break;
        }
        return;
    }
    if (func_00174470(a) == 0) {
        SET(4);
        return;
    }
    if (*(s16 *)(b + 0x280) >= 3) {
        SET(0xF);
        return;
    }
    if (c[1] != 0) {
        SET(0xA);
        return;
    }
    if (b[0x1E4] == 0x16 && (n = b[0x20]) >= 5 && n != 10) {
        switch (n) {
        case 6:
            SET(8);
            break;
        case 9:
            SET(0x10);
            break;
        default:
            SET(9);
            break;
        }
        return;
    }
    if (*(s16 *)(b + 0x434) <= 0) {
        SET(0xF);
        return;
    }
    d = func_001C3A20(b, 0x30) - *(f32 *)(a + 0x34);
    if (*(f32 *)(b + 0x38) >= *(f32 *)(a + 0x38) + 102.85713958740234f) cnt++;
    if (d < 0.0f) d *= -1.0f;
    if (d >= 66.66666412353516f) cnt += 2;
    SET(*(s8 *)((u8 *)D_004BFA20 + cnt * 2));
}
