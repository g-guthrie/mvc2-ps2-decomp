typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*StateHandler)(u8 *,u8 *);
extern const u32 jtbl_004C14C8[2] __attribute__((section(".sdata")));
void func_00303200(u8 *p,void *context)
{
    if(p[0x20D]==2) p[6]=1;
    ((StateHandler)jtbl_004C14C8[p[6]])(p,context);
}
