typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct N { s32 key; u8 pad[0x34]; struct N *next; } N;
typedef struct M { u8 pad[8]; N *list; u8 pad2[8]; struct M *next; } M;
typedef struct O { u8 pad[0x28]; M *m; } O;
N *func_00106B98(s32 key, O *o) {
    M *m;
    N *n;
    for (m = o->m; m; m = m->next)
        for (n = m->list; n; n = n->next)
            if (n->key == key) return n;
    return 0;
}
