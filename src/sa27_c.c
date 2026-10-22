typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u16 k; s16 v; } E413;
extern u16 *D_004C2510;

s32 func_00413B20(E413 *e, s32 n, s32 key)
{
    s32 cnt;
    s32 first;
    E413 *q;
    s32 minv;
    s32 best;
    best = -1;
    minv = 0x18;
    q = e + 1;
    first = best;
    cnt = n - 1;
    do {
        *D_004C2510 = q->k;
        if (*D_004C2510 == key + 1) {
            q->v = 0x18;
            return (n - cnt) | 0x80000000;
        }
        if (*D_004C2510 == 0 && first < 0)
            first = cnt;
        if (q->v < minv) {
            minv = q->v;
            best = cnt;
        }
        q++;
    } while (--cnt != 0);
    if (first >= 0) {
        e[n - first].k = key + 1;
        e[n - first].v = 0x18;
        return n - first;
    }
    if (best >= 0) {
        e[n - best].k = key + 1;
        e[n - best].v = 0x18;
        return n - best;
    }
    return 0x80000000;
}
