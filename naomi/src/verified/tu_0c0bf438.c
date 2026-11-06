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
typedef void (*handler_ub3_05)(struct Obj_ub3_05 *);
extern int func_0c037d54(struct Obj_ub3_05 *);
extern void func_0c044450(struct Obj_ub3_05 *, int);
extern struct Rec_ub3_05 *dat_0c2d6f84;
extern handler_ub3_05 table_0c23f68c[];
extern handler_ub3_05 table_0c23f694[];
extern handler_ub3_05 table_0c23f69c[];
extern handler_ub3_05 table_0c23f6a4[];
extern handler_ub3_05 table_0c23f6ac[];
extern int func_0c03916c(struct Obj_ub3_05 *);
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c245d10[];
extern ActorHandler table_0c24174c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c15ba0c(struct Actor *, int, int);

/* func_0c0bf438: no verified twin. Ghidra draft:
/- func_0c0bf438 0x0c0bf438-0x0c0bf4c0 Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c0bf4ac) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf4a4) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf498) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf480) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf478) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf474) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf46e) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf466) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf460) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf458) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf452) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf44a) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf448) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf450) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf456) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf45e) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf464) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf46c) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf472) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf476) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf47c) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf482) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf49c) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf4a8) -/
/- WARNING: Removing unreachable block (ram,0x0c0bf4b2) -/

void func_0c0bf438(int param_1)

{
  undefined4 uVar1;

  (*(code *)0x0c02a026)();
  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) + *(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x60);
  *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x6c);
  if (*(float *)(0x41c + param_1) < *(float *)(param_1 + 0x38)) {
    return;
  }
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(0x41c + param_1);
  *(undefined1 *)(0x1f9 + param_1) = 1;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  uVar1 = 0x0c02a0c4;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  (*(code *)uVar1)(param_1,0x16,0xf);
  return;
}

*/
void func_0c0bf438(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > a->f41c)
        return;
    a->b6 = a->b6 + 1;
    a->f56 = a->f41c;
    a->b1f9 = 1;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 22, 15);
}

void func_0c0bf4c0(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0bf4e2(struct Actor *a)
{
    table_0c245d10[a->b6](a);
}

void func_0c0bf4f4(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 97;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 27);
}

/* func_0c0bf56a: no verified twin. Ghidra draft:
/- func_0c0bf56a 0x0c0bf56a-0x0c0bf59c Ghidra draft; not source -/

void func_0c0bf56a(int param_1)

{
  (*(code *)0x0c02a026)();
  if (*(char *)((short)0x0c0bf5a2 + param_1) != '\0') {
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(undefined1 *)((short)0x0c0bf5a2 + param_1) = 0;
    (*(code *)0x0c0bf5c4)(param_1,5,0);
    return;
  }
  return;
}

*/
void func_0c0bf56a(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->b141 = 0;
        func_0c15ba0c(a, 5, 0);
    }
}
