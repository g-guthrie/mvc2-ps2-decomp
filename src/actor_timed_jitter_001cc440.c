typedef unsigned char u8;typedef signed char s8;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
extern int func_00175670(u8*),func_00174170(void);
extern void func_001548D0(u8*,V3*,int),func_001CBE10(u8*,int,int);
/* Five positive durations followed by the native reset sentinel. */
extern short D_0044DC90[6];
extern u8 *D_004C270C __attribute__((section(".sdata")));
void func_001CC440(u8*p){
 u8*owner=*(u8**)(p+0x18);V3 position;
 func_00175670(p);
 if(--p[0x22]==0){
  p[0x22]=4;
  position.x=(float)((u32)func_00174170()&127)-63.0f;position.x*=1.6666666269302368f;
  position.y=(float)((u32)func_00174170()&127)-63.0f;position.y*=2.142857074737549f;position.z=0;
  func_001548D0(p,&position,0);
 }
 if(--*(short*)(p+0x1C)==0){
  func_001CBE10(p,3,p[0x1E]);++*(short*)(p+0x1E);if((*(short*)(p+0x1C)=D_0044DC90[*(short*)(p+0x1E)])<0){*(short*)(p+0x1E)=0;*(short*)(p+0x1C)=D_0044DC90[*(short*)(p+0x1E)];}
 }
 if(owner[0x425]||*(s8*)(D_004C270C+9)>=2)++p[5];
}
