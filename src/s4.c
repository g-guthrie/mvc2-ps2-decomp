typedef signed int s32;
typedef unsigned int u32;

extern void func_0040EDE0(void);
void func_003FF258(void){ func_0040EDE0(); }

typedef struct { s32 a; s32 b; s32 c; } T3;
extern void func_003F64A0(s32);
void func_003FF5D0(T3 *p, s32 v){ p->c = v; func_003F64A0(p->b); }

extern s32 func_00406AE8(s32);
typedef struct { s32 a, b, c; } T4;
void func_00400BE8(T4 *p, s32 *out){ *out = func_00406AE8(p->c); }


typedef struct { s32 pad[2]; void *items[1]; } TblF;
typedef struct { s32 pad; s32 f; } ObjF;
typedef struct { s32 pad[3]; TblF *tbl; } HolderF;
extern u32 func_00410AD0(s32, s32);
u32 func_003FF060(HolderF *h, s32 i){ return func_00410AD0(((ObjF *)h->tbl->items[i])->f, 0) >> 1; }


typedef struct { s32 f0; s32 pad[4]; s32 f5; s32 pad2[2]; s32 f8; } Q48;
typedef struct { s32 pad[2]; s32 h; } P48b;
extern void func_00404408(s32, s32, s32, s32);
extern void func_00404468(s32);
void func_003F8448(P48b *p, s32 x){
    Q48 *q = (Q48 *)((char *)p + 0x48);
    s32 h = p->h;
    func_00404408(h, q->f0, x, q->f5 + q->f8 * 2);
    func_00404468(h);
}


typedef struct { s32 a; s32 n; } RP;
void func_004104E0(RP *src, s32 max, RP *out, RP *res){
    *out = *src;
    res->n = out->n;
    if (out->n > max) out->n = max;
    res->n = res->n - out->n;
    if (res->n == 0) res->a = 0; else { s32 n = out->n; s32 a = out->a; res->a = a + n; }
}

typedef struct { signed char flag; char pad[0xAB]; } Slot;
extern Slot D_0047C620[16];
extern void func_00401428(Slot *);
void func_004015C8(void){
    Slot *p = D_0047C620;
    do {
        if (p->flag == 1) func_00401428(p);
        p++;
    } while ((s32)p < (s32)(D_0047C620 + 16));
}

typedef struct { char pad[3]; signed char count; s32 pad2[2]; void *items[1]; } Grp;
extern void func_00404CA0(Grp *);
extern void func_004026B0(void *, s32);
void func_00404D18(Grp *g, s32 a){
    s32 i;
    func_00404CA0(g);
    *(s32 *)((char *)g + 0x1A4) = a;
    for (i = 0; i < g->count; i++)
        if (g->items[i]) func_004026B0(g->items[i], a);
}

typedef struct { s32 val; char name[12]; } Ent;
extern Ent D_0062FB48[32];
extern s32 func_00120288(s32, void *, s32);
s32 func_004063B0(s32 a, s32 b){
    s32 i;
    for (i = 0; i < 32; i++)
        if (!func_00120288(a, D_0062FB48[i].name, b)) return 1;
    return 0;
}

extern s32 func_0011FFA0(s32);
s32 func_00406128(s32 a){
    u32 i;
    s32 r = func_0011FFA0(a);
    for (i = 0; i < 32; i++)
        if (!func_00120288(a, D_0062FB48[i].name, r)) return D_0062FB48[i].val;
    return 0;
}

