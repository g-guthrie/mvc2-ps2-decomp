typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x13]; u8 b13; u16 h14; u16 h16; } R4C10;

s32 func_003F4C10(s32 *o, s32 x)
{
    extern s32 func_003F5090(s32);
    extern R4C10 *func_003F51F0(s32, s32);
    R4C10 *r;
    if (func_003F5090(x) == 0) return 0;
    r = func_003F51F0(x, 0);
    o[0] = 0;
    o[1] = r->h14;
    o[2] = r->h16;
    switch (r->b13) {
    case 4:
        o[0] |= 0x14; o[5] = 0; o[3] = o[1] >> 1;
        o[7] = 0; o[6] = 0; o[8] = 0; o[10] = 0; o[9] = 0; o[11] = 0; o[13] = 0; o[12] = 0; o[14] = 0; o[16] = 0; o[15] = 0; o[17] = 0;
        break;
    case 5:
        o[0] |= 4; o[5] = 1; o[3] = o[5] * o[1];
        o[7] = 0; o[6] = 0; o[8] = 0; o[10] = 0; o[9] = 0; o[11] = 0; o[13] = 0; o[12] = 0; o[14] = 0; o[16] = 0; o[15] = 0; o[17] = 0;
        break;
    case 1:
        o[5] = 2; o[3] = o[5] * o[1];
        o[6] = 5; o[7] = 10; o[8] = 31; o[9] = 5; o[10] = 5; o[11] = 31; o[12] = 5;
        o[13] = 0; o[14] = 31; o[15] = 1; o[16] = 15; o[17] = 1; o[7] = 0; o[13] = 10;
        break;
    case 2:
        o[5] = 3; o[3] = o[5] * o[1];
        o[6] = 8; o[7] = 16; o[8] = 255; o[9] = 8; o[10] = 8; o[11] = 255; o[12] = 8;
        o[13] = 0; o[14] = 255; o[15] = 0; o[16] = 0; o[17] = 0; o[7] = 0; o[13] = 16;
        break;
    case 3:
        o[5] = 4; o[3] = o[5] * o[1];
        o[6] = 8; o[7] = 16; o[8] = 255; o[9] = 8; o[10] = 8; o[11] = 255; o[12] = 8;
        o[13] = 0; o[14] = 255; o[15] = 8; o[16] = 24; o[17] = 255; o[7] = 0; o[13] = 16;
        break;
    default:
        break;
    }
    return 1;
}
