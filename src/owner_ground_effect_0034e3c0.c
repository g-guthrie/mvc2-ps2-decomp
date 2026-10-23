/* Start the effect at its owner ground height with facing-dependent motion. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {u8 pad[0x7C];s16 counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern void func_0034E760(u8 *),func_0015E630(u8 *),func_001E3210(u8 *,int);
extern int func_001757E0(u8 *,int,int);
void func_0034E3C0(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);
 p[0x13C]=1;p[0x24]=11;*(float*)(p+0x38)=*(float*)(owner+0x430);
 p[0x1B0]=68;p[0x1B1]=68;
 if(owner[0x269]==3) {
  p[0x1B5]=92;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;D_004C2794->counters[p[2]]++;
 } else {
  p[0x1B5]=68;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;D_004C2794->counters[p[2]]++;
 }
 func_0034E760(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x5C)=*(s16*)(p+0x140)?13.33333301544189453125f:-13.33333301544189453125f;
 *(float*)(p+0x68)=0;func_0015E630(p);p[0]=1;func_001E3210(p,31);func_001757E0(p,23,16);
}
