#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;
typedef struct {u32 words[49];} Fields;typedef struct {float x,y,z;} V3;
extern void func_0035E090(u8*,void*);
void func_0035DFC0(u8*p,void*context) {
 u8 *owner=context;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];*(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=0;*(float*)(p+0x34)=*(float*)(owner+0x34);*(float*)(p+0x38)=*(float*)(owner+0x38);*(float*)(p+0x3C)=*(float*)(owner+0x3C);
 *(s16*)(p+0x1C)=1;*(s16*)(p+0x1E)=48;func_0035E090(p,owner);
}
