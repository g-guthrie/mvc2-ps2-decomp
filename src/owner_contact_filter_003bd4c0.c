typedef unsigned char u8;

int func_003BD4C0(u8 *p)
{
    u8 *owner=*(u8 **)(p+0x18);
    u8 *state=p+0xD0;
    u8 *status=owner+0x2B8;
    if (owner[5]==0 && owner[0x1E4]==0x15) {
        if (owner[0x1FD]==2) return -1;
        if (owner[0x1FD]==3) return -1;
        return 0;
    }
    if (status[4] != state[6]) return -1;
    {
        int previous4 = state[4];
        if (previous4) {
            int previous5 = state[5];
            if (previous5) {
                if (owner[0x169]==previous4 && owner[0x168]==previous5) return 0;
                state[4]=0;
                state[5]=0;
            }
        }
    }
    if (owner[0x169]==7 && owner[0x168]==2) return -1;
    if (owner[0x169]==8 && owner[0x168]==2) return -1;
    if (owner[0x169]==9 && owner[0x168]==2) return -1;
    if (owner[0x169]==10 && owner[0x168]==2) return -1;
    if (owner[0x169]==11 && owner[0x168]==2) return -1;
    if (owner[0x169]==12 && owner[0x168]==2) return -1;
    return 0;
}
