typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_001D37D0(u8 *);
void func_001D36E0(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001D37D0;
 p[32]=mode;p[33]=0;
 *(u8 **)(p+24)=owner;
 p[1]=owner[1];
 *(s16 *)(p+38)=11265;
 }
}
