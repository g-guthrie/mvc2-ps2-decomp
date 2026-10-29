/* func_001076E0: libkernl _sceFs_Rcv_Intr (SDK 2.5 double-buffered), Sony EE GCC 2.9.
 * Adapted from OpenRAC/rac1-decomp src/core/00119D88.c
 * (https://github.com/OpenRAC/rac1-decomp), licensed under the GNU General
 * Public License version 3; this file is distributed under the same license
 * (see LICENSES/GPL-3.0.txt). Changes: symbol names mapped to this project. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;

typedef struct {
    s32 v;
} __attribute__((packed)) Word;

typedef struct {
    Word ret;
    Word func;
    Word dest;
    Word size;
} FsRcvHead;

typedef struct {
    void *dest;
} __attribute__((packed)) FsRcvPtr;

typedef struct {
    Word dest;
    Word size;
} FsRcvBuf;

typedef struct {
    s32 n1;
    s32 n2;
    u8 *d1;
    u8 *d2;
    u8 buf1[0x40];
    u8 buf2[0x40];
} FsRcvRead;

typedef struct {
    u8 b[0x144];
} __attribute__((packed)) FsDirent;

typedef struct {
    u8 b[0x40];
} __attribute__((packed)) FsStat;

extern volatile s32 D_00438278[];
extern u32 D_004382F8[];
extern s32 D_00438300[];
extern u8 D_004C6180[];
extern void *memcpy(void *, const void *, u32);
extern int func_00103E10(int);

void func_001076E0(s32 *arg) {
    FsRcvHead h;
    FsRcvHead *src;
    FsRcvBuf *bs;
    union {
        FsRcvPtr p;
        FsRcvBuf b;
    } u;
    FsRcvRead *r;
    u8 *pkt;
    u8 *base;
    u8 *d;
    u32 *bank = D_004382F8;
    s32 idx;
    s32 i;
    s64 ret;
    u32 n;
    u32 addr;

    idx = D_00438300[0] != 0 ? arg[3] : 0;
    *bank = idx;
    base = D_004C6180;
    addr = (u32)base;
    addr += (u32)idx * 0x440;
    pkt = (u8 *)(addr | 0x20000000);
    src = (FsRcvHead *)pkt;
    h.ret = src->ret;
    h.func = src->func;
    h.dest = src->dest;
    h.size = src->size;
    if (h.ret.v >= 0) {
        memcpy((void *)h.dest.v, pkt + 0x10, h.size.v);
    }
    switch (h.func.v) {
    case 2:
        r = (FsRcvRead *)(pkt + 0x14);
        if (r->n1 > 0) {
            d = r->d1;
            for (i = 0; i < r->n1; i++) {
                d[i] = r->buf1[i];
            }
        }
        if (r->n2 > 0) {
            d = r->d2;
            for (i = 0; i < r->n2; i++) {
                d[i] = r->buf2[i];
            }
        }
        break;
    case 11:
        u.p = *(FsRcvPtr *)(pkt + 0x14);
        *(FsDirent *)u.p.dest = *(FsDirent *)(pkt + 0x18);
        break;
    case 12:
        u.p = *(FsRcvPtr *)(pkt + 0x14);
        *(FsStat *)u.p.dest = *(FsStat *)(pkt + 0x18);
        break;
    case 23:
    case 25:
    case 26:
        bs = (FsRcvBuf *)(pkt + 0x14);
        u.b.dest = bs->dest;
        u.b.size = bs->size;
        n = u.b.size.v;
        if (n > 0x400) {
            u.b.size.v = 0x400;
            n = 0x400;
        }
        memcpy((void *)u.b.dest.v, pkt + 0x1C, n);
        break;
    }
    if (h.ret.v < 0) {
        u32 semaphore = 0u - (u32)h.ret.v;
        ret = (s32)semaphore;
        h.ret.v = (s32)semaphore;
        for (i = 0; i < 32; i++) {
            if (((s32 *)D_00438278)[i] == ret) {
                D_00438278[i] = -1;
                break;
            }
        }
        return;
    }
    func_00103E10(h.ret.v);
}
