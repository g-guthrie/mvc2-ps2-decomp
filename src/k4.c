typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_00438250;
void func_00104260(void) { D_00438250 = 0; }

void func_0040EA48(s32 a, s32 *b, s32 *c) { *b = 0; *c = 0xBB80; }

extern void func_0040EA98(void);
void func_003FF1A8(void) { func_0040EA98(); }

extern s32 func_003F81E8(void *);
s32 func_00400098(void *object) { return func_003F81E8(*(void **)((u8 *)object + 4)); }

extern void func_00103B90(void);
void func_00104A80(void) { func_00103B90(); __asm__ volatile("sync"); }

extern s32 D_00632140[];
extern void func_00409708(s32, void *, s32, void *, s32);
void func_00410990(s32 a) { D_00632140[0] = a; func_00409708(0x25, D_00632140, 1, 0, 0); }

extern char D_004BB508[];
extern void func_003FB128(void *);
s32 func_003FD530(signed char *p) {
    if (p == 0) { func_003FB128(D_004BB508); return -3; }
    return p[1];
}

/* Hand-written: call, then a nop-padded spin loop that never returns. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits
.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_003FF1C0,
  "lui $4,%hi(D_004BBE88)\n"
  "addiu $29,$29,-16\n"
  "sd $31,0($29)\n"
  "jal func_0011EB60\n"
  "addiu $4,$4,%lo(D_004BBE88)\n"
  ".p2align 3\n"
  "1:\n"
  "nop\nnop\nnop\nnop\nnop\n"
  "b 1b\n"
  "nop\n"
  );

struct T028Item { s32 pad[1]; s32 f4; };
struct T028Tbl { s32 pad[2]; struct T028Item *items[1]; };
struct T028 { s32 pad[3]; struct T028Tbl *tbl; };
extern unsigned func_00410AD0(s32, s32);
unsigned func_003FF028(struct T028 *p, s32 i) {
    return func_00410AD0(p->tbl->items[i]->f4, 1) >> 1;
}

extern void func_0040E9F8(s32, s32);
extern void func_0040E980(s32, s32);
extern void func_0040E868(s32);
void func_003FF0E0(s32 a) { func_0040E9F8(a, 0); func_0040E980(a, 0); func_0040E868(a); }

struct Q { s32 size; s32 cnt; char *cur; s32 pad; char data[1]; };
struct R { char p0; char p1; signed char n; char pad[0x11]; s32 v[1]; };
void func_003F6108(char *p) {
    s32 i;
    for (i = 0; i < ((signed char *)p)[2]; i++) ((s32 *)(p + 0x14))[i] = 0;
    *(s32 *)(p + 0x2C) = 0;
    p[1] = 2;
}

extern char D_004C3570[];
struct T401 { s32 a, b; };
extern void func_0040CA70();
extern void func_0040CAA0();
void func_00401000(struct T401 *p) {
    if (p) { func_0040CA70(p->b); func_0040CAA0(p->a); }
    else { func_0040CA70(); func_0040CAA0(0); }
}

extern double litodp(s32);
extern double dpmul(double, double);
extern double dpdiv(double, double);
extern float dptofp(double);
extern signed char D_00487358[];
extern void func_00408960(void *);
extern void func_00409810(void);
void func_00408CE8(void) {
    s32 i;
    u32 address = (u32)D_00487358;
    for (i = 31; i >= 0; i--, address += 0x40) {
        signed char *p = (signed char *)address;
        if (p[0] == 1) func_00408960(p);
    }
    func_00409810();
}

extern char D_004C2278[], D_004C2280[];
extern s32 func_0011D6A8(void *, void *, s32);
s32 func_003F9568(char *p) {
    if (func_0011D6A8(p, D_004C2278, 4) == 0) {
        if (func_0011D6A8(p + 8, D_004C2280, 4) == 0) return 1;
    }
    return 0;
}

struct VT { char pad[0x2C]; s32 (*fn)(s32); };
struct T406 { struct VT *vt; s32 f4; };
extern char D_004BCBB0[], D_004BCBD0[];
extern void func_00405DC8(void *);
s32 func_00406AE8(struct T406 *p) {
    s32 r = 3;
    if (p == 0) { func_00405DC8(D_004BCBB0); return 3; }
    if (p->vt->fn) r = p->vt->fn(p->f4);
    else func_00405DC8(D_004BCBD0);
    return r;
}

struct T2990 { unsigned f0; s32 pad[3]; s32 f10; s32 pad2[3]; s32 f20; };
extern s32 func_00102520(s32);
extern void func_00102428(void *);
extern s32 D_0043BB60, D_0043BB64, D_00438990;
extern s32 func_00103CD0(void);
extern void func_00103E20(s32);
void func_0011D9B8(void) {
    s32 t = func_00103CD0();
    if (D_0043BB60 == t) {
        D_0043BB64++;
    } else {
        func_00103E20(D_00438990);
        D_0043BB60 = t;
        D_0043BB64++;
    }
}

extern s32 D_00438660[];
extern void D_0010C900(void);
extern void func_00103A90(s32, void *);
extern void func_00103AA0(s32, void *);
struct E6128 { s32 v; char key[12]; };
extern char D_0062FB4C[];
extern s32 func_0011FFA0(void);
extern s32 func_00120288(s32, void *, s32);
extern char D_0062FD58[], D_004BD4A8[];
extern s32 func_00406430(void);
extern s32 func_00407AB8(s32);
extern void func_0011FE88(void *, s32);
extern void func_0011F938(s32, void *, s32, void *);
void func_00407B08(s32 p, s32 q) {
    if (p == 0) p = func_00406430();
    if (func_00407AB8(p) == 1) {
        func_0011FE88(D_0062FD58, q);
        func_0011F938(q, D_004BD4A8, p, D_0062FD58);
    }
}
