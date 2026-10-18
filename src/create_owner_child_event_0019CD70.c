typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_0019CDD0(u8 *);
void func_0019CD70(u8 *owner){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_0019CDD0;
 p[32]=0;p[33]=0;
 *(void **)(p+24)=*(void **)(owner+476);
 p[1]=owner[1];
 *(s16 *)(p+38)=2309;
 }
}
