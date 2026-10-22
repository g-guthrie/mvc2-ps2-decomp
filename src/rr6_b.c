typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_0027E3F0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_00280D80(u8 *);
    extern s32 func_00174170(void);
    u32 t;
    u32 h;
    u32 k;
    u32 v;
    f32 a, b, c;
    f32 *q;

    func_00175700(p);
    if (p[7] == 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            t = p[7];
            p[7] = t + 1;
        }
    } else if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x118) = (f32)*(s8 *)(p + 0x152) / (f32)*(s8 *)(*(u8 **)(p + 0x164) + 2);
    } else {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(s16 *)(p + 0x1E) = 6;
        p[0x22] = 0;
        *(s16 *)(p + 0x1C) = 10;
        p[0x15A] |= 0x80;
        if (*(s8 *)(p + 0x539) == 0) {
            h = *(u16 *)(p + 0x35E);
            if (h & 0x800) {
                p[0x1B7] = 0;
            } else if (h & 0x400) {
                p[0x1B7] = 1;
            } else {
                p[0x1B7] = 2;
            }
        } else {
            k = func_00280D80(p) & 0xFF;
            switch (k) {
            case 4:
                if (func_00174170() & 1) p[0x1B7] = 0;
                else p[0x1B7] = 2;
                break;
            case 3:
            case 5:
                p[0x1B7] = 1;
                break;
            default:
                p[0x1B7] = 2;
                break;
            }
        }
        switch (p[0x1B7]) {
        case 0:
        case 2:
            *(V3 *)(p + 0x68) = *(V3 *)(p + 0x34);
            break;
        case 1:
            *(V3 *)(p + 0x68) = *(V3 *)(*(u8 **)(p + 0x220) + 0x34);
            break;
        default:
            break;
        }
        *(f32 *)(p + 0x6C) = *(f32 *)(p + 0x430);
    }
}
