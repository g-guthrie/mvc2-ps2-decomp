#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_001757E0(u8*,int,int);
extern void func_00185490(u8*),func_00183D10(u8*);
void func_00251140(u8 *p)
{
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[7];func_00185490(p);*(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 func_00183D10(p);func_001757E0(p,22,0);
}
