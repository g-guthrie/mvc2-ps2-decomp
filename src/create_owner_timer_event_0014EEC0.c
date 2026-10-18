typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_0014EF40(u8 *);
extern u32 D_004C27FC;
void func_0014EEC0(u8 *owner,int timer) {
 u8 *p=func_003DA750(0,13,1);
 if(p){
  *(u32 *)(p+208)=33;
  *(void (**)(u8 *))(p+16)=func_0014EF40;
  *(s16 *)(p+204)=48;
  *(u32 *)(p+132)=D_004C27FC;
  *(u8 **)(p+200)=owner+136;
  *(s16 *)(p+30)=timer;
  *(u8 **)(p+24)=owner;
 }
}
