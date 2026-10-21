typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_001CCD40(u8 *);
u8 *func_001CCC20(u8 *owner){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001CCD40;
 p[32]=1;p[33]=0;
 *(void **)(p+24)=*(void **)(owner+24);
 p[1]=owner[1];
 *(s16 *)(p+38)=8704;
 *(u32 *)(p+208)=*(u32 *)(owner+208);
 }
 return p;
}
