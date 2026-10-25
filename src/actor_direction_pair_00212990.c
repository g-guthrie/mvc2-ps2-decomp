/* Build the contiguous position pair and derive the facing-relative direction. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef struct {float x,y,z;} V3;
extern int func_00175700(u8 *);
extern void func_001830D0(u8 *,const V3 *,int);
extern int func_001748C0(const V3 *,const V3 *);
extern void func_00212DA0(u8 *,u8 *),func_00352670(u8 *,int,int,int);
void func_00212990(u8 *p,u8 *work)
{
 V3 points[2];
 p[0x40C]=2;p[0x33C]=5;
 p[0x405]=p[0x269]==6?2:0;
 if((s8)func_00175700(p)>=0){
  if(*(s8*)(p+0x151)){
   p[0x151]=0;p[0x404]=0;p[0x405]=0;
   if(p[0x20D]==2){points[0].x=-6.666666507720947f;points[0].y=222.8571319580078f;}
   else {points[0].x=-46.666664123535156f;points[0].y=180.0f;}
   points[0].z=0;
   func_001830D0(p,&points[0],1);
  }
 }else{
  u8 *q;
  u8 direction;
  ++p[6];*(short*)(p+0x1C)=50;
  work[4]=255;work[5]=48;work[1]=64;*(short*)(work+2)=13;
  points[0]=*(V3*)(p+0x34);points[0].y+=102.0f;
  points[1]=*(V3*)(*(u8**)(p+0x220)+0x34);
  q=*(u8**)(p+0x220);
  if(q[0x20D]==0 || q[0x20D]==1)points[1].y=102.0f+*(float*)(q+0x430);
  else points[1].y+=56.0f;
  direction=(((u8)func_001748C0(&points[0],&points[1]))/16)&15;
  if(*(short*)(p+0x140))direction=(16-(s8)direction)&15;
  work[0]=direction;
  func_00212DA0(p,work);
  func_00352670(p,0,0,2);
 }
}
