typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00417A40(void);

void func_0012BA70(s16 *base, s32 idx, s32 mode)
{
    s16 val = 0;
    s16 z = 0;
    s16 *p;
    switch (mode) {
    case 0:
    case 2:
        val = (s16)(func_00417A40() % 0x5DD + 0x1F4);
        break;
    case 1:
    case 3:
        val = (s16)(func_00417A40() % 0x3E9 + 0x3E8);
        break;
    case 4:
    case 5:
        val = (s16)(func_00417A40() % 0x5DD + 0x5DC);
        break;
    case 6:
    case 7:
        val = (s16)(func_00417A40() % 0x7D1 + 0x7D0);
        break;
    }
    p = (s16 *)((u8 *)base + idx * 6);
    *(s16 *)((u8 *)p + 0x1C) = val;
    *(s16 *)((u8 *)p + 0x1E) = z;
    *(s16 *)((u8 *)p + 0x20) = 0;
}
