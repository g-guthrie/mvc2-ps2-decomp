typedef unsigned char u8;
extern void func_0037EAA0(u8 *);
extern void *func_003DA750(void *,int,int);
void func_0037EA30(void *owner,void *context,u8 mode){
 u8 *p=func_003DA750(0,1,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_0037EAA0;
 *(void **)(p+24)=owner;
 *(void **)(p+20)=context;
 p[32]=mode;
 }
}
