/* Candidate: SDK big-number subtract a -= b (big-endian bytes, length n);
   returns -1 on underflow when sign == 0, else 0 if the result is zero,
   else 1. Control flow and pool match; retail keeps d and the start
   pointer a + n - 1 in stack slots (frame 8) with r12-r14 only, while this
   spelling strength-reduces the index into r8-r14, so registers differ. */
int func_0c203dd0(int sign, unsigned char *a, unsigned char *b, int n)
{
    int i;
    int borrow;
    int zero;
    int d;

    borrow = 0;
    zero = 1;
    for (i = n - 1; i >= 0; i--) {
        d = a[i] - b[i] - borrow;
        if (d < 0) {
            d += 0x100;
            borrow = 1;
        } else {
            borrow = 0;
        }
        if (d != 0)
            zero = 0;
        a[i] = d;
    }
    if (borrow == 1 && sign == 0)
        return -1;
    if (zero == 1)
        return 0;
    return 1;
}
