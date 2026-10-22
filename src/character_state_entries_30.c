typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_00175C00(u8 *,int);
extern void func_00176160(u8 *,int,int,int);
extern int func_00174170(void),func_001757E0(u8 *,int,int);
extern void func_001C57B0(void *,u8);
extern int func_0028DA30(u8 *,u8),func_00294D40(u8 *,u8);
extern void func_00288400(u8 *),func_00290080(u8 *);
extern void func_00288A70(u8 *),func_00288950(u8 *);
extern void func_00288B60(u8 *),func_00288CC0(u8 *);
extern void func_00290450(u8 *),func_00290660(u8 *),func_002907A0(u8 *);
void func_00288890(u8 *p)
{
 func_00175C00(p,0);
 func_00176160(p,7,p[0x25]*0x57+0x39,1);
 if(!(*(u16*)(p+0x4F0)&0x200) && (func_00174170()&0xF0)) {
  p[7]=4;
  func_001757E0(p,0x13,6);
  func_00288A70(p);
 } else {
  p[7]++;
  func_001757E0(p,0x13,7);
  func_00288950(p);
 }
}
void func_00288AB0(u8 *p)
{
 if(func_0028DA30(p,29)) {p[0x20]=5;func_00288400(p);return;}
 p[7]++;
 *(s16*)(p+0x1C)=1;
 func_00175C00(p,0);
 func_00176160(p,7,p[0x25]*0x57+57,1);
 func_001C57B0(p,5);
 func_001757E0(p,0,0);
 func_00288B60(p);
}
void func_00288BF0(u8 *p)
{
 if(func_0028DA30(p,29)) {p[0x20]=5;func_00288400(p);return;}
 p[7]++;
 *(s16*)(p+0x1C)=1;
 func_00175C00(p,0);
 func_00176160(p,7,p[0x25]*0x57+57,1);
 func_00176160(p,2,p[0x25]*0x57+85,1);
 func_001C57B0(p,7);
 func_001757E0(p,0,0);
 func_00288CC0(p);
}
void func_002903A0(u8 *p)
{
 if(func_00294D40(p,28)) {p[0x20]=5;func_00290080(p);return;}
 p[7]++;
 *(s16*)(p+0x1C)=1;
 func_00175C00(p,0);
 func_00176160(p,7,p[0x25]*0x57+57,1);
 func_001C57B0(p,8);
 func_001757E0(p,0,0);
 func_00290450(p);
}
void func_00290590(u8 *p)
{
 if(func_00294D40(p,28)) {p[0x20]=5;func_00290080(p);return;}
 p[7]++;
 *(s16*)(p+0x1C)=1;
 func_00175C00(p,0);
 func_00176160(p,1,p[0x25]*0x57+85,1);
 func_00176160(p,2,p[0x25]*0x57+32,1);
 func_001C57B0(p,9);
 func_001757E0(p,0,0);
 func_00290660(p);
}
void func_002906F0(u8 *p)
{
 if(func_00294D40(p,28)) {p[0x20]=5;func_00290080(p);return;}
 p[7]++;
 *(s16*)(p+0x1C)=1;
 func_00175C00(p,0);
 func_00176160(p,2,p[0x25]*0x57+85,1);
 func_001C57B0(p,10);
 func_001757E0(p,0,0);
 func_002907A0(p);
}
