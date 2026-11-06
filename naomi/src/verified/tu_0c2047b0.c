/* SDK big-number helper: shift a byte string right by one bit; returns the bit shifted out. */
#pragma section n2047b0
int func_0c2047b0(unsigned char *buf, int n)
{
    int i;
    int carry = 0;
    int c;
    for (i = 0; i < n; i++) {
        c = buf[i] & 1;
        buf[i] >>= 1;
        if (carry) buf[i] |= 0x80;
        carry = c;
    }
    return carry;
}
