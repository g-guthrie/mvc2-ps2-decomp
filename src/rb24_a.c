typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct { s32 f0; s32 w; s32 h; s32 stride; s32 f10; s32 bpp; s32 pad[14]; } Hdr;
typedef struct { u8 p0[8]; s32 f8; u8 pc[0xC]; s16 h18; s16 h1a; u8 p1c[0xC]; s32 f28; u8 p2c[0x14]; } Slot;
extern Slot D_006207A0[];
s32 func_00418410(u8 *a, s32 b) {
 extern s32 func_003E8F90(void);
 extern void func_003F3770(Hdr *, u8 *);
 extern void func_003E8C00(Hdr *, s32, s32);
 extern s32 func_003DCFE0(s32, s32);
 extern u8 *func_003DD030(s32);
 extern u8 *func_003F3850(u8 *);
 extern void func_003E8DF0(s32, s32);
 u8 *dst;
 Hdr hd;
 Slot *sl;
 s32 id;
 u8 r, g, bl;
 u8 *src;
 s32 x, y;
 u8 *o;
 id = func_003E8F90();
 sl = D_006207A0 + ((id & 0xFFFF) - 1);
 func_003F3770(&hd, a);
 if (hd.bpp != 3) return 0;
 func_003E8C00(&hd, id, b);
 sl->f28 = func_003DCFE0(sl->f8, 2);
 dst = func_003DD030(sl->f28);
 src = func_003F3850(a);
 switch (hd.bpp) {
 case 3:
  o = dst;
  for (y = 0; y < hd.h; y++) {
   for (x = 0; x < hd.w; x++) {
    r = src[0]; g = src[1]; bl = src[2]; o[0] = bl; o[1] = g; o[2] = r; src += 3; o += 3;
   }
  }
  break;
 default:
  return 0;
 }
 func_003E8DF0(id, b);
 return id;
}
