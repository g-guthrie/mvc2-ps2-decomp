typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; } O_0028A490;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad1[0x1E6-0x38]; u8 b1e6; u8 pad2[0x220-0x1E7]; O_0028A490 *o; } P_0028A490;
s32 func_0028A490(P_0028A490 *p) {
  u8 b = p->b1e6;
  O_0028A490 *o = p->o;
  if ((b == 0 && p->f34 < o->f34) || (b != 0 && p->f34 > o->f34)) return 1;
  return 0;
}

