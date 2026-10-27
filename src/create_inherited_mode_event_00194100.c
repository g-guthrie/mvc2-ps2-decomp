typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern void *func_003DA750(void *,int,int);
extern void func_00194170(u8 *);
void *func_00194100(u8 *owner){
 u8 *p=func_003DA750(owner,3,3);
 if(p){
 *(void (**)(u8 *))(p+16)=func_00194170;
 *(void **)(p+24)=*(void **)(owner+24);
 *(u8 **)(p+20)=owner;
 p[1]=owner[1];p[32]=1;
 p[33]=(s8)owner[33]+1;
 *(s16 *)(p+38)=769;
 }
    return p;
}
