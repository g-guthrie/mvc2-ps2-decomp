int func_0c203d08(unsigned char *s, int n, short k)
{
    short j;
    unsigned char *p;
    unsigned char carry;
    unsigned char hi;
    int mask;
    j = 8 - k;
    if (j != 0) {
        mask = 255 << j;
        carry = 0;
        for (p = s + (n - 1); p >= s; p--) {
            hi = *p & mask; *p <<= k; *p |= carry; carry = hi >> j;
        }
        if (carry)
            return 1;
        return 0;
    }
}
