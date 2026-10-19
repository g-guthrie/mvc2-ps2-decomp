typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, int, int);
extern void func_001DB2E0(u8 *);
extern void func_001BD600(u8 *);
extern void func_001F0420(u8 *);

void func_001920B0(u8 *p)
{
    p[6]++;
    *(u16 *)(p + 0x1C) = 16;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x5C) = 0xC17D5555;
    *(u32 *)(p + 0x68) = 0x3EA00000;
    if (p[0x1E6]) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 2, 4);
}

void func_001DB1A0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    func_00175700(p);
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0x1C))
        func_001DB2E0(p);
}

void func_001BD5E0(u8 *p)
{
    p[5]++;
    p[0x13C] = 1;
    func_001BD600(p);
}

void func_001F5780(u8 *p)
{
    p[6]++;
    func_001F0420(p);
    func_001757E0(p, 21, 14);
}

void func_001FE090(u8 *p)
{
    p[6]++;
    p[0x206] = 10;
    p[0x207] = 10;
    p[0x2D1] = 1;
    *(u16 *)(p + 0x2C2) = *(u16 *)(p + 0x20E);
    func_001757E0(p, 2, 4);
}
