/* EE GCC 2.96: ./tryee.sh src/s8i_a.c sn 0 O2 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_003F8490();
extern void func_003F8448();
void func_003F84E8(unsigned char *p)
{
    s32 *q = (s32 *)(p + 0x48);
    s32 n, a, b, r, lt, x, o, e, bs, m, c;
    n = q[1] / q[2];
    m = q[6];
    o = q[8];
    bs = q[4];
    c = q[10];
    a = (m - o + bs - 1) / bs;
    b = (c + bs - 1) / bs;
    r = bs - (c + bs - 1) % bs - 1;
    e = q[9];
    lt = c < e;
    { s32 t = a * bs;
    if (b < a) {
        a += (o + t - r) < m;
    } }
    e += lt * r;
    x = e / bs;
    if (x < n) n = x;
    if (b < n) n = b;
    if (a < n) n = a;
    if (q[2] == 2) func_003F8490(p, n);
    else func_003F8448(p, n);
}

typedef struct { u16 key; u16 w; s32 val; } E47;

typedef struct N47 {
    struct N47 *next;
    u8 pad4[8];
    u16 cnt;
    u8 padE[2];
    u8 data[0x100];
    s32 f110;
    E47 e[1];
} N47;

extern N47 *D_0047B180[];

s32 func_003FD748(s32 a0, s32 a1, u8 *a2, s32 *a3, s32 *t0, s32 *t1)
{
    extern s32 func_003FD560();
    extern s32 func_00120440(void *, const void *, u32);
    N47 *n;
    E47 *e;
    u16 *q;
    s32 r;
    u32 sum;
    N47 *nx;
    s32 c;
    E47 *b;
    s32 i;
    s32 f;

    r = func_003FD560(a0, a1);
    if (r < 0) {
        *a3 = 0;
        *t0 = -1;
        *t1 = -1;
        return r;
    }
    n = D_0047B180[a0];
    for (; n->next != 0; n = n->next) {
        b = n->e;
        for (i = 0; i < n->cnt; i++) {
            e = b + i;
            if (e->key == a1) {
                s32 g;
                func_00120440(a2, n->data, 0x100);
                g = n->f110;
                *t0 = e->val;
                *a3 = g;
                *t1 = e->w;
                return r;
            }
        }
    }
    sum = *(u16 *)&n->e[0];
    q = (u16 *)&n->e[0] + 1;
    for (i = 0; i < a1; i++)
        sum += q[i];
    func_00120440(a2, n->data, 0x100);
    { s32 g = n->f110; *t0 = sum; *a3 = g; *t1 = q[a1]; }
    return r;
}
