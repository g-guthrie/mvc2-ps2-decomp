typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 *D_004C2840;
extern u8 D_004D18A0 __attribute__((section(".data")));
extern u8 data_u8_00450500[];
extern s32 func_00174170(void);
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_00185490(u8 *);
extern void func_00206A80(u8 *);

void func_00207070(u8 *p)
{
    s16 timer;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    func_00175700(p);
    func_00206A80(p);
    p[0x22] = 0;
    p[0x209] = 3;

    if (p[0x269] == 5 || (s8)p[0x539] != 0 || p[0x269] == 4) {
        if ((D_004C2840[0x84] & 7) == 0) {
            p[0x22] = (func_00174170() & 3) + 1;
            p[0x21] = data_u8_00450500[func_00174170() & 0xF];
        }
    } else if (*(u16 *)(p + 0x35C) & 0x360) {
        if (*(u16 *)(p + 0x35C) & 0x200) p[0x22] = 1;
        if (*(u16 *)(p + 0x35C) & 0x100) p[0x22] = 2;
        if (*(u16 *)(p + 0x35C) & 0x40) p[0x22] = 3;
        if (*(u16 *)(p + 0x35C) & 0x20) p[0x22] = 4;
        p[0x21] = (*(u16 *)(p + 0x354) & 0x3C00) >> 10;
    }

    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0 || D_004D18A0 >= 5) {
        u32 count = p[6];
        p[6] = count + 1;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00185490(p);
        func_001757E0(p, 0x16, 0x16);
    }
}
