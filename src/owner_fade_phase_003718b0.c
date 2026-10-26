typedef unsigned char u8;typedef signed char s8;
extern int func_00175700(u8*);
void func_003718B0(u8*p) {
 u8 *owner=*(u8**)(p+0x18);
 if(owner[6]!=2) ++p[4];
 else {
  if(*(float*)(p+0x118)) {
   *(float*)(p+0x118)-=0.05999999865889549f;
   if(*(float*)(p+0x118)<0.0f) *(float*)(p+0x118)=0.0f;
  }
  if(*(s8*)(p+0x153)<0) {++p[5];p[0x13C]=0;}
  else func_00175700(p);
 }
}
