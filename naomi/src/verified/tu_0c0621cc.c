#include "objects.h"
struct ActorSubByte28 {
  unsigned char pad[28], b28;
};
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c1349b0(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c061148(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c240120[])(struct Actor *);
extern void (*table_0c240128[])(struct Actor *);
void func_0c0622d4(struct Actor *);
void func_0c0621cc(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  a->b3f8 = 2;
  a->b328 = 5;
  if (func_0c02a026(a) < 0) {
    a->b6++;
    a->b3f9 = 0;
    a->b3f8 = 0;
    a->b327 = 0;
    a->b328 = 0;
    func_0c02a0c4(a, 22, 42);
    return;
  }
  if (a->b140) {
    a->b140 = 0;
    if (func_0c1349b0(a))
      sub->b21++;
  }
}
void func_0c062246(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  (*(unsigned char *)&sub->s18) = 6;
  func_0c02a026(a);
  if (!sub->b21) {
    a->b6++;
    func_0c02a39a(a, 0);
    func_0c02a0c4(a, 22, 43);
  }
}
void func_0c06228c(struct Actor *a) {
 char *sub=(char*)&a->sub2a4;
 goto animate;
animate:
 if(func_0c02a026(a)<0){sub[12]=0;func_0c0437b8(a);}
}
void func_0c0622c0(struct Actor *a) { table_0c240120[a->b32](a); }
void func_0c0622d4(struct Actor *a) {
  struct ActorSub2a4 *sub = &a->sub2a4;
  struct LinkedActorVec3 position;
  a->b3f8 = 2;
  a->b328 = 5;
  a->b3f1 = a->b255 == 6 ? 2 : 0;
  if (func_0c02a026(a) < 0) {
    a->b3f0 = 0;
    a->b3f1 = 0;
    a->b6++;
    a->b7 = 0;
    a->s28 = 40;
    a->f92 = 13.33333302f;
    a->f104 = -0.1041666642f;
    if (!a->w130) {
      a->f92 = -a->f92;
      a->f104 = -a->f104;
    }
    a->b1f9 = 2;
    func_0c02a0c4(a, 22, 6);
    ((struct ActorSubByte28 *)sub)->b28 = 1;
    position.x = -26.666666031f;
    position.y = 137.142853f;
    func_0c0429a4(a, &position, 1);
  }
}
void func_0c0623b4(struct Actor *a) {
  if (a->b255 == 6) {
    a->b3f0 = 255;
    a->b3f1 = 16;
  }
  a->b7++;
  func_0c061148(a);
  func_0c0432ca(a);
  a->b1a1 = 59;
  a->w1ac = 0;
  a->b19e = 0;
  *(unsigned int *)&a->p1c4 = 0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c02a39a(a, 0);
  func_0c02a0c4(a, 22, 5);
  func_0c0622d4(a);
}
void func_0c062422(struct Actor *a) { table_0c240128[a->b7](a); }
