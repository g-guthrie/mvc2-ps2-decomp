typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef struct {u8 prefix[0x7C];s16 count[2];} CounterBank;
extern CounterBank *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8*);
extern int func_001757E0(u8*,int,int);
void func_001FA920(u8 *p,void *work_context) {
 u8 *work=work_context;
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];p[0x1B5]=72;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u8**)(p+0x1D8)=0;
 ++D_004C2794->count[p[2]];
 func_00185490(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 p[0x20D]=2;work[1]=(*(u8**)(p+0x220))[1];*(s16*)(p+0x1C)=16;p[0x21]=0;
 *(float*)(p+0x5C)=p[0x1E6]?20.0f:-20.0f;
 func_001757E0(p,22,6);
}
