typedef unsigned int u32;
typedef unsigned char u8;
extern volatile u8 D_00630000[0x4000];
extern volatile u8 D_00634100[512];
#define CURSOR (*(volatile u32 *)(D_00630000 + 0x3e18))
int func_00423AA0(const u32 *words)
{
    int shift;
    int count;
    u32 value;
    if ((int)CURSOR + 8 < 512) goto valid;
    return -1;
valid:
    value = words[0];
    shift = 24;
    count = 4;
    do {
        D_00634100[CURSOR] = (u8)(value >> shift);
        CURSOR = CURSOR + 1;
        shift -= 8;
        count--;
    } while (count > 0);
    value = words[1];
    shift = 16;
    count = 3;
    do {
        D_00634100[CURSOR] = (u8)(value >> shift);
        CURSOR = CURSOR + 1;
        shift -= 8;
        count--;
    } while (count > 0);
    D_00634100[CURSOR] = 0xff;
    return 0;
}
