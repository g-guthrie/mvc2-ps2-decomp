typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
/* Unary state callbacks. Positions, velocities and accelerations retain
 * the native actor offsets and float operation order. */
extern int func_00417A40(void);
extern int func_001757E0(u8 *,int,int),func_00175700(u8 *);
extern int func_001754A0(u8 *,int,int);
extern void func_001843A0(u8 *),func_00170DF0(u32);
extern void func_001B5350(u8 *,u8 *);

void func_00151120(u8 *p)
{
 u8 state=p[4];
 switch(state) {
 case 0:
  p[4]=state+1;
  *(s16*)(p+0x1C)=0;*(s16*)(p+0x1E)=0;
  func_00170DF0(*(u32*)(p+0x84));
  break;
 case 1:
  if(++*(s16*)(p+0x1C)>=1000)*(s16*)(p+0x1C)=0;
  if(++*(s16*)(p+0x1E)>=1000)*(s16*)(p+0x1E)=0;
  *(u32*)(p+0xD0)|=0x20000;
  *(float*)(p+0xE0)=(float)(1.0-0.001*(double)*(s16*)(p+0x1C));
  *(float*)(p+0xE4)=(float)(1.0-0.001*(double)*(s16*)(p+0x1E));
  break;
 }
}

void func_001610E0(u8 *p)
{
 int r;
 p[4]++;
 r=func_00417A40();
 r%=4000;
 *(float*)(p+0x34)=(float)(r%2?r:-r);
}

void func_0017CFF0(u8 *p)
{
 if(p[6]==0) {
  p[6]++;
  p[0x20D]=0;
  *(float*)(p+0x5C)=0.0f;
  *(float*)(p+0x60)=0.0f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x6C)=0.0f;
  if(p[0x217]) {
   if(*(float*)(p+0x38)<34.28571319580078125f+*(float*)(p+0x430))
    *(float*)(p+0x38)=*(float*)(p+0x21C);
  } else *(float*)(p+0x38)=*(float*)(p+0x430);
  func_001757E0(p,0x18,3);
 } else if((s8)func_00175700(p)<0)func_001843A0(p);
}

void func_001B3090(u8 *p)
{
 if(*(s8*)(*(u8**)(p+0x18)+0x151)==1) {
  p[5]++;
  *(float*)(p+0x5C)=*(s16*)(p+0x140)?-15.83333301544189453125f:15.83333301544189453125f;
  *(float*)(p+0x68)=*(s16*)(p+0x140)?-0.3125f:0.3125f;
  *(float*)(p+0x60)=6.428571224212646484375f;
  *(float*)(p+0x6C)=-0.53571426868438720703125f;
  *(s16*)(p+0x1C)=30;
 }
}

void func_001B5120(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);
 if(*(u16*)(p+0xD0)!=*(u16*)(owner+0x168)){p[4]=2;return;}
 p[6]++;
 p[0x13C]=1;
 p[0x24]=0;
 func_001B5350(owner,p);
 func_001754A0(p,0x1B,p[0x20]);
 switch(p[0x20]) {
 case 0x16:*(int*)(p+0x48)=0;break;
 case 0x17:*(int*)(p+0x48)=0xE000;break;
 case 0x18:*(int*)(p+0x48)=0xD000;break;
 }
}
