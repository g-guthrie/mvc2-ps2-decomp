#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_001757E0(u8*,int,int);
extern void func_001E3210(u8*,int);
void func_00230360(u8 *p)
{
 ++p[6];*(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(s16*)(p+0x140)&=254;p[0x169]=20;
 if(!p[0x1E6])p[0x168]=3;else p[0x168]=4;
 func_001757E0(p,p[0x169],p[0x168]);func_001E3210(p,33);
}
