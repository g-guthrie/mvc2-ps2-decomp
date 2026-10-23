/* Initialize the grounded lane using the provided actor work context. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {u8 pad[0x7C];s16 counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_0020AE50(u8 *p,void *context)
{
 u8 *work=context;
 p[6]++;func_0018C4B0(p,10);func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 *(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
 if(p[0x269]==3) {
  p[0x1B5]=90;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
  D_004C2794->counters[p[2]]++;
 } else if(p[0x1FD]) {
  p[0x1B5]=52;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
  D_004C2794->counters[p[2]]++;
 } else {
  p[0x1B5]=p[0x1B7]?50:48;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
  D_004C2794->counters[p[2]]++;
 }
 work[6]=0;
 *(float*)(p+0x5C)=p[0x1E6]?16.6666660308837890625f:-16.6666660308837890625f;
 *(float*)(p+0x68)=p[0x1E6]?-0.3125f:0.3125f;
 *(s16*)(p+0x1C)=p[0x1B7]?12:1;
 func_00183D10(p);func_001757E0(p,21,0);
}
