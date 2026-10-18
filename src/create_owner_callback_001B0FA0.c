typedef unsigned char u8;
extern void *func_003DA750(void *,int,int);
extern void func_001B1000(u8 *);
void func_001B0FA0(u8 *owner,u8 mode){
 u8 *p=func_003DA750(0,3,0);
 if(p){
 *(void (**)(u8 *))(p+16)=func_001B1000;
 *(void **)(p+24)=*(void **)(owner+24);
 *(u8 **)(p+20)=owner;
 p[32]=mode;
 }
}

extern void func_0036C120(u8 *);
void func_0036C050(u8 *owner, u8 mode)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p) {
        *(void (**)(u8 *))(p + 16) = func_0036C120;
        *(void **)(p + 24) = *(void **)(owner + 24);
        *(u8 **)(p + 20) = owner;
        p[32] = mode;
    }
}
