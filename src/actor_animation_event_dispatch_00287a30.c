#pragma padloop on
typedef unsigned char u8;typedef signed char s8;
extern int func_00175700(u8*);
extern void func_00184540(u8*),func_00385A20(void*,u8),func_001C09A0(void*,u8);
void func_00287A30(u8*p) {
 if((s8)func_00175700(p)<0)func_00184540(p);
 else switch(p[0x1FC]) {
 case 2:
  if(*(s8*)(p+0x151)) {
   p[0x151]=0;func_00385A20(p,2);func_001C09A0(p,2);
  }
  break;
 }
}
