/* Entry 0 of the two-entry s32(u8 *, u8 *) handler table at 0x004BFE50
 * (entry 1 is func_0020D350). */
typedef unsigned char u8;
typedef unsigned short u16;
int func_0020D310(u8 *p, u8 *q)
{
    if (!(*(u16 *)(p + 0x362) & 0x400)) return 0;
    q[7]++;
    q[8] = 15;
    return 0;
}
