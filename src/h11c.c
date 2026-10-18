typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00175700(u8 *);
extern void func_001E3270(u8 *, s32, f32);
extern void func_00198620(u8 *, s32, s32);
void func_00206040(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        func_001E3270(p, 0x1E, 5.0f);
        t = p[6];
        p[6] = t + 1;
        func_00198620(p, 1, 0);
        func_00198620(p, 1, 1);
    }
}
