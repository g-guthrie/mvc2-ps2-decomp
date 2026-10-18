typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct O O;
typedef struct { u8 pad[0x14]; void (*f)(O *); } V;
struct O { V *vt; };
void func_00404BD0(u8 *p) {
    extern s32 func_00404CA8();
    extern void func_00401868();
    extern void func_004005F8();
    s32 i;
    O **pp;
    for (i = 0; i < *(s8 *)(p + 3); i++) {
        func_00401868(func_00404CA8(p, i));
    }
    if (*(s32 *)(p + 8) != 0) {
        func_004005F8(*(s32 *)(p + 8));
    }
    *(s32 *)(p + 8) = 0;
    (*(O **)(p + 0x8C))->vt->f(*(O **)(p + 0x8C));
    i = 0;
    if (*(s8 *)(p + 3) > 0) {
        pp = (O **)(p + 0x90);
        do {
            (*pp)->vt->f(*pp);
            pp++;
            i++;
        } while (i < *(s8 *)(p + 3));
    }
    p[1] = 0;
}
