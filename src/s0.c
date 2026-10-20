typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

u32 func_00102C58(u32 *p, u32 v) { u32 o = *p; *p = v; return (o >> 8) & 1; }

extern void func_00103BB0(void);
void func_00104AC0(void) { func_00103BB0(); __asm__ volatile("sync"); }

extern int D_0048831C;
void func_0040A2C8(u32 a) { D_0048831C = a; if (a > 1) D_0048831C = 0; }

extern void func_00103E10(int);
void func_0010E5E0(int a, int b, int c) { func_00103E10(c); __asm__ volatile("sync\n\tei"); }

extern void func_00107A68(void);
extern void func_00103E20(int);
extern int D_00438304;





extern char D_004BE080[];
extern void func_0040AF58(void *, void *);
int func_0040B9F0(int *p) { if (p == 0) { func_0040AF58(p, D_004BE080); return 0; } return p[7]; }

extern char D_004BC098[];
extern void func_003FB128(void *);
extern s32 func_003FFFF0(int);
typedef struct { char a; signed char b; short c; int w; } S01;
s32 func_00401E98(S01 *p) {
    if (p == 0) { func_003FB128(D_004BC098); return -1; }
    if (p->b >= 2) return func_003FFFF0(p->w);
    return 0;
}

extern char D_00478D10[];


typedef struct { int p0[3]; u32 cur; u32 end; u32 al; } S09;

extern char D_004BCD70[], D_004BCD90[];
extern void func_00405DC8(void *);
typedef struct { char pad[0x30]; int (*fn)(int); } Ops;
typedef struct { Ops *ops; int arg; } Obj;
int func_00406E20(Obj *p) {
    int r = 0;
    if (p == 0) { func_00405DC8(D_004BCD70); return 0; }
    if (p->ops->fn) r = p->ops->fn(p->arg); else func_00405DC8(D_004BCD90);
    return r;
}

extern void func_001191F0(void *, void *);
extern long long func_001192B0(void *, void *, void *);
extern long long func_00119118(long long);
long long func_00119568(long long a, long long b) {
    s32 x[8], y[8], z[8];
    func_001191F0(&a, x);
    func_001191F0(&b, y);
    y[1] ^= 1;
    return func_00119118(func_001192B0(x, y, z));
}

extern int D_0047C5B0, D_0047C5B4;
extern int func_003FD530(void);
extern void func_003FD138(int);
extern void func_003FBFD8(void);

typedef struct { signed char st; char pad[0x2F]; } E30;
extern E30 D_00489220[];
extern int func_0040AFD8(void *);
int func_0040B028(void) {
    int i; E30 *p = D_00489220;
    for (i = 0; i < 13; i++, p++) {
        if (p->st == 1 && func_0040AFD8(p) == 0) return 0;
    }
    return 1;
}

extern int D_00438318;
extern char D_004C6CC0[], D_004C6D00[];
extern int D_004C6D40;
extern int func_00106E68(void *, int, int, int, int, void *, int, int, int);

extern int func_0011D6A8(void *, void *, int);
extern char D_0043824C[], D_004C6C28[];
extern char *D_00438310;

extern int func_0011FFA0(char *);
extern int func_0040C088(int, int);
int func_0040C0E0(char *a, char *b) {
    int n = func_0011FFA0(a);
    int m = func_0011FFA0(b);
    int i;
    if (n != m) return -1;
    for (i = 0; i < n; i++) if (func_0040C088(a[i], b[i])) return -1;
    return 0;
}
