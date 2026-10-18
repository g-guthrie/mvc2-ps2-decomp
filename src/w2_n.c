typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0040B220(u8 *p)
{
    extern void func_00411288();
    extern void func_004112B0();
    extern s32 func_00407EC0();
    extern void func_00407C80();
    if (*(s32 *)(p + 0x2C) != 0) {
        func_00411288();
        switch (func_00407EC0(*(s32 *)(p + 0x2C))) {
        case 9:
            *(u8 *)(p + 2) = 3;
            func_00407C80(*(s32 *)(p + 0x2C));
            *(s32 *)(p + 0x2C) = 0;
            break;
        case 3:
            *(s32 *)(p + 0x28) = *(s32 *)(p + 0x24);
            *(s32 *)(p + 0x1C) += *(s32 *)(p + 0x24);
            *(u8 *)(p + 2) = 1;
            func_00407C80(*(s32 *)(p + 0x2C));
            *(s32 *)(p + 0x2C) = 0;
            break;
        case 0:
            *(u8 *)(p + 2) = 0;
            func_00407C80(*(s32 *)(p + 0x2C));
            *(s32 *)(p + 0x2C) = 0;
            break;
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            break;
        }
        func_004112B0();
    }
}
