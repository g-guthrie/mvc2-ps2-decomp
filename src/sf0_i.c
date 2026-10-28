typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh SRC "-O4 -Op -fp off -sdatathreshold 8"
   Every static function below is a verified copy (each exact at its own
   retail address under these flags) of the real contiguous run of functions
   immediately preceding func_0013F880 in address order, func_0013E570 ..
   func_0013F870. The keep_ tables only stop MW dropping unreferenced statics. */
typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750(s32, s32, s32);
typedef struct T41C {u8 pad[0x1c];s32 w1C;u8 pad20[0x170-0x20];} T41C;
typedef struct A41B {s32 w0;u32 w4;s32 w8,wC;u16 h10,h12;} A41B;
extern T41C D_005BF2F0[];
extern s32 func_003DD030(s32);
extern void func_0041BAD0(A41B *);
extern u8 *func_0041BBB0(A41B *);
extern void func_0041BB30(A41B *);
extern f32 func_00417440(u32);
typedef struct {f32 x,y,z;} Point3;
typedef struct {u8 *actor;s32 phase;} WaveContext;
static void func_0013E570(u8 *p,u8 *q,s32 context) {
 WaveContext *state=(WaveContext *)(u32)context;
 u8 *actor=state->actor;
 s32 phase=state->phase;
 Point3 *point;
 s32 resource=((A41B *)q)->w0-1;
 u8 *base=(u8 *)(u32)func_003DD030(((T41C *)((u8 *)&D_005BF2F0+resource*0x170))->w1C);
 u16 *ranges=(u16 *)(u32)func_003DD030(((A41B *)q)->w8);
 u16 *offsets=(u16 *)(u32)func_003DD030(((A41B *)q)->wC);
 func_0041BAD0((A41B *)q);
 while((point=(Point3 *)func_0041BBB0((A41B *)p))!=0 && func_0041BBB0((A41B *)q)!=0) {
  f32 y=point->y;
  f32 z=point->z;
  u32 turn=(u16)(u32)(s32)(0.5+(65536.0*(f64)(*(s16 *)(actor+0x1e)+phase))/360.0);
  z+=0.019999999552965164f*y*y*func_00417440(turn);
  phase+=0x14;
  {u16 start=ranges[2* *(s16 *)(q+0x10)];
   u16 count=ranges[2* *(s16 *)(q+0x10)+1];
   s32 i;
   for(i=0;i<count;i++,start++)*(f32 *)(base+offsets[start]+8)=z;
  }
 }
 state->phase=phase;
 ((A41B *)p)->h12=0;((A41B *)p)->h10=0;((A41B *)q)->h12=0;((A41B *)q)->h10=0;
 func_0041BB30((A41B *)q);
}

typedef struct { V3 v[2]; } V3x2;
extern V3x2 D_004B1940[];
extern s8 D_004B1A10[];
extern f32 D_004B1A00[];
extern f32 D_004B1A04[];
extern f32 D_004B1A08[];
extern s32 D_004C2824;
typedef f32 F32Vec[3];
extern f32 data_f32_004B1940[8][2][3];
static void func_0013E760(u8 *p)
{
    F32Vec *a = &data_f32_004B1940[p[0x20]][0];
    F32Vec *b = &data_f32_004B1940[0][0] + (p[0x20] * 2 + 1);
    f32 d, e;
    e = (*a)[0];
    d = ((*b)[0] - e) / 30.0f;
    *(f32 *)(p + 0x34) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = (*a)[1];
    d = ((*b)[1] - e) / 30.0f;
    *(f32 *)(p + 0x38) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = (*a)[2];
    d = ((*b)[2] - e) / 30.0f;
    *(f32 *)(p + 0x3C) = e + (f32)*(s16 *)(p + 0x1C) * d;
}

static void func_0013EA00(u8 *p);
static void func_0013E820(s32 a) {
    u8 *o;
    double k;
    extern void func_00170DF0(u32);
    if ((o = func_003DA750(0, 0x12, 1)) != 0) {
        o[0x13C] = 1;
        o[0x20] = a;
        *(void **)(o + 0x10) = func_0013EA00;
        o[0x22] = D_004B1A10[a];
        *(s16 *)(o + 0xCC) = o[0x22];
        *(s32 *)(o + 0x84) = D_004C2824;
        *(V3 *)(o + 0x34) = D_004B1940[a].v[0];
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B1A00[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B1A04[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_004B1A08[0]) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xD0) = 0x200003;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        if (a < 2) func_00170DF0((u32)*(s32 *)(o + 0x84));
    }
}

static void func_0013EA00(u8 *p) {
    s32 a = *(s16 *)(p + 0x1C);
    if (a != 0x1E) {
        *(s16 *)(p + 0x1C) = a + 1;
        func_0013E760(p);
    }
    *(s16 *)(p + 0x1E) += 1;
    if (*(s16 *)(p + 0x1E) >= 0xC8) *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    if (p[0x20] & 1) {
        *(f32 *)(p + 0xE0) = 0.004999999888241291f * (f32)*(s16 *)(p + 0x1E);
    } else {
        *(f32 *)(p + 0xE0) = 1.0f - 0.004999999888241291f * (f32)*(s16 *)(p + 0x1E);
    }
    *(u32 *)(p + 0xE4) = 0;
}

static void func_0013ED10(u8 *p);
extern u8 D_004BF378[4];
extern V3 D_00440620[];
extern f32 D_00440650[];
extern f32 D_00440654[];
extern f32 D_00440658[];
extern s32 D_004C281C;

static void func_0013EAD0(s32 a) {
    u8 *o;
    double k;
        extern void func_00170DF0(u32);
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        o[0x20] = a;
        *(void **)(o + 0x10) = func_0013ED10;
        o[0x22] = D_004BF378[a];
        *(s16 *)(o + 0xCC) = o[0x22];
        *(s32 *)(o + 0x84) = D_004C281C;
        *(V3 *)(o + 0x34) = D_00440620[a];
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_00440650[a * 3]) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * D_00440654[a * 3] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * D_00440658[a * 3] / 360.0) & 0xFFFF;
        switch (a) {
        case 0:
        case 1:
            func_00170DF0((u32)*(s32 *)(o + 0x84));
            *(s32 *)(o + 0xD0) = 0x80F;
            *(s16 *)(o + 0x1E) = 0;
            break;
        case 2:
            *(s32 *)(o + 0xD0) = 0x4800;
            *(s16 *)(o + 0x1C) = 0x40;
            *(s16 *)(o + 0x1E) = 3;
            *(f32 *)(o + 0x5C) = 48.0f;
            break;
        }
        *(s32 *)(o + 0xD0) |= 0x400;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
    }
}

/* ---- func_0013ED10 (src/actor_scale_dispatch_0013ed10.c) ---- */
typedef struct { u8 a[0x20]; u8 state; u8 b[0x57]; float x,y,z; } Actor;
typedef void (*StateCallback)(u8 *);
extern u8 *D_004C2840;
extern StateCallback const jtbl_00440678[3];
static void func_0013ED10(u8 *p) {
    Actor *a = (Actor *)p;
    if (((s8 *)D_004C2840)[2] >= 3 && !(a->x < 0.5f)) {
        a->x -= 0.01f;
        a->y = a->x;
        a->z = a->x;
    }
    jtbl_00440678[a->state](p);
}

/* ---- func_0013ED90, func_0013EE10 (src/g12e.c) ---- */
static void func_0013ED90(u8 *p) {
    *(s32 *)(p + 0x40) += 0x100;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    if (*(s16 *)(p + 0x1E) >= 200) *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(s32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -(1.0f - 0.004999999888f * (f32)*(s16 *)(p + 0x1E));
}

static void func_0013EE10(u8 *p) {
    *(s32 *)(p + 0x40) -= 0x100;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    if (*(s16 *)(p + 0x1E) >= 200) *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(s32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -(1.0f - 0.004999999888f * (f32)*(s16 *)(p + 0x1E));
}

/* ---- func_0013EE90 (src/fb47_e.c) ---- */
static void func_0013EE90(u8 *p)
{
    extern void func_003DAA40(u8 *);
    extern void func_00416AE0(s32);
    extern void func_00416CC0(s32);
    extern void func_003DD260(f32 *);
    extern void func_003DDB60(f32 *, f32, f32, f32);
    extern void func_003DE160(f32 *, f32 *, f32 *);
    extern void func_003DDB70(f32 *, f32);
    extern void func_003DDC30(f32 *, f32);
    extern void func_003DDD00(f32 *, f32);
    f32 a[16];
    f32 b[16];
    s16 h;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        *(s16 *)(p + 0x1C) = 0x40;
        *(V3 *)(p + 0x34) = D_00440620[p[0x20]];
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h == 0) {
            func_003DAA40(p);
            return;
        }
    }
    func_00416AE0(0);
    func_003DD260(a);
    func_003DD260(b);
    func_003DDB60(b, *(f32 *)(p + 0x5C), 0.0f, 0.0f);
    func_003DE160(a, a, b);
    func_003DD260(b);
    func_003DDB70(b, 0.017453292f * ((V3 *)D_00440650)[p[0x20]].x);
    func_003DDC30(b, 0.017453292f * ((V3 *)D_00440654)[p[0x20]].x);
    func_003DDD00(b, 0.017453292f * ((V3 *)D_00440658)[p[0x20]].x);
    func_003DE160(a, a, b);
    func_003DD260(b);
    func_003DDB60(b, *(f32 *)(p + 0x34), *(f32 *)(p + 0x38), *(f32 *)(p + 0x3C));
    func_003DE160(a, a, b);
    *(f32 *)(p + 0x88) = a[0];
    *(f32 *)(p + 0x8C) = a[1];
    *(f32 *)(p + 0x90) = a[2];
    *(f32 *)(p + 0x94) = a[3];
    *(f32 *)(p + 0x98) = a[4];
    *(f32 *)(p + 0x9C) = a[5];
    *(f32 *)(p + 0xA0) = a[6];
    *(f32 *)(p + 0xA4) = a[7];
    *(f32 *)(p + 0xA8) = a[8];
    *(f32 *)(p + 0xAC) = a[9];
    *(f32 *)(p + 0xB0) = a[10];
    *(f32 *)(p + 0xB4) = a[11];
    *(f32 *)(p + 0xB8) = a[12];
    *(f32 *)(p + 0xBC) = a[13];
    *(f32 *)(p + 0xC0) = a[14];
    *(f32 *)(p + 0xC4) = a[15];
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0xB8);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0xBC);
    *(f32 *)(p + 0x3C) = *(f32 *)(p + 0xC0);
    func_00416CC0(1);
}
static void *keep_0013E[] = { (void *)func_0013E820, (void *)func_0013EAD0, (void *)func_0013ED90, (void *)func_0013EE10, (void *)func_0013EE90 };
/* ---- func_0013F100 (src/sc14_c.c) ---- */
extern u8 D_004BF37C[8];
extern V3 D_00440690[];
extern f32 D_004406B8[];
extern f32 D_004406BC[];
extern f32 D_004406C0[];
extern V3 D_004B1A18;
extern V3 D_004B1A30[];
typedef struct { u8 pad[0x93]; s8 b93; } G_F100;
typedef struct { s8 p0[2]; s8 b2; s8 b3; u8 p1[0x8D]; s8 b91; } G_F350;
typedef struct {
    u8 pad0[3];
    s8 b3;
    u8 pad4[0xE - 4];
    s16 he;
    u8 pad10[0x91 - 0x10];
    s8 b91;
} G_nq42b;

static void func_0013F350();
static void func_0013F100(s32 id)
{
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        o[0x20] = id;
        *(void **)(o + 0x10) = (void *)func_0013F350;
        *(s16 *)(o + 0xCC) = D_004BF37C[id];
        *(s32 *)(o + 0x84) = D_004C281C;
        *(V3 *)(o + 0x34) = D_00440690[id];
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + k * (double)D_004406B8[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004406BC[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + k * (double)D_004406C0[0] / 360.0) & 0xFFFF;
        *(V3 *)(o + 0x50) = D_004B1A18;
        *(s32 *)(o + 0xD0) = 0xC00C1F;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        if (id == 2) {
            *(V3 *)(o + 0x34) = D_004B1A30[((G_F100 *)D_004C2840)->b93];
            if (((G_F100 *)D_004C2840)->b93 == 0x3A) {
                *(f32 *)(o + 0x50) = 0.75f;
                *(f32 *)(o + 0x54) = 0.75f;
                *(f32 *)(o + 0x58) = 0.75f;
            }
        }
    }
}

/* ---- func_0013F350 (src/t14_d.c) ---- */
struct Object;
typedef struct { u8 p0[0x78]; f32 f78; f32 f7c; f32 f80; u8 p1[0xB8]; u8 b13C; } S_0013F350;
static void func_0013F350(S_0013F350 *p) {
    f32 v;
    if (((G_F350 *)D_004C2840)->b2 >= 3) {
        v = p->f78;
        if (!(v < 0.5f)) {
            f32 w = v - 0.0099999998f;
            p->f78 = w;
            p->f7c = w;
            p->f80 = p->f78;
        }
    } else if (((G_F350 *)D_004C2840)->b91 != 0) {
        func_003DAA40((u8 *)p);
        return;
    }
    if (((G_F350 *)D_004C2840)->b2 >= 5 && ((G_F350 *)D_004C2840)->b3 > 0) p->b13C = 0;
}

/* ---- func_0013F400 (src/sf0_g.c) ---- */
extern u8 D_004406C8[];
extern V3 D_004406E0[];
extern f32 D_00440740[];
extern f32 D_00440744[];
extern f32 D_00440748[];
typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x1C - 5];
    s16 h1c;
    u8 pad1e[0x20 - 0x1E];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    V3 v34;
    u8 pad40[0x13C - 0x40];
    u8 b13c;
} P_nq42b;
static void func_0013F6B0(P_nq42b *p);
static void func_0013F400(s32 a, s32 b) {
    u8 *o;
    double k;
    extern void func_00170DF0(u32);
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 0;
        o[0x20] = a;
        *(void (**)(P_nq42b *))(o + 0x10) = func_0013F6B0;
        o[0x22] = D_004406C8[b];
        *(s16 *)(o + 0xCC) = o[0x22];
        *(s32 *)(o + 0x84) = D_004C281C;
        *(V3 *)(o + 0x34) = D_004406E0[a];
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_00440740[a * 3]) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * D_00440744[a * 3] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * D_00440748[a * 3] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        if (a < 4) func_00170DF0((u32)*(s32 *)(o + 0x84));
    }
}

/* ---- func_0013F5F0 (src/x0_e.c) ---- */
typedef struct { u8 pad0[0x1C]; s16 h; u8 pad1e[2]; u8 idx; u8 pad21[0x13]; f32 f34, f38, f3c; } P13F5F0;
extern V3 D_004407A0[8];
static void func_0013F5F0(P13F5F0 *p) {
    V3 *a = &D_004406E0[p->idx];
    V3 *b = &D_004407A0[p->idx];
    f32 d, s, e;
    s = a->x; e = b->x;
    d = (e - s) / 30.0f;
    p->f34 = s + (f32)p->h * d;
    s = a->y; e = b->y;
    d = (e - s) / 30.0f;
    p->f38 = s + (f32)p->h * d;
    s = a->z; e = b->z;
    d = (e - s) / 30.0f;
    p->f3c = s + (f32)p->h * d;
}

/* ---- func_0013F6B0 (src/nq42_b.c) ---- */
extern void (*D_00440800[])();
static void func_0013F6B0(P_nq42b *p) {
    G_nq42b *q = (G_nq42b *)D_004C2840;
    if (q->b3 != 4 || q->b91 != 0) {
        func_003DAA40((u8 *)p);
        return;
    }
    if (p->b4 == 0) {
        switch (q->he) {
        case 0:
            break;
        default:
            p->b13c = 1;
        if (p->h1c >= 0x1E) {
            p->b4++;
            p->v34 = D_004407A0[p->b20];
        } else {
            p->h1c = p->h1c + 1;
            func_0013F5F0((P13F5F0 *)p);
        }
            break;
        }
    } else {
        D_00440800[p->b20](p);
    }
}

/* ---- func_0013F7A0 (src/wave16.c) ---- */
static void func_0013F7A0(u8 *p) {
    *(s16 *)(p + 30) = *(s16 *)(p + 30) + 1;
    if (*(s16 *)(p + 30) >= 200) *(s16 *)(p + 30) = 0;
    *(u32 *)(p + 208) = *(u32 *)(p + 208) | 0x20000;
    *(f32 *)(p + 224) = -0.005f * *(s16 *)(p + 30);
    *(f32 *)(p + 228) = -0.005f * *(s16 *)(p + 30);
}

/* ---- func_0013F810 (src/wave13d.c) ---- */
static void func_0013F810(u8 *p) {
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(f32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -(f32)(*(s16 *)(D_004C2840 + 0xC) + *(s16 *)(D_004C2840 + 0xA) * 8) / 64.0f;
}

/* ---- func_0013F870 (src/simple_leaves.c) ---- */
static void func_0013F870(void) {}

static void *keep_0013F[] = { (void *)func_0013F100, (void *)func_0013F400, (void *)func_0013F7A0, (void *)func_0013F810, (void *)func_0013F870 };

extern u8 D_004BF380[4];
extern V3 D_00440820[];
extern V3 D_00440860[];
extern V3 D_004408A0;
extern f32 D_004408B0[];
extern f32 D_004408F0[];

void func_0013F880(s32 a, s32 b) {
    u8 *o;
    V3 *q;
    f32 *r;
    double k;
    extern void func_0013FAC0();
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 0;
        o[0x20] = a;
        o[0x22] = b;
        *(void **)(o + 0x10) = func_0013FAC0;
        *(s16 *)(o + 0xCC) = D_004BF380[a];
        *(s32 *)(o + 0x84) = D_004C281C;
        *(f32 *)(o + 0x50) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(f32 *)(o + 0x58) = 1.0f;
        *(s32 *)(o + 0xD0) = 0x81F;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0x1E;
        switch (a) {
        case 0:
        case 3:
            q = &D_00440820[b];
            r = &D_004408B0[b * 3];
            break;
        case 1:
            q = &D_00440860[b];
            r = &D_004408B0[b * 3];
            break;
        case 2:
            q = &D_004408A0;
            r = D_004408F0;
            break;
        }
        *(V3 *)(o + 0x34) = *q;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= r[0]) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * r[1] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * r[2] / 360.0) & 0xFFFF;
    }
}
