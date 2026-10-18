typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_001CBD00(u8 *);
void func_001CB610(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001CBD00;
 p[32]=mode;p[33]=0;
 *(u8 **)(p+24)=owner;
 p[1]=owner[1];
 *(s16 *)(p+38)=7939;
 *(u32 *)(p+212)=*(u16 *)(owner+360);
 }
}
