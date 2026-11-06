/* Assembled by tools/clone.py from verified twins. */
struct Rec_ub3_05 { unsigned char pad[28]; int l28; };
struct Obj_ub3_05 {
    unsigned char pad0[5];
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[20];
    short s28;
    unsigned char pad2[2];
    unsigned char b32;
    unsigned char pad3[19];
    float f52;
    float f56;
    unsigned char pad4[32];
    float f92;
    float f96;
    unsigned char pad5[4];
    float f104;
    float f108;
    unsigned char pad6[209];
    unsigned char b141;
    unsigned char pad7[144];
    unsigned char b1d2;
    unsigned char pad8[36];
    unsigned char b1f7;
    unsigned char pad9[10];
    unsigned char b202;
};
#include "objects.h"
typedef void (*handler_ub3_05)(struct Obj_ub3_05 *);
typedef void (*ActorHandler)(struct Actor *);
extern int func_0c037d54(struct Obj_ub3_05 *);
extern void func_0c044450(struct Obj_ub3_05 *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
struct Glob_0c2d9260 { unsigned char pad[5]; unsigned char b5, b6; };
extern struct Glob_0c2d9260 dat_0c2d9260;
extern struct Rec_ub3_05 *dat_0c2d6f84;
extern handler_ub3_05 table_0c23f68c[];
extern handler_ub3_05 table_0c23f694[];
extern handler_ub3_05 table_0c23f69c[];
extern handler_ub3_05 table_0c23f6a4[];
extern handler_ub3_05 table_0c23f6ac[];
extern int func_0c03916c(struct Obj_ub3_05 *);
extern ActorHandler table_0c24c234[];

/* func_0c114394: no verified twin. Ghidra draft:
/- func_0c114394 0x0c114394-0x0c114410 Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c1143f6) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ee) -/
/- WARNING: Removing unreachable block (ram,0x0c1143e2) -/
/- WARNING: Removing unreachable block (ram,0x0c1143dc) -/
/- WARNING: Removing unreachable block (ram,0x0c1143d4) -/
/- WARNING: Removing unreachable block (ram,0x0c1143d0) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ca) -/
/- WARNING: Removing unreachable block (ram,0x0c1143c2) -/
/- WARNING: Removing unreachable block (ram,0x0c1143bc) -/
/- WARNING: Removing unreachable block (ram,0x0c1143b4) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ae) -/
/- WARNING: Removing unreachable block (ram,0x0c1143a6) -/
/- WARNING: Removing unreachable block (ram,0x0c1143a4) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ac) -/
/- WARNING: Removing unreachable block (ram,0x0c1143b2) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ba) -/
/- WARNING: Removing unreachable block (ram,0x0c1143c0) -/
/- WARNING: Removing unreachable block (ram,0x0c1143c8) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ce) -/
/- WARNING: Removing unreachable block (ram,0x0c1143d2) -/
/- WARNING: Removing unreachable block (ram,0x0c1143d8) -/
/- WARNING: Removing unreachable block (ram,0x0c1143de) -/
/- WARNING: Removing unreachable block (ram,0x0c1143ea) -/
/- WARNING: Removing unreachable block (ram,0x0c1143f2) -/
/- WARNING: Removing unreachable block (ram,0x0c1143fe) -/

void func_0c114394(int param_1)

{
  byte abVar1 [4];

  (*(code *)0x0c1144f8)();
  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) + *(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x60);
  *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x6c);
  if (*(float *)(param_1 + 0x38) <= *(float *)((short)0x0c1144f4 + param_1)) {
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)((short)0x0c1144f4 + param_1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    abVar1 = 0x0c1144fc;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    (*(code *)abVar1)(param_1,2,3);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  return;
}

*/
void func_0c114394(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c >= a->f56) {
        a->f56 = a->f41c;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 2, 3);
        a->b6 = a->b6 + 1;
    }
}

void func_0c114410(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c114432(struct Actor *a)
{
    table_0c24c234[a->b6](a);
}

/* func_0c114444: no verified twin. Ghidra draft:
/- func_0c114444 0x0c114444-0x0c114480 Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c114476) -/
/- WARNING: Removing unreachable block (ram,0x0c11446e) -/
/- WARNING: Removing unreachable block (ram,0x0c114466) -/
/- WARNING: Removing unreachable block (ram,0x0c11445e) -/
/- WARNING: Removing unreachable block (ram,0x0c11445a) -/
/- WARNING: Removing unreachable block (ram,0x0c114462) -/
/- WARNING: Removing unreachable block (ram,0x0c11446a) -/
/- WARNING: Removing unreachable block (ram,0x0c114472) -/
/- WARNING: Removing unreachable block (ram,0x0c11447a) -/

void func_0c114444(int param_1)

{
  byte abVar1 [4];
  undefined4 uVar2;

  uVar2 = 480f /- 0x43f00000 -/;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  *(undefined1 *)((short)0x0c1144f6 + param_1) = 1;
  abVar1 = 0x0c1144fc;
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + (float)uVar2;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x60) = -8.571428f /- 0xc1092492 -/;
  *(undefined4 *)(param_1 + 0x6c) = -0.5357143f /- 0xbf092492 -/;
  (*(code *)abVar1)(0x12,0);
  return;
}

*/
void func_0c114444(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 1;
    a->f56 += 480.0f;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = -8.5714283f;
    a->f108 = -0.5357143f;
    func_0c02a0c4(a, 18, 0);
}

/* func_0c114480: no verified twin. Ghidra draft:
/- func_0c114480 0x0c114480-0x0c1144f4 Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c1144bc) -/
/- WARNING: Removing unreachable block (ram,0x0c1144b2) -/
/- WARNING: Removing unreachable block (ram,0x0c1144ac) -/
/- WARNING: Removing unreachable block (ram,0x0c1144a4) -/
/- WARNING: Removing unreachable block (ram,0x0c1144a0) -/
/- WARNING: Removing unreachable block (ram,0x0c11449a) -/
/- WARNING: Removing unreachable block (ram,0x0c114492) -/
/- WARNING: Removing unreachable block (ram,0x0c114490) -/
/- WARNING: Removing unreachable block (ram,0x0c114498) -/
/- WARNING: Removing unreachable block (ram,0x0c11449e) -/
/- WARNING: Removing unreachable block (ram,0x0c1144a2) -/
/- WARNING: Removing unreachable block (ram,0x0c1144a8) -/
/- WARNING: Removing unreachable block (ram,0x0c1144ae) -/
/- WARNING: Removing unreachable block (ram,0x0c1144b8) -/
/- WARNING: Removing unreachable block (ram,0x0c1144c2) -/

void func_0c114480(int param_1)

{
  byte abVar1 [4];
  undefined4 uVar2;

  (*(code *)0x0c1144f8)();
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x60);
  *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x6c);
  if (*(float *)(param_1 + 0x38) <= *(float *)((short)0x0c1144f4 + param_1)) {
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)((short)0x0c1144f4 + param_1);
    *(undefined4 *)(param_1 + 0x60) = 0;
    uVar2 = 0x0c043324;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    (*(code *)uVar2)(param_1);
    (*(code *)0x0c0346da)(param_1,0x35);
    uVar2 = 0x0c2d9260;
    abVar1 = 0x0c1144fc;
    *(undefined1 *)(0x0c2d9260 + 5) = 3;
    *(undefined1 *)(uVar2 + 6) = 1;
    (*(code *)abVar1)(param_1,0x12,1);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(undefined2 *)(param_1 + 0x1c) = 0x3c;
  }
  return;
}

*/
void func_0c114480(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c >= a->f56) {
        a->f56 = a->f41c;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        func_0c043324(a);
        func_0c0346da(a, 53);
        dat_0c2d9260.b5 = 3;
        dat_0c2d9260.b6 = 1;
        func_0c02a0c4(a, 18, 1);
        a->b6 = a->b6 + 1;
        a->s28 = 60;
    }
}
