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
} SA;

extern volatile s32 D_00487344;
extern volatile s32 D_00487348;
extern volatile s32 D_0048734C;
extern char D_004BD600[];

void func_004081C0(SA *o)
{
    extern s32 func_0010FBE0(void);
    extern void func_0011EB60(char *, s32);
    extern s32 func_0010F148(s32);
    extern s32 func_0010F968(s32, s32, s32, s32 *);
    extern s32 func_004080E8(SA *);
    s32 s0;
    s32 r;

    if (o->x4 == 1) {
        switch (o->b2) {
        case 2:
            if (func_0010FBE0() == 0)
                func_0011EB60(D_004BD600, D_00487344);
            func_0010F148(0);
            o->b2 = 0;
            D_0048734C++;
            break;
        case 0:
        case 3:
        case 9:
            o->b2 = 0;
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        }
        o->x4 = 0;
    }
    if (o->b2 == 1) {
        if (func_0010F968(o->x8, o->xC, o->x10, &o->x14) == 1) {
            D_00487348++;
            o->b2 = 2;
        } else {
            o->b2 = 9;
            o->x34 = -1;
        }
    }
    if (o->b2 == 2) {
        s0 = func_0010F148(1);
        r = func_004080E8(o);
        if (s0 == 0) {
            o->b2 = (r == 1) ? 9 : 3;
            D_0048734C++;
        }
    }
}
