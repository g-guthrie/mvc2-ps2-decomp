typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void func_00152550(void *, void (*)(u8 *));
extern void func_00162810(u8 *);
void func_00162670(u8 *controller,u8 *state)
{
 if(controller[0x23E]!=3)*(u32*)(state+0xD8)=0;
 if((*(u32*)(state+0xD8))--==0) {
  state[4]=1;
  func_00152550(state,func_00162810);
 }
}
void func_001ACA30(u8 *p,void *owner_context)
{
 u8 *owner=(u8*)owner_context;
 if(owner[0x1E4]!=0x16) {
  p[4]=2;
  p[0x13C]=0;
 } else {
  if(--*(s16*)(p+0x1C)==0) {
   p[5]++;
   p[0x13C]=1;
  }
 }
}
