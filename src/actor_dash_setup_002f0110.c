typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;
typedef struct {u8 prefix[0x7C];s16 count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));
typedef struct SS SS;
extern void func_00183D10(u8*),func_003A8B10(u8*),func_0018C4B0(u8*,int);
extern void func_002F01E0(SS*);
extern int func_001757E0(u8*,int,int);
void func_002F0110(u8*p){
 float vx;
 ++p[6];p[0x1B5]=53;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
 ++D_004C2794->count[p[2]];func_00183D10(p);
 p[0x20D]=0;p[0x20]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 vx=-6.666666507720947f;if(p[0x1E6])vx=-vx;*(float*)(p+0x5C)=vx;*(float*)(p+0x68)=0;
 func_001757E0(p,21,11);*(int*)(p+0x2EC)=*(s8*)(p+0x152);func_003A8B10(p);func_0018C4B0(p,10);func_002F01E0((SS*)p);
}
