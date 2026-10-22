typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;



typedef struct DB {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    u8 _p2[0x22];
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x10];
    f32 f5c;
    f32 f60;
    f32 f64;
} DB;

extern f32 D_00583C48[];
extern f32 D_00583C4C[];
extern f32 D_00583C50[];

static void func_00338670(DB *p)
{
    p->h1c = p->h1c + 1;
    if (p->h1c > 150) {
        p->b4 = 0;
        p->h1c = 0;
        return;
    }
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f5c / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f60 / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f64 / 360.0) & 0xFFFF;
    p->w40 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C48[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C4C[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w48 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C50[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
}
static void (*keep_00338670)(DB *) = func_00338670;

typedef struct E28 { f32 v; u8 pad[24]; } E28;
extern E28 D_0045E488[], D_0045E48C[], D_0045E490[], D_0045E494[], D_0045E498[], D_0045E49C[];
extern E28 D_0045E4A0[], D_0045E4A4[], D_0045E4A8[], D_0045E4AC[], D_0045E4B0[], D_0045E4B4[], D_0045E4B8[];
extern E28 D_0045E4BC[], D_0045E4C0[], D_0045E4C4[], D_0045E4C8[], D_0045E4CC[], D_0045E4D0[], D_0045E4D4[];

typedef struct P {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 _p2[0x14];
    f32 f34;
    f32 f38;
    f32 f3c;
    u32 w40;
    u32 w44;
    u32 w48;
} P;

void func_0032FF00(P *p)
{
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    extern void func_003302E0(P *);
    f32 vx, vy, vz;
    s16 i;
    s16 h;

    h = p->h1e;
    func_0032FEB0((f32)p->h1c / (D_0045E4BC[h].v - D_0045E4A0[h].v), &vx, &vy, &vz);
    h = p->h1e;
    p->f34 = vx * D_0045E488[h].v + vy * D_0045E4A4[h].v + vz * D_0045E4C0[h].v;
    p->f38 = vx * D_0045E48C[h].v + vy * D_0045E4A8[h].v + vz * D_0045E4C4[h].v;
    p->f3c = vx * D_0045E490[h].v + vy * D_0045E4AC[h].v + vz * D_0045E4C8[h].v;
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045E494[h].v + vy * D_0045E4B0[h].v + vz * D_0045E4CC[h].v) / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045E498[h].v + vy * D_0045E4B4[h].v + vz * D_0045E4D0[h].v) / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045E49C[h].v + vy * D_0045E4B8[h].v + vz * D_0045E4D4[h].v) / 360.0) & 0xFFFF;
    i = p->h1c + 1;
    p->h1c = i;
    if ((f32)p->h1c >= D_0045E4BC[p->h1e].v - D_0045E4A0[p->h1e].v) {
        p->h1c = 0;
        i = p->h1e + 1;
        p->h1e = i;
        if ((u32)(p->h1e + 1) >= 0x22) {
            p->h1e = 1;
        }
    }
    func_003302E0(p);
}
