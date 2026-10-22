typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct _sj_vtbl;
typedef struct { signed char *data; signed int len; } SJCK;
typedef struct SJ_OBJ { struct _sj_vtbl *vtbl; } SJ_OBJ;
struct _sj_vtbl {
    void (*QueryInterface)(void);
    void (*AddRef)(void);
    void (*Release)(void);
    void (*Destroy)(SJ_OBJ *object);
    void *(*GetUuid)(SJ_OBJ *object);
    void (*Reset)(SJ_OBJ *object);
    void (*GetChunk)(SJ_OBJ *object, signed int id, signed int nbyte, SJCK *chunk);
    void (*UngetChunk)(SJ_OBJ *object, signed int id, SJCK *chunk);
    void (*PutChunk)(SJ_OBJ *object, signed int id, SJCK *chunk);
};

typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0xC];
    SJ_OBJ *sj;
    u8 pad18[0x30];
    s32 f48;
    u8 pad4C[0x4C];
    s8 f98;
    u8 pad99[0xB];
    s32 fA4;
} Obj;

extern s32 func_003F9F80(s8 *, s32, s16 *);
extern s32 func_003F98C8(s8 *, s32, s16 *);
extern void func_004104E0(SJCK *, s32, SJCK *, SJCK *);
extern s32 func_003FFEC8(s32);
extern void func_003FF658(s32);
extern void func_003FF628(s32);
extern void func_003FFE20(s32);
extern s32 func_003FF5C8(s32);
extern void func_003FF600(s32, s32);
extern s32 func_003FFFF0(s32);
extern void func_003FFF30(s32, s32);
extern void func_003FFF50(s32, s32);
extern void func_003FFF40(s32, s32);

void func_00403308(Obj *a)
{
    SJCK c1, c3, c2, c4;
    s16 n, m;
    s32 h, r, v1, s0, s6, tot;
    SJ_OBJ *sj;
    h = a->f4;
    sj = a->sj;
    if (a->f98 == 0) return;
    m = 0;
    sj->vtbl->GetChunk(sj, 1, 0x7FFFFFFF, &c1);
    sj->vtbl->GetChunk(sj, 1, 0x7FFFFFFF, &c2);
    if (func_003F9F80(c1.data, c1.len, &n) != 0) {
        a->f98 = 0;
        sj->vtbl->UngetChunk(sj, 1, &c2);
        sj->vtbl->UngetChunk(sj, 1, &c1);
        return;
    }
    s0 = n;
    r = func_003F98C8(c1.data + s0, c1.len - s0, &n);
    v1 = -1;
    if (r != 0) v1 = func_003F98C8(c2.data, c2.len, &m);
    tot = s0 + n;
    s6 = m;
    if (r != 0 && v1 != 0) {
        sj->vtbl->UngetChunk(sj, 1, &c2);
        sj->vtbl->UngetChunk(sj, 1, &c1);
        a->f98 = 0;
        return;
    }
    if (r == 0) {
        sj->vtbl->UngetChunk(sj, 1, &c2);
        func_004104E0(&c1, tot, &c1, &c3);
        sj->vtbl->PutChunk(sj, 0, &c1);
        sj->vtbl->UngetChunk(sj, 1, &c3);
    } else {
        sj->vtbl->PutChunk(sj, 0, &c1);
        func_004104E0(&c2, s6, &c2, &c4);
        sj->vtbl->PutChunk(sj, 0, &c2);
        sj->vtbl->UngetChunk(sj, 1, &c4);
    }
    a->fA4 += func_003FFEC8(h);
    func_003FF658(h);
    func_003FF628(h);
    func_003FFE20(h);
    if (func_003FF5C8(h) != 2) {
        a->f98 = 0;
    } else {
        func_003FF600(h, a->f48);
        func_003FFF30(h, func_003FFFF0(h));
        func_003FFF50(h, 0);
        func_003FFF40(h, 0);
    }
}
