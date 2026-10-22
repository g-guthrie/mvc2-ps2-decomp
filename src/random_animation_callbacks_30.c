typedef unsigned char u8;
typedef signed short s16;
extern int func_00174170(void),func_001757E0(u8 *,int,int);
extern void func_001E3210(u8 *,int);
/* The random selector is masked to the complete 16-byte pick table. */
extern const u8 D_0045B110[16];

void func_002C2310(u8 *p)
{
 p[6]++;
 if(p[0x20]==2)func_001757E0(p,0x13,3);
 else {
  *(s16*)(p+0x1C)=func_00174170()&3;
  switch(*(s16*)(p+0x1C)) {
  case 0:func_001757E0(p,0x13,0);break;
  case 1:func_001757E0(p,0x13,1);break;
  case 2:func_001757E0(p,0x13,1);break;
  case 3:func_001757E0(p,0x13,2);break;
  }
 }
}

void func_002E5CE0(u8 *p)
{
 u8 *state=p+0x2B8;
 p[6]++;
 switch(p[0x20]) {
 case 0:
 case 2:
  state[1]=D_0045B110[func_00174170()&0xF];
  func_001757E0(p,0x13,state[1]);
  func_001E3210(p,0xA);
  break;
 case 1:
 case 3:
 case 4:func_001757E0(p,0x13,2);break;
 }
}
