typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004B7510[];
extern u8 *D_004554F0;

u8 *func_00280AE0(u8 *p, u8 *s) {
    extern s32 func_00281040(u8 *, void *);
    u8 done;
    do {
        done = 0;
        switch (*s++) {
        case 0:
            p[0x472] = *s++;
            p[0x455] = p[0x454];
            p[0x454] = 0;
            p[0x452] = 0;
            p[0x453] = 0;
            break;
        case 1:
            p[0x472] = *s++;
            p[0x1E7] = 0;
            p[0x455] = p[0x454];
            p[0x454] = 1;
            p[0x452] = 0;
            p[0x453] = 0;
            break;
        case 10:
            p[0x472] = *s++;
            p[0x1E7] = 1;
            p[0x455] = p[0x454];
            p[0x454] = 1;
            p[0x452] = 0;
            p[0x453] = 0;
            break;
        case 2:
            p[0x471] = 1;
            p[0x45C] = *s++;
            p[0x455] = p[0x454];
            p[0x454] = 2;
            p[0x452] = 0;
            p[0x453] = 0;
            break;
        case 3:
            if (func_00281040(p, D_004B7510) != 0) {
                p[0x450] = 1;
                p[0x451] = 0;
                p[0x452] = 0;
                p[0x453] = 0;
            } else {
                done = 1;
            }
            break;
        case 5:
            if (func_00281040(p, D_004554F0) != 0) {
                p[0x450] = 1;
                p[0x451] = 0;
                p[0x452] = 0;
                p[0x453] = 0;
            } else {
                p[0x450] = 0;
                p[0x451] = 0;
                p[0x452] = 0;
                p[0x453] = 0;
                *(s32 *)(p + 0x4C4) = 0;
                p[0x496] = 0;
            }
            break;
        case 4:
            p[0x472] = s[0];
            p[0x45D] = s[1];
            s += 2;
            p[0x455] = p[0x454];
            p[0x454] = 3;
            p[0x452] = 0;
            p[0x453] = 0;
            break;
        case 7:
            p[0x496] = 1;
            done = 1;
            break;
        case 8:
            p[0x496] = 0;
            done = 1;
            break;
        case 9:
            *(s32 *)(p + 0x4C4) = 0;
            p[0x496] = 0;
            done = 1;
            break;
        default:
            p[0x450] = 0;
            p[0x451] = 0;
            p[0x452] = 0;
            p[0x453] = 0;
            *(s32 *)(p + 0x4C4) = 0;
            p[0x496] = 0;
            break;
        }
    } while (done);
    return s;
}
