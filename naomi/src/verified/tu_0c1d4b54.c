/* Exact 0x0c1d4b54..0x0c1d4e18 constructor group: six functions, both pools.
 * Keep angle word 1 as an array compound assignment: the scalar spelling
 * changes SHC addition scheduling and the destination register.
 */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern void func_0c1d4e18(struct Obj_tu5_03 *),
    func_0c1d4e64(struct Obj_tu5_03 *), func_0c1d4ef6(struct Obj_tu5_03 *),
    func_0c1d4f40(struct Obj_tu5_03 *), func_0c1d4fba(struct Obj_tu5_03 *);
void func_0c1d4b80(struct Vec3_tu5_03 *, int);
void func_0c1d4c12(struct Vec3_tu5_03 *, int);
void func_0c1d4cc0(struct Vec3_tu5_03 *, int);
void func_0c1d4d28(struct Vec3_tu5_03 *, int);
void func_0c1d4d90(struct Vec3_tu5_03 *, int);
void func_0c1d4b54(struct Vec3_tu5_03 *position, int mirror) {
  func_0c1d4b80(position, mirror), func_0c1d4c12(position, mirror),
      func_0c1d4cc0(position, mirror), func_0c1d4d28(position, mirror),
      func_0c1d4d90(position, mirror);
  return;
}
void func_0c1d4b80(struct Vec3_tu5_03 *position, int mirror) {
  struct Obj_tu5_03 *a;
  if ((a = func_0c0374da(0, 7, 1)) != 0) {
    a->b12c = 1;
    a->p16 = func_0c1d4e18;
    a->l84 = (int)((void **)dat_0c2d9650->p0)[169];
    a->pos = *position;
    a->pos.y += 10.0f;
    a->lcc = 1029;
    a->w28 = 0;
    a->w30 = 0;
    a->f116 = 1.0f;
    a->f120 = 0.0f;
    a->f124 = 0.0f;
    a->f128 = 0.0f;
    a->w130 = mirror;
    a->angles.array[1] += (a->w130 ? 32768 : 0);
  }
}
void func_0c1d4c12(struct Vec3_tu5_03 *position, int mirror) {
  struct Obj_tu5_03 *a;
  if ((a = func_0c0374da(0, 7, 1)) != 0) {
    a->b12c = 1;
    a->p16 = func_0c1d4e64;
    a->pos = *position;
    a->lcc = 1045;
    a->w28 = 0;
    a->w30 = 0;
    a->f116 = 1.0f;
    a->f120 = 0.0f;
    a->f124 = 0.0f;
    a->f128 = 0.0f;
    a->f80 = 1.0f;
    a->f84 = 1.0f;
    a->f88 = 1.0f;
    a->w130 = mirror;
    a->angles.array[1] += (a->w130 ? 32768 : 0);
  }
}
void func_0c1d4cc0(struct Vec3_tu5_03 *position, int mirror) {
  struct Obj_tu5_03 *a;
  if ((a = func_0c0374da(0, 7, 1)) != 0) {
    a->b12c = 1;
    a->p16 = func_0c1d4ef6;
    a->pos = *position;
    a->lcc = 37;
    a->w28 = 0;
    a->w30 = 0;
    a->f116 = 0.0f;
    a->w130 = mirror;
    a->angles.array[1] += (a->w130 ? 32768 : 0);
  }
}
void func_0c1d4d28(struct Vec3_tu5_03 *position, int mirror) {
  struct Obj_tu5_03 *a;
  if ((a = func_0c0374da(0, 7, 1)) != 0) {
    a->b12c = 1;
    a->p16 = func_0c1d4f40;
    a->pos = *position;
    a->lcc = 37;
    a->w28 = 0;
    a->w30 = 0;
    a->f116 = 0.0f;
    a->w130 = mirror;
    a->angles.array[1] += (a->w130 ? 32768 : 0);
  }
}
void func_0c1d4d90(struct Vec3_tu5_03 *position, int mirror) {
  struct Obj_tu5_03 *a;
  if ((a = func_0c0374da(0, 7, 1)) != 0) {
    a->b12c = 1;
    a->p16 = func_0c1d4fba;
    a->pos = *position;
    a->lcc = 37;
    a->w28 = 0;
    a->w30 = 0;
    a->f116 = 0.0f;
    a->w130 = mirror;
    a->angles.array[1] += (a->w130 ? 32768 : 0);
  }
}
