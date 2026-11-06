/* Candidate: 151/160 bytes equal. Control flow, imask intrinsics and pool
   match; scratch registers differ: retail uses r1 for the first global
   address and r1/r3 swapped around the imask restore (stc sr / mov #0 /
   0xff0f mask), so only register choice is off. */
extern int dat_0c343d48;
extern int dat_0c353f3c;
extern int dat_0c34543c;
extern int func_0c1f7570(void);
extern void func_0c1f9200(int);
extern void func_0c1f91d0(int);

void func_0c1f949c(void)
{
    int r;
    unsigned int mask;
    if (dat_0c343d48 == 0) {
        if (dat_0c353f3c != 0) {
            r = func_0c1f7570();
            if (r == 1) {
                mask = _builtin_get_imask();
                _builtin_set_imask(15);
                func_0c1f9200(r);
                dat_0c353f3c = 0;
                _builtin_set_imask(mask);
            }
        }
        dat_0c34543c++;
        if ((dat_0c34543c & 15) == 0) {
            r = func_0c1f7570();
            if (r == 1)
                func_0c1f91d0(r);
            else
                dat_0c34543c = 15;
        }
    }
}
