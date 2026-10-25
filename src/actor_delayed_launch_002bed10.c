#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*);
extern void func_001266A0(u8*,int,int);
void func_002BED10(u8 *p)
{
 if(!p[7]){++p[7];}
 else{
  func_00175700(p);
  if(*(s8*)(p+0x151)){
   ++p[6];func_001266A0(p,5,5);
   *(float*)(p+0x5C)=p[0x1E6]?-3.3333332538604736f:3.3333332538604736f;
   *(float*)(p+0x68)=0;*(float*)(p+0x60)=17.14285659790039f;*(float*)(p+0x6C)=-1.6071428060531616f;
  }
 }
}
