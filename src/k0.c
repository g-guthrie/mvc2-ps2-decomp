extern volatile int D_00487348;
extern void func_0040EA58(void);
extern void func_0040EEA8(void);
extern void func_0040E288(void);
extern void func_0040EE00(void);
extern void func_003FB128(void *);
extern void func_0011EB60(void *);
extern char D_004BE810[];

int func_00408948(void) { return D_00487348; }
void func_003FF190(void) { func_0040EA58(); }
void func_003FF2E8(void) { func_0040EEA8(); }
void func_003FF098(void) { func_0040E288(); }
void func_003FF270(void) { func_0040EE00(); }
void func_003FD9C8(int a, void *b) { func_003FB128(b); }
void func_0040EA08(void) { func_0011EB60(D_004BE810); }

struct H { int p0, p1, p2; };
extern int func_00404488(int);
void func_003F83C0(struct H *p) { func_00404488(p->p2); p->p1 = 0; }
extern char D_004BC4C0[], D_004BB478[], D_004BC248[];
int func_00402620(int *p) {
    if (p == 0) { func_003FB128(D_004BC4C0); return 0; }
    return p[5];
}
int func_003FD480(int *p) {
    if (p == 0) { func_003FB128(D_004BB478); return -3; }
    return p[4];
}
int func_00402118(short *p) {
    if (p == 0) { func_003FB128(D_004BC248); return 0; }
    return p[0x20];
}

void func_003F83A8(int *p) {
    if (p[1] == 0)
        p[1] = 1;
}



struct Slot { void (**fn)(void); int pad[3]; };
extern struct Slot D_0062FB48[];
void func_00406A88(void) {
    struct Slot *s = D_0062FB48;
    int i;
    for (i = 31; i >= 0; i--, s++) {
        if (s->fn != 0 && *s->fn != 0) (*s->fn)();
    }
}

struct B { int p0, p4; long long lim; int p10, p14, p18; int a; int base; int b; };
extern void func_0011D8F8(int, int, int);
void func_0040B1C0(struct B *p) {
    long long lim = p->lim;
    long long end = ((long long)p->a + p->b) << 11;
    if ((unsigned long long)lim < (unsigned long long)end) {
        int n = (int)(end - lim);
        func_0011D8F8(p->base + (p->b << 11) - n, 0, n);
    }
}

extern int func_0011FFA0(char *);
void func_004061C0(unsigned char *s) {
    int len = func_0011FFA0((char *)s);
    unsigned i;
    for (i = 0; i < len + 1U; i++) {
        int c = s[i];
        if ((unsigned)(c - 0x61) < 0x1A) s[i] = c - 0x20;
    }
}


extern volatile int D_0048732C;
extern volatile unsigned D_00487340;
extern char D_004BD678[];
void func_00408628(void) {
    D_00487340 = 0;
    for (;;) {
        if (D_0048732C != 1) return;
        D_00487340 = D_00487340 + 1;
        if (D_00487340 > 0x19640000) {
            func_0011EB60(D_004BD678);
            return;
        }
    }
}


struct Inst;
struct VT { int pad[8]; void (*fn)(struct Inst *, int, void *); };
struct Inst { struct VT *vt; };
struct Obj { int p0; struct Inst *inst; };
struct Ent { signed char flag; char pad[3]; struct Obj *obj; int data[2]; };
struct P { int n; int pad[3]; struct Ent e[1]; };
extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
void func_00410DC8(int unused, struct P *p) {
    int n;
    struct Ent *e;
    if (p == 0) {
        for (;;)
            ;
    }
    n = p->n;
    func_0040EFE0();
    e = (struct Ent *)p;
    if (n > 0) {
        do {
            if (e[1].flag == 0) {
                struct Inst *i = e[1].obj->inst;
                i->vt->fn(i, 1, e[1].data);
            }
            e++;
        } while (--n != 0);
    }
    func_0040EFF8();
}

extern int func_00406B50(void);
extern int func_004064E8(int, int, int);
extern int func_004001A8(int, int, int, int);
extern void func_00400658(int, int);
extern void func_003FB178(void *, int);
extern char D_004BBF18[];
int func_00400528(int a, int b) {
    int s = func_00406B50();
    int v = func_004064E8(a, 0, 0);
    int r;
    if (v == 0) {
        func_003FB178(D_004BBF18, a);
        return 0;
    }
    r = func_004001A8(v, 0, s, b);
    if (r != 0) func_00400658(r, 0);
    return r;
}
