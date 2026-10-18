typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_001D85F0(u8 *);
void func_001D8580(void *owner,void *context,u8 mode){
 u8 *p=func_003DA750(0,3,1);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001D85F0;
 *(void **)(p+24)=owner;
 *(void **)(p+20)=context;
 p[32]=mode;
 *(s16 *)(p+38)=12288;
 }
}
