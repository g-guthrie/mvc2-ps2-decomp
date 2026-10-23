typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
void func_0035D880(u8 *p,u8 *owner_unused)
{
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);func_001E7F60(p);
 if(*(s8*)(p+0x151)) {
  p[5]++;
  *(float*)(p+0x60)=-0.53571426868438720703125f;
  *(float*)(p+0x6C)=0;
 }
}
void func_0035DD40(u8 *p,u8 *owner_unused)
{
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);func_001E7F60(p);
 if(*(s8*)(p+0x151)) {
  p[5]++;
  *(float*)(p+0x60)=-2.142857074737548828125f;
  *(float*)(p+0x6C)=0;
 }
}
