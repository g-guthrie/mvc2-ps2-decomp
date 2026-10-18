typedef unsigned char u8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_001D1BF0(u8 *);
void func_001D1B80(void *first,void *second,u8 mode){
 u8 *p=func_003DA750(0,3,1);
 if(p){
 *(s16 *)(p+38)=11008;
 p[32]=mode;
 *(void (**)(u8 *))(p+16)=func_001D1BF0;
 *(void **)(p+20)=first;
 *(void **)(p+24)=second;
 }
}
