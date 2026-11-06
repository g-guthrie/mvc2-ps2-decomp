#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c04b02a(struct Actor *);
extern void func_0c1ceafe(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c04bad8(struct Actor *, struct Actor *);
extern void func_0c034946(void *, int);
extern void func_0c0445fe(struct Actor *, struct Actor *);
void func_0c084b6e(struct Actor *, struct ActorChildReference *);
void func_0c084b14(struct Actor *a) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0)
    func_0c0437b8(a);
}
void func_0c084b6e(struct Actor *a, struct ActorChildReference *reference) {
  struct Actor *child = reference->child;
  float velocity, acceleration, height;
  if (!(child->f96 > 0)) {
    velocity = child->f96;
    acceleration = 2.1428571f;
    if (velocity < 32.14286f)
      velocity = 32.14286f;
    if (child->f108 > acceleration)
      acceleration = child->f108;
    height = velocity + acceleration;
    height += height;
    height += child->f41c;
    if (height > child->f56) {
      child->f56 = height;
      child->f92 = 0;
      child->f96 = 0;
      child->f104 = 0;
      child->f108 = 0;
      a->b6++;
      a->b7 = 0;
    }
  }
}
void func_0c084bc8(struct Actor *a, struct ActorChildReference *reference) {
  a->f52 += a->f92;
  a->f92 += a->f104;
  a->f56 += a->f96;
  a->f96 += a->f108;
  if (func_0c02a026(a) < 0)
    a->b7++;
  func_0c084b6e(a, reference);
}
void func_0c084c28(struct Actor *a, struct ActorChildReference *reference) {
  a->b7++;
  a->w130 = a->w130 ^ 1;
  a->b1d2 = a->b1d2 ^ 1;
  a->f92 = a->w130 ? -10.0f : 10.0f;
  a->f104 = 0;
  a->f96 = 0;
  a->f108 = 0;
  reference = (struct ActorChildReference *)reference->child;
  ((struct Actor *)reference)->b236 = 0;
  func_0c02a0c4(a, 22, 4);
}
void func_0c084c96(struct Actor *a, struct ActorChildReference *reference) {
  struct LinkedActorVec3 position;
  if (func_0c02a026(a) < 0) {
    a->b6++;
    a->b7 = 0;
    goto done;
  }
  if (a->b140) {
    {
      struct Actor *child = reference->child;
      child->p1b4 = a;
      a->b1a1 = a->b140 + 76;
      child->b1a1 = a->b140 + 76;
    }
    a->b140 = 0;
    func_0c04b02a(a);
    position.x = -80.0f;
    position.y = 137.142853f;
    func_0c1ceafe(a, &position);
    func_0c04bad8(reference->child, a);
    if (a->b14b) {
      register int offset = 255;
      func_0c034946(a->p1c8, offset + ((char *)a)[offset + 76]);
      a->b14b = 0;
    }
  }
done:;
}
void func_0c084d3a(struct Actor *a, struct ActorChildReference *reference) {
  a->b7++;
  func_0c02a0c4(a, 22, 5);
  a->b1f7 = 197;
  func_0c0445fe(a, reference->child);
}
void func_0c084d6a(struct Actor *a) {
  if (func_0c02a026(a) < 0)
    func_0c0437b8(a);
}
