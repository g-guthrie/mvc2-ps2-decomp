extern int D_004399A8;
extern volatile int D_004399AC;
extern int D_004399A0;
extern int D_004399B0;
extern unsigned func_00103DE0(int *);


typedef struct {
    int f0;
    int f4;
} S6C80;
extern S6C80 D_004C6C80;
extern int D_004382FC;
extern int func_00107AB8(int);
extern void func_00107BC0(void);
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_00107AE8(void);

int func_00107AF8(int a0, int a1) {
    int old;
    int en;
    S6C80 *p;

    p = &D_004C6C80;
    func_00107AB8(0x1B);
    if (D_004382FC == 0) {
        func_00107BC0();
    }
    en = func_0010CA20();
    old = D_004C6C80.f0;
    p->f4 = a1;
    D_004C6C80.f0 = a0;
    if (en) {
        func_0010CA68();
    }
    func_00107AE8();
    return old;
}

extern char D_004C6E88[];
extern char D_004C7080[];
extern int func_0010B198(int);
extern int func_0010B298(void);
extern char *func_00120440(char *, int, int);
extern int func_00106E68(void *, int, int, void *, int, void *, int, int, int);

int func_0010B800(int a0) {
    int r;
    char *p;
    char *base;

    r = func_0010B198(a0);
    if (r < 0) {
        return 0xFFFF0000;
    }
    if (func_0010B298() != 0) {
        return 0xFFFEFFFC;
    }
    p = D_004C6E88;
    func_00120440(p, a0, 0xFC);
    base = p - 8;
    base[0x103] = 0;
    r = func_00106E68(D_004C7080, 9, 0, base, 0x200, base, 4, 0, 0);
    if (r < 0) {
        return 0xFFFEFFFF;
    }
    return *(int *)base;
}

extern int D_00438254;
extern int func_00103DC0(void);
extern int *func_0011B370(void);

unsigned func_001044E0(unsigned a0) {
    unsigned s0;
    int st;
    int v;
    unsigned old;

    asm volatile ("mfc0 %0, $12" : "=r"(st));
    st = st & 0x10000;
    if (st) {
        do {
            asm volatile ("di");
            asm volatile ("sync.p");
            asm volatile ("mfc0 %0, $12" : "=r"(v));
        } while (v & 0x10000);
    }
    s0 = D_00438254 + a0;
    if ((unsigned)func_00103DC0() < (unsigned)s0) {
        *func_0011B370() = 0xC;
        if (st) {
            asm volatile ("ei");
        }
        return 0xFFFFFFFF;
    }
    old = D_00438254;
    D_00438254 = s0;
    if (st) {
        asm volatile ("ei");
    }
    return old;
}

extern int D_00438260;
extern unsigned char D_004C3980[];
extern void func_00104FF8(unsigned char *);

void func_00105578(int c) {
    int idx;

    idx = D_00438260;
    if (idx >= 0x7E) {
        D_00438260 = 0;
        D_004C3980[0x7F] = 0;
        func_00104FF8(D_004C3980);
        idx = D_00438260;
    }
    if (c == 10) {
        D_00438260 = 0;
        D_004C3980[idx] = c;
        D_004C3980[idx + 1] = 0;
        func_00104FF8(D_004C3980);
        return;
    }
    D_00438260 = idx + 1;
    D_004C3980[idx] = c;
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int pad2[2];
} E1C;
typedef struct {
    E1C e[4];
} E70;
extern E1C D_004C83D0[][4];
extern unsigned char *func_0010D860(int);


extern volatile int D_004399D4;
extern volatile int D_004399AC;
extern char D_0043AB80[];
extern char D_0043B3C8[];
extern int func_0010F258(int);
extern void func_00103E00(int);

int func_0010FBE0(void) {
    int v;
    int r;
    int res;

    if (func_0010F258(0x1E) == 0) {
        return 0;
    }
    D_004399D4 = 8;
    r = func_00106E68(D_0043B3C8, 0x16, 0, 0, 0, D_0043AB80, 4, 0, 0);
    if (r < 0) {
        func_00103E00(D_004399AC);
        D_004399D4 = 0;
        res = 0;
    } else {
        D_004399D4 = 0;
        v = *(int *)((unsigned)D_0043AB80 | 0x20000000);
        func_00103E00(D_004399AC);
        res = v;
    }
    return res;
}

typedef struct {
    volatile int f0;
    int f4;
    int f8;
    int fC;
    char *f10;
    char *f14;
    int f18;
} S36D0;
extern S36D0 D_004C36D0;
extern char D_004C3700[];
extern char D_004C3840[];
extern void func_00104060(int);
extern int func_00104E40(int, void *, void *);
extern void func_001050C8(void);
extern int func_00105020(int);


typedef struct {
    char pad[0x24];
    int f24;
} S8900;
typedef struct {
    int f0;
    int f4;
} S8980;
extern S8900 D_004C8900;
extern S8980 D_004C8980;
extern int D_0043B404;
extern int D_004C9EC0;
extern int func_00103E30(int);

int func_00110070(int a0) {
    int res;

    if (D_004C8900.f24 == 0) {
        return -0x64;
    }
    if (func_00103E30(D_0043B404) < 0) {
        return -0xC8;
    }
    D_004C8980.f4 = a0;
    res = func_00106E68(&D_004C8900, 0x15, 0, &D_004C8980, 0x30, &D_004C9EC0, 4, 0, 0);
    if (res != 0) {
        func_00103E00(D_0043B404);
        return res;
    }
    func_00103E00(D_0043B404);
    return D_004C9EC0;
}

typedef struct {
    int a;
    int b;
} E8;
extern E8 D_004386A8[];
extern int D_004386A0;
extern char D_00438328[];
extern void func_0010C2E8(int, int);
extern int func_0010C2D8(int);
extern void func_0010C290(unsigned, void *, int);

void func_0010C2F8(void) {
    E8 *e;
    E8 *q;
    unsigned i;
    int r;

    e = D_004386A8;
    func_0010C2E8(e[0].a, e[0].b);
    func_0010C290(0x80075000, D_00438328, 0x330);
    func_00104060(0);
    func_00104060(2);
    func_0010C2E8(e[1].a, e[1].b);
    func_0010C2E8(e[2].a, e[2].b);
    q = e + 3;
    i = 3;
    do {
        i++;
        r = func_0010C2D8(q->a);
        func_0010C2E8(q->a, r);
        q++;
    } while (i < 8);
    D_004386A0 = func_0010C2D8(3);
}

extern unsigned long *func_00100468();

short func_001009C8(short a0, short a1, short a2) {
    int w;
    int h;
    unsigned long *p;
    int prod;

    p = func_00100468();
    w = (a1 + 63) / 64;
    if (a0 & 2) {
        h = (a2 + 63) / 64;
    } else {
        h = (a2 + 31) / 32;
    }
    if ((*p & 0xFFFF0000FFFFUL) == 1) {
        prod = w * h;
        return prod;
    }
    prod = w * h;
    return prod * 2;
}

typedef struct {
    int f0;
    int count;
} S3168;
extern S3168 D_004C3168;
extern char _gp[];
extern int D_00438258;
extern int D_004C3160;
extern char D_004C2D60[];
extern void func_00104AE0(void);
extern int func_00103BE0(void *);
extern void func_00103DF0(int);
extern void func_00103C00(int, void *);
extern int func_00103CD0(void);
extern void func_00103C70(int, int);

int func_00104BB8(void) {
    int th[12];
    int sema[8];
    int r;

    if (D_00438258 > 0) {
        return -1;
    }
    sema[2] = 0;
    sema[1] = 0xFF;
    D_004C3160 = func_00103DE0(sema);
    if (D_004C3160 < 0) {
        return -1;
    }
    th[1] = (int)func_00104AE0;
    th[2] = (int)D_004C2D60;
    th[3] = 0x400;
    th[4] = (int)_gp;
    th[5] = 0;
    r = func_00103BE0(th);
    D_00438258 = r;
    if (r < 0) {
        func_00103DF0(D_004C3160);
        return -1;
    }
    D_004C3168.f0 = 0;
    D_004C3168.count = 0;
    func_00103C00(r, &D_004C3168);
    func_00103C70(func_00103CD0(), 1);
    return D_00438258;
}

typedef struct {
    int f0;
    int f4;
    int f8;
    unsigned char name[8];
    int f14;
} S85C0;
extern S85C0 D_004C85C0;
extern char D_004C8380[];
extern void func_0010DA40(int, int, int);

int func_0010E020(int a0, int a1, unsigned char *a2) {
    S85C0 *p;
    int i;
    int v;
    int res;

    p = &D_004C85C0;
    p->f0 = 8;
    p->f4 = a0;
    p->f8 = a1;
    i = 0;
    do {
        p->name[i] = a2[i];
        i++;
    } while (i < 6);
    if (func_00106E68(D_004C8380, 1, 0, p, 0x80, p, 0x80, 0, 0) < 0) {
        return 0;
    }
    v = p->f14;
    if (v == 1) {
        func_0010DA40(a0, a1, 2);
        v = p->f14;
    }
    return v;
}

typedef struct {
    int f0;
    int f4;
    int f8;
} S6E80;
extern S6E80 D_004C6E80;


extern int D_0043B400;
extern int func_00107058(void *);
extern void func_00110770(int);

int func_001107B8(int a0, int *a1, int *a2) {
    int r;

    if (D_0043B400 == 0) {
        return -1;
    }
    r = func_00107058(&D_004C8900);
    if (a0 == 0 && r != 0) {
        while (func_00107058(&D_004C8900) != 0) {
            func_00110770(0x3C);
        }
        r = 0;
    }
    r = (r == 0);
    if (a1 != 0) {
        *a1 = D_0043B400;
    }
    if (r != 0) {
        D_0043B400 = 0;
        if (a2 != 0) {
            *a2 = D_004C9EC0;
        }
        func_00103E00(D_0043B404);
    }
    return r;
}

typedef struct {
    char b[8];
} U8;
extern int D_00439990;
extern char D_004AB598[];
extern char D_004AB5B8[];
extern void func_00105E80(char *, ...);

int func_0010FC98(U8 *a0) {
    int v;

    if (func_0010F258(0xF) == 0) {
        return 0;
    }
    if (D_00439990 > 0) {
        func_00105E80(D_004AB598);
    }
    if (func_00106E68(D_0043B3C8, 1, 0, 0, 0, D_0043AB80, 0x10, 0, 0) < 0) {
        func_00103E00(*(int *)&D_004399AC);
        return 0;
    }
    *a0 = *(U8 *)(((unsigned)D_0043AB80 + 4) | 0x20000000);
    if (D_00439990 > 0) {
        func_00105E80(D_004AB5B8);
    }
    v = *(int *)((unsigned)D_0043AB80 | 0x20000000);
    func_00103E00(D_004399AC);
    return v;
}

extern char D_004C6E88[];

int func_0010BBD8(char *a0, char *a1, int *a2, int a3) {
    int r;
    int v;
    char *p;
    char *base;
    extern int func_0010B198();

    if (func_0010B198() < 0) {
        return 0xFFFF0000;
    }
    if (func_0010B298() != 0) {
        return 0xFFFEFFFC;
    }
    p = D_004C6E88;
    func_00120440(p, (int)a0, 0xFC);
    base = p - 8;
    base[0x103] = 0;
    func_00120440(p + 0xFC, (int)a1, 0xFC);
    base[0x1FF] = 0;
    r = func_00106E68(D_004C7080, a3, 0, base, 0x200, base, 0x10, 0, 0);
    if (r < 0) {
        return 0xFFFEFFFF;
    }
    v = *(int *)base;
    if (v == 0) {
        return 0xFFFEFFFD;
    }
    a2[0] = v;
    a2[1] = ((int *)base)[1];
    return 0;
}



typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    char name[0x40];
} S70C0;
extern S70C0 D_004C70C0;
extern void func_001040B0(char *);
extern int func_001041F0(unsigned);
extern void func_00106578(void *, int);
extern void func_001041E0(unsigned, unsigned);
extern int func_001041A0(void *, int);


typedef struct {
    int f0;
    int f4;
} S9158;
extern S9158 D_00439158;
extern void func_0010CEA8(int, int);
extern int func_0010CE68(char *, void *, int);
extern int func_0011FFA0(char *);

char *func_0010CEB8(char *a0, int a1, char **a2) {
    char *base;
    char *end;
    char *cur;
    int n;
    S9158 *q;
    char **t;

    base = (char *)D_004386A0;
    q = &D_00439158;
    cur = base + 0x40;
    end = cur;
    func_0010CEA8(D_00439158.f0, q->f4);
    if (a1 >= 0x10) {
        a1 = 0xF;
    }
    func_0010CE68(base, &cur, 4);
    base += 4;
    n = func_0011FFA0(a0) + 1;
    func_0010CE68(cur, a0, n);
    cur += n;
    if (a1 > 0) {
        t = a2;
        do {
            func_0010CE68(base, &cur, 4);
            base += 4;
            a1--;
            n = func_0011FFA0(*t) + 1;
            func_0010CE68(cur, *t, n);
            t++;
            cur += n;
        } while (a1 != 0);
    }
    return end;
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} S5500;
extern S5500 D_004C5500;
extern char D_004C6C00[];
extern char D_004C6140[];
extern void func_00103E20(int);

int func_00109550(int a0) {
    int sema[8];
    int buf[4];
    int s1;
    int v;
    S5500 *p;

    p = &D_004C5500;
    func_00107AB8(0xF);
    if (D_004382FC == 0) {
        func_00107BC0();
    }
    p->fC = a0;
    sema[1] = 1;
    sema[2] = 0;
    sema[5] = 0;
    s1 = func_00103DE0(sema);
    D_004C5500.f0 = s1;
    p->f4 = (int)buf;
    p->f8 = 4;
    if (func_00106E68(D_004C6C00, 0xF, 0, p, 0x10, D_004C6140, 4, 0, 0) < 0) {
        func_00103DF0(s1);
        func_00107AE8();
        return -1;
    }
    v = *(int *)((unsigned)D_004C6140 | 0x20000000);
    func_00107AE8();
    if (v == 0) {
        func_00103DF0(s1);
        return -1;
    }
    func_00103E20(s1);
    func_00103DF0(s1);
    return buf[0];
}

typedef struct {
    int a;
    int b;
    int c;
    int d;
} E16;
extern int D_004C3AE0;
extern int func_001041B0(void *, int);


typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
} SC98;
extern char D_004C5480[];
extern SC98 *func_001067F0(void *);
extern int func_001063D0(unsigned, void *, int, int, int, int);
extern void func_00106898(void *);

int func_00106C98(SC98 *a0, int a1, unsigned a2) {
    SC98 *p;
    int sema[8];

    a0->f10 = 0;
    a0->f24 = 0;
    p = func_001067F0(D_004C5480);
    if (p == 0) {
        return -1;
    }
    a0->f4 = p->f18;
    a0->f0 = (int)p;
    p->f20 = a1;
    p->f14 = (int)p;
    p->f1C = (int)a0;
    if ((a2 & 1) == 0) {
        sema[1] = 1;
        sema[2] = 0;
        a0->f8 = func_00103DE0(sema);
        if (a0->f8 < 0) {
            func_00106898(p);
            return -3;
        }
        if (func_001063D0(0x80000009, p, 0x40, 0, 0, 0) == 0) {
            func_00106898(p);
            func_00103DF0(a0->f8);
            return -2;
        }
        func_00103E20(a0->f8);
        func_00103DF0(a0->f8);
        return 0;
    }
    a0->f8 = -1;
    if (func_001063D0(0x80000009, p, 0x40, 0, 0, 0) == 0) {
        func_00106898(p);
        return -2;
    }
    return 0;
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char name[0x400];
} S89B0;
extern S89B0 D_004C89B0;

int func_00110AE0(int a0, int a1, char *a2, int a3, int t0, int t1) {
    int res;

    if (D_004C8900.f24 == 0) {
        return -0x64;
    }
    if (func_00103E30(D_0043B404) < 0) {
        return -0xC8;
    }
    if (a2 == 0 || *a2 == 0) {
        func_00103E00(D_0043B404);
        return -0xD2;
    }
    D_004C89B0.f0 = a0;
    D_004C89B0.f4 = a1;
    D_004C89B0.f8 = a3;
    D_004C89B0.fC = t0;
    D_004C89B0.f10 = t1;
    func_00120440(D_004C89B0.name, (int)a2, 0x3FF);
    D_004C89B0.name[0x3FF] = 0;
    if (t0 >= 0) {
        func_00106578((void *)t1, t0 << 6);
    }
    res = func_00106E68(&D_004C8900, 0xD, 1, &D_004C89B0, 0x414, &D_004C9EC0, 4, 0, 0);
    if (res == 0) {
        D_0043B400 = 0xD;
    } else {
        func_00103E00(D_0043B404);
    }
    return res;
}

extern int func_00104EB0(int, int);
extern void func_00104EE0(int);


typedef struct {
    int f0;
    int f4;
} S76;
typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
} S5500b;
extern S76 *func_00107670(int);

int func_001098C0(int a0, int a1) {
    int sema[8];
    int buf[4];
    int s1;
    int v;
    int w;
    S76 *q;
    S5500 *p;

    p = &D_004C5500;
    q = func_00107670(a0);
    func_00107AB8(0xB);
    if (D_004382FC == 0) {
        func_00107AE8();
        return -1;
    }
    if (q == 0 || q->f4 == 0) {
        func_00107AE8();
        return -9;
    }
    w = q->f0;
    ((int *)p)[4] = a1;
    p->fC = w;
    sema[1] = 1;
    sema[2] = 0;
    sema[5] = 0;
    s1 = func_00103DE0(sema);
    D_004C5500.f0 = s1;
    p->f4 = (int)buf;
    p->f8 = 4;
    if (func_00106E68(D_004C6C00, 0xB, 0, p, 0x20, D_004C6140, 4, 0, 0) < 0) {
        func_00103E20(s1);
        func_00107AE8();
        return -0xB;
    }
    v = *(int *)((unsigned)D_004C6140 | 0x20000000);
    func_00107AE8();
    if (v == 0) {
        func_00103DF0(s1);
        return -0xB;
    }
    func_00103E20(s1);
    func_00103DF0(s1);
    return buf[0];
}

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int pad[3];
} EN1C;
typedef struct {
    EN1C e[4];
} EN70;

extern int D_0043991C;
extern char D_004AB268[];
extern int func_00104180(void);
extern int func_001046D8(int *, int *, int);

