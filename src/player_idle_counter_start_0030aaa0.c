typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef struct {u8 prefix[0x7C];s16 count[2];} CounterBank;
extern CounterBank *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8*),func_00183D10(u8*);
extern int func_001757E0(u8*,int,int);
void func_0030AAA0(u8 *p) {
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];func_00185490(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 p[0x1B5]=0;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u8**)(p+0x1D8)=0;
 ++D_004C2794->count[p[2]];
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;func_00183D10(p);func_001757E0(p,22,0);
}
