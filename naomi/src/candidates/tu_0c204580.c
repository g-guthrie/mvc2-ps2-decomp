/* Candidate: SDK bit-string helper (sets the mask bit at index bit when a
   lower bit of that byte or any later byte is set). Control flow, loop
   shapes and pool match; retail computes bit % 8 inline in r0 (cmp/pz,
   and #7, not/add negations) and keeps p in r14 and the mask in r13. This
   spelling of the signed remainder negates with neg and swaps p/mask. */
void func_0c204580(unsigned char *s, int n, int bit)
{
    unsigned char *p;
    unsigned char *q;
    unsigned char m;
    unsigned char lo;
    unsigned char t;
    int r;

    p = s + bit / 8;
    r = bit;
    r = (r >= 0) ? (r & 7) : -(-r & 7);
    m = 0x80 >> r;
    q = p;
    if (*q & m)
        return;
    lo = 0;
    for (t = m; t; t >>= 1)
        lo |= t;
    if (*q & lo) {
        *q |= m;
        return;
    }
    s += n;
    while (++q < s) {
        if (*q) {
            *p |= m;
            return;
        }
    }
}
