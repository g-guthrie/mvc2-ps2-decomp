/* Select a mapped input or random action and start its animation. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
extern u8 D_004D18E6;
extern const u8 D_004BFE28[] __attribute__((section(".sdata")));
extern const u8 D_004BFE2C[] __attribute__((section(".sdata")));
extern int func_00174170(void),func_001841C0(u8 *),func_001757E0(u8 *,int,int);
extern void func_0034FA80(void *,u8);
void func_0020A9A0(u8 *p)
{
 unsigned int buttons;
 if(!*(s8*)(p+0x539)&&((buttons=*(u16*)(p+0x354))&0x360)) {
  if(buttons&0x200)*(s16*)(p+0x1C)=0;
  else if(buttons&0x100)*(s16*)(p+0x1C)=1;
  else if(buttons&0x40)*(s16*)(p+0x1C)=2;
  else *(s16*)(p+0x1C)=3;
 } else *(s16*)(p+0x1C)=func_00174170()&3;
 if(D_004D18E6)*(s16*)(p+0x1C)=D_004BFE28[*(s16*)(p+0x1C)];
 else *(s16*)(p+0x1C)=D_004BFE2C[*(s16*)(p+0x1C)];
 if(func_001841C0(p)>=2)*(s16*)(p+0x1C)=1;
 switch(*(s16*)(p+0x1C)) {
 case 0:func_0034FA80(p,6);func_001757E0(p,19,0);break;
 case 1:func_001757E0(p,19,1);break;
 case 2:func_001757E0(p,19,2);break;
 case 3:func_001757E0(p,19,4);break;
 default:func_001757E0(p,19,1);break;
 }
}
