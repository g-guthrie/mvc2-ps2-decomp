typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_001D27A0(u8 *);
void func_001D2730(void *owner,u8 first,u8 second){
 u8 *p=func_003DA750(0,3,1);
 if(p){
 *(s16 *)(p+38)=11008;
 p[32]=first;p[33]=second;
 *(void (**)(u8 *))(p+16)=func_001D27A0;
 *(void **)(p+24)=owner;
 }
}
