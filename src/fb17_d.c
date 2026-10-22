typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s32 w0, w4, w8, wC, w10, w14, w18, w1C, w20, w24, w28, w2C, w30, w34, w38, w3C, w40, w44;
} O17;
typedef struct {
    s16 h0, h2;
    s32 w4, w8;
} I17;

s32 func_00415CE0(O17 *o, I17 *in)
{
    s32 f;
    o->w0 = 0;
    o->w4 = in->h0;
    o->w8 = in->h2;
    o->w10 = in->w8;
    f = in->w4;
    switch (f & 0xF0) {
    case 0:
        switch (f & 0xF) {
        case 2:
            o->w14 = 2;
            o->wC = o->w14 * o->w4;
            o->w18 = 5; o->w1C = 10; o->w20 = 31; o->w24 = 5; o->w28 = 5; o->w2C = 31;
            o->w30 = 5; o->w34 = 0; o->w38 = 31; o->w3C = 1; o->w40 = 15; o->w44 = 1;
            o->w1C = 0; o->w34 = 10;
            break;
        case 3:
            o->w14 = 3;
            o->wC = o->w14 * o->w4;
            o->w18 = 8; o->w1C = 0x10; o->w20 = 0xFF; o->w24 = 8; o->w28 = 8; o->w2C = 0xFF;
            o->w30 = 8; o->w34 = 0; o->w38 = 0xFF; o->w3C = 0; o->w40 = 0; o->w44 = 0;
            o->w1C = 0; o->w34 = 0x10;
            break;
        case 4:
            o->w14 = 4;
            o->wC = o->w14 * o->w4;
            o->w18 = 8; o->w1C = 0x10; o->w20 = 0xFF; o->w24 = 8; o->w28 = 8; o->w2C = 0xFF;
            o->w30 = 8; o->w34 = 0; o->w38 = 0xFF; o->w3C = 8; o->w40 = 0x18; o->w44 = 0xFF;
            o->w1C = 0; o->w34 = 0x10;
            break;
        default:
            return 0;
        }
        break;
    case 0x10:
        o->w0 |= 4;
        o->w14 = 0;
        o->wC = o->w4 >> 1;
        o->w18 = 0; o->w1C = 0; o->w20 = 0; o->w24 = 0; o->w28 = 0; o->w2C = 0;
        o->w30 = 0; o->w34 = 0; o->w38 = 0; o->w3C = 0; o->w40 = 0; o->w44 = 0;
        break;
    case 0x20:
        o->w0 |= 4;
        o->w14 = 1;
        o->wC = o->w14 * o->w4;
        o->w18 = 0; o->w1C = 0; o->w20 = 0; o->w24 = 0; o->w28 = 0; o->w2C = 0;
        o->w30 = 0; o->w34 = 0; o->w38 = 0; o->w3C = 0; o->w40 = 0; o->w44 = 0;
        break;
    default:
        return 0;
    }
    return 1;
}
