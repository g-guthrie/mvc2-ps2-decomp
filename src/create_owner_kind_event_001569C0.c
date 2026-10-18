typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_00156A40(u8 *);
void func_001569C0(u8 *owner,u8 kind) {
 u8 pool;
 u8 *p;
 if(kind==9)pool=25;else pool=61;
 p=func_003DA750(0,pool,1);
 if(p){
  p[316]=1;
  *(void (**)(u8 *))(p+16)=func_00156A40;
  *(u32 *)(p+208)=0x00800400;
  *(u8 **)(p+200)=owner+136;
 }
}
