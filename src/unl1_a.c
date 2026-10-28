/* MWCC 3.0: ./try30.sh src/unl1_a.c "-O4 -Op -fp off -sdatathreshold 8". Leads with the real contiguous predecessor run 0x0033FCE0..0x00340B10 (static copies, each verified exact at its own address under these flags); func_00340B20, func_00341170 and func_003413B0 are credited, with the real functions between them as static copies. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3_fe;
extern u8 D_004C2A40[2];
extern u8 D_004C2A41[2];
extern u8 D_004C2A42[2];
extern u8 D_004C2A43[2];
typedef struct { u8 pad[0x14]; u8 *f14; } G283C;
extern G283C *D_004C283C;
extern V3_fe D_0045F9E0[];
extern V3_fe D_0045FA04[];

static void func_0033FCE0(u8 *p) {
    switch (p[0x20]) {
    case 0:
        *(u32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * (double)(D_004C2A42[0] * 3 * 2) / 360.0));
        break;
    case 1:
        *(u32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * (double)((D_004C2A42[0] + (D_004C2A43[0] % 12) * 60) / 2) / 360.0));
        break;
    }
}

static void func_0033FE10(s32 idx) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern s32 func_0010FC98(u8 *);
    extern void func_003D7220(u8 *);
    u8 *o;
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        if (func_0010FC98(D_004C2A40) == 0) {
            D_004C2A43[0] = 0;
            D_004C2A42[0] = 0;
            D_004C2A41[0] = 0;
        }
        func_003D7220(D_004C2A40);
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0033FCE0;
        *(s16 *)(o + 0xCC) = idx + 9;
        *(s32 *)(o + 0x84) = (s32)D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3_fe *)(o + 0x34) = D_0045F9E0[idx];
        *(u32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)D_0045FA04[idx].x / 360.0) & 0xFFFF;
        o[0x20] = idx;
    }
}

#pragma padloop on
static void func_0033FF30(void) {
    int i=0;
    do { func_0033FE10(i); } while (++i < 0x2);
}
#pragma padloop off

extern V3_fe D_0045FA18;
static void func_00340000(u8 *p);
static void func_0033FF70(u8 *p) {
    extern u8 *func_003DA750(s32 a, s32 b, s32 c);
    u8 *r = func_003DA750(0, 6, 0);
    if (r != 0) {
        r[0x13C] = 1;
        *(u32 *)(r + 0x10) = (u32)func_00340000;
        *(s16 *)(r + 0xCC) = 0x15;
        *(u32 *)(r + 0x84) = (u32)D_004C283C;
        *(V3_fe *)(r + 0x34) = D_0045FA18;
        *(u32 *)(r + 0x44) = 0xE001;
        *(u32 *)(r + 0xD0) = 0x805;
        *(u8 **)(r + 0x18) = p;
    }
}

static void func_003400A0(u8 *p,u8 *q,s32 context);
typedef struct { u8 pad[0x1C]; s16 h1c; } S340;
static void func_00340000(u8 *p)
{
    extern void func_00170E60(u8 *, u8 *, s32, s32, void (*)(u8 *, u8 *, s32), void *);
    u8 *q;
    u8 *r;
    s32 a[2];
    if (*(u8 *)(*(s32 *)(p + 0x18) + 4) > 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) += 4;
        if (*(s16 *)(p + 0x1C) >= 0x168) ((S340 *)p)->h1c = 0;
        q = *(u8 **)(p + 0x84);
        a[0] = (s32)p;
        a[1] = 0;
        r = *(u8 **)(q + 0x1C);
        func_00170E60(D_004C283C->f14, *(u8 **)(r + 0x54) + 0x190, *(s32 *)(q + 0x14),
                      *(s32 *)(r + *(s16 *)(p + 0xCC) * 4), func_003400A0, (void *)((s32)a));
    }
}

#pragma padloop on
typedef struct T41C {u8 pad[0x1c];s32 w1C;u8 pad20[0x170-0x20];} T41C;
typedef struct A41B {s32 w0;u32 w4;s32 w8,wC;u16 h10,h12;} A41B;
extern T41C D_005BF2F0[];
extern s32 func_003DD030(s32);
extern void func_0041BAD0(A41B *);
extern u8 *func_0041BBB0(A41B *);
extern void func_0041BB30(A41B *);
extern f32 func_00117078(f32);
extern f32 func_00117240(f32);
extern f32 func_00417440(u32);
typedef struct {f32 x,y,z;} Point3;
typedef struct {u8 *actor;s32 phase;} WaveContext;
static void func_003400A0(u8 *p,u8 *q,s32 context) {
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
  if(y<-10.0f) {
   f32 distance=func_00117078(y);
   z+=0.00019999999494757503f*distance*distance*func_00117240(0.01745329238474369f*(f32)(*(s16 *)(actor+0x1c)+phase));
  }
  phase+=30;
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

#pragma padloop off

typedef void (*DispatchFn_sfc)(u8 *);
extern DispatchFn_sfc jtbl_0045FB80[];
static void func_00340290(u8 *p) { jtbl_0045FB80[p[4]](p); }

static void func_003402B0(u8 *p)
{
    extern void func_001E3710(u8 *, int);
    p[4]++;
    *(s16 *)(p + 0x1C) = 0x32;
    if (p[0x20] == 8) {
        func_001E3710(p, 0x30);
        func_001E3710(p, 0x49);
    }
}

static void *keep_sfc_b[] = { (void *)func_0033FF30, (void *)func_0033FF70, (void *)func_00340290, (void *)func_003402B0 };

typedef double f64;
typedef struct DB {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    s16 h1e;
    u8 b20;
    u8 _p2[0x13];
    f32 f34;
    f32 f38;
    f32 f3c;
    u32 w40;
    u32 w44;
    u32 w48;
} DB;

typedef struct { f32 x, y, z; } V3;
extern f32 D_0045FA70[];
extern f32 D_0045FAA0[];
extern f32 D_0045FB10[];
extern f32 D_0045FB14[];
extern f32 D_0045FB18[];
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

#define ANG(x) ((u32)(s32)(0.5 + 65536.0 * (f64)(x) / 360.0) & 0xFFFF)

static void func_00340310(DB *p) {
    extern void func_0032E690();
    extern void func_001E3710(DB *, s32);
    extern void func_00154120(f32 *, s32);
    f32 v7[3];
    f32 v8[3];
    f32 *q;
    u32 u;
    u8 t;
    if (p->h1e != 0) {
        p->h1e = p->h1e - 1;

    } else if (p->h1c != 0) {

        p->h1c = p->h1c - 1;
        func_0032E690();
        if (p->b20 >= 4) {
            t = p->b20;
            p->w40 += ANG(D_0045FB10[t * 3] / 50.0f);
            p->w44 += ANG((D_0045FB14[p->b20 * 3] - -45.0f) / 50.0f);
            p->w48 += ANG(D_0045FB18[p->b20 * 3] / 50.0f);
        } else {
            t = p->b20;
            q = &D_0045FA70[t * 3];
            p->w40 += ANG((D_0045FB14[t * 3] - q[0]) / 50.0f);
            p->w44 += ANG((D_0045FB14[p->b20 * 3] - q[1]) / 50.0f);
            p->w48 += ANG((D_0045FB14[p->b20 * 3] - q[2]) / 50.0f);
        }
        if (p->b20 == 8 && p->h1c == 0x14) {
            func_001E3710(p, 0x49);

        }

    } else {
    u = p->b4;
    p->b4 = u + 1;
    *(V3 *)&p->f34 = *(V3 *)&D_0045FAA0[p->b20 * 3];
    p->w40 = ANG(D_0045FB10[p->b20 * 3]);
    p->w44 = ANG(D_0045FB14[p->b20 * 3]);
    p->w48 = ANG(D_0045FB18[p->b20 * 3]);
    p->h1c = 0x20;
    if (p->b20 >= 6) {
    if (p->b20 == 6) {
            D_004F1F45[0] = 1;
            D_004F1F46[0] = 1;
        }
        if (p->b20 == 7) {
            v7[0] = 1191.0f;
            v7[1] = 26.0f;
            v7[2] = -338.0f;
            D_004F1F45[0] = 2;
            D_004F1F46[0] = 1;
            func_00154120(v7, 1);
        }
        if (p->b20 == 8) {
            v8[0] = 782.0f;
            v8[1] = 36.0f;
            v8[2] = -650.0f;
            D_004F1F45[0] = 3;
            D_004F1F46[0] = 1;
            func_00154120(v8, 1);
            func_001E3710(p, 0x31);
        }
    }
}
}

typedef struct { u8 p0[4]; u8 b4; u8 p5[0x17]; s16 h1c; u8 p1e[2]; u8 b20; u8 p21[0x13]; f32 f34, f38; } S_0970;
static void func_00340A40(u8 *p);
static void func_00340970(S_0970 *p) {
    s32 h = p->h1c;
    if (h != 0) {
        p->h1c = h - 1;
        if (p->b20 < 4) {
            func_00340A40((u8 *)p);
            return;
        }
        p->f34 += (f32)((p->h1c % 2) ? 2 : -2);
        p->f38 += (f32)((p->h1c % 2) ? 4 : -4);
    } else {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->h1c = 0x1E;
    }
}

typedef struct {float x,y,z;} Vec3;
typedef struct { u8 pad[0x38]; f32 f38; u8 p3c[0x20]; f32 f5c, f60, f64; } SA40;
static void func_00340A40(u8 *p) {
 extern void func_0032E690(u8 *);
 SA40 *sa=(SA40 *)p;
 Vec3 *origin=&((Vec3 *)D_0045FAA0)[p[0x20]];
 func_0032E690(p);
 if(sa->f38<origin->y) {
  sa->f38=origin->y;
  sa->f60*=-0.12f;
  sa->f5c*=0.8f;
  sa->f64*=0.8f;
 }
}

static void func_00340AE0(void) {}
static void func_00340AF0(u8 *p) { u32 v = p[4]; v += (1); p[4] = v; p[316] = 0; }
struct Object;
static void func_00340B10(s32 a0, s32 a1, s32 a2, s32 a3) { extern void func_003DAA40(struct Object *); func_003DAA40((struct Object *)(a0)); }
static void *keep_unl1_a[] = { (void *)func_00340310, (void *)func_00340970, (void *)func_00340AE0, (void *)func_00340AF0, (void *)func_00340B10 };

extern V3 D_0045FA28;
extern f32 D_0045FA2C[];
extern f32 D_0045FA30[];
extern V3 D_0045FA40[];
extern f32 D_0045FAA4[];
extern f32 D_0045FAA8[];

void func_00340B20(s32 n)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00340290();
    u8 *o;
    V3 *s1, *s2;
    f64 k;

    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00340290;
        *(s16 *)(o + 0xCC) = n + 0xC;
        *(s32 *)(o + 0x84) = (s32)D_004C283C;
        if (n >= 4) {
            *(V3 *)(o + 0x34) = D_0045FA28;
            *(s32 *)(o + 0x44) = 0xE001;
            *(f32 *)(o + 0x5C) = (D_0045FAA0[n * 3] - D_0045FA28.x) / 50.0f;
            *(s32 *)(o + 0x60) = 0;
            *(f32 *)(o + 0x64) = (D_0045FAA8[n * 3] - D_0045FA30[0]) / 50.0f;
            *(f32 *)(o + 0x6C) = 2.0f * (D_0045FAA4[n * 3] - D_0045FA2C[0]) / 2500.0f;
        } else {
            s1 = &D_0045FA40[n];
            s2 = &((V3 *)D_0045FA70)[n];
            *(V3 *)(o + 0x34) = *s1;
            k = 65536.0;
            *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= s2->x) / 360.0) & 0xFFFF;
            *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)s2->y / 360.0) & 0xFFFF;
            *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)s2->z / 360.0) & 0xFFFF;
            *(f32 *)(o + 0x5C) = (D_0045FAA0[n * 3] - s1->x) / 50.0f;
            *(s32 *)(o + 0x60) = 0;
            *(f32 *)(o + 0x64) = (D_0045FAA8[n * 3] - s1->z) / 50.0f;
            *(f32 *)(o + 0x6C) = 2.0f * (D_0045FAA4[n * 3] - s1->y) / 2500.0f;
        }
        *(s32 *)(o + 0xD0) = 0x80F;
        o[0x20] = n;
        *(s16 *)(o + 0x1E) = n * 6;
    }
}

typedef void (*DispatchFn_u1)(u8 *);
extern DispatchFn_u1 jtbl_004C1950[2];
static void func_00340E50(u8 *p) { jtbl_004C1950[p[4]](p); }

extern u8 *D_004D18B8[];
extern u8 *D_004D18C4[];
extern s8 D_004D18D6[];
extern s8 D_004D18D7[];
extern f32 D_004F1FDC[];
#pragma padloop on
static void func_00340E70(u8 *p) {
    extern s32 func_003D90A0(s32);
    u8 *a;
    u8 *b;
    s32 i;
    a = D_004D18B8[0];
    b = D_004D18C4[0];
    if (D_004D18D6[0] != 3 && D_004D18D7[0] != 3) return;
    if (func_003D90A0(1) == 0) return;
    if (a[0x249] != 0) {
        if (!(*(f32 *)(a + 0x34) <= 50.0f + D_004F1FDC[0])) return;
        if (*(f32 *)(a + 0x34) < D_004F1FDC[0] - 50.0f) return;
        p[4]++;
        *(s16 *)(p + 0x1C) = 100;
        *(s16 *)(p + 0xCC) = 8;
        *(s32 *)(p + 0x84) = (s32)D_004C283C;
        i = 0;
        do {
            func_00340B20(i);
            i++;
        } while (i < 9);
    } else {
    if (!(*(f32 *)(b + 0x34) <= 50.0f + D_004F1FDC[0])) return;
    if (*(f32 *)(b + 0x34) < D_004F1FDC[0] - 50.0f) return;
    p[4]++;
    *(s16 *)(p + 0x1C) = 100;
    *(s16 *)(p + 0xCC) = 8;
    *(s32 *)(p + 0x84) = (s32)D_004C283C;
    i = 0;
    do {
        func_00340B20(i);
        i++;
    } while (i < 9);
    }
}

#pragma padloop off

static void func_00340FF0(void) {}

static void func_00341000(void) {
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *o;
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00340E50;
        *(s16 *)(o + 0xCC) = 4;
        *(u32 *)(o + 0x84) = (u32)D_004C283C;
        *(V3 *)(o + 0x34) = D_0045FA28;
        *(u32 *)(o + 0x44) = 0xCAAC;
        *(s32 *)(o + 0xD0) = 0x805;
        func_0033FF70(o);
    }
}

static void func_003410D0(s32 a0);
#pragma padloop on
static void func_00341090(void) {
    int i=0;
    do { func_003410D0(i); } while (++i < 0x2);
}

#pragma padloop off
extern V3 D_004B82B0[];
void func_00341170();
static void func_003410D0(s32 a0) {
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *r = func_003DA750(0, 6, 0);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_00341170;
        *(s16 *)(r + 0xCC) = a0 + 0x17;
        *(u32 *)(r + 0x84) = (u32)D_004C283C;
        *(u32 *)(r + 0xD0) = 0x801;
        *(V3 *)(r + 0x34) = D_004B82B0[a0];
        r[0x20] = a0;
    }
}
static void *keep_unl1_a2[] = { (void *)func_00340E70, (void *)func_00340FF0, (void *)func_00341000, (void *)func_00341090 };

extern f32 func_00417440(u32);
extern s32 D_004B82A0[];
extern f32 D_004B82B4[];
extern f32 D_004B82C8[];
typedef struct { u8 pad0[0x1C]; s16 h1C; u8 pad1E[2]; u8 b20; u8 pad21[0x13]; f32 f34; f32 f38; } Pc;

void func_00341170(Pc *p)
{
    f32 s;
    f32 a;
    f32 k;
    f32 t;

    a = 360.0f * (f32)p->h1C / (f32)D_004B82A0[p->b20];
    s = func_00417440(((u32)(s32)((double)a * 65536.0 / 360.0 + 0.5) & 0xFFFFu));
    k = 100.0f;
    k *= s;
    t = D_004B82B0[p->b20].x;
    t += k;
    p->f34 = t;
    p->f38 = D_004B82B4[p->b20 * 3] + (f32)p->h1C * D_004B82C8[p->b20] / (f32)D_004B82A0[p->b20];
    p->h1C = p->h1C + 1;
    if (p->h1C >= D_004B82A0[p->b20])
        p->h1C = 0;
}

extern u8 D_004C27D0;
void func_003413B0();
static void func_003412F0(void)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00341800(u8 *, s32, s32, s32);
    extern void func_003419A0(u8 *);
    extern void func_003418A0(void);
    extern void func_00341900(u8 *);
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_003413B0;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1E) = 1;
        i = 7;
        do {
            func_00341800(o, i, 0x800, 6);
            i--;
        } while (i > -1);
        func_003419A0(o);
        if ((D_004C27D0 & 0x1F) == 7) {
            func_003418A0();
            return;
        }
        if ((D_004C27D0 & 0x1F) == 0x10) {
            func_00341900(o);
        }
    }
}
static void *keep_unl1_a3[] = { (void *)func_003412F0 };

typedef struct XA {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 _p1[0x14];
    f32 f34;
    f32 f38;
    f32 f3c;
    u32 w40;
    u32 w44;
    u32 w48;
} XA;

extern f32 D_0045FB88[], D_0045FB8C[], D_0045FB90[], D_0045FB94[], D_0045FB98[], D_0045FB9C[];
extern f32 D_0045FBA0[], D_0045FBA4[], D_0045FBA8[], D_0045FBAC[], D_0045FBB0[], D_0045FBB4[];
extern f32 D_0045FBB8[], D_0045FBBC[], D_0045FBC0[], D_0045FBC4[], D_0045FBC8[], D_0045FBCC[];
extern f32 D_0045FBD0[], D_0045FBD4[];

void func_003413B0(XA *p)
{
    f32 v38[3];
    f32 v48[3];
    f32 c0, c1, c2;
    extern s32 func_0032FEB0(f32, f32 *, f32 *, f32 *);
    extern void func_00416AE0(s32);
    extern void func_004171E0();
    extern void func_00417350(s32);
    extern void func_004172E0(s32);
    extern void func_00417270(s32);
    extern void func_00417E30(f32 *, f32 *);
    extern void func_00416CC0(s32);
    s32 i = p->h1e;

    func_0032FEB0((f32)p->h1c / (D_0045FBBC[i * 7] - D_0045FBA0[i * 7]), &c0, &c1, &c2);
    i = p->h1e;
    p->w40 = -((u32)(s32)(0.5 + 65536.0 * (f64)(c0 * D_0045FB94[i * 7] + c1 * D_0045FBB0[i * 7] + c2 * D_0045FBCC[i * 7]) / 360.0) & 0xFFFF);
    p->w44 = -((u32)(s32)(0.5 + 65536.0 * (f64)(c0 * D_0045FB98[i * 7] + c1 * D_0045FBB4[i * 7] + c2 * D_0045FBD0[i * 7]) / 360.0) & 0xFFFF);
    p->w48 = -((u32)(s32)(0.5 + 65536.0 * (f64)(c0 * D_0045FB9C[i * 7] + c1 * D_0045FBB8[i * 7] + c2 * D_0045FBD4[i * 7]) / 360.0) & 0xFFFF);
    v38[0] = c0 * D_0045FB88[i * 7] + c1 * D_0045FBA4[i * 7] + c2 * D_0045FBC0[i * 7];
    v38[1] = c0 * D_0045FB8C[i * 7] + c1 * D_0045FBA8[i * 7] + c2 * D_0045FBC4[i * 7];
    v38[2] = c0 * D_0045FB90[i * 7] + c1 * D_0045FBAC[i * 7] + c2 * D_0045FBC8[i * 7];
    func_00416AE0(0);
    func_004171E0();
    func_00417350(p->w40);
    func_004172E0(p->w44);
    func_00417270(p->w48);
    func_00417E30(v38, v48);
    func_00416CC0(1);
    p->f34 = -v48[0];
    p->f38 = -v48[1];
    p->f3c = -v48[2];
    if (D_004C27D0 == 7) {
        p->h1c = p->h1c + 1;
    } else {
        p->h1c = p->h1c + 2;
    }
    i = p->h1e;
    if (!((f32)p->h1c < D_0045FBBC[i * 7] - D_0045FBA0[i * 7])) {
        p->h1c = 0;
        p->h1e = p->h1e + 1;
        if ((u32)(p->h1e + 2) >= 0x59) {
            p->h1e = 1;
        }
    }
}
