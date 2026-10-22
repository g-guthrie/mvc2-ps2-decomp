typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G_a;
extern G_a *D_004C2794;
extern f32 D_00464910[];
extern f32 D_00464914[];
void func_00386B00(u8 *p, u8 *q) {
 extern void func_00386570(u8 *, u8 *);
 extern s32 func_003870C0(u8 *, u8 *);
 extern void func_001548D0(u8 *, f32 *, s32);
 extern void func_001E3210(u8 *, s32);
 extern void func_00175700(u8 *);
 extern void func_001E7F60(u8 *);
 extern void func_00386F30(u8 *, u8 *);
 s16 c;
 s16 h;
 if (q[0x2BC] != 0 || ((s8 *)p)[0x1B3] != 0) { func_00386570(p, q); return; }
 if (((s8 *)p)[0x1B2] != 0) { if (p[0x21] < 3) p[0x21] = 2; }
 *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
 *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
 *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
 *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
 c = *(s16 *)(p + 0x1C);
 if (c != 0) {
  *(s16 *)(p + 0x1C) = c - 1;
 } else if (q[0x169] == 0xC) {
  f32 v[3];
  if (func_003870C0(p, q) != 0) {
   p[0x21]++;
   *(s16 *)(p + 0x1C) = 8;
   *(f32 *)(p + 0x5C) = D_00464910[q[0x1B7] * 2];
   *(f32 *)(p + 0x60) = D_00464914[q[0x1B7] * 2];
   *(f32 *)(p + 0x68) = 0;
   *(f32 *)(p + 0x6C) = 0;
   h = *(s16 *)(q + 0x140);
   *(s16 *)(p + 0x140) = h;
   if (h != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
   v[2] = 0; v[1] = 0; v[0] = 0;
   func_001548D0(p, v, 0);
   func_001E3210(p, 0x1F);
   p[0x1B5] = 0x39;
   p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
   *(s32 *)(p + 0x1D8) = 0;
   D_004C2794->f7c[p[2]]++;
   if (p[0x21] >= 3) {
    p[5]++;
    func_00175700(p);
    func_001E7F60(p);
    return;
   }
  }
 }
 func_00386F30(p, q);
 if (p[0x21] >= 3) p[5]++;
 func_00175700(p);
 func_001E7F60(p);
}
