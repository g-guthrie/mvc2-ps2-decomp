/* MWCC 3.0: ./try30.sh src/sfc_b.c "-O3 -Op -fp off -sdatathreshold 8". Leads with the real contiguous predecessor run 0x0033FCE0..0x003402B0 as static copies (soft-float file-position effect). */
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

void func_00340310(DB *p) {
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
