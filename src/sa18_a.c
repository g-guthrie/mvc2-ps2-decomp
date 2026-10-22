typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00250210(u8 *p) {
    extern s8 func_00175700();
    extern void func_00365F60(u8 *, s32);
    extern void func_001843A0(u8 *);
    if (func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            if (p[0x1B7] != 0) {
                func_00365F60(p, 2);
                p[0x28F] = 0;
            } else {
                func_00365F60(p, 0);
                p[0x28F] = 0;
            }
            p[0x28E] = 0x10;
        }
        return;
    }
    {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}
