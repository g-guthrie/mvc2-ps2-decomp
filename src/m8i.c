typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
extern void func_001843A0(void *p);
extern void func_00183920(void *p, void *v);
extern void func_001E3710(void *p, s32 a);

void func_002077C0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        if (*(s8 *)(p + 0x151) != 0) {
            u32 v[4];
            p[0x151] = 0;
            v[1] = 0x43092492;
            v[0] = 0;
            func_00183920(p, v);
        }
        if (*(s8 *)(p + 0x150) != 0) {
            p[0x150] = 0;
            func_001E3710(p, 0x16);
        }
    }
}
