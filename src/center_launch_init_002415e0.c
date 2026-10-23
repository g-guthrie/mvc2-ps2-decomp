/* Launch toward the midpoint while initializing the supplied work context. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {u8 pad[0x7C];s16 counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern float D_004F1FC8,D_004F1FCC;
extern void func_00185490(u8 *),func_00183D10(u8 *),func_001266A0(u8 *,int,int);
extern int func_001757E0(u8 *,int,int);
void func_002415E0(u8 *p,void *context)
{
 u8 *work=context;
 if(p[0x269]==6) {p[0x404]=255;p[0x405]=16;}
 p[7]++;p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 func_00185490(p);func_00183D10(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 p[0x1B5]=55;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
 D_004C2794->counters[p[2]]++;
 func_001266A0(p,1,13);
 *(float*)(p+0x5C)=((D_004F1FC8+D_004F1FCC)/2.0f-*(float*)(p+0x34))/16.0f;
 *(float*)(p+0x68)=0;*(float*)(p+0x60)=12.85714244842529296875f;*(float*)(p+0x6C)=-0.803571403026580810546875f;
 *(s16*)(p+0x1C)=16;*(s16*)(p+0x1E)=0;work[2]=0;work[1]=1;
 func_001757E0(p,22,0);
}
