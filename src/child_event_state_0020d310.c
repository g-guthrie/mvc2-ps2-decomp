/* Provisional: shared callback table ownership and phase bounds remain open. */
typedef unsigned char u8;
typedef unsigned short u16;
int func_0020D310(u8 *p, u8 *q)
{
    if (!(*(u16 *)(p + 0x362) & 0x400)) return 0;
    q[7]++;
    q[8] = 15;
    return 0;
}
