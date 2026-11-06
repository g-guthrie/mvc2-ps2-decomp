/* Candidate (1280/1284): func_0c08755c keeps the 0x0c2f8338 pointer in r6 (retail r3), and func_0c0875ce schedules add #8 between the two shll2 of b37<<4 (retail after both). Everything else exact. */
#include "objects.h"
typedef void (*ActorCallback)(struct Actor *);
extern ActorCallback table_0c242418[], table_0c242424[], table_0c242430[],
    table_0c24243c[];
extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char dat_0c2f8338[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *), func_0c02a39a(struct Actor *, int),
    func_0c02a0c4(struct Actor *, int, int),
    func_0c02a684(struct Actor *, int, int, int),
    func_0c195384(struct Actor *, int);
void func_0c087838(struct Actor *);
void func_0c0873c4(struct Actor *a) {
  a->b6++;
  a->f92 = 15.83333302f;
  a->f104 = -0.3125f;
  a->f96 = 6.428571224213f;
  a->f108 = -0.5357143f;
  if (a->w130) {
    a->f92 = -a->f92;
    a->f104 = -a->f104;
  }
}
void func_0c087406(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
  if (a->f56 <= a->f41c) {
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 2, 3);
  }
}
void func_0c087490(struct Actor *a) {
  if (func_0c02a026(a) < 0)
    func_0c0437b8(a);
}
void func_0c0874b2(struct Actor *a) { table_0c242418[a->b32](a); }
void func_0c0874c6(struct Actor *a) {
  func_0c02a39a(a, 0);
  if (((unsigned char *)dat_0c2d6f84)[139]) {
    a->b32 = 2;
    if (dat_0c2d6f84->b_a5 & (1 << (a->b524 & 1)))
      goto set_one;
  } else {
    a->b32 = 2;
    if (a->b525) {
    set_one:
      a->b32 = 1;
    }
  }
}
void func_0c08754a(struct Actor *a) { table_0c242424[a->b6](a); }
void func_0c08755c(struct Actor *a) {
  int zero = 0;
  float movement;
  unsigned int state = (unsigned int)dat_0c2f8338;
  a->b12c = zero;
  if (*(unsigned char *)state == 2) {
    a->b6++;
    a->b7 = zero;
    a->b12c = 1;
    a->s28 = zero;
    a->s30 = 3;
    movement = 71.666664124f;
    if (!a->b1d2)
      movement = -71.666664124f;
    a->f52 += movement;
    a->f96 = -12.3214283f;
    a->f108 = 0.2678571343422f;
    func_0c02a0c4(a, 18, 0);
  }
}
void func_0c0875bc(struct Actor *a) { table_0c242430[a->b7](a); }
void func_0c0875ce(struct Actor *a) {
  if (func_0c02a026(a) >= 0) {
    if (--a->s30 == 0) {
      a->s30 = 3;
      func_0c02a39a(a, 1);
    } else
      func_0c02a684(a, 1, (a->b37 << 4) + (int)(a->s28 + 8U), 1);
    a->s28 = (a->s28 + 1) % 3;
    a->b12c = dat_0c2d6f84->flags & 1;
  } else {
    a->b7++;
    a->b12c = 1;
    a->s28 = 0;
    a->s30 = 1;
    a->f56 += 308.571411133f;
    func_0c195384(a, 0);
    func_0c087838(a);
    func_0c02a0c4(a, 18, 1);
  }
}
void func_0c0876b0(struct Actor *a) {
  func_0c02a026(a);
  if (a->b141)
    func_0c087838(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (a->f96 * a->f108 >= 0.0f) {
    a->b7++;
    a->f92 = -1.66666663f;
    a->f104 = 0.0f;
    a->f96 = 10.714285f;
    a->f108 = -0.5357143f;
    if (!a->b1d2)
      a->f92 = -a->f92;
    func_0c02a0c4(a, 18, 2);
  }
}
void func_0c087778(struct Actor *a) {
  func_0c02a026(a);
  if (a->b141) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
      a->b6++;
      a->b7 = 0;
      a->f56 = a->f41c;
      a->b1f9 = 0;
      func_0c02a0c4(a, 18, 3);
    }
  }
}
void func_0c0877fc(struct Actor *a) {
  if (func_0c02a026(a) < 0) {
    a->b5++;
    a->b32 = (((char *)a)[6] = 0);
    func_0c02a39a(a, 0);
    func_0c02a0c4(a, 0, 0);
  }
}
void func_0c087838(struct Actor *a) {
  if (--a->s30 == 0) {
    a->s30 = 3;
    if (a->s28 == 8) {
      func_0c02a39a(a, 1);
      return;
    }
    {
      int value;
      goto animate;
animate:
      value = (a->b37 << 4);
      func_0c02a684(a, 0, value + a->s28, 1);
      a->s28++;
    }
  }
}
void func_0c08788e(struct Actor *a) { table_0c24243c[a->b6](a); }
void func_0c0878a0(struct Actor *a) {
  a->b6++;
  func_0c02a0c4(a, 18, 4);
}
