typedef unsigned char u8;typedef signed char s8;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
void func_002180B0(u8 *p){p[6]++;switch(p[0x20]) {case 0:case 2:p[0x21]=*(s8 *)(D_004C2840+0x1c)&1;func_001757E0(p,19,p[0x21]);break;case 1:case 3:case 4:func_001757E0(p,19,2);break;}}
void func_0031D590(u8 *p){p[6]++;switch(p[0x20]) {case 0:case 2:p[0x21]=*(s8 *)(D_004C2840+0x1c)&1;func_001757E0(p,19,p[0x21]);break;case 1:case 3:case 4:func_001757E0(p,19,2);break;}}
