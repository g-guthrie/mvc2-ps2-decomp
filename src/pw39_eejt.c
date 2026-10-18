typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_00411288(void);
extern void func_004112B0(void);
extern s32 func_00407EC0(s32);
extern void func_00407C80(s32);
void func_00409948(u8 *p) {
    if (*(s32 *)(p + 0x1C) != 0) {
        func_00411288();
        switch (func_00407EC0(*(s32 *)(p + 0x1C))) {
        case 9:
            p[2] = 3;
            func_00407C80(*(s32 *)(p + 0x1C));
            *(s32 *)(p + 0x1C) = 0;
            break;
        case 3:
            *(s32 *)(p + 0x14) = *(s32 *)(p + 0x10);
            *(s32 *)(p + 0xC) += *(s32 *)(p + 0x10);
            p[2] = 1;
            func_00407C80(*(s32 *)(p + 0x1C));
            *(s32 *)(p + 0x1C) = 0;
            break;
        case 1: case 2: case 4: case 5: case 6: case 7: case 8:
            break;
        case 0:
            p[2] = 0;
            func_00407C80(*(s32 *)(p + 0x1C));
            *(s32 *)(p + 0x1C) = 0;
            break;
        }
        func_004112B0();
    }
}
