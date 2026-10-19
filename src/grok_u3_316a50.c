typedef unsigned char u8;

/* 00179160 forwards two actor pointers and fixes the callee mode to 1. */
extern void func_00179160(void *, void *);

void func_00316A50(u8 *p)
{
    func_00179160(*(u8 **)(p + 0x1DC), p);
}
