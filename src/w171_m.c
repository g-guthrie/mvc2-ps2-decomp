typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00257100(u8 *p)
{
    extern void func_00257CC0();
    extern void func_00257D60();
    extern void func_00257E30();
    extern void func_00258070();
    extern int func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    switch (p[0x1FC]) {
    case 3:
        func_00257CC0(p);
        return;
    case 4:
        func_00257CC0(p);
        break;
    case 5:
        func_00257CC0(p);
        break;
    case 6:
        func_00257CC0(p);
        break;
    case 7:
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_00257D60(p);
        break;
    case 8:
        func_00257E30(p);
        break;
    case 9:
        func_00257CC0(p);
        break;
    case 10:
        func_00257CC0(p);
        break;
    case 11:
        func_00257CC0(p);
        break;
    case 12:
        func_00258070(p);
        break;
    case 2:
    case 1:
    case 0:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}
