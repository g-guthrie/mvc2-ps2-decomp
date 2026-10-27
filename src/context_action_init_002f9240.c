/* Provisional: shared callback tables and state bounds require proof. */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_00185490(u8 *), func_0018C4B0(u8 *,int), func_00175C00(u8 *,int), func_00183D10(u8 *), func_002F92E0(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
void func_002F9240(u8 *p, u8 *context)
{
    p[7]++;
    func_00185490(p);
    func_0018C4B0(p,5);
    func_00175C00(p,0);
    if (p[0x20d] != 2) func_00183D10(p);
    *(u32 *)(p+0x5c)=0;
    *(u32 *)(p+0x60)=0;
    *(u32 *)(p+0x68)=0;
    *(u32 *)(p+0x6c)=0;
    func_001757E0(p,21,2);
    func_002F92E0(p,context);
}
