typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002876B0(u8 *p)
{
    extern int func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00385A20(void *, u8);
    extern void func_001C09A0(void *, u8);

    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_00385A20(p, 1);
            func_001C09A0(p, 1);
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            if (*(s16 *)(p + 0x140) == 0) {
                *(f32 *)(p + 0x5C) = -5.0f;
                *(f32 *)(p + 0x68) = 0.3125f;
            } else {
                *(f32 *)(p + 0x5C) = 5.0f;
                *(f32 *)(p + 0x68) = -0.3125f;
            }
        }
        break;
    case 0:
        break;
    }
}
