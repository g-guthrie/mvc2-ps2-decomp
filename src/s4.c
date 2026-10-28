#include "runtime_decode_descriptor.h"
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

extern void func_0040EDE0(s32 *, s32);
void func_003FF258(s32 *state, s32 value){ func_0040EDE0(state, value); }

typedef struct S64 S64;
typedef struct { s32 state; S64 *reference; void *input; } Decoder;
extern void func_003F64A0(S64 *reference);
void func_003FF5D0(void *object, void *sj){
    Decoder *decoder = object;
    decoder->input = sj;
    func_003F64A0(decoder->reference);
}

extern s32 func_00406AE8(s32);
typedef struct { s32 a, b, c; } T4;
void func_00400BE8(T4 *p, s32 *out){ *out = func_00406AE8(p->c); }


typedef struct { s32 pad[2]; void *items[1]; } TblF;
typedef struct { s32 pad; s32 f; } ObjF;
typedef struct { s32 pad[3]; TblF *tbl; } HolderF;
extern u32 func_00410AD0(s32, s32);
u32 func_003FF060(HolderF *h, s32 i){ return func_00410AD0(((ObjF *)h->tbl->items[i])->f, 0) >> 1; }


typedef struct { const void *f0; s32 pad[4]; short *f5; s32 pad2[2]; s32 f8; } Q48;
typedef struct { s32 pad[2]; RuntimeDecodeDescriptor *h; } P48b;
extern s32 func_00404408(RuntimeDecodeDescriptor *, const void *, s32, short *);
extern void func_00404468(s32 *);
void func_003F8448(P48b *p, s32 x){
    Q48 *q = (Q48 *)((char *)p + 0x48);
    RuntimeDecodeDescriptor *h = p->h;
    func_00404408(h, q->f0, x, q->f5 + q->f8);
    func_00404468((s32 *)h);
}


#include "cri_sj_ring_buffer_types.h"
/* Provisional: not all callers use the same chunk type or proved bounds. */
void func_004104E0(SJCK *src, s32 max, SJCK *out, SJCK *res){
    *out = *src;
    res->len = out->len;
    if (out->len > max) out->len = max;
    res->len = res->len - out->len;
    if (res->len == 0) res->data = 0; else { s32 n = out->len; s8 *a = out->data; res->data = a + n; }
}

typedef struct { u8 pad[0xC]; void (*callback)(void *); } SlotVtable;
typedef struct { SlotVtable *vtable; } SlotObject;
typedef struct {
    s8 active;
    u8 pad1[2];
    s8 callbackCount;
    void *resource4;
    void *resource8;
    void *resourceC;
    void *callback10;
    u32 pad14;
    SlotObject *callback18;
    u8 pad1C[0x58];
    void *resource74;
    SlotObject *callback78[2];
    SlotObject *callback80[5];
    void *resource94;
    u8 pad98[0x14];
} Slot;
extern void func_003FB128(const char *message);
extern void func_00401400(void);
extern void func_00401868(u8 *slot);
extern void func_003FF0E0(void *object);
extern void func_003FF568(s32 *object);
extern void func_004005F8(u8 *object);
extern void func_0040CD38(u8 *object);
extern void func_003F9630(void);
extern void func_003F60B0(void *object);
extern void *func_0011D8F8(void *destination, s32 value, u32 size);
extern void func_003F9660(void);
extern char gAdxtDiagnostic_004BBFD0[];
void func_00401428(Slot *slot)
{
    SlotObject **firstTable;
    SlotObject **secondTable;
    s32 i;
    SlotObject *object;
    void *resource;

    if (slot == 0) {
        func_003FB128(gAdxtDiagnostic_004BBFD0);
        return;
    }
    func_00401400();
    if (slot->active == 1)
        func_00401868((u8 *)slot);
    if (slot->resourceC != 0)
        func_003FF0E0(slot->resourceC);
    if (slot->resource4 != 0)
        func_003FF568((s32 *)slot->resource4);
    if (slot->resource8 != 0)
        func_004005F8((u8 *)slot->resource8);
    if (slot->resource94 != 0)
        func_0040CD38((u8 *)slot->resource94);
    func_003F9630();
    if (slot->callback10 != 0)
        ((SlotObject *)slot->callback10)->vtable->callback(slot->callback10);
    i = 0;
    if (i < slot->callbackCount) {
        secondTable = slot->callback80;
        firstTable = slot->callback78;
        do {
            /* The per-slot callback at +0x18 is 0x60 bytes before this table. */
            object = *(SlotObject **)((u8 *)firstTable - 0x60);
            if (object != 0)
                object->vtable->callback(object);
            if (*firstTable != 0)
                (*firstTable)->vtable->callback(*firstTable);
            if (*secondTable != 0)
                (*secondTable)->vtable->callback(*secondTable);
            i++;
            firstTable++;
            secondTable++;
        } while (i < slot->callbackCount);
    }
    resource = slot->resource74;
    if (resource != 0)
        func_003F60B0(resource);
    func_0011D8F8(slot, 0, 0xAC);
    slot->active = 0;
    func_003F9660();
}

extern Slot D_0047C620[16];
void func_004015C8(void){
    Slot *p = D_0047C620;
    do {
        if (p->active == 1) func_00401428(p);
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

