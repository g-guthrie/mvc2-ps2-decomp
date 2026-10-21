typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*StateHandler)(void *,void *,void *);
extern const u32 jtbl_0044ADF0[3];
void func_0019FF30(u8 *p)
{
    ((StateHandler)jtbl_0044ADF0[p[4]])(p,p+0xD0,*(void **)(p+0x18));
}
