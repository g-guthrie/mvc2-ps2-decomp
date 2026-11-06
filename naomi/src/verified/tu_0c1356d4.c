#include "objects.h"

/* Assembled by tools/clone.py from verified twins. */
struct Pair_0c132c24 { char b0, b1; };
struct Inner_0c132c24 {
    unsigned char pad0[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad1[0x130 - 0x12d];
    unsigned short w130;
    unsigned char pad2[0x150 - 0x132];
    struct Pair_0c132c24 s150;
    unsigned char pad3[0x19c - 0x152];
};
struct Vec3 { float x, y, z; };
struct Obj_0c132c24 {
    unsigned char pad0;
    unsigned char b1, b2;
    unsigned char pad1;
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*fn16)(struct Obj_0c132c24 *);
    unsigned char pad3[4];
    struct Obj_0c132c24 *p24;
    unsigned char pad4[36 - 28];
    unsigned char b36;
    unsigned char pad5[48 - 37];
    unsigned char b48;
    unsigned char pad6[52 - 49];
    float f52, f56, f60;
    unsigned char pad7[80 - 64];
    struct Vec3 s80;
    unsigned char pad8[0xdc - 92];
    struct Inner_0c132c24 sdc;
    unsigned char pad9[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
};
typedef void (*fn_t)(struct Obj_0c132c24 *);
extern fn_t dat_0c24e314[];
extern struct Obj_0c132c24 *func_0c0374da(int a, int b, int c);
extern void func_0c02a0c4(struct Obj_ub3_05 *, int, int);
void func_0c132c4a(struct Obj_0c132c24 *p);
void func_0c132d14(struct Obj_0c132c24 *p);
int func_0c132dc0(struct Obj_0c132c24 *p);
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
extern void func_0c037688(struct Obj_ub3_05 *);
extern struct Rec_ub3_05 *dat_0c2d6f84;
extern handler_ub3_05 table_0c23f68c[];
extern handler_ub3_05 table_0c23f694[];
extern handler_ub3_05 table_0c23f69c[];
extern handler_ub3_05 table_0c23f6a4[];
extern handler_ub3_05 table_0c23f6ac[];
extern int func_0c03916c(struct Obj_ub3_05 *);

/* func_0c1356d4: no verified twin. Ghidra draft:
/- func_0c1356d4 0x0c1356d4-0x0c13570a Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c1356fe) -/
/- WARNING: Removing unreachable block (ram,0x0c1356f6) -/
/- WARNING: Removing unreachable block (ram,0x0c1356ee) -/
/- WARNING: Removing unreachable block (ram,0x0c1356f2) -/
/- WARNING: Removing unreachable block (ram,0x0c1356fa) -/
/- WARNING: Removing unreachable block (ram,0x0c135702) -/

void func_0c1356d4(int param_1)

{
  char cVar1;

  cVar1 = (*(code *)0x0c02a026)();
  if (cVar1 < '\0') {
    *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + '\x01';
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 17.14286f /- 0x41892492 -/;
  }
  return;
}

*/

extern char func_0c02a026(struct Actor *a);
extern float dat_0c2d92f0;

void func_0c1356d4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b5 = a->b5 + 1;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f96 = 17.142857f;
    }
}

/* func_0c13570a: no verified twin. Ghidra draft:
/- func_0c13570a 0x0c13570a-0x0c135758 Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c135748) -/
/- WARNING: Removing unreachable block (ram,0x0c135742) -/
/- WARNING: Removing unreachable block (ram,0x0c13573e) -/
/- WARNING: Removing unreachable block (ram,0x0c135738) -/
/- WARNING: Removing unreachable block (ram,0x0c135730) -/
/- WARNING: Removing unreachable block (ram,0x0c13572a) -/
/- WARNING: Removing unreachable block (ram,0x0c135722) -/
/- WARNING: Removing unreachable block (ram,0x0c13571c) -/
/- WARNING: Removing unreachable block (ram,0x0c135714) -/
/- WARNING: Removing unreachable block (ram,0x0c135712) -/
/- WARNING: Removing unreachable block (ram,0x0c13571a) -/
/- WARNING: Removing unreachable block (ram,0x0c135720) -/
/- WARNING: Removing unreachable block (ram,0x0c135728) -/
/- WARNING: Removing unreachable block (ram,0x0c13572e) -/
/- WARNING: Removing unreachable block (ram,0x0c135736) -/
/- WARNING: Removing unreachable block (ram,0x0c13573c) -/
/- WARNING: Removing unreachable block (ram,0x0c135740) -/
/- WARNING: Removing unreachable block (ram,0x0c135746) -/
/- WARNING: Removing unreachable block (ram,0x0c13574a) -/

void func_0c13570a(int param_1)

{
  byte abVar1 [4];

  abVar1 = 0x0c135778;
  *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) + *(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x60);
  *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x6c);
  if (*(float *)abVar1 < *(float *)(param_1 + 0x38)) {
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  }
  return;
}

*/

void func_0c13570a(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 > dat_0c2d92f0)
        a->b4 = a->b4 + 1;
}

int func_0c135758(struct Obj_0c132c24 *p)
{
    p->b4++;
    p->sdc.b12c = 0;
}

void func_0c135766(struct Obj_ub3_05 *a)
{
    func_0c037688(a);
}
