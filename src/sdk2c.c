typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Stream Stream;
typedef struct StreamVT { char pad[0x24]; int (*seek)(Stream *, int); } StreamVT;
struct Stream { StreamVT *vt; };
typedef struct Mid { char pad[8]; Stream *s; } Mid;
typedef struct Outer { char pad[8]; Mid *m; } Outer;

int func_0040EA58(Outer *o) {
    Stream *s = o->m->s;
    return (0x4000 - s->vt->seek(s, 0)) / 2;
}

typedef struct Table { char pad[0xC]; Mid **ent; } Table;
u32 func_003FEFA8(Table *t, int i) {
    Mid **e = t->ent + i;
    Stream *s = e[2]->s;
    return (u32)s->vt->seek(s, 1) >> 1;
}

extern void func_003FB128(void *);
extern char D_004BC3A0[];
typedef struct File { char pad[0x14]; Stream *s; char pad2[0x26]; short blocks; } File;
int func_004023E8(File *f) {
    if (f == 0) {
        func_003FB128(D_004BC3A0);
        return -1;
    }
    if (f->s != 0) {
        if (f->s->vt->seek(f->s, 1) < (f->blocks << 11)) return 0;
        return 1;
    }
    return 0;
}
