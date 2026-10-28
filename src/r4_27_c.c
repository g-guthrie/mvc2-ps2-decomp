/* nearmiss func_003C6A30: ./try30.sh "-O3 -Op -sdatathreshold 0"; 804/808 bytes; only diff: block-B float regs (zero gets f2, retail f0) + one mtc1 hazard nop */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3c[0x140 - 0x3C];
    s16 h140;
} O3C6A30;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x14 - 6];
    O3C6A30 *o14;
    u8 *p18;
    s16 h1c;
    u8 pad1e[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
    u8 pad70[0x140 - 0x70];
    s16 h140;
    u8 pad142[0x1B2 - 0x142];
    s8 b1b2;
    s8 b1b3;
    u8 pad1b4[0x1C4 - 0x1B4];
    s32 w1c4;
} P3C6A30;

void func_003C6A30(P3C6A30 *p, u8 *w)
{
    extern void func_001757E0(P3C6A30 *, s32, s32);
    extern void func_0015B200(u8 *, f32 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_00175700(P3C6A30 *);
    extern s32 func_00174470(P3C6A30 *);
    extern void func_003C80A0(P3C6A30 *, u8 *);
    extern void func_001E7F60(P3C6A30 *);
    O3C6A30 *o;
    u8 *q;
    u8 *r;
    f32 v[3];
    s16 c;

    if (p->b5 == 0) {
        if (p->b1b2 != 0 || p->b1b3 != 0) {
            u32 t;
            s32 iv;
            t = *(volatile u8 *)&p->b5;
            o = p->o14;
            p->b5 = t + 1;
            p->h1c = 0x3E;
            func_001757E0(p, 0x15, 0x1B);
            *(u32 *)&p->f60 = 0x41892492;
            *(u32 *)&p->f6c = 0xBF092492;
            iv = -0x80000;
            if (o->h140 != 0) iv = 0x80000;
            p->f5c = (o->f34 + 1.6666666269302368f * (f32)iv / 65536.0f - p->f34) / 64.0f;
            p->f68 = 0;
            v[0] = -53.33333206176758f;
            if (p->h140 != 0) v[0] = -v[0];
            v[0] += p->f34;
            v[1] = p->f38;
            func_0015B200(w, v, 1, 0xF9);
            func_001E3710(w, 0x49);
        } else {
            f32 k;
            f32 s;
            func_00175700(p);
            k = 13.333333015441895f;
            p->f34 += p->f5c;
            p->f5c += p->f68;
            p->f38 += p->f60;
            p->f60 += p->f6c;
            s = p->f5c;
            if (p->f68) {
                if (p->f68 >= 0.0f) { s = -s; k = -k; }
                if (s >= 13.333333015441895f) {
                    p->f68 = 0;
                    p->f5c = k;
                }
            }
            if (func_00174470(p) == 0) {
                q = (u8 *)p->o14;
                if (q[5] == 3) q[5] = 5;
                func_003C80A0(p, w);
                return;
            }
            func_001E7F60(p);
            return;
        }
    }
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    c = p->h1c - 1;
    p->h1c = c;
    if (c > 0) return;
    {
    s8 b;
    q = (u8 *)p->o14;
    r = p->p18;
    if (p->b1b3 == 0 && (b = p->b1b2) != 0 && p->w1c4 != 0 && *(s32 *)(r + 0x220) == p->w1c4 && !(b & 1)) {
        q[5] = 6;
        func_003C80A0(p, w);
        return;
    }
    }
    q[5] = 7;
    func_003C80A0(p, w);
}
