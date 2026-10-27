typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int),func_00174170(void),func_00417A40(void);
extern void func_00182C30(u8 *,int),func_001C3510(u8 *,u8 *);
extern int func_001A5D80(u8 *,int,int);
extern void func_002413C0(u8 *,float *),func_0034B040(u8 *,u8 *),func_00175C00(u8 *,int);

void func_001A5810(u8 *p,u8 *unused,u8 *other)
{
 func_00175700(p);
 if(*(s8*)(p+0x151)) {
  p[5]++;
  other[0x13C]=0;
  func_001757E0(other,0,0);
  func_00182C30(other,10);
 }
}

void func_001C3480(u8 *p,u8 *owner)
{
 p[7]++;
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x68)=0.0f;
 *(float*)(p+0x60)=0.0f;*(float*)(p+0x6C)=0.0f;
 if(*(float*)(owner+0x34)<=*(float*)(p+0x34))*(s16*)(p+0x140)=0;
 else *(s16*)(p+0x140)=1;
 func_001757E0(p,0x19,0);
 func_001C3510(p,owner);
}

void func_00242A20(u8 *p,u8 *state)
{
 p[6]++;p[7]=0;
 p[0x22]=28;
 p[0x206]=12;p[0x207]=12;
 state[0x20]=0;
 func_001A5D80(p,8,0);
 func_001757E0(p,0x14,3);
 func_002413C0(p,(float*)state);
}

void func_0026CA30(u8 *p)
{
 p[7]++;
 if(func_00417A40()&1)func_001757E0(p,0x13,0);
 else func_001757E0(p,0x13,1);
}

void func_002FDBC0(u8 *p)
{
 u8 *state=p+0x2B8;
 if(p[6]==0) {
  p[6]++;
  if(!(func_00174170()&1))p[0x168]=2;
  else p[0x168]=3;
  func_001757E0(p,0x13,p[0x168]);
  p[0x216]=0;
  *(s16*)(state+4)=0;
  func_00175C00(p,0);
 } else func_00175700(p);
}

void func_002D30B0(u8 *p)
{
 p[7]++;
 if(func_00417A40()&1)func_001757E0(p,0x13,0);
 else func_001757E0(p,0x13,1);
}
