typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *), func_001757E0(u8 *, int, int);
extern void func_001E7F60(u8 *);

void func_003488E0(u8 *p,u8 *owner)
{
 u8 *state=owner+0x2B8;
 if(*(s8*)(p+0x1B2)||*(s8*)(p+0x1B3)) {
  state[0x1A]=0;p[5]++;p[0x169]=21;p[0x168]=12;
  func_001757E0(p,p[0x169],p[0x168]);
 } else {
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  *(float*)(p+0x38)+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  func_00175700(p);func_001E7F60(p);
 }
}
