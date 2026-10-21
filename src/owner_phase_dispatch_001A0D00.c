typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef void (*StateHandler)(u8 *,u8 *);
extern const u32 jtbl_0044AF90[3];
void func_001A0D00(u8 *p,void *context)
{
    if(((s8 *)context)[0x2F1]!=0 || ((u8 *)context)[0x169]!=0x13 || ((u8 *)context)[0x168]!=1) { p[4]=2; p[0x13C]=0; }
    ((StateHandler)jtbl_0044AF90[p[4]])(p,context);
}
