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
s32 func_00418570(u8 *a, s32 b) {
 extern s32 func_003E8F90(void);
 extern void func_003F4740(Hdr *, u8 *);
 extern void func_003E8C00(Hdr *, s32, s32);
 extern s32 func_003DCFE0(s32, s32);
 extern u8 *func_003DD030(s32);
 extern u8 *func_003F4A00(u8 *);
 extern void func_003DD1D0(u8 *, s32, s32);
 extern void func_003E8DF0(s32, s32);
 u8 *dst;
 Hdr hd;
 s32 id;
 Slot *sl;
 u8 *src;
 s32 cnt;
 s32 len;
 s32 n;
 s32 t;
 s32 y;
 u8 *o;
 u8 *o2;
 s32 cnt2;
 id = func_003E8F90();
 sl = D_006207A0 + ((id & 0xFFFF) - 1);
 func_003F4740(&hd, a);
 if (hd.bpp != 3 && hd.bpp != 4) return 0;
 func_003E8C00(&hd, id, b);
 sl->f28 = func_003DCFE0(sl->f8, 2);
 dst = func_003DD030(sl->f28);
 src = func_003F4A00(a);
 for (y = 0; y < hd.h; y++) {
  cnt = 0;
  o = dst + y * hd.stride;
  while (cnt < hd.w) {
   t = *src++;
   if (t == 0x80) {
    len = (src[0] << 8) | src[1];
    cnt += len;
    n = len;
    while (n--) { o[0] = src[2]; o[1] = src[3]; o[2] = src[4]; o += hd.bpp; }
    src += 5;
   } else if (t > 0x80) {
    len = t - 0x7F;
    cnt += len;
    n = len;
    while (n--) { o[0] = src[0]; o[1] = src[1]; o[2] = src[2]; o += hd.bpp; }
    src += 3;
   } else {
    len = t + 1;
    cnt += len;
    n = len;
    while (n--) { o[0] = src[0]; o[1] = src[1]; o[2] = src[2]; src += 3; o += hd.bpp; }
   }
  }
  if (hd.bpp != 3) {
   cnt2 = 0;
   o2 = dst + y * hd.stride + 3;
   while (cnt2 < hd.w) {
    t = *src++;
    if (t == 0x80) {
     len = (src[0] << 8) | src[1];
     cnt2 += len;
     n = len;
     while (n--) { *o2 = src[2]; o2 += 4; }
     src += 3;
    } else if (t > 0x80) {
     len = t - 0x7F;
     cnt2 += len;
     n = len;
     while (n--) { *o2 = src[0]; o2 += 4; }
     src += 1;
    } else {
     len = t + 1;
     cnt2 += len;
     n = len;
     while (n--) { *o2 = *src; src++; o2 += 4; }
    }
   }
  }
 }
 if (hd.bpp == 4) {
  func_003DD1D0(func_003DD030(sl->f28), sl->h18, sl->h1a);
 }
 func_003E8DF0(id, b);
 return id;
}
