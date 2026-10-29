/* func_003F01B0 (r12_10): MW 3.0.3 or 3.0, -O3,p -sdatathreshold 0. Levers: opt_lifetimes off + opt_propagation off (push/pop), separate lo/lo2 per arm, explicit inner offset jo, named m1 = -1 in the else arm, element pointer q assigned before k (sets loop-invariant hoist order). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 pad[0x44]; u32 w44; u8 pad2[4]; } Eb;
typedef struct { s32 w0; u8 pad[0x3C]; } Kb;
extern Eb D_0061B420[];
extern Kb D_006207A0[];
extern Kb D_0061C7A0[];

typedef struct {
    u8 pad[0x28];
    s32 n28;
    s32 n2C;
    u8 pad2[0x20];
    u8 b50[0x20];
    u32 w70[0x20];
    u32 wF0[0x20];
} Pb;

#pragma push
#pragma opt_lifetimes off
#pragma opt_propagation off
void func_003F01B0(Pb *p)
{
    s32 j;
    u32 lo2;
    s32 i;
    Eb *e;
    Kb *k;
    Kb *q;
    s32 o;
    u32 lo;
    u32 v;
    u32 hi;
    s32 jo;
    s32 m1;
    p->n2C = 0;
    for (i = 0, o = 0; i < p->n28; o += 4, i++) {
        e = &D_0061B420[p->b50[i]];
        *(u32 *)((u8 *)p + o + 0x70) = 0;
        if (e->w44 == 0) continue;
        *(u32 *)((u8 *)p + o + 0x70) = e->w44;
        for (j = 0, jo = 0; j < p->n2C; jo += 4, j++) {
            if (*(u32 *)((u8 *)p + 0xF0 + jo) == e->w44) goto next;
        }
        v = e->w44;
        hi = (v & 0xFFFF0000) >> 16;
        if (hi == 0) {
            lo = (v & 0xFFFF) - 1;
            if (D_006207A0[lo].w0 == 3) continue;
        } else {
            m1 = -1;
            lo2 = (v & 0xFFFF) + m1;
            q = &D_006207A0[lo2];
            k = &D_0061C7A0[hi - 1];
            if (q->w0 == 3 && k->w0 == 3) continue;
        }
        p->wF0[p->n2C++] = v;
    next:;
    }
}
#pragma pop
