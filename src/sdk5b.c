/* Busy-wait: 50000 rounds of one nop; GCC pads the short loop to five. */
void func_003FB5C0(void)
{
    int i = 50000;
    while (--i, 1) {
        __asm__ volatile("nop");
        if (i == 0) break;
    }
}
/* Busy-wait for *count rounds; spins forever when count is NULL. */
void func_0040DFA8(int unused, int *count)
{
    int n;
    if (count == 0) {
        for (;;) __asm__ volatile("nop");
    }
    n = *count;
    if (n > 0) {
        while (--n, 1) {
            __asm__ volatile("nop");
            if (n == 0) break;
        }
    }
}
