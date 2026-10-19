typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_00205F50(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_0018C4B0(p, 16);
    if (p[0x20D] != 2) {
        p[0x20D] = 0;
        func_00183D10(p);
        func_001757E0(p, 21, (u8)(p[0x1B7] + 9));
    } else {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        p[0x20D] = 2;
        func_001757E0(p, 21, (u8)(p[0x1B7] + 14));
    }
    p[0x22] = 0;
    *(u32 *)(p + 0x64) = 0x43200000;
    if (p[0x1B7] != 0)
        *(u32 *)(p + 0x64) = 0x43AD5555;
    if (*(s16 *)(p + 0x140) == 0)
        *(f32 *)(p + 0x64) = -*(f32 *)(p + 0x64);
}
