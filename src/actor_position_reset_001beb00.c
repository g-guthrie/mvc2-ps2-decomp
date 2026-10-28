/* Provisional: modes 1 and 2 read beyond this two-float owner. Retail uses
 * three adjacent pairs, currently split across data owners. Dispatcher bounds,
 * callback ABI and owner lifetime also remain unresolved. */
typedef unsigned char u8; typedef float f32;
typedef struct { f32 x,y,z; } V3;
extern f32 data_u32_0044C470[2];
extern void func_001BEB60(u8 *, u8 *);
void func_001BEB00(u8 *p,u8 *q) {
 p[5]++;
 *(V3 *)(p+0x34)=*(V3 *)(p+0x5c);
 *(f32 *)(p+0x50)=data_u32_0044C470[p[0x20]*2];
 *(f32 *)(p+0x54)=data_u32_0044C470[p[0x20]*2+1];
 func_001BEB60(p,q);
}
