typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0xE]; u16 h0E; u8 pad10[2]; u8 b12; u8 b13; } R4E70;

s32 func_003F4E70(s32 *o, s32 x)
{
    extern s32 func_003F5090(s32);
    extern R4E70 *func_003F51F0(s32, s32);
    R4E70 *r;
    if (func_003F5090(x) == 0) return 0;
    r = func_003F51F0(x, 0);
    o[0] = 0;
    switch (r->b12) {
    case 1:
        o[5] = 2; o[6] = 5; o[7] = 10; o[8] = 31; o[9] = 5; o[10] = 5; o[11] = 31; o[12] = 5;
        o[13] = 0; o[14] = 31; o[15] = 1; o[16] = 15; o[17] = 1; o[7] = 0; o[13] = 10;
        break;
    case 2:
        o[5] = 3; o[6] = 8; o[7] = 16; o[8] = 255; o[9] = 8; o[10] = 8; o[11] = 255; o[12] = 8;
        o[13] = 0; o[14] = 255; o[15] = 0; o[16] = 0; o[17] = 0; o[7] = 0; o[13] = 16;
        break;
    case 3:
        o[5] = 4; o[6] = 8; o[7] = 16; o[8] = 255; o[9] = 8; o[10] = 8; o[11] = 255; o[12] = 8;
        o[13] = 0; o[14] = 255; o[15] = 8; o[16] = 24; o[17] = 255; o[7] = 0; o[13] = 16;
        break;
    default:
        return 0;
    }
    switch (r->b13) {
    case 4:
        if (r->h0E != 0x10) return 0;
        o[1] = 0x10; o[2] = 1;
        break;
    case 5:
        if (r->h0E != 0x100) return 0;
        o[1] = 0x100; o[2] = 1;
        break;
    default:
        return 0;
    }
    o[3] = o[5] * o[1];
    return 1;
}
