typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 b0, b1;
    s8 b2;
    u8 p3;
    s32 x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C, x30, x34;
} SB;

extern volatile s32 D_00487348;
extern volatile s32 D_0048734C;

void func_00408348(SB *o)
{
    extern void func_00407F18(SB *);
    extern long func_00108298(s32, s32, s32);
    extern long func_001084D0(s32, s32, s32);
    extern s32 func_001089F0(s32, s32, s32 *);
    long r;
    s32 st;

    if (o->x4 == 1) {
        switch (o->b2) {
        case 2:
            func_00407F18(o);
            o->b2 = 0;
            D_0048734C++;
        case 0:
        case 3:
        case 9:
            o->b2 = 0;
            o->x4 = 0;
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            o->x4 = 0;
            break;
        }
    }
    if (o->b2 == 1) {
        r = func_00108298(o->x30, o->x28 << 11, 0);
        if (r < 0) {
            o->b2 = 9;
            o->x34 = (s32)r;
        }
        r = func_001084D0(o->x30, o->x18, o->x20);
        if (r >= 0) {
            o->b2 = 2;
            D_00487348++;
        } else {
            o->b2 = 9;
            o->x34 = (s32)r;
        }
    }
    if (o->b2 == 2) {
        if (func_001089F0(o->x30, 1, &st) < 0) {
            o->b2 = 9;
            o->x34 = -1;
        } else if (st == 0) {
            o->b2 = 3;
            D_0048734C++;
        }
    }
}
