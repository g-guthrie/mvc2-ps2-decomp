/* Four-phase ground capture sequence and animation-event transitions. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Vec3;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *),func_001830D0(u8 *,float *,int),func_001B6F40(u8 *);
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
void func_0026D340(u8 *p)
{
 float offset[3];
 switch(p[7]) {
 case 0:
  if(p[0x269]==6) {p[0x404]=255;p[0x405]=16;}
  p[7]++;p[0x20D]=0;
  *(float*)(p+0x38)=*(float*)(p+0x430);
  *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
  p[0x1B5]=56;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
  ((s16*)(D_004C2794+0x7C))[p[2]]++;
  *(u16*)(p+0x1C0)=16;
  func_00185490(p);func_001757E0(p,22,0);func_00183D10(p);
  break;
 case 1:
  p[0x40C]=2;p[0x33C]=5;
  p[0x405]=p[0x269]==6?2:0;
  func_00175700(p);
  if(*(s8*)(p+0x151)) {
   p[0x404]=0;p[0x405]=0;p[7]++;p[0x151]=0;
   offset[1]=102.85713958740234375f;offset[0]=0;offset[2]=0;
   func_001830D0(p,offset,1);
  }
  break;
 case 2:
  p[0x209]=3;p[0x40C]=2;p[0x33C]=5;
  func_00175700(p);
  if(*(s8*)(p+0x151)) {
   p[7]++;p[0x151]=0;p[0x152]=2;func_001B6F40(p);
  }
  break;
 case 3:
  p[0x209]=3;p[0x40C]=2;p[0x33C]=5;
  if((s8)func_00175700(p)<0) {
   p[6]++;p[7]=0;*(s16*)(p+0x1C)=60;*(s16*)(p+0x1E)=40;
   *(float*)(p+0x68)=34.0f;*(float*)(p+0x6C)=0;
   *(Vec3*)(p+0x50)=*(Vec3*)(p+0x298);
   func_001757E0(p,22,1);
  }
  break;
 }
}
