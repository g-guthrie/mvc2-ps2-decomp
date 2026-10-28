typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C240C;
#include "cri_sj_ring_buffer_types.h"
typedef SJCK PR;

void func_00403B20(u8 *p)
{
    extern s32 func_003FF190(void *);
    extern s32 func_003FFF90(void *);
    extern void func_003F9630(void);
    extern void func_003F9660(void);
    extern void func_004104E0(PR *, s32, PR *, PR *);
    extern void *func_0011D8F8(void *, int, unsigned int);
    extern void func_003FF148(s8 *, s32);
    extern void func_003FF160(s32, s32);
    extern void func_0040EA00(s32, s32);
    PR A[2];
    PR B[2];
    PR *pa, *pb;
    s32 i, n, fp, mx, r, a;
    u32 mn, v;
    s32 **q, **q2, **q3;
    s32 *o;

    i = 0;
    r = func_003FF190(*(void **)(p + 0xC));
    a = *(s32 *)(p + 4);
    D_004C240C = r;
    n = func_003FFF90((void *)a);
    func_003F9630();
    mn = *(u32 *)(p + 0x48);
    if (n > 0) {
        q = (s32 **)(p + 0x18);
        do {
            o = *q++;
            (*(void (**)(s32 *, s32, s32, PR *))(*(s32 *)o + 0x18))(o, 0, mn * 2, &A[i]);
            v = (u32)A[i].len >> 1;
            i++;
            if (v < mn) mn = v;
        } while (i < n);
    }
    i = 0;
    if (n > 0) {
        fp = mn * 2;
        q2 = (s32 **)(p + 0x18);
        do {
            pa = &A[i];
            pb = &B[i];
            func_004104E0(pa, fp, pa, pb);
            func_0011D8F8(pa->data, 0, A[i].len);
            i++;
            o = *q2;
            (*(void (**)(s32 *, s32, PR *))(*(s32 *)o + 0x20))(o, 1, pa);
            o = *q2++;
            (*(void (**)(s32 *, s32, PR *))(*(s32 *)o + 0x1C))(o, 0, pb);
        } while (i < n);
    }
    *(s32 *)(p + 0xA8) = *(s32 *)(p + 0xA8) + mn;
    mx = 0;
    func_003F9660();
    if (n > 0) {
        q3 = (s32 **)(p + 0x18);
        i = n;
        do {
            o = *q3++;
            v = (*(u32 (**)(s32 *, s32))(*(s32 *)o + 0x24))(o, 1);
            if ((s32)(v >> 1) >= mx) mx = v >> 1;
        } while (--i != 0);
    }
    if (mx + func_003FF190(*(void **)(p + 0xC)) - *(s32 *)(p + 0xA8) <= 0) {
        func_003FF148(*(s8 **)(p + 0xC), 0);
        func_003FF160(*(s32 *)(p + 0xC), 0);
        func_0040EA00(*(s32 *)(p + 0xC), 1);
        p[1] = 5;
    }
}
