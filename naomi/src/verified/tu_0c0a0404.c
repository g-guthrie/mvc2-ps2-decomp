#include "objects.h"
typedef void (*ActorCallback)(struct Actor *);
extern ActorCallback table_0c243938[], table_0c243940[], table_0c243948[],
    table_0c243974[], table_0c24397c[], table_0c243984[], table_0c243990[],
    table_0c24399c[], table_0c2439d8[], table_0c243a00[];
extern unsigned char dat_0c2439b8[];
extern float dat_0c2437a4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c2d92e8, dat_0c2d92ec;
extern char func_0c02a026(struct Actor *);
extern int func_0c03916c(struct Actor *), func_0c02849a(void),
    func_0c043628(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int),
    func_0c02a39a(struct Actor *, int), func_0c19ee9c(struct Actor *, int),
    func_0c048bb0(struct Actor *, short);
extern void func_0c043324(struct Actor *), func_0c0437b8(struct Actor *),
    func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
void func_0c0a0526(struct Actor *), func_0c0a09ea(struct Actor *),
    func_0c0a0b88(struct Actor *);
void func_0c0a0404(struct Actor *a) {
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
  if (a->f56 < a->f41c) {
    a->b7++;
    func_0c043324(a);
    a->b1f9 = 0;
    a->f52 = a->f92;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 18, 2);
  }
}
void func_0c0a046e(struct Actor *a) {
  if ((char)a->b141 == 1) {
    a->b141 = 0;
    func_0c19ee9c(a, 5);
  }
  if (func_0c02a026(a) < 0)
    a->b5++;
}
void func_0c0a04a2(struct Actor *a) { table_0c243938[a->b7](a); }
void func_0c0a04b4(struct Actor *a) {
  a->b7++;
  func_0c02a0c4(a, 18, 3);
}
void func_0c0a04c2(struct Actor *a) {
  if ((char)a->b141 == 1) {
    a->b141 = 0;
    func_0c19ee9c(a, 5);
  }
  if (func_0c02a026(a) < 0)
    a->b5++;
}
void func_0c0a04f6(struct Actor *a) { table_0c243940[a->b6](a); }
void func_0c0a0508(struct Actor *a) {
  a->b6++;
  if (!a->b32)
    func_0c0a09ea(a);
  func_0c0a0526(a);
}
void func_0c0a0526(struct Actor *a) {
  if (func_0c03916c(a))
    func_0c0437b8(a);
  else
    table_0c243948[a->b32](a);
}
void func_0c0a0578(struct Actor *a) { table_0c243974[a->b7](a); }
void func_0c0a058a(struct Actor *a) {
  a->b7++;
  func_0c02a39a(a, 0);
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->f56 = a->f41c;
  a->b1fc = 0;
  a->b1f9 = 0;
  func_0c02a0c4(a, 19, 6);
}
void func_0c0a05d0(struct Actor *a) { func_0c02a026(a); }
void func_0c0a05d6(struct Actor *a) { table_0c24397c[a->b7](a); }
void func_0c0a05e8(struct Actor *a) {
  a->b7++;
  func_0c02a39a(a, 0);
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->f56 = a->f41c;
  a->b1fc = 0;
  a->b1f9 = 0;
  func_0c02a0c4(a, 19, 4);
}
void func_0c0a062e(struct Actor *a) { func_0c02a026(a); }
void func_0c0a0634(struct Actor *a) { table_0c243984[a->b7](a); }
void func_0c0a0646(struct Actor *a) {
  a->b7++;
  func_0c02a39a(a, 0);
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->f56 = a->f41c;
  a->b1fc = 0;
  a->b1f9 = 0;
  func_0c19ee9c(a, 9);
  func_0c19ee9c(a, 6);
  func_0c02a0c4(a, 19, 4);
}
void func_0c0a069c(struct Actor *a) {
  if (a->b143 < 0) {
    a->b7++;
    func_0c02a0c4(a, 19, 5);
  }
  func_0c02a026(a);
}
void func_0c0a06c4(struct Actor *a) { func_0c02a026(a); }
void func_0c0a06f0(struct Actor *a) { table_0c243990[a->b7](a); }
void func_0c0a0702(struct Actor *a) {
  a->b7++;
  func_0c02a39a(a, 0);
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->f56 = a->f41c;
  a->b1fc = 0;
  a->b1f9 = 0;
  func_0c19ee9c(a, 9);
  func_0c19ee9c(a, 7);
  func_0c02a0c4(a, 19, 4);
}
void func_0c0a0758(struct Actor *a) {
  if (a->b143 < 0) {
    a->b7++;
    func_0c02a0c4(a, 19, 5);
  }
  func_0c02a026(a);
}
void func_0c0a0780(struct Actor *a) { func_0c02a026(a); }
void func_0c0a0786(struct Actor *a) { table_0c24399c[a->b7](a); }
void func_0c0a0798(struct Actor *a) {
  a->b7++;
  func_0c02a39a(a, 0);
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->f56 = a->f41c;
  a->b1fc = 0;
  a->b1f9 = 0;
  func_0c19ee9c(a, 9);
  func_0c19ee9c(a, 8);
  func_0c02a0c4(a, 19, 4);
}
void func_0c0a07ee(struct Actor *a) {
  if (a->b143 < 0) {
    a->b7++;
    func_0c02a0c4(a, 19, 5);
  }
  func_0c02a026(a);
}
void func_0c0a0816(struct Actor *a) { func_0c02a026(a); }
void func_0c0a083c(struct Actor *a) {
  a->b7++;
  func_0c02a39a(a, 0);
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->f56 = a->f41c;
  a->b1f9 = (((char *)a)[0x1fc] = 0);
  if (a->b1d2)
    a->f92 = -26.666666031f;
  else
    a->f92 = 26.666666031f;
  a->f96 = 8.5714283f;
  a->f108 = 0.016741071f;
  a->s28 = 90;
  func_0c02a0c4(a, 19, 0);
}
void func_0c0a08ae(struct Actor *a) {
  if (a->s28-- == 0) {
    a->b7++;
    a->f52 = a->w130 ? (dat_0c2d92e8 + (-96.0f)) : (dat_0c2d92ec + 96.0f);
    func_0c19ee9c(a, 2);
    func_0c19ee9c(a, 3);
    func_0c19ee9c(a, 4);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1fc = 0;
    a->b1f9 = 0;
    a->s28 = 120;
    func_0c02a0c4(a, 19, 1);
    return;
  }
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
}
void func_0c0a097a(struct Actor *a) {
  a->f52 += a->w130 ? 18 : -18;
  if (a->s28-- == 0)
    a->b7++;
}
void func_0c0a09e4(struct Actor *a) { func_0c02a026(a); }
void func_0c0a09ea(struct Actor *a) {
  if (a->w340 & 0x3f0) {
    if (a->w340 & 0x200)
      a->b32 = (unsigned char)5;
    else if (a->w340 & 0x100)
      a->b32 = (unsigned char)6;
    else if (a->w340 & 0x80)
      a->b32 = 7;
    else if (a->w340 & 0x40)
      a->b32 = 8;
    else if (a->w340 & 0x20)
      a->b32 = 9;
    else
      a->b32 = 10;
  } else
    a->b32 = dat_0c2439b8[(func_0c02849a() & 15) * 2];
  if (func_0c043628(a) > 1)
    a->b32 = 5;
}
void func_0c0a0a72(struct Actor *a) { table_0c2439d8[a->b1e9](a); }
void func_0c0a0a86(struct Actor *a) { table_0c243a00[a->b6](a); }
void func_0c0a0a98(struct Actor *a) {
  a->b6++;
  if (a->b255 == 3)
    a->b1a1 = 84;
  else {
    goto L; L: a->b1a1 = a->b1a3 + 48; }
  a->w1ac = 0;
  a->b19e = 0;
  a->p1c4 = 0;
  dat_0c2f83f8->arr[a->b2]++;
  goto M; M:
  func_0c048bb0(a, 5);
  func_0c0442fa(a);
  a->b1f9 = 0;
  func_0c0432ca(a);
  func_0c02a0c4(a, 21, a->b1a3);
}
void func_0c0a0b32(struct Actor *a) {
  float *motion = dat_0c2437a4;
  a->b6++;
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  motion += (unsigned char)a->b1a3 * 2;
  if (a->b1d2)
    a->f92 = -motion[0];
  else
    a->f92 = motion[0];
  if (a->b1d2)
    a->f104 = -((struct ActorVec2 *)motion)->y;
  else
    a->f104 = ((struct ActorVec2 *)motion)->y;
  a->s28 = 0;
  func_0c0a0b88(a);
}
void func_0c0a0b88(struct Actor *a) {
next:
  func_0c02a026(a);
  if ((char)a->b141 == 1) {
    a->b6++;
    goto next;
  }
  if (!a->b411 && (char)a->b141 == 2) {
    func_0c19ee9c(a, 1);
    a->s28++;
    a->b141 = 0;
  }
  if (a->f92 * a->f104 < 0.0f) {
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
  }
}
