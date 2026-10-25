#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*);
extern void func_00179150(u8*,u8*);
void func_00325FE0(u8 *p)
{
 float x,y;s8 *frame;
 func_00175700(p);
 if(!*(s8*)(p+0x151)){
  frame=(s8*)(p+0x160);
  ++p[6];*(s16*)(p+0x1C)=40;x=*(float*)(p+0x34);y=*(float*)(p+0x38);
  *(s8*)(p+0x16A)=-1;*frame=3;func_00179150(p,*(u8**)(p+0x1DC));
  p[0x20D]=2;*(float*)(p+0x5C)=(*(float*)(p+0x34)-x)/40.0f;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=-0.8035714030265808f;
  *(float*)(p+0x60)=(*(float*)(p+0x38)-y)/40.0f-(-16.071428298950195f);
  *(s8*)(p+0x16A)=-1;*frame=1;func_00179150(p,*(u8**)(p+0x1DC));
  *(float*)(p+0x34)=x;*(float*)(p+0x38)=y;
 }
}
