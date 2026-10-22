typedef unsigned char u8;
typedef signed short s16;
extern void func_001EAB30(u8 *),func_00211DB0(u8 *),func_00217AD0(u8 *),func_0031CFB0(u8 *);
extern void func_001E3210(u8 *,int);
extern int func_001757E0(u8 *,int,int);

void func_001EAAB0(u8 *p)
{
 p[6]++;
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 *(float*)(p+0x5C)=p[0x1E6]?-18.333332061767578125f:18.333332061767578125f;
 *(float*)(p+0x68)=p[0x1E6]?0.3385416567325592041015625f:-0.3385416567325592041015625f;
 *(s16*)(p+0x1C)=20;
 func_001EAB30(p);
}

void func_001FE340(u8 *p)
{
 u8 *state=p+0x2B8;
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 p[6]++;
 *(s16*)(p+0x1C)=16;
 *(float*)(p+0x5C)=p[0x1E6]?-11.6666660308837890625f:11.6666660308837890625f;
 state[0x1C]=1;
 func_001E3210(p,0x1F);
}

void func_00207BE0(u8 *p)
{
 if(--*(s16*)(p+0x1C)==0) {
  p[6]++;
  *(s16*)(p+0x1C)=6;
  *(float*)(p+0x70)=-*(float*)(p+0x64)/8.0f;
 }
}

void func_00211D60(u8 *p)
{
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 p[6]++;
 *(float*)(p+0x5C)=p[0x1E6]?-13.33333301544189453125f:13.33333301544189453125f;
 func_00211DB0(p);
}

void func_00217A60(u8 *p)
{
 p[6]++;
 p[0x20]=p[0x214];
 *(s16*)(p+0x1C)=24;
 *(float*)(p+0x5C)=-16.6666660308837890625f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 if(p[0x20])*(float*)(p+0x5C)=-26.6666660308837890625f;
 if(p[0x1E6])*(float*)(p+0x5C)=-*(float*)(p+0x5C);
 func_00217AD0(p);
}

void func_00222440(u8 *p)
{
 p[6]++;
 if(p[0x1E6])*(float*)(p+0x5C)=8.33333301544189453125f;
 else *(float*)(p+0x5C)=-8.33333301544189453125f;
 *(float*)(p+0x68)=0.0f;
 if(!(*(float*)(p+0x6C)<=0.0f)) {
  *(float*)(p+0x6C)/=4.28571414947509765625f;
  *(float*)(p+0x6C)=-*(float*)(p+0x6C);
 }
}

void func_00257660(u8 *p)
{
 p[7]++;
 p[0x20D]=2;
 *(float*)(p+0x5C)=p[0x1E6]?4.28571414947509765625f:-4.28571414947509765625f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x60)=8.5714282989501953125f;
 *(float*)(p+0x6C)=-1.0714285373687744140625f;
}

void func_0027F720(u8 *p)
{
 p[6]++;
 p[0x20D]=0;
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 p[0x13C]=0;
 *(s16*)(p+0x1C)=270;
 *(s16*)(p+0x1E)=0;
 func_001757E0(p,0x13,7);
}

void func_0031CF40(u8 *p)
{
 p[6]++;
 p[0x20]=p[0x214];
 *(s16*)(p+0x1C)=24;
 *(float*)(p+0x5C)=-16.6666660308837890625f;
 *(float*)(p+0x68)=0.0f;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 if(p[0x20])*(float*)(p+0x5C)=-26.6666660308837890625f;
 if(p[0x1E6])*(float*)(p+0x5C)=-*(float*)(p+0x5C);
 func_0031CFB0(p);
}
