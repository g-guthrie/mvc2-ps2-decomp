#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
typedef struct {u8 prefix[0x34];V3 position;} Position;
extern float D_004F1F4C,D_004B8740[];
extern int func_001757E0(u8*,int,int);
extern void func_001E3210(u8*,int);
void func_0039CCE0(u8 *p)
{
 u8 *owner;float offset;Position *pos=(Position*)p;
 ++p[4];owner=*(u8**)((*(u8**)(p+0x18))+0x18);
 *(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x24]=0;pos->position.y=*(float*)(owner+0x430);pos->position.x=D_004F1F4C;p[0x13C]=1;
 offset=D_004B8740[p[0x22]];if(*(s16*)(p+0x140))offset-=213.3333282470703f;
 pos->position.x+=offset;func_001757E0(p,23,20);func_001E3210(p,31);
}
