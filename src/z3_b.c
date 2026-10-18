typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_00500000;
static s32 func_00291800(void) { return D_00500000 + 1; }
void func_00292170(u8 *p, u8 *q) {
    extern void func_002918A0();
    extern void func_00292420();
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        if (func_00291800()) {
            p[7] = 6;
            q[0x18] = 0;
            func_002918A0();
        } else {
            func_00292420();
        }
    }
}
