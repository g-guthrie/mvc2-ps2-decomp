/* Candidate: loop body matches; the prologue keeps n - 1 live in a stack
   slot (r13 frame) where retail recomputes it in r6, so registers in the
   prologue/epilogue and the carry register differ. */
int func_0c20426c(unsigned char *s, int n)
{
    unsigned char *p;
    unsigned char *q;
    int carry;
    int bit;
    unsigned int i; i = n - 1; carry = 0; for (p = s + i, q = p; p >= s; p--, q--) {
        bit = *p & 0x80;
        *p <<= 1;
        if (carry)
            *q |= 1;
        carry = bit;
    }
    if (carry)
        return 1;
    return 0;
}
