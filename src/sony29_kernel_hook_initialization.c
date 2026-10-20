/* Complete native Sony kernel-hook initialization. The existing syscall
 * stubs are invoked under the temporary contracts installed by the table. */
typedef unsigned char u8;
typedef struct {int number;void *handler;} KernelHook;
extern KernelHook D_004386A8[];
extern u8 D_00438328[];
extern char *D_004386A0;
extern void func_0010C2E8(int,void *);
extern void *func_0010C2D8(int);
extern void func_0010C290(void *,const void *,unsigned int);
extern void func_00104060(int);
void func_0010C2F8(void)
{
 unsigned int i;
 func_0010C2E8(D_004386A8[0].number,D_004386A8[0].handler);
 func_0010C290((void *)0x80075000,D_00438328,0x330);
 func_00104060(0);
 func_00104060(2);
 func_0010C2E8(D_004386A8[1].number,D_004386A8[1].handler);
 func_0010C2E8(D_004386A8[2].number,D_004386A8[2].handler);
 for(i=3;i<8;i++)func_0010C2E8(D_004386A8[i].number,func_0010C2D8(D_004386A8[i].number));
 D_004386A0=func_0010C2D8(3);
}
