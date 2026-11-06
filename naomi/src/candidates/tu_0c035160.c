/* Three complete helpers match: shift32, status34, byte copy38 bytes.
 * Display loop58/76 bytes; cached locals use different registers.
 * Full204-byte extent and24-byte shared pool match placement. */
struct History_0c2fb248 { unsigned char pad[84]; int values[11]; };
extern struct History_0c2fb248 dat_0c2fb248;
extern unsigned char dat_0c22dc78[],dat_0c22dc88[];
extern signed char dat_0c2fb216[];
extern int func_0c1f3870(void);
extern void func_0c02c32e(int,int,int,unsigned char *,...);
void func_0c0351cc(void);
void func_0c035160(void)
{
    register int i=0;
    register struct History_0c2fb248 *history=&dat_0c2fb248;
    register int count=10;
    register unsigned char *format=dat_0c22dc78;
    register void (*print)(int,int,int,unsigned char *,...)=func_0c02c32e;
    register int row=25;
next:
    print(row,row-i,0,format,history->values[i]);
    if (++i<count) goto next;
    func_0c0351cc();
}

void func_0c0351ac(int value)
{
    int i;
    for(i=9;i>=0;i--) dat_0c2fb248.values[i+1]=dat_0c2fb248.values[i];
    dat_0c2fb248.values[0]=value;
}
void func_0c0351cc(void)
{
    int status=func_0c1f3870();
    func_0c02c32e(25,27,0,dat_0c22dc88,status);
}
void func_0c0351ee(const signed char *src)
{
    signed char *dst=dat_0c2fb216;
    *dst++=*src++;*dst++=*src++;*dst++=*src++;
    *dst++=*src++;*dst++=*src++;*dst=*src;
}
