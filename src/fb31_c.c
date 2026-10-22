typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
extern u8 *D_004C2794;
extern f32 D_004599CC[];
extern f32 D_004599D0[];
extern f32 D_004599D4[];
extern u32 D_004C0DC4;
extern u32 D_004C0DC8;
extern u32 D_004C0DCC;
extern u32 D_004C0DDC;
extern u32 D_004C0DE0;
extern u32 D_004C0DE4;
void func_002C1010(u8 *p) {
 extern s32 func_00184110(f32);
 extern void func_001E3710(u8 *, s32);
 extern void func_001757E0(u8 *, s32, s32);
 u32 counterAddress;
 u32 t;
 s8 h;
 switch (p[0x1FC]) {
 case 0:
  if (func_00184110(D_004599CC[0])) {
   p[0x168] = 6;
   p[0x1B5] = 63;
   func_001E3710(p, 20);
  } else {
   p[0x168] = 0;
   p[0x1B5] = 15;
   func_001E3710(p, 20);
  }
  if (*(u16 *)(p + 0x20E) & 0x1000) {
   p[0x168] = 9;
   p[0x1FC] = 97;
   p[0x1B5] = 19;
  }
  if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C0DC4;
  else *(u32 **)(p + 0x408) = &D_004C0DDC;
  p[0x1BB] = 0;
  break;
 case 1:
  if (func_00184110(D_004599D0[0])) {
   p[0x168] = 7;
   p[0x1B5] = 64;
   func_001E3710(p, 21);
  } else {
   p[0x168] = 1;
   p[0x1B5] = 16;
   func_001E3710(p, 21);
  }
  if (*(u16 *)(p + 0x20E) & 0x1000) {
   p[0x168] = 10;
   p[0x1FC] = 98;
   p[0x1B5] = 20;
  }
  if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C0DC8;
  else *(u32 **)(p + 0x408) = &D_004C0DE0;
  p[0x1BB] = 1;
  break;
 case 2:
  if (func_00184110(D_004599D4[0])) {
   p[0x168] = 8;
   p[0x1B5] = 65;
   func_001E3710(p, 22);
  } else {
   p[0x168] = 2;
   p[0x1B5] = 17;
   func_001E3710(p, 22);
  }
  if (*(u16 *)(p + 0x20E) & 0x1000) {
   p[0x168] = 11;
   p[0x1FC] = 99;
   p[0x1B5] = 21;
  }
  if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004C0DCC;
  else *(u32 **)(p + 0x408) = &D_004C0DE4;
  p[0x1BB] = 2;
  break;
 default:
  break;
 }
 t = p[0x1B5];
 p[0x1B5] = t;
 p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
 *(u32 *)(p + 0x1D8) = 0;
 counterAddress = p[2] * 2;
 counterAddress += (u32)D_004C2794;
 counterAddress += 0x7c;
 ++*(s16 *)counterAddress;
 func_001757E0(p, 0xC, p[0x168]);
 h = p[0x1EA];
 if (h & 0xF0) p[0x1EA] = h - 0x10;
}
