/* Process each pending phase independently and initialize the linked effect. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_0018FDB0(u8 *),func_001548D0(u8 *,float *,int),func_001E3710(u8 *,u8),func_00126400(void);
extern u8 *func_001B53E0(u8 *,int,int);
void func_0026A1B0(u8 *p)
{
 float offset[3];
 func_00175700(p);
 if(*(s8*)(p+0x151)==1){
  p[0x151]=3;(*(u8**)(p+0x1DC))[0x1B5]=32;func_0018FDB0(p);
  offset[0]=0;offset[1]=0;func_001548D0(p,offset,1);func_001E3710(p,14);
 }
 if(*(s8*)(p+0x151)==2){
  u8 *q;
  float xOffset;
  q=*(u8**)(p+0x1DC);++p[6];*(u8**)(q+0x1C8)=p;q[0x1E6]=*(s8*)(p+0x1E6)^1;
  q[0x1B5]=34;q[0x20A]=1;func_00126400();func_001B53E0(p,31,0);
  if(*(short*)(p+0x140))xOffset=-106.66666412353516f;else xOffset=106.66666412353516f;
  *(float*)(p+0x34)+=xOffset;*(float*)(p+0x38)+=-154.28570556640625f;
  *(float*)(p+0x60)=11.785714149475098f;*(float*)(p+0x6C)=-0.9040178060531616f;
 }
}
