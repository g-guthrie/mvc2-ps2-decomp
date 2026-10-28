/* EE GCC 2.96 at -O1 (-G0, SN as): short busy-wait delays.  The five nops
 * in each loop are the compiler's own R5900 short-loop padding. */

void func_00407EC8(void)
{
    int i = 0x8000;
    while (--i)
        ;
}

void func_0040AF28(void)
{
    int i = 0x8000;
    while (--i)
        ;
}
