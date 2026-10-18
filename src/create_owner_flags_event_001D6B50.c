typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_003DA750(void *,int,int);
extern void func_001D6BC0(u8 *);
void func_001D6B50(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001D6BC0;
 *(u8 **)(p+24)=owner;
 p[32]=mode;
 *(s16 *)(p+38)=12032;
 *(u32 *)(p+208)=*(u16 *)(owner+360);
 }
}
