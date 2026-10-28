typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh SRC "-O4 -Op -fp off -sdatathreshold 8"
   The static functions below are verified copies (each exact at its own
   retail address under these flags) of the real contiguous run of functions
   immediately preceding func_0013EAD0 in address order:
   func_0013E570 (src/hy4_d.c), func_0013E760 (src/y1_e.c),
   func_0013E820 (src/sf0_f.c), func_0013EA00 (src/fb14_c.c). */
typedef struct { f32 x, y, z; } V3;
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
extern u8 *func_003DA750(s32, s32, s32);
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

extern u8 D_004BF378[4];
extern V3 D_00440620[];
extern f32 D_00440650[];
extern f32 D_00440654[];
extern f32 D_00440658[];
extern s32 D_004C281C;

void func_0013EAD0(s32 a) {
    u8 *o;
    double k;
    extern void func_0013ED10();
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
