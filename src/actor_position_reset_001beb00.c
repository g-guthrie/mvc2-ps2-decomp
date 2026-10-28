/* Phase 0 of the jtbl_004BF9B0 dispatch (func_001BEAE0 passes p, owner):
 * restore the position, load the per-mode scale pair, then run phase 1. */
typedef unsigned char u8; typedef float f32;
typedef struct { f32 x,y,z; } V3;
extern f32 data_u32_0044C470[3][2];
extern void func_001BEB60(u8 *p, u8 *q);
void func_001BEB00(u8 *p,u8 *q) {
 p[5]++;
 *(V3 *)(p+0x34)=*(V3 *)(p+0x5c);
 *(f32 *)(p+0x50)=data_u32_0044C470[p[0x20]][0];
 *(f32 *)(p+0x54)=data_u32_0044C470[p[0x20]][1];
 func_001BEB60(p,q);
}
