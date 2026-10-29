/* func_003F8690: EE GCC 2.96, ./tryee.sh src/r13_08_a.c sn 0 O2. The dispatch re-reads q->f8 (CSE turns it into the retail daddu v0,v1 copy). */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad[8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 padq[8];
    s32 f20;
    u8 padq2[4];
    s32 f28;
} Q;

typedef struct {
    u8 pad0[8];
    s32 f08;
    u8 pad1[0x34];
    s32 f40;
    s32 f44;
    Q q;
    u8 pad3[0x1C];
    s32 f90;
    s32 f94;
} PA;

void func_003F8690(PA *p)
{
    extern s32 func_004044C8(s32);
    extern void func_003F8600(s32, s32, s32, s32);
    extern void func_003F8670(s32, s32, s32, s32);
    Q *q;
    s32 d0;
    s32 f20;
    s32 f44;
    s32 t;
    s32 w;
    s32 r;
    s32 v;
    s32 f40;
    s32 rem;
    s32 f14;
    s32 fC;
    s32 c;
    s32 quot;
    s32 d;
    q = &p->q;
    fC = q->fC;
    w = q->f10;
    f20 = q->f20;
    t = q->f28 + w - 1;
    f14 = q->f14;
    f40 = p->f40;
    rem = t % w;
    quot = t / w;
    d0 = w - rem - 1;
    f44 = p->f44;
    r = func_004044C8(p->f08);
    c = q->f8;
    v = r * w / c;
    p->f94 = r * fC;
    d = (r >= quot * c) ? v - d0 : v;
    p->f90 = d;
    f20 += d;
    if (f20 >= f40) {
        f20 -= f40;
        if (q->f8 == 2) func_003F8600(f14, f40, f44, f20); else func_003F8670(f14, f40, f44, f20);
    }
}
