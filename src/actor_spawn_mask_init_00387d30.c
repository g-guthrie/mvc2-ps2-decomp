#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
typedef struct Event Event;
extern Event *func_00387C40(int,u8);
extern void func_00387EA0(u8*);
void func_00387D30(u8 *p)
{
 s16 i;u8 remaining=8;u8 *owner=*(u8**)(p+0x18);
 ++p[4];*(u16*)(p+0x26)=0x1C04;
*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=0;*(s16*)(p+0x1C)=300;
 p[0x14C]=48;p[0x14D]=48;p[0x14E]=48;p[0x14F]=48;
 *(u32*)(p+0xD0)=0;*(u32*)(p+0xD4)=0;*(u32*)(p+0xD8)=255;
 for(i=0;i<8;++i){if(!func_00387C40((int)p,remaining))break;--remaining;*(u32*)(p+0xD0)|=1u<<i;}
 func_00387EA0(p);
}
