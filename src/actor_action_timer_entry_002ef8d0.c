typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;
typedef struct {u8 pad[0x7C];s16 count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));extern u8 D_004C1250[] __attribute__((section(".sdata")));
extern void func_00185490(u8*),func_00183D10(u8*),func_0018C4B0(u8*,int);extern int func_001757E0(u8*,int,int);
void func_002EF8D0(u8*p) {
 ++p[6];*(int*)(p+0x308)=4;p[0x1B5]=53;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
 ++D_004C2794->count[p[2]];func_00185490(p);func_00183D10(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;p[0x20]=0;*(int*)(p+0x2E0)=96;
 {s16 timer=120;if(!*(s8*)(p+0x539) || p[0x425])timer=30;*(s16*)(p+0x1C)=timer;}
 func_0018C4B0(p,10);{u8 *row=D_004C1250+*(int*)(p+0x2D4)*2;func_001757E0(p,21,row[p[0x1B7]]);}
 *(int*)(p+0x2EC)=*(s8*)(p+0x152);
}
