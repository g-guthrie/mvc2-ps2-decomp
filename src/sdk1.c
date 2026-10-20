extern void func_0040EE98(void); void func_003FF2D0(void){ func_0040EE98(); }

extern void func_0040C7C0(void *a, int *b);
int func_0040CA48(void *a){ int b[2]; func_0040C7C0(a, b); return b[1] != 0; }

extern void func_00104818(void *first, void *last);
void func_003FB370(int a, long b){ func_00104818((void *)(unsigned int)a, (void *)((unsigned int)a + (unsigned int)b - 1u)); }

extern char D_004BC278[];
extern void func_003FB128(void *p);
void func_00402148(int *p, int v){ if (p == 0) { func_003FB128(D_004BC278); return; } p[14] = v; }

extern char D_004BE2F8[];
extern void func_0040D5A0(void *p);
void func_0040D0D8(char *p, int v){ if (p == 0) { func_0040D5A0(D_004BE2F8); return; } if (v == 1) p[4] = v; else p[4] = 0; }

extern char D_004BC430[];
extern void func_003FB128(void *p);
void func_00402580(char *p){ if (p == 0) { func_003FB128(D_004BC430); return; }  *(short*)(p+0x60)=0; *(int*)(p+0x64)=0; *(short*)(p+0x68)=0; *(short*)(p+0x6A)=0; }

extern void func_00405100(void); extern void func_00405118(void);
void func_00405278(int *p){ if (p) { func_00405100(); *p = 0; func_00405118(); } }

extern int func_0011D6A8(void *, void *, int);
extern char D_004C2218[], D_004C2220[];
int func_003F68A0(char *p){ if (func_0011D6A8(p, D_004C2218, 4) == 0 && func_0011D6A8(p + 8, D_004C2220, 4) == 0) return 1; return 0; }

extern char D_004BCAC8[], D_004BCAE8[]; extern void func_00405DC8(void *);
typedef struct { char pad[0x18]; int (*fn)(int); } Ops;
typedef struct { Ops *ops; int arg; } Obj;
int func_004068F8(Obj *p){ int r; if (p == 0) { func_00405DC8(D_004BCAC8); return 0; } if (p->ops->fn) r = p->ops->fn(p->arg); else { r = 0; func_00405DC8(D_004BCAE8); } return r; }

