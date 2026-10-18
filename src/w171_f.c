typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002F4260(u8 *p, u8 *q)
{
    extern void func_002F4390(u8 *, u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_002F4570(u8 *, u8 *);
    extern void func_00175700(u8 *);
    u32 t;
    if (p[0x269] == 8) {
        func_002F4390(p, q, 0);
        return;
    }
    if ((*(u16 *)(p + 0x35E) & 0x3C00) != 0) {
        t = *(u16 *)(p + 0x362);
        if ((t & 0x300) != 0) {
            func_002F4390(p, q, 0);
            return;
        }
        if ((t & 0x60) == 0) goto tail;
        func_002F4390(p, q, 1);
        return;
    } else {
        t = *(u16 *)(p + 0x362);
        if ((t & 0x300) != 0) {
            p[6] = 9;
            func_001E3210(p, 0x17);
            func_002F4570(p, q);
            return;
        }
        if ((t & 0x60) == 0) goto tail;
        p[6] = 10;
        func_001E3210(p, 0x16);
        func_002F4570(p, q);
        return;
    }
tail:
    func_00175700(p);
}

extern u8 D_004621B0[];
extern u8 D_004621C0[];
extern u8 D_004621D0[];
extern u8 D_004621E0[];

void func_0034CF60(u8 *p)
{
    extern void func_0034D080();
    u8 *q = *(u8 **)(p + 0x18);
    u32 k = q[0x22];
    if (k != 0 && *(s16 *)(p + 0x1E) == 0) {
        if (p[0x20] == 1 && (k & 0xFF) == 1) {
            p[5] = 3;
            p[0x22] = D_004621B0[q[0x21]];
        }
        if (p[0x20] == 0 && q[0x22] == 2) {
            p[5] = 3;
            p[0x22] = D_004621C0[q[0x21]];
        }
        if (p[0x20] == 1 && q[0x22] == 3) {
            p[5] = 3;
            p[0x22] = D_004621D0[q[0x21]];
        }
        if (p[0x20] == 0 && q[0x22] == 4) {
            p[5] = 3;
            p[0x22] = D_004621E0[q[0x21]];
        }
        func_0034D080(p);
    }
}

s32 func_0018BDA0(u8 *p, u8 *q)
{
    extern s32 func_00168F80();
    extern void func_0018D660(u8 *, u8 *);
    u8 *s;
    u32 k;
    s32 m;
    s = *(u8 **)(p + 0x1D0);
    if ((s[2] & 8) != 0) {
        return 0;
    }
    if (*(s8 *)(p + 0x539) != 0 && func_00168F80(p) != 0) {
        func_0018D660(p, q);
        return 1;
    }
    if (p[5] != 0) {
        return 0;
    }
    k = p[0x1E4];
    if (k != 0x13 && k != 0x12) {
        return 0;
    }
    m = *(s8 *)(s + 2) & 0xF;
    if (m != 0) {
        if ((u8)m == 2) {
            if (p[0x20D] == 1 && (*(u16 *)(p + 0x354) & 0x1000) != 0) {
                return 0;
            }
        } else if ((u8)m == 4) {
            if (p[0x20D] != 1 && (*(u16 *)(p + 0x354) & 0x1000) == 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    func_0018D660(p, q);
    return 1;
}

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[0x13C - 0x64];
    u8 b13c;
    u8 pad13d[0x140 - 0x13D];
    s16 h140;
} PS;

void func_003B6FF0(PS *p, PS *q)
{
    u8 *r = *(u8 **)((u8 *)p + 0x14) + 0x88;
    PS *s = *(PS **)((u8 *)p + 8);
    u32 k;
    u32 m;
    if (p->b21 == 0) {
        k = p->b20;
        if (k == 0 || k == 2) {
            *(u32 *)&p->f5c = 0x4312AAAA;
            *(u32 *)&p->f60 = 0x435EDB6D;
        } else {
            *(u32 *)&p->f5c = 0x4312AAAA;
            *(u32 *)&p->f60 = 0x430B4924;
        }
        if (p->h140 == 0) {
            p->f5c = -p->f5c;
        }
        p->f34 = q->f34 + p->f5c;
        p->f38 = q->f38 + p->f60;
    } else {
        m = p->b21;
        if ((s32)m <= *(s16 *)(r + 6)) {
            *(u32 *)&p->f5c = 0x42555555;
            if (p->h140 == 0) {
                p->f5c = -p->f5c;
            }
            p->f34 = s->f34 + p->f5c;
            p->f38 = s->f38;
            p->b13c = 1;
        } else {
            p->b13c = 0;
        }
    }
}
