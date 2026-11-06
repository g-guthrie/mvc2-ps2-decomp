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
void func_0c132d14(struct Obj_0c132c24 *p);
int func_0c132dc0(struct Obj_0c132c24 *p);
struct Rec_ub3_05 { unsigned char pad[28]; int l28; };
struct Obj_ub3_05 {
    unsigned char pad0[4];
    unsigned char b4;
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
extern void func_0c0437b8(struct Obj_ub3_05 *);
extern struct Rec_ub3_05 *dat_0c2d6f84;
extern handler_ub3_05 table_0c252058[];
extern handler_ub3_05 table_0c23f694[];
extern handler_ub3_05 table_0c23f69c[];
extern handler_ub3_05 table_0c23f6a4[];
extern handler_ub3_05 table_0c23f6ac[];
extern int func_0c03916c(struct Obj_ub3_05 *);
extern void func_0c037688(struct Obj_ub3_05 *);
extern handler_ub3_05 table_0c23f68c[];
void func_0c16884e(struct Obj_ub3_05 *p);

struct V3_168860 { float x, y, z; };
struct Blk_168860 {
    unsigned char pad0[0x50];
    unsigned char b12c;
    unsigned char pad1[3];
    short w130;
    unsigned char pad2[0x65 - 0x56];
    char b141;
    unsigned char pad3[0xc0 - 0x66];
};
struct Obj_168860 {
    unsigned char pad0;
    unsigned char b1, b2;
    unsigned char pad1;
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_168860 *);
    unsigned char pad3[24 - 20];
    struct Obj_168860 *p24;
    unsigned char pad4[36 - 28];
    unsigned char b36;
    unsigned char pad5[48 - 37];
    unsigned char b48;
    unsigned char pad6[52 - 49];
    float f52, f56, f60;
    unsigned char pad7[80 - 64];
    struct V3_168860 v80;
    unsigned char pad8[0xdc - 92];
    struct Blk_168860 sdc;
    unsigned char pad9[0x1a3 - 0x19c];
    unsigned char b1a3, b1a4;
};
extern char func_0c02a026(struct Obj_168860 *a);
extern void func_0c02a0c4(struct Obj_168860 *a, int b, int c);
void func_0c1688fa(struct Obj_168860 *a);
void func_0c168964(struct Obj_168860 *a);

struct Obj_0c132c24 *func_0c168828(struct Obj_0c132c24 *a)
{
    struct Obj_0c132c24 *p;

    if ((p = func_0c0374da(0, 1, 0)) != 0) {
        p->fn16 = (void (*)(struct Obj_0c132c24 *))func_0c16884e;
        p->p24 = a;
    }
    return p;
}

void func_0c16884e(struct Obj_ub3_05 *a)
{
    table_0c252058[a->b4](a);
}

/* func_0c168860: no verified twin. Ghidra draft:
/- func_0c168860 0x0c168860-0x0c168972 Ghidra draft; not source -/

/- WARNING: Removing unreachable block (ram,0x0c168934) -/
/- WARNING: Removing unreachable block (ram,0x0c168914) -/
/- WARNING: Removing unreachable block (ram,0x0c16890c) -/
/- WARNING: Removing unreachable block (ram,0x0c1688ea) -/
/- WARNING: Removing unreachable block (ram,0x0c1688e2) -/
/- WARNING: Removing unreachable block (ram,0x0c1688da) -/
/- WARNING: Removing unreachable block (ram,0x0c16889e) -/
/- WARNING: Removing unreachable block (ram,0x0c168896) -/
/- WARNING: Removing unreachable block (ram,0x0c168898) -/
/- WARNING: Removing unreachable block (ram,0x0c1688a0) -/
/- WARNING: Removing unreachable block (ram,0x0c1688dc) -/
/- WARNING: Removing unreachable block (ram,0x0c1688e4) -/
/- WARNING: Removing unreachable block (ram,0x0c1688ee) -/
/- WARNING: Removing unreachable block (ram,0x0c168912) -/
/- WARNING: Removing unreachable block (ram,0x0c168930) -/
/- WARNING: Removing unreachable block (ram,0x0c16893a) -/

void func_0c168860(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  float fVar4;
  undefined1 uVar5;
  undefined4 unaff_r14;
  undefined4 in_PR;

  uVar1 = 0x0c1fb838;
  *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  (*(code *)uVar1)();
  uVar5 = 1;
  *(undefined1 *)((short)0x0c16897a + param_1) = 1;
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(*(int *)(param_1 + 0x18) + 2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(*(int *)(param_1 + 0x18) + 1);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x50);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x54);
  iVar3 = (int)0x1a3;
  *(undefined1 *)(iVar3 + param_1) = *(undefined1 *)(iVar3 + *(int *)(param_1 + 0x18));
  *(undefined1 *)(iVar3 + 1 + param_1) = *(undefined1 *)(iVar3 + 1 + *(int *)(param_1 + 0x18));
  *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(*(int *)(param_1 + 0x18) + 0x30);
  (*(code *)0x0c1fb7a0)();
  *(undefined1 *)(param_1 + 0x24) = 0xb;
  *(undefined1 *)((short)0x0c16897a + param_1) = uVar5;
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x34);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x38);
  uVar1 = 0x0c02a0c4;
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x3c);
  (*(code *)uVar1)(param_1,0x17,0);
  if (*(char *)(0x141 + param_1) != '\0') {
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + (float)-2.142857f /- 0xc0092492 -/;
    uVar1 = 0x0c2d6f84;
    fVar4 = (float)-0.8333333f /- 0xbf555555 -/;
    if (*(short *)(0x130 + param_1) == 0) {
      fVar4 = (float)0.8333333f /- 0x3f555555 -/;
    }
    iVar3 = (int)(short)0x0c16897a;
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + fVar4;
    *(byte *)(iVar3 + param_1) =
         *(byte *)(param_1 + 2) ^ (byte)*(undefined4 *)(*(int *)uVar1 + 0x1c) & 1;
  }
  cVar2 = (*(code *)0x0c02a026)(param_1,in_PR,unaff_r14);
  if (cVar2 < '\0') {
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    *(undefined1 *)((short)0x0c16897a + param_1) = 0;
    return;
  }
  return;
}

*/

void func_0c168860(struct Obj_168860 *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->b36 = 11;
    a->sdc.b12c = 1;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    a->f60 = a->p24->f60;
    func_0c02a0c4(a, 23, 0);
    func_0c1688fa(a);
}

void func_0c1688fa(struct Obj_168860 *a)
{
    if (a->sdc.b141) {
        a->f56 += -2.1428571f;
        if (a->sdc.w130 == 0)
            a->f52 += 0.8333333135f;
        else
            a->f52 += -0.8333333135f;
        a->sdc.b12c = a->b2 ^ (dat_0c2d6f84->l28 & 1);
    }
    if (func_0c02a026(a) < 0)
        func_0c168964(a);
}

void func_0c168964(struct Obj_168860 *a)
{
    a->b4 = a->b4 + 1;
    a->sdc.b12c = 0;
}

void func_0c168972(struct Obj_ub3_05 *a)
{
    func_0c037688(a);
}
