typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; } O_0028A490;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad1[0x1E6-0x38]; u8 b1e6; u8 pad2[0x220-0x1E7]; O_0028A490 *o; } P_0028A490;
static s32 func_0028A490(P_0028A490 *p) {
  u8 b = p->b1e6;
  O_0028A490 *o = p->o;
  if ((b == 0 && p->f34 < o->f34) || (b != 0 && p->f34 > o->f34)) return 1;
  return 0;
}

void func_0028AE00(u8 *a, u8 *b)
{
    extern void func_0028A530(u8 *, u8 *);
    extern void func_0028B0B0(u8 *, u8 *);
    s16 v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) {
        if (func_0028A490((P_0028A490 *)a)) {
            a[7] = 6;
            b[0x18] = 0;
            func_0028A530(a, b);
        } else {
            func_0028B0B0(a, b);
        }
    }
}
