typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0041DF20 */
extern void func_0041F900(void);
extern void func_0041DE10(void);
extern s32 D_004C2B78;
extern s32 D_004C2B7C;
s32 func_0041DF20(void) {
  func_0041F900();
  func_0041DE10();
  if (D_004C2B78 != -1 && D_004C2B7C != -1) return D_004C2B78 | (D_004C2B7C << 8);
  return 0;
}

