typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {float x,y,z;} Vec3;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00191EF0(u8 *,u8),func_001D5670(u8 *,u8,u8),func_001E3210(u8 *,int);
extern void func_001E3270(u8 *,int,float),func_001266A0(u8 *,int,int);
extern void func_0018FDB0(u8 *),func_001548D0(u8 *,float *,int),func_001E3710(u8 *,u8);

void func_00192360(u8 *p)
{
 p[6]++;
 *(s16*)(p+0x1C)=4;
 func_00191EF0(p,p[0x22]);
 if(p[1]==0x2E && !p[0x215])func_001D5670(p,4,0);
 switch(p[1]) {
 case 0x2E:
 case 0x33:
  func_001E3210(p,0x22);
  func_001E3270(p,0x22,3.0f);
  break;
 case 0xF:func_001E3210(p,0x24);break;
 }
}

void func_00273160(u8 *p)
{
 Vec3 offset;
 u8 *owner=*(u8**)(p+0x1DC);
 int trigger;
 func_00175700(p);
 trigger=*(s8*)(p+0x151);
 if(trigger<0) {
  p[6]++;
  func_001266A0(p,0,0);
  *(u8**)(owner+0x1C8)=p;
  owner[0x20A]=1;
  owner[0x1B5]=0x24;
  *(float*)(p+0x5C)=p[0x1E6]?-5.83333301544189453125f:5.83333301544189453125f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x60)=12.85714244842529296875f;
  *(float*)(p+0x6C)=-0.803571403026580810546875f;
 } else switch(trigger) {
 case 1:
  p[0x151]=0;
  owner[0x1B5]=0x22;
  func_0018FDB0(p);
  offset.x=-36.66666412353515625f;
  offset.y=111.42856597900390625f;
  offset.z=0.0f;
  func_001548D0(p,&offset.x,1);
  func_001E3710(p,4);
  break;
 case 2:
  p[0x151]=0;
  owner[0x1B5]=0x22;
  func_0018FDB0(p);
  offset.x=-45.0f;
  offset.y=96.42856597900390625f;
  offset.z=0.0f;
  func_001548D0(p,&offset.x,1);
  func_001E3710(p,4);
  break;
 case 3:
  p[0x151]=0;
  owner[0x1B5]=0x23;
  func_0018FDB0(p);
  offset.x=-60.0f;
  offset.y=90.0f;
  offset.z=0.0f;
  func_001548D0(p,&offset.x,1);
  func_001E3710(p,6);
  break;
 }
}
