typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_00156480(u8 *);

void func_00156280(u8 *p)
{
 if(p[5]==0) {
  s16 v=*(s16 *)(p+0x1c)-1;
  *(s16 *)(p+0x1c)=v;
  if(v>0) return;
  {u32 t=p[5]; p[5]=t+1;}
  p[0x13c]=1;
 }
 func_00156480(p);
 *(f32 *)(p+0x50)+=*(f32 *)(p+0x5c);
 *(f32 *)(p+0x54)+=*(f32 *)(p+0x60);
 *(f32 *)(p+0x58)+=*(f32 *)(p+0x64);
 if(p[6]==0) {
  s16 v=*(s16 *)(p+0x1e)-1;
  *(s16 *)(p+0x1e)=v;
  if(v<=0) {u32 t=p[6]; p[6]=1;}
 }
 if(p[6]!=0) {
  *(f32 *)(p+0x78)-=0.1f;
  *(f32 *)(p+0x7c)-=0.1f;
  *(f32 *)(p+0x80)-=0.1f;
  if(*(f32 *)(p+0x80)<0.0f) {
   {u32 t=p[4]; p[4]=t+1;}
   p[0x13c]=0;
  }
 }
}
