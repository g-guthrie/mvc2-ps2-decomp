typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void (*D_004C2120[])(void);

void func_003C32F0(u8 *p, u8 *q)
{
    s8 v;
    if (q[5] != 0 || q[0x169] != 0x16) {
        p[4]++;
        return;
    }
    D_004C2120[p[5]]();
    v = (s8)q[0x24] + (s8)p[0x31];
    p[0x24] = v;
    if ((s8)p[0x24] >= 8)
        p[0x24] = 7;
    if ((s8)p[0x24] < 0)
        p[0x24] = 0;
}
