/* Native callers 0x0014D84C..0x0014D8D4 pass A0..A3 plus depth in F12. */
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef union {float value;u32 bits;} FloatBits;
extern void *func_003DA750(void *,int,int);
extern void func_0014DA80(u8 *);
void func_0014D9E0(u8 *owner,u32 resource,int index,int initialize,float depth){
 u8 *p=func_003DA750(0,13,initialize);
 if(p){
 p[316]=1;
 *(void (**)(u8 *))(p+16)=func_0014DA80;
 *(s16 *)(p+204)=index;
 *(u32 *)(p+132)=resource;
 *(u32 *)(p+208)=1;
 *(float *)(p+60)=depth;
 *(u8 **)(p+200)=owner+136;
 if(index>=12)((FloatBits *)(p+56))->bits=0xBD75C28F;
 }
}
