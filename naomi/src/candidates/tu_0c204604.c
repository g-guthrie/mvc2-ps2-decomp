/* Candidate: retail keeps n - 1 in r14 and builds both pointers from it,
   then reuses r14 for the byte sum; here r14 becomes q, so q/sum registers
   differ (11 words). */
void func_0c204604(unsigned char *a, unsigned char *b, int n)
{
    unsigned char *p;
    unsigned char *q;
    int carry;
    int sum;
    q = &b[n - 1]; p = &a[n - 1]; for (carry = 0; p >= a; p--, q--) {
        sum = *p + *q + carry;
        *p = sum;
        carry = sum / 256;
    }
}
