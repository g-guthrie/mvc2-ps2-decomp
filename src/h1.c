typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00126400(u8 *);
void func_00205520(u8 *p) {
    s16 v;
    p[0x208] = 3;
    p[0x201] = 3;
    p[0x207] = 3;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x14;
        p[0x201] = 0;
        func_00126400(p);
    }
}
