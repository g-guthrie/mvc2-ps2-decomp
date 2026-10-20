/* Convert sixty-hertz ticks into five native timer display digits. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern const char gUiDecimal2Format_004B1158[];
extern s32 func_0011F938(char *, const char *, ...);

void func_001366C0(u8 *p)
{
    u8 *buf = p + 0x1B0;
    u16 ticks = *(u16 *)(p + 0x1E0);
    u16 minutes = ticks / 3600;

    if (minutes > 9) {
        buf[0] = '9';
        buf[1] = '5';
        buf[2] = '9';
        buf[3] = '9';
        buf[4] = '9';
    } else {
        u16 remainder = ticks % 3600;
        buf[0] = (char)(minutes + '0');
        func_0011F938((char *)buf + 1, gUiDecimal2Format_004B1158, (u16)(remainder / 60));
        func_0011F938((char *)buf + 3, gUiDecimal2Format_004B1158,
            (u16)(((u16)(remainder % 60) * 100) / 60));
    }

    for (minutes = 0; minutes < 5; minutes++) {
        u32 character = buf[minutes];
        u8 value = (u8)(character - 0x30);
        buf[minutes] = value;
        if (value < 0)
            buf[minutes] = (u8)-1;
    }
}
