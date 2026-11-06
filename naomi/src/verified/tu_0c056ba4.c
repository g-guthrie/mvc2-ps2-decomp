/* One retail unit 0x0c056ba4-0x0c057490 (bsr into func_0c056bb8 from 0x0c056f60/0x0c057216/0x0c05734e ties it together). */
#include "objects.h"
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern void (*table_0c23f6c0[])(struct Actor *);
extern void (*table_0c23f718[])(struct Actor *);
extern void (*table_0c23f720[])(struct Actor *);
extern void (*table_0c23f728[])(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, short, short);
extern void func_0c043352(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c23f730[])(struct Actor *);
extern void (*table_0c23f738[])(struct Actor *);
extern void (*table_0c23f740[])(struct Actor *);
extern void (*table_0c23f748[])(struct Actor *);
extern void (*table_0c23f75c[])(struct Actor *);
extern void (*table_0c23f764[])(struct Actor *);
extern short table_0c23f750[][2];
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c131ff0(struct Actor *);
extern struct Actor *func_0c037da4(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c044548(struct Actor *, struct Actor *);
void func_0c056bb8(struct Actor *a);

void func_0c056ba4(struct Actor *a) { table_0c23f6c0[a->b1e9](a); }
void func_0c056bb8(struct Actor *a) {
  a->f92 = 0.0f;
  a->f96 = 0.0f;
  a->f104 = 0.0f;
  a->f108 = 0.0f;
  a->b1fc = 0;
  a->b1f9 = 0;
  a->f56 = a->f41c;
  func_0c0442fa(a);
  func_0c0432ca(a);
}
void func_0c056bf2(struct Actor *a) { table_0c23f718[a->b6](a); }
void func_0c056c04(struct Actor *a) { table_0c23f720[a->b7](a); }
void func_0c056c16(struct Actor *a) {
  a->b7++;
  a->b1a1 = 50;
  a->w1ac = 0;
  a->b19e = 0;
  a->p1c4 = 0;
  dat_0c2f83f8->w7c[a->b2]++;
  func_0c048bb0(a, 8);
  func_0c056bb8(a);
  func_0c0344a0(a, 3);
  func_0c02a0c4(a, 21, 0);
}
void func_0c056c6a(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  func_0c043352(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  if (func_0c02a026(a) < 0) {
    func_0c0437b8(a);
    return;
  }
  if (a->b140) {
    a->b1a1 = a->b140;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    a->b140 = 0;
  }
  if (a->b141) {
    if (a->b525) {
      if (*(unsigned short *)sub & 0x800)
        goto left;
      else if (*(unsigned short *)sub & 0x400)
        goto right;
    } else if (a->w340 & 0xc00) {
      if (a->w340 & 0x800) {
      left:
        a->f92 = -3.3333333f;
      } else if (a->w340 & 0x400) {
      right:
        a->f92 = 3.3333333f;
      }
      return;
    }
  }
  a->f92 = 0.0f;
}
void func_0c056d78(struct Actor *a) { table_0c23f728[a->b7](a); }
void func_0c056da8(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  a->b7++;
  a->b1a1 = 52;
  a->w1ac = 0;
  a->b19e = 0;
  a->p1c4 = 0;
  dat_0c2f83f8->w7c[a->b2]++;
  func_0c048bb0(a, 8);
  func_0c0442fa(a);
  a->f96 = 6.428571224213f;
  a->f108 = -0.80357140303f;
  a->f104 = 0.0f;
  func_0c02a0c4(a, 21, 1);
  a->f92 = 3.3333333f;
  if (a->w130) {
    a->f92 = -a->f92;
    if (a->b525) {
      if (!(*(unsigned short *)sub & 0x800))
        goto neg;
      return;
    }
    goto t1; t1: if (a->w340 & 0x800)
      return;
    goto neg;
  }
  if (a->b525) {
    if (*(unsigned short *)sub & 0x400)
      return;
  } else { goto t2; t2: if (a->w340 & 0x400)
    return; }
neg:
  a->f92 = -a->f92;
}
void func_0c056e7a(struct Actor *a) {
  if (func_0c044e52(a)) {
    func_0c044f1c(a);
    return;
  }
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
}
void func_0c056f0a(struct Actor *a) { table_0c23f730[a->b6](a); }
void func_0c056f1c(struct Actor *a) { table_0c23f738[a->b7](a); }
void func_0c056f2e(struct Actor *a) {
  a->b7++;
  a->b1a1 = 51;
  a->w1ac = 0;
  a->b19e = 0;
  a->p1c4 = 0;
  dat_0c2f83f8->w7c[a->b2]++;
  func_0c056bb8(a);
  func_0c048bb0(a, 8);
  func_0c0344a0(a, 3);
  func_0c02a0c4(a, 21, 2);
}
void func_0c056f82(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  func_0c043352(a);
  a->f52 += a->f92;
  a->f92 += a->f104;
  if (func_0c02a026(a) < 0) {
    func_0c0437b8(a);
    return;
  }
  if (a->b141) {
    if (a->b525) {
      if (*(unsigned short *)sub & 0x800)
        goto left;
      else if (*(unsigned short *)sub & 0x400)
        goto right;
    } else if (a->w340 & 0xc00) {
      if (a->w340 & 0x800) {
      left:
        a->f92 = -2.5f;
      } else if (a->w340 & 0x400) {
      right:
        a->f92 = 2.5f;
      }
      return;
    }
  }
  a->f92 = 0.0f;
}
void func_0c057056(struct Actor *a) { table_0c23f740[a->b7](a); }
void func_0c057068(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  a->b7++;
  a->b1a1 = 53;
  a->w1ac = 0;
  a->b19e = 0;
  a->p1c4 = 0;
  dat_0c2f83f8->w7c[a->b2]++;
  func_0c048bb0(a, 8);
  func_0c0442fa(a);
  a->f96 = 6.428571224213f;
  a->f108 = -0.80357140303f;
  a->f104 = 0.0f;
  func_0c02a0c4(a, 21, 3);
  a->f92 = 2.5f;
  if (a->w130) {
    a->f92 = -a->f92;
    if (a->b525) {
      if (!(*(unsigned short *)sub & 0x800))
        goto neg;
      return;
    }
    goto t1; t1: if (a->w340 & 0x800)
      return;
    goto neg;
  }
  if (a->b525) {
    if (*(unsigned short *)sub & 0x400)
      return;
  } else { goto t2; t2: if (a->w340 & 0x400)
    return; }
neg:
  a->f92 = -a->f92;
}
void func_0c05716e(struct Actor *a) {
  if (func_0c044e52(a)) {
    func_0c044f1c(a);
    return;
  }
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  func_0c02a026(a);
}
void func_0c0571ca(struct Actor *a) { table_0c23f748[a->b6](a); }
void func_0c0571dc(struct Actor *a) {
  a->b6++;
  a->b1a1 = 48;
  a->w1ac = 0;
  a->b19e = 0;
  a->p1c4 = 0;
  dat_0c2f83f8->w7c[a->b2]++;
  func_0c048bb0(a, 6);
  func_0c056bb8(a);
  func_0c02a0c4(a, 21, a->b1a3 + 4);
}
void func_0c05722c(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0) {
    func_0c0437b8(a);
    return;
  }
  a->f92 = 0.0f;
  if (((char *)&a->w150)[1]) {
    a->f92 = table_0c23f750[((char *)&a->w150)[1] - 1][(unsigned char)a->b1a3] * 1.66666663f / 256.0f;
    if (!a->w130)
      a->f92 = -a->f92;
    if (((char *)&a->w150)[1] == 2)
      func_0c131ff0(a);
    ((char *)&a->w150)[1] = 0;
  }
}
void func_0c057316(struct Actor *a) { table_0c23f75c[a->b6](a); }
void func_0c057328(struct Actor *a) { table_0c23f764[a->b7](a); }
void func_0c05733a(struct Actor *a) {
  a->b7++;
  func_0c048bb0(a, 10);
  func_0c056bb8(a);
  func_0c02a0c4(a, 15, 8);
}
void func_0c057360(struct Actor *a) {
  struct LinkedActorVec3 position;
  struct Actor *target;
  if (func_0c02a026(a) < 0) {
    a->b7 = 8;
    func_0c02a0c4(a, 15, 9);
  } else if ((target = func_0c037da4(a))) {
    a->b7++;
    func_0c025900(a, 5, 5);
    func_0c0344a0(a, 5);
    position.x = -146.66666f;
    position.y = 171.42856f;
    func_0c1d4610(a, &position);
    func_0c02a0c4(a, 15, 10);
    a->b1f7 = 0xc3;
    func_0c044548(a, target);
  }
}
void func_0c05740e(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  a->b1ea = 1;
  a->b1ed = 2;
  a->b1f5 = 2;
  a->b1f2 = 3;
  if (func_0c02a026(a) < 0) {
    a->b7++;
    sub->b2 = 0;
    func_0c02a0c4(a, 15, 11);
  }
}
