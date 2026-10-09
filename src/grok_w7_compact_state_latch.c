typedef unsigned char u8;
typedef signed char s8;
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_002FC890(u8 *p)
{
    u8 *state;

    if (p[0x15B] == 0)
        return;
    if (*(s8 *)(p + 0x1B2) == 0)
        return;

    p[0x15B] = 0;
    state = *(u8 **)(p + 0x1C4);
    if (state[3] != 0)
        return;

    D_004F1F45 = 3;
    D_004F1F46 = 1;
}
