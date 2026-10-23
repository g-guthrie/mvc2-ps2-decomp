/* Initialize or slow the motion lane and clear its supplied work state. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 pad[0x7C];signed short counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *),func_001DA790(u8 *,u8),func_0018C4B0(u8 *,int);
extern int func_001757E0(u8 *,int,int);
void func_00306B80(u8 *p,void *context)
{
 u8 *work=context;
 p[6]++;func_00185490(p);
 if(p[7]==0) {
  *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
  p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);func_00183D10(p);
  p[0x1B5]=p[0x1B7];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;D_004C2794->counters[p[2]]++;
  func_001757E0(p,21,0);func_001DA790(p,p[0x1B7]);
 } else {
  *(float*)(p+0x5C)/=16.0f;*(float*)(p+0x68)/=16.0f;*(float*)(p+0x60)/=16.0f;*(float*)(p+0x6C)/=16.0f;
  p[0x1B5]=p[0x1B7];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;D_004C2794->counters[p[2]]++;
  func_001757E0(p,21,14);func_001DA790(p,(u8)(p[0x1B7]+3));
 }
 work[4]=0;func_0018C4B0(p,5);
 p[0x1B5]=48;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;D_004C2794->counters[p[2]]++;
}
