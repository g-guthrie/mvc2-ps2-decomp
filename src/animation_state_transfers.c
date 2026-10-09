typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern u8 D_0045BC10[];
extern u8 D_004C12E8[] __attribute__((section(".sdata")));
extern void func_001266A0(u8 *, int, int);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_002F4390(u8 *, u8 *, int);
extern void func_002F4A50(u8 *, void *, int);

void func_002F4360(u8 *p, u8 *q)
{
    *(u16 *)(p + 862) = *(u16 *)(q + 20);
    p[486] ^= q[17];
    *(u16 *)(p + 320) = p[486];
    func_002F4390(p, q, q[22]);
}

void func_002F4390(u8 *p, u8 *q, int flag)
{
    u8 value;
    s32 half;
    u16 options;
    func_001266A0(p, 5, 5);
    options = *(u16 *)(p + 0x35E);
    value = D_0045BC10[(options & 0x3C00) >> 10];
    if (p[0x269] == 8)
        value = 10;
    if (flag != 0 && value >= 10)
        flag = 0;
    p[0x20] = flag;
    *(s16 *)q = value;
    half = (s32)value / 2;
    func_001757E0(p, 21, D_004C12E8[half]);
    p[6] = 6;
    func_00175700(p);
}

void func_002F4A20(u8 *p, u8 *q)
{
    *(u16 *)(p + 862) = *(u16 *)(q + 20);
    p[486] ^= q[17];
    *(u16 *)(p + 320) = p[486];
    func_002F4A50(p, q, q[22]);
}
