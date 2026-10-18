typedef unsigned char u8;
extern void *func_003DA750(void *,int,int);
extern void func_001ACE30(u8 *);
void func_001ACDC0(void *owner,void *context,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001ACE30;
 *(void **)(p+24)=owner;
 *(void **)(p+20)=context;
 p[32]=mode;
 }
}
