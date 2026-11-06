#include "objects.h"
extern void func_0c04bfe0(struct Actor *), func_0c04ac78(struct Actor *),
    func_0c04a730(struct Actor *), func_0c03484c(struct Actor *),
    func_0c1d8eb4(struct Actor *), func_0c03cbee(struct Actor *),
    func_0c034922(struct Actor *), func_0c04ad38(struct Actor *),
    func_0c040b08(struct Actor *), func_0c040b3a(struct Actor *),
    func_0c043248(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern int func_0c04daae(struct Actor *, int, int);
extern void func_0c02a0c4(struct Actor *, int, int),
    func_0c0453c4(struct Actor *, int),
    func_0c1d1622(struct LinkedActorVec3 *, int),
    func_0c1be360(struct Actor *, unsigned short);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c23bb64[])(struct Actor *);
void func_0c03e56a(struct Actor *), func_0c03e832(struct Actor *),
    func_0c03e94c(struct Actor *);
void func_0c03e440(struct Actor *a) {
  a->b6++;
  a->b23a++;
  a->b238 = 0;
  func_0c04bfe0(a);
  a->p1bc = a->p1c8->p174 + ((a->b1a1 & 127) * 28);
  func_0c04ac78(a);
  {
    unsigned char one = 1;
    if (((struct AnimationFrame20 *)a->p1bc)->event & 32)
      a->b235 = one;
    a->b239 = a->b232;
    a->w130 = a->b1d2;
    a->b1f9 = 2;
    a->b22e = (a->b22e + 8) & 16;
    a->b158 = a->b22e ? 29 : 28;
    a->b12c = one;
    a->i72 = 0;
    *(struct LinkedActorVec3 *)&a->f80 =
        *(struct LinkedActorVec3 *)((unsigned char *)a + 0x284);
    a->f264 = 1.0f;
    func_0c02a0c4(a, 13, a->b158);
    func_0c04a730(a);
    a->f92 = a->f218;
    a->f96 = a->f21c;
    a->f108 = -1.2053571f;
    if (!(a->f96 > 0))
      a->s28 = 1;
    else
      a->s28 = 0;
    func_0c03e56a(a);
  }
}
void func_0c03e56a(struct Actor *a) {
  func_0c02a026(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (a->b1fd && !a->b238) {
    a->b238 = 1;
    func_0c03484c(a);
    func_0c1d8eb4(a);
    if (a->b235) {
      {
        int kind = a->b207 < 5 ? 1 : 3;
        dat_0c2d9260.b5 = kind;
      }
      dat_0c2d9260.b6 = 1;
    }
  }
  if (!a->s28 && a->f96 <= 0) {
    func_0c02a0c4(a, 13, 29);
    a->s28 = 1;
  }
  if (a->b233 != 2 && --a->b239 < 0 && a->w420) {
    a->b6 = 3;
    ((char *)&a->b1d6)[0] = -1;
    a->b1fc = 1;
    func_0c02a0c4(a, 13, 30);
    func_0c03cbee(a);
    return;
  }
  if (a->f96 <= 0 && func_0c044e52(a)) {
    a->b1eb = 2;
    a->s278 = 5;
    a->b6++;
    a->b1f9 = 3;
    func_0c02a0c4(a, 13, 26);
  }
}
void func_0c03e6c4(struct Actor *a) {
  int value;
  a->b1eb = 2;
  if ((value = a->s278) >= 0) {
  if ((short)a->w420 > 0 && value > 0)
    goto animate;
  a->s278 = -1;
  func_0c034922(a);
  func_0c1d1622((struct LinkedActorVec3 *)&a->f52, a->b2);
  if (a->b233 != 1) {
    value = a->b207;
    value = value < 5 ? 1 : 3;
    dat_0c2d9260.b5 = value;
    dat_0c2d9260.b6 = 1;
  }
  if (a->b235 || !a->w420 || !a->b236)
    goto animate;
  if (a->b525) {
    if (func_0c04daae(a, 29, 2))
      *(char *)&a->b236 = -1;
    else
      *(char *)&a->b236 = 0;
  }
  if ((char)a->b236 < 0) {
    a->b1d3 = 0;
    func_0c0453c4(a, 17);
    return;
  }
  }
animate:
  if (func_0c02a026(a) < 0)
    func_0c0453c4(a, 23);
}
void func_0c03e7c6(struct Actor *a) { table_0c23bb64[a->b6](a); }
void func_0c03e7d8(struct Actor *a) {
  a->b6++;
  a->b1ed = 2;
  a->w130 = a->b1d2;
  a->b1f9 = 2;
  a->s28 = 7;
  a->s30 = 0;
  a->b12c = 1;
  a->i72 = 0;
  *(struct LinkedActorVec3 *)&a->f80 =
      *(struct LinkedActorVec3 *)((unsigned char *)a + 0x284);
  a->f264 = 1.0f;
  func_0c02a0c4(a, 13, 16);
  func_0c03e832(a);
}
void func_0c03e832(struct Actor *a) {
  a->b1ed = 2;
  func_0c043248(a);
  if (--a->s30 < 0) {
    if (a->s28) {
      func_0c1be360(a, a->s28 & 3);
      a->s30 = 2;
      if (!--a->s28)
        a->s30 = 10;
    } else {
      a->b6++;
      a->p1bc = a->p1c8->p174 + ((a->b1a1 & 127) * 28);
      func_0c04ad38(a);
      if (((struct AnimationFrame20 *)a->p1bc)->event & 32)
        a->b235 = (unsigned char)1;
      a->b239 = a->b232;
      a->w130 = a->b1d2;
      func_0c040b08(a);
      func_0c04a730(a);
      a->f108 = -1.2053571f;
      a->f92 = a->f218;
      a->f96 = a->f21c;
      a->s28 = 0;
      func_0c03e94c(a);
    }
  }
}
void func_0c03e94c(struct Actor *a) {
  func_0c02a026(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (a->b1fd && !a->b238) {
    a->b238 = 1;
    func_0c03484c(a);
    func_0c1d8eb4(a);
    if (a->b235) {
    }
  }
  if (!a->s28 && a->f96 <= 0) {
    a->s28 = 1;
    func_0c040b3a(a);
  }
  if (a->b233 != 2 && --a->b239 < 0 && a->w420) {
    a->b6 = 4;
    ((char *)&a->b1d6)[0] = -1;
    a->b1fc = 1;
    func_0c02a0c4(a, 13, 30);
    func_0c03cbee(a);
    return;
  }
  if (a->f96 <= 0 && func_0c044e52(a)) {
    a->b1eb = 2;
    a->s278 = 5;
    a->b6++;
    a->b1f9 = 3;
    func_0c02a0c4(a, 13, 26);
  }
}
