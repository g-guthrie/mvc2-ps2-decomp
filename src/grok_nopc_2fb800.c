typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;

extern int func_00175700(u8 *);

void residual_002FB800(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        p[6]++;
        *(u32 *)(p + 0x60) = 0x41AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(s16 *)(p + 0x1C) = 0x14;
    }
}
