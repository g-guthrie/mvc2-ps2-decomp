typedef unsigned char u8;typedef signed char s8;typedef signed short s16;typedef unsigned int u32;typedef float f32;
struct S39; extern void func_0039E110(struct S39 *); extern void func_00191210(u8 *);
void func_00269320(u8 *p,void *context) {u8 *q=context; if (*(s8 *)(p+0x539)==0 || --*(s16 *)(q+8)<=0) { p[6]++;p[7]=0;p[0x216]|=0x80;p[0x1ff]=2;func_00191210(p); }}
void func_0039E080(u8 *p) {
 *(f32 *)(p+0x34)+=1.6666666269302368f*(f32)*(u32 *)(p+0x9c)/65536.0f;
 if (*(s8 *)(*(u8 **)(p+0x18)+0x15b)<0) {p[5]++;func_0039E110((struct S39 *)p);}
}
