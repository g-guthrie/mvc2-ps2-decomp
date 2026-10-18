typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_00197920(u8 *);
extern void func_001B6830(u8 *);
void func_001978B0(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,1);
 if(p){
 *(void (**)(u8 *))(p+16)=func_00197920;
 *(u8 **)(p+24)=owner;
 p[1]=owner[1];
 p[32]=mode;
 *(s16 *)(p+38)=771;
 }
}

void func_001B6750(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001B6830;
 *(u8 **)(p+24)=owner;
 p[32]=mode;
 p[1]=owner[1];
 *(s16 *)(p+38)=5377;
 }
}
