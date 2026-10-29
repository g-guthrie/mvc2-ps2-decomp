/* func_001D82B0: MW 3.0 (try30.sh) -O3 -Op -sdatathreshold 0. Needs
 * opt_dead_assignments + opt_propagation off so the first jitter keeps
 * retail's li -1 / addu and named block temps set the register order. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x18];
    s16 h1E;
    u8 pad20;
    u8 b21;
    u8 pad22[2];
    s8 b24;
    u8 pad25[0xF];
    f32 f34;
    f32 f38;
    u8 pad3C[0x2C];
    f32 f68;
    f32 f6C;
    u8 pad70[0x70];
    u8 *d_pad;
} PA;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x1E];
    s8 b24;
    u8 pad25[0xF];
    f32 f34;
    f32 f38;
    u8 pad3C[0x104];
    s16 h140;
    u8 pad142[0xA];
    u8 b14C;
    u8 pad14D;
    u8 b14E;
    u8 b14F;
    u8 pad150[0xEE];
    u8 b23E;
    u8 pad23F[8];
    u8 b247;
} PO;

extern s8 D_0044E6C0[];
extern s8 D_0044E6E0[];

#pragma push
#pragma opt_dead_assignments off
#pragma opt_propagation off

void func_001D82B0(u8 *a, u8 *b)
{
    extern s32 func_00174170();
    extern u8 *func_001D7CE0();
    extern void func_001D8570();
    extern s32 func_00175670();
    extern s32 func_001754A0();
    PO *o;
    u8 *s1;
    PA *p;
    s32 sum;
    u32 t, w;
    f32 f;
    p = (PA *)a;
    s1 = b;
    o = *(PO **)(a + 0xD8);
    if (p->b21 == 0) {
        if (o->b5 != 3 || o->b247 != 9 || p->h1E < 0) goto fail;
        if ((s1 = func_001D7CE0(s1, 2)) == 0) return;
        sum = o->b14E + o->b14F;
        { s32 h = sum >> 4; w = D_0044E6C0[p->h1E] * h; }
        { s32 j, k; j = func_00174170() & 2; k = -1; t = w + (j + k); }
        f = (f32)t;
        *(f32 *)(s1 + 0x68) = 1.6666666269302368f * f;
        w = (o->b14C >> 5) * D_0044E6E0[p->h1E];
        t = w + ((func_00174170() & 2) - 1);
        f = (f32)t;
        *(f32 *)(s1 + 0x6C) = 2.142857074737549f * f;
        p->h1E = p->h1E - 1;
    } else
    if (p->b5 == 0) {
        { s32 n = (s32)p->f68;
        if (o->h140 != 0) n = -n;
        p->f34 = o->f34 + (f32)n; }
        p->f38 = o->f38 + p->f6C;
        p->b24 = o->b24;
        func_00175670(p);
        if (o->b5 == 3 && (o->b23E == 1 || o->b23E == 0)) {
            switch (o->b247) {
            default:
                break;
            case 9:
                return;
            }
        }
        { u32 bb = p->b5; p->b5 = bb + 1; }
        func_001754A0(p, 0x1B, (u8)(*(u8 *)((u8 *)p + 0x168) + 4));
    } else {
        if ((s8)func_00175670(a) < 0) goto fail;
        if ((s8)func_00175670(p) < 0) goto fail;
    }
    return;
fail:
    func_001D8570(p, s1);
}

#pragma pop
