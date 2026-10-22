typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

static void func_0014C030(u8 *a0, u8 *a1) {
    if (a1) {
        F(a1, 92) = F(a1, 52) - F(a0, 52);
        F(a1, 96) = F(a1, 56) - F(a0, 56);
        F(a1, 100) = F(a1, 60) - F(a0, 60);
        I(a1, 24) = (s32)a0;
    }
}

typedef struct {
    u8 pad0[0x10];
    u32 w10;
    u8 pad14[0x20 - 0x14];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x84 - 0x40];
    u32 w84;
    u8 pad88[0xCC - 0x88];
    s16 hCC;
    u8 padCE[2];
    u32 wD0;
    u8 pad_D4[0x13C - 0xD4];
    u8 b13C;
} E;

typedef struct {
    E *o;
    u8 pad4[0x50 - 4];
} S;

extern S D_004CAED0[];
extern S D_004CAE80[];
extern u32 D_004C27E8;
extern u8 D_0014C0D0[];

void func_0014D1C0(s32 n, s32 m, s16 *q) {
    E *o;
    u8 *s0, *s1, *s2;
    s32 i, j;
    f32 z = 0.0f;
    extern E *func_003DA750(s32, s32, s32);
    extern void func_0014CB10(u8 *, s32, s32);
    extern void func_0014C760(u8 *, s32, s32, s32, s32, f32);
    extern void func_0014CE20(u8 *, s32);
    extern void func_0014D670(s32);
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o->b13C = 1;
        o->w10 = (u32)D_0014C0D0;
        o->b20 = n;
        o->wD0 = 1;
        o->f34 = 0.0f;
        o->f38 = 0.0f;
        o->f3C = -13.0f;
        if (n != 2) {
            o->hCC = 4;
            o->w84 = D_004C27E8;
            if (n == 1) o->f34 += 7.5f;
        } else {
            o->hCC = 0xB;
            o->w84 = D_004C27E8;
            o->f34 += 18.0f;
            o->f3C = z;
        }
        D_004CAED0[n].o = o;
    } else {
        D_004CAED0[n].o = 0;
    }
    s0 = (u8 *)&D_004CAE80[n + 1];
    func_0014CB10(s0 + 0x34, n + 1, m);
    if (n != 2) {
        func_0014C760(s0 + 4, n + 1, *q, 0, 0, -0.22499999403953552f);
    } else {
        func_0014C760(s0 + 4, n + 1, *q, 0, 0, -0.800000011920929f);
    }
    for (i = 0; i < 4; i++) {
        s1 = (u8 *)&D_004CAE80[n];
        s2 = s1 + 0x50;
        func_0014C030(*(u8 **)s2, *(u8 **)(s1 + i * 4 + 0x84));
        func_0014C030(*(u8 **)s2, *(u8 **)(s1 + i * 4 + 0x54));
    }
    func_0014CE20(s0 + 0x48, n + 1);
    for (i = 0; i < 2; i++) {
        func_0014C030(*(u8 **)s2, *(u8 **)(s1 + i * 4 + 0x98));
    }
    if (m == -1) func_0014D670(n + 1);
}
