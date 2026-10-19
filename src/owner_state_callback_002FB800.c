/* Table 0x0045BFC0 is consumed by func_002FB9D0; physical predecessor: 002FB7E0. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;

extern int func_00175700(u8 *);

void func_002FB800(u8 *p)
{
    u32 speed = 0x41AB6DB6;
    u32 gravity = 0xBF4DB6DB;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;
    p[0x151] = 0;
    p[6]++;
    *(u32 *)(p + 0x60) = speed;
    *(u32 *)(p + 0x6C) = gravity;
    *(s16 *)(p + 0x1C) = 0x14;
}
