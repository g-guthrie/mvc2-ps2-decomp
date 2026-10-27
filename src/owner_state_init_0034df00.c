/* Provisional: state-table bounds and callback ownership require proof. */
typedef unsigned char u8;typedef float f32;
extern void func_0034DD60(u8 *,u8);
extern int func_001757E0(u8 *,int,int);
void func_0034DF00(u8 *p){
 u8 *q=*(u8 **)(p+0x14);
 p[0x24]=0;
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
 *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
 func_0034DD60(p,1);
 func_001757E0(p,23,7);
}
