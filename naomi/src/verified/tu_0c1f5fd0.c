/* Maple DMA queue terminator and transfer start (SDK). */
extern volatile int *dat_0c344d6c;
extern volatile int *dat_0c344d70;
extern volatile int *dat_0c344d74;
extern int dat_0c344d64;
extern int dat_0c344d68;

volatile int *func_0c1f5fd0(int flags)
{
    while (*(volatile int *)0xa05f6c18)
        ;
    *dat_0c344d6c = -1;
    dat_0c344d74 = dat_0c344d70;
    *dat_0c344d74++ = 0x80000000;
    *dat_0c344d74++ = dat_0c344d64;
    *dat_0c344d74++ = flags | 0x2000;
    *dat_0c344d70 |= (dat_0c344d74 - dat_0c344d70) - 3;
    dat_0c344d70[2] |= (unsigned char)*dat_0c344d70 << 24;
    while (*(volatile int *)0xa05f6c18)
        ;
    *(volatile int *)0xa05f6c04 = dat_0c344d68;
    *(volatile int *)0xa05f6c14 = 1;
    *(volatile int *)0xa05f6c18 = 1;
    while (*(volatile int *)0xa05f6c18)
        ;
    return dat_0c344d6c;
}
