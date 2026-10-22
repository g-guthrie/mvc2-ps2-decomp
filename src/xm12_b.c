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
    s8 pad0;
    s8 b1;
    s8 b2;
    u8 pad3;
    SJ_OBJ *sjA;
    SJ_OBJ *sjB;
    SJCK ca;
    SJCK cb;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad30[8];
    s32 f38;
    s32 f3C;
} Obj408960;

extern s32 func_00104180(s32);
extern void func_004104E0(SJCK *, s32, SJCK *, SJCK *);
extern void func_001046D8(void *, void *);
extern s32 func_001041A0(s32 *, s32);
extern s32 func_0011EB60();
extern u8 D_004BD7A8[], D_004BD7C8[], D_004BD7F0[], D_004BD820[], D_004BD848[], D_004BD870[];

void func_00408960(Obj408960 *a)
{
    SJCK c1, c3, c2, c4;
    s32 n;

    if (a->b1 != 1)
        return;
    if (a->b2 == a->b1 && func_00104180(a->f2C) < 0) {
        a->sjA->vtbl->PutChunk(a->sjA, 0, &a->ca);
        a->ca.data = 0;
        a->ca.len = 0;
        a->sjB->vtbl->PutChunk(a->sjB, 1, &a->cb);
        a->cb.data = 0;
        a->f3C += a->ca.len;
        a->cb.len = 0;
        a->b2 = 0;
        if (a->ca.len != 0) {
            func_0011EB60(D_004BD7A8);
            for (;;) {
                __asm__ volatile("nop");
            }
        }
    }
    if ((u8)a->b2 != 0)
        return;
    a->sjA->vtbl->GetChunk(a->sjA, 1, 0x7FFFFFFF, &c1);
    a->sjB->vtbl->GetChunk(a->sjB, 0, 0x7FFFFFFF, &c2);
    n = c2.len;
    if (c1.len < n)
        n = c1.len;
    n = n / a->f38 * a->f38;
    func_004104E0(&c1, n, &c1, &c3);
    a->sjA->vtbl->UngetChunk(a->sjA, 1, &c3);
    func_004104E0(&c2, n, &c2, &c4);
    a->sjB->vtbl->UngetChunk(a->sjB, 0, &c4);
    if (n <= 0)
        return;
    if (c1.len & 0x3F) {
        func_0011EB60(D_004BD7C8);
        func_0011EB60(D_004BD7F0, c1.data, c2.data, c1.len);
        for (;;) {
            __asm__ volatile("nop");
        }
    }
    if ((s32)c1.data & 0x3F) {
        func_0011EB60(D_004BD820);
        func_0011EB60(D_004BD7F0, c1.data, c2.data, c1.len);
        for (;;) {
            __asm__ volatile("nop");
        }
    }
    if ((s32)c2.data & 0x3F) {
        func_0011EB60(D_004BD848);
        func_0011EB60(D_004BD7F0, c1.data, c2.data, c1.len);
        for (;;) {
            __asm__ volatile("nop");
        }
    }
    func_001046D8(c1.data, c1.data + c1.len - 1);
    a->f1C = (s32)c1.data & 0xFFFFFFF;
    a->f20 = (s32)c2.data;
    a->f24 = c1.len;
    a->f28 = 0;
    a->f2C = func_001041A0(&a->f1C, 1);
    if (a->f2C == 0) {
        func_0011EB60(D_004BD870);
        a->sjA->vtbl->UngetChunk(a->sjA, 1, &c1);
        a->sjB->vtbl->UngetChunk(a->sjB, 0, &c2);
        return;
    }
    a->ca = c1;
    a->cb = c2;
    a->b2 = 1;
}
