typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 h2;
    u32 w4;
} Ent;

typedef struct Node {
    struct Node *next;
    u8 pad4[8];
    u16 cnt;
    u8 pad[2];
    u8 name[0x104];
    Ent ents[1];
} Node;

extern Node *D_0047B180[];
extern s32 func_003FD560(s32, s32);
extern void func_00120440(void *, void *, s32);

s32 func_003FD5D8(s32 a0, s32 a1, void *a2, u32 *a3, u32 *a4)
{
    u16 *t;
    s32 r;
    Node *n;
    s32 j;
    u32 sum;

    r = func_003FD560(a0, a1);
    if (r < 0) {
        *a3 = -1;
        *a4 = -1;
        return r;
    }
    n = D_0047B180[a0];
    while (n->next != 0) {
        Ent *base = n->ents;
        for (j = 0; j < n->cnt; j++) {
            Ent *e = &base[j];
            if (base[j].id == a1) {
                func_00120440(a2, n->name, 0x100);
                *a3 = e->w4;
                *a4 = e->h2;
                return r;
            }
        }
        n = n->next;
    }
    sum = *(u16 *)((u8 *)n + 0x114);
    t = (u16 *)((u8 *)n + 0x116);
    for (j = 0; j < a1; j++) {
        sum += t[j];
    }
    func_00120440(a2, (u8 *)n + 0x10, 0x100);
    *a3 = sum;
    *a4 = t[a1];
    return r;
}
