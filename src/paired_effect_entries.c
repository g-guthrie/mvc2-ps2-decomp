typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00183D10(u8 *),func_00185490(u8 *);
extern int func_001757E0(u8 *,int,int);
extern u8 *func_001DD470(u8 *,u16);
extern void func_001DC6D0(u8 *,u32);
#define ENTER_ACTION(action) do { \
 p[0x1B5]=(action); \
 p[0x1B2]=*(u16*)(p+0x1C0)=0; \
 *(u32*)(p+0x1D8)=0; \
 ((s16*)(D_004C2794+0x7C))[p[2]]++; \
} while(0)

void func_0030E1B0(u8 *p)
{
 u8 *effect;
 if(p[0x269]==6){p[0x404]=0xFF;p[0x405]=16;}
 p[6]++;
 p[0x20D]=0;
 func_00183D10(p);
 func_00185490(p);
 ENTER_ACTION(61);
 func_001757E0(p,0x15,9);
 if((effect=func_001DD470(p,4))!=0)effect[0x22]=0;
 if((effect=func_001DD470(p,4))!=0)effect[0x22]=16;
}

void func_0030E4C0(u8 *p)
{
 u8 *effect;
 if(p[0x269]==6){p[0x404]=0xFF;p[0x405]=16;}
 p[6]++;
 p[0x20D]=0;
 func_00183D10(p);
 func_00185490(p);
 ENTER_ACTION(62);
 func_001DC6D0(p,0);
 func_001757E0(p,0x15,10);
 if((effect=func_001DD470(p,5))!=0)effect[0x22]=0;
 if((effect=func_001DD470(p,5))!=0)effect[0x22]=16;
}

void func_0030E7C0(u8 *p)
{
 u8 *effect;
 if(p[0x269]==6){p[0x404]=0xFF;p[0x405]=16;}
 p[6]++;
 p[0x20D]=0;
 func_00183D10(p);
 func_00185490(p);
 ENTER_ACTION(66);
 func_001757E0(p,0x15,11);
 if((effect=func_001DD470(p,8))!=0)effect[0x22]=0;
 if((effect=func_001DD470(p,8))!=0)effect[0x22]=16;
}

void func_0030EB20(u8 *p)
{
 u8 *effect;
 if(p[0x269]==6){p[0x404]=0xFF;p[0x405]=16;}
 p[6]++;
 func_00185490(p);
 p[0x20D]=0;
 func_00183D10(p);
 ENTER_ACTION(68);
 func_001757E0(p,0x15,13);
 if((effect=func_001DD470(p,6))!=0)effect[0x22]=0;
 if((effect=func_001DD470(p,6))!=0)effect[0x22]=16;
}
