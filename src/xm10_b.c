typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#include "cri_sj_ring_buffer_types.h"
typedef SJ_OBJ Obj;

typedef struct {
    u32 magic;
    s32 len;
    u8 b8;
    u8 pad9;
    s16 hA;
    s32 fC;
} Hdr;

typedef struct {
    u8 pad0[1];
    u8 b1;
    s8 b2;
    u8 pad3;
    s8 b4;
    u8 pad5[3];
    s32 f8;
    u8 pad0C[0x10];
    Obj *f1C;
    Obj *arr[0x20];
    u8 pad0A0[0xC];
    s8 bAC;
} P;

extern void *memcpy(void *, const void *, u32);

s32 func_00405968(P *p) {
    extern s32 func_00405778(s8 *, s32, Hdr *);
    extern void func_004104E0(SJCK *, s32, SJCK *, SJCK *);
    extern void func_00405100();
    extern void func_00405118();
    Hdr T;
    SJCK U, W, X;
    Obj **q;
    s32 n;
    s32 i;
    s32 ret;
    s32 j;
    s32 idx;
    Obj *o;
    s32 r;

    ret = -3;
    q = p->arr;
    n = p->bAC;
    o = p->f1C;
    for (i = 0; i < n; i++) {
        o->vtbl->GetChunk(o, 1, 0x7FFFFFFF, &U);
        if (func_00405778(U.data, U.len, &T) == 0) {
            o->vtbl->UngetChunk(o, 1, &U);
            return ret;
        }
        if (U.len < T.len + 8) {
            o->vtbl->UngetChunk(o, 1, &U);
            return ret;
        }
        if (T.magic == 0x41495845) {
            idx = T.b8;
            func_004104E0(&U, T.len + 8, &U, &W);
            o->vtbl->PutChunk(o, 0, &U);
            o->vtbl->UngetChunk(o, 1, &W);
            r = o->vtbl->GetNumData(o, 1);
            if (r <= 0) p->b4 = 0;
            if (p->b4 == 0) p->b1 = 3;
            return ret;
        }
        idx = T.b8;
        if (!(idx < p->b2)) for (;;) ;
        if (q[idx]->vtbl->GetNumData(q[idx], 0) < T.hA) {
            o->vtbl->UngetChunk(o, 1, &U);
            return ret;
        }
        func_00405100();
        ret = T.fC;
        func_004104E0(&U, T.len + 8, &U, &W);
        o->vtbl->UngetChunk(o, 1, &W);
        func_004104E0(&U, 0x10, &U, &W);
        if (W.len < T.hA) for (;;) ;
        j = 0;
        if (T.hA > 0) {
            do {
                q[idx]->vtbl->GetChunk(q[idx], 0, W.len - j, &X);
                memcpy(X.data, W.data + j, X.len);
                q[idx]->vtbl->PutChunk(q[idx], 1, &X);
                j += X.len;
            } while (j < T.hA);
        }
        o->vtbl->PutChunk(o, 0, &U);
        o->vtbl->PutChunk(o, 0, &W);
        p->f8 += U.len + W.len;
        func_00405118(p->f8);
    }
    return ret;
}
