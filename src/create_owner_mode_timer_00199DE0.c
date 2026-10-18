typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_00199E50(u8 *);
void func_00199DE0(void *owner,u8 mode,s16 timer){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_00199E50;
 *(void **)(p+24)=owner;
 p[33]=mode;
 *(s16 *)(p+28)=timer;
 *(s16 *)(p+38)=1282;
 }
}
