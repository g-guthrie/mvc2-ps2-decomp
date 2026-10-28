typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern void func_00179150(u8*,u8*);
void residual_003264A0(u8 *p)
{
 float x,y;s8 *frame;
 p[6]=2;*(s16*)(p+0x1C)=20;x=*(float*)(p+0x34);y=*(float*)(p+0x38);
 frame=(s8*)(p+0x160);
 *(s8*)(p+0x16A)=-1;*frame=3;func_00179150(p,*(u8**)(p+0x1DC));
 *(float*)(p+0x5C)=(*(float*)(p+0x34)-x)/20.0f;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=-0.8035714030265808f;
 *(float*)(p+0x60)=(*(float*)(p+0x38)-y)/20.0f-(-8.035714149475098f);
 *(s8*)(p+0x16A)=-1;*frame=1;func_00179150(p,*(u8**)(p+0x1DC));
 *(float*)(p+0x34)=x;*(float*)(p+0x38)=y;
}
