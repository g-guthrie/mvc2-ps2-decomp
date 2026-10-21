typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;
extern void *func_0011D8F8(void *, s32, s32);
extern void *func_003F55B0(void *, s32, s32);




extern s32 D_004C2AB0, D_004C2AB4;
typedef struct { char b[0x18]; } R18;
extern R18 D_006267A0[];
void func_003EB900(void) {
    s32 i = 0;
    s32 off = 0;
    D_004C2AB0 = 0;
    D_004C2AB4 = 0;
    do {
        func_003F55B0((char *)D_006267A0 + off, 0, 0x18);
        i++;
        off += 0x18;
    } while (i < 0x380);
}

typedef struct { char pad[0x2C]; s16 f; char pad2[0x12]; } E64;
extern E64 D_0061C7A0[];
extern s32 func_003EA130(E64 *);

typedef struct { s32 a; s32 n; } H1530;
typedef struct { u8 t; u8 p[7]; s32 len; } Ent;
static H1530 *func_003F1530(void *file) { return (H1530 *)file; }
Ent *func_003F1540(Ent *e, s32 t) {
    H1530 *h = func_003F1530(e);
    s32 n = h->n;
    u32 i;
    e = (Ent *)((char *)e + 0xC);
    for (i = 0; i < n; i++) {
        if (e->t == t) return e;
        e = (Ent *)((char *)e + e->len);
    }
    return 0;
}

extern s32 D_00439990, D_004399B0;
extern char D_004AB498[], D_0043AB50[];
extern void func_00105E80(void *);
extern s32 func_00107058(void *);
extern void func_0010E608(s32);

extern s32 func_0010B198(void);
extern s32 func_0010B298(void);
extern s32 D_004C6E80[];
extern char D_004C7080[];

extern void func_00104060(s32);

typedef struct { s32 w0[10]; s32 w28; s16 f; char pad2[0x12]; } E64b;
extern E64b D_006207A0[];
extern s32 D_004C2AE8;
extern void func_003DC9C0(void);
extern void func_003EBD00(E64b *);
extern void func_003DD020(s32);
s32 func_003E9420(u32 i) {
    E64b *e = &D_006207A0[i - 1];
    if (i == 0) return 0;
    if (i > 0x180) return 0;
    if (e->f == 0) return 0;
    func_003DC9C0();
    func_003EBD00(e);
    if (e->w28) func_003DD020(e->w28);
    func_003F55B0(e, 0, 0x40);
    D_004C2AE8--;
    return 1;
}

extern s32 D_004C253C;
extern s32 D_006340C0[4];
extern char D_00634030[];
extern void func_00103E20(s32);
extern void func_00103E00(s32);
extern void func_00423890(void);
extern s32 func_00106E68(void *, s32, s32, void *, s32, void *, s32, void *, long);

extern char D_00633DC0[], D_00633D70[], D_00633970[], D_00633940[], D_004C2B88[6], D_00633960[];
void func_0041FFD0(void) {
    func_0011D8F8(D_00633DC0, 0, 0x18);
    func_0011D8F8(D_00633D70, 0, 0x44);
    func_0011D8F8(D_00633970, 0, 0x400);
    func_0011D8F8(D_00633940, 0, 0x14);
    func_0011D8F8(D_004C2B88, 0, 6);
    func_0011D8F8(D_00633960, 0, 0x10);
    *(s32 *)D_00633960 = -1;
}

typedef struct { u8 b0, b1, b2; signed char n; s32 p4, p8; s32 w; char pad[0x32]; s16 v[1]; } S4028;
extern char D_004BC188[], D_004BC1B8[];
extern void func_003FB128(void *);
extern void func_003FF270(s32);

typedef struct { char p[0x34]; float x; float y; char q[0x108]; s16 h; } F41B;
