typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00175C00(u8 *,s32);
extern void func_00176160(u8 *,s32,s32,s32);

void func_002D6570(u8 *p)
{
 u8 *a2,*a1;
 s32 c;
 a2=p+0x2b8;
 if(*(s8 *)(a2)) {
  if(*(u16 *)(p+0x168)!=0x1600) {
   *(s8 *)(a2)=0;
   func_00175C00(p,0);
  }
 }
 a1=p+0x2b8;
 *(s16 *)(p+0x3f8)=2;
 a2=a1+4;
 c=*(s8 *)(p+0x2bc);
 if(c==0) {
  if(*(s8 *)(a1+5)==0) return;
  *(s8 *)(a2)=c+1;
  p[0x1b2]=0;
  *(s8 *)(a1+6)=0;
  *(s8 *)(a1+7)=0;
 }
 if(*(s8 *)(a2)==0) return;
 if(*(s16 *)(p+0x434)!=0) {
  u8 *t=p+0x2b8;
  if(*(s8 *)(p+0x2bd)!=0) goto L663c;
  if(*(s8 *)(t+6)==0 && (p[0x15a]&0xe0)!=0) goto L663c;
 }
 *(s8 *)(p+0x2bd)=0;
 *(s8 *)(a2)=0;
 *(s8 *)(p+0x219)=0;
 func_00175C00(p,0);
 return;
L663c:
 if(*(s8 *)(p+0x1b2)!=0) {
  *(s8 *)(p+0x219)=0;
  *(s8 *)(p+0x2be)=-1;
 }
 *(s8 *)(p+0x2bf)=*(s8 *)(p+0x2bf)+1;
 *(s8 *)(p+0x2bf)=*(s8 *)(p+0x2bf)&7;
 func_00176160(p,0,*(s8 *)(p+0x2bf)+2+10*p[0x25],1);
}
