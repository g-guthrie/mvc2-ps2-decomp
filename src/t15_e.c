typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O_001BF3B0 { u8 pad0[0x10]; void *f10; u32 pad14; void *f18; u8 pad1c[4]; u8 b20; u8 pad21[2]; u8 b23; u8 pad24[2]; s16 s26; } O_001BF3B0;
extern O_001BF3B0 *func_003DA750(void *, s32, s32);
extern void func_001BF460(void);
void func_001BF3B0(void *p) {
  s8 i;
  s8 n = 0;
  O_001BF3B0 *o;
  for (i = 0; i < 12; i++) {
    if ((o = func_003DA750(p, 3, 2)) != 0) {
      o->f10 = (void *)func_001BF460;
      o->b20 = 1;
      o->f18 = p;
      o->s26 = 0x1901;
      o->b23 = n;
      n++;
    }
  }
}

