#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
extern u8 D_004648D0[];
extern void func_00386EC0(u8*,u32),func_00386740(u8*);
extern int func_001757E0(u8*,int,int);
void func_00386620(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);u32 kind;
 ++p[4];*(u16*)(p+0x26)=0x1C00;*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=1;kind=p[0x20];if(kind&&(u8)kind<10)func_00386EC0(p,(u32)owner);
 func_001757E0(p,23,D_004648D0[p[0x20]]);func_00386740(p);
}
