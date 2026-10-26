typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*);
extern void func_001E7F60(u8*);
void func_00396230(u8 *p,void *owner_context) {
 u8 *q=owner_context;
 *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=*(float*)(q+0x38);
 func_00175700(p);
 if(*(s8*)(p+0x151)!=0) {
  p[0x151]=0;++p[5];
  if(p[0x20]==0) {
   float dx=133.333328f;
   if(*(s16*)(p+0x140))dx=-dx;
   *(float*)(p+0x38)+=265.714264f;*(float*)(p+0x34)-=dx;
  }
 }
 func_001E7F60(p);
}
