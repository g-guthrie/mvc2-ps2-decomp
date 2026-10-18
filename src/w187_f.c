typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004C2078[2])(u8 *);
extern void func_003BD4A0(u8 *);
extern void func_003BD410(u8 *);
extern s32 func_003BD650(u8 *);

void func_003BAC70(u8 *p) {
    s32 a = *(s8 *)(p + 0x1B2);
    if (a != 0) {
        u8 *q = *(u8 **)(p + 0x1C4);
        if (q[3] == 0) {
            if (q[0x425] != 0 || (q[1] >= 0x18 && q[1] < 0x1B)) {
                func_003BD4A0(p);
                return;
            }
            if (((s8)a & 0x7F) != 0) func_003BD4A0(p);
            else func_003BD410(p);
        } else {
            func_003BD4A0(p);
        }
    } else {
        if (func_003BD650(p) != 0) func_003BD4A0(p);
        else D_004C2078[p[6]](p);
    }
}

extern void (*D_004C2088[2])(u8 *);

void func_003BB080(u8 *p) {
    s32 a = *(s8 *)(p + 0x1B2);
    if (a != 0) {
        u8 *q = *(u8 **)(p + 0x1C4);
        if (q[3] == 0) {
            if (q[0x425] != 0 || (q[1] >= 0x18 && q[1] < 0x1B)) {
                func_003BD4A0(p);
                return;
            }
            if (((s8)a & 0x7F) != 0) func_003BD4A0(p);
            else func_003BD410(p);
        } else {
            func_003BD4A0(p);
        }
    } else {
        if (func_003BD650(p) != 0) func_003BD4A0(p);
        else D_004C2088[p[6]](p);
    }
}
