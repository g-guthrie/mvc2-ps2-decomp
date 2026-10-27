typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0018FAA0(u8 *, s32);
extern void func_0015F4B0(u8 *, s8);
extern void func_001E3210(u8 *, s32);
extern void func_001E3710(u8 *, s32);
void func_00268F50(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        if (*(s8 *)(p + 0x151) == 2) {
            p[0x151] = 0;
            func_0018FAA0(p, 0x14);
            func_0015F4B0(p, 4);
            func_001E3210(p, 0x1F);
            func_001E3710(p, 0x2A);
        }
    }
}
