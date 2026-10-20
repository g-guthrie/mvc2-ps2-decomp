typedef unsigned char u8;
typedef float f32;
extern f32 D_004F1FC8,D_004F1FCC;
void func_0023E0B0(u8 *p, u8 *context) {
 f32 limit;
 limit=D_004F1FC8+160.0f/3.0f;
 if(!(limit<=*(f32 *)(p+0x34))) *(f32 *)(p+0x34)=limit;
 limit=D_004F1FCC-160.0f/3.0f;
 if(limit<*(f32 *)(p+0x34)) *(f32 *)(p+0x34)=limit;
}
