typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00256FC0(u8 *p) {
    s8 r;
    extern void func_00257CC0();
    extern void func_00257D60();
    extern void func_00257E30();
    extern void func_00258070();
    extern void func_00257640();
    extern s32 func_00175700();
    extern void func_001843A0();
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
        if (*(u16 *)(p + 0x20E) & 0x800) {
            func_00257640(p);
            break;
        }
    case 1:
    case 0:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        }
        break;
    }
}
