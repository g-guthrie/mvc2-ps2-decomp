typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int),func_00174170(void);
extern void func_00176160(u8 *,int,int,int),func_001843A0(u8 *),func_001E3CE0(int);
extern u8 D_00583B90[];
typedef void (*Unary)(u8 *);
extern Unary const jtbl_0045E2B0[4];
extern u8 D_004F20B0[];

void func_001F88A0(u8 *p)
{
 func_00175700(p);
 if(*(s8*)(p+0x151)) {
  float zero=0.0f;
  p[6]++;
  p[0x151]=0;
  p[0x20D]=2;
  *(float*)(p+0x5C)=5.416666507720947265625f;
  *(float*)(p+0x68)=0.0f;
  if(!p[0x1E6]) {
   *(float*)(p+0x5C)=-5.416666507720947265625f;
   *(float*)(p+0x68)=zero;
  }
  *(float*)(p+0x60)=0.0f;
  *(float*)(p+0x6C)=0.0f;
 }
}

void func_00201740(u8 *p)
{
 u8 *state=p+0x2B8;
 func_00175700(p);
 if(*(s8*)(state+0xD)) {
  p[7]++;
  state[0x10]=0;
  *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
  *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
  *(float*)(p+0x60)=0.53571426868438720703125f;
  func_001757E0(p,0x16,0x16);
 }
}

void func_0030A9D0(u8 *p)
{
 u8 random;
 func_00176160(p,2,0x11,1);
 random=func_00174170();
 func_001757E0(p,0x13,random&1);
}

void func_0032AFB0(u8 *p)
{
 p[5]=1;
 D_00583B90[*(s8*)(p+0x538)]=0;
 if(*(s16*)(p+0x1E)==0)func_001E3CE0((u8)(*(s8*)(p+0x538)+0x4A));
}

void func_002FFE70(u8 *p,u8 *state_unused)
{
 if((s8)func_00175700(p)<0) {func_001843A0(p);return;}
 if(*(s8*)(p+0x151)) {
  u8 *owner;
  p[0x151]=0;
  owner=*(u8**)(p+0x1DC);
  owner[0x20A]=16;
  owner[0x20D]=2;
  owner[0x1B5]=0x22;
  p[0x1B5]=0x22;
  owner[0x1E6]=p[0x1E6];
 }
}

void func_0032AF60(u8 *p)
{
 *(u8**)(p+0x18)=D_004F20B0+0x5B8*(2**(s16*)(p+0x1E)+*(s8*)(p+0x538));
 jtbl_0045E2B0[p[5]](p);
}
