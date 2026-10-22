/* MW 3.0.3: ./try.sh src/rb77_a.c "-O3 -Op -fp off -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z; } V3;
typedef struct { s16 v; s16 pad; } SH2;

typedef struct DA {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 _p1[0x14];
    V3 v34;
    u8 _p2[0x50 - 0x40];
    f32 f50;
    f32 f54;
    f32 f58;
    u8 _p3[0x84 - 0x5C];
    s32 w84;
    u8 _p4[0xCC - 0x88];
    s16 hcc;
} DA;

extern V3 D_0045F8E0[];
extern SH2 D_0045F880[];
extern f32 D_0045F8B0[];
extern s32 D_004C283C;
extern s32 func_00417A40(void);
extern f64 func_00119B08(s32);
extern s32 dptoli(f64);
extern f32 func_00417440(u32);
extern f32 func_00417500(u32);
extern void func_0033EE60(V3 *);

void func_0033F030(DA *p)
{
    s16 t = p->h1e + 1;
    p->h1e = t;
    if (t >= 5) {
        s16 u;
        p->h1e = 0;
        u = p->h1c + 1;
        p->h1c = u;
        if ((u32)u >= 10) {
            u32 r = (u32)func_00417A40() % 6;
            p->v34 = D_0045F8E0[r];
            p->h1c = 0;
            func_0033EE60(&p->v34);
        }
        if (p->h1c == 5) {
            p->v34.x += 50.0f * func_00417440((u32)(s32)(0.5 + 65536.0 * func_00119B08(func_00417A40() % 360) / 360.0) & 0xFFFF);
            p->v34.z += 50.0f * func_00417500((u32)(s32)(0.5 + 65536.0 * func_00119B08(func_00417A40() % 360) / 360.0) & 0xFFFF);
        }
        p->hcc = D_0045F880[p->h1c].v;
        p->w84 = D_004C283C;
        p->f50 = D_0045F8B0[p->h1c];
        p->f54 = D_0045F8B0[p->h1c];
        p->f58 = D_0045F8B0[p->h1c];
    }
}
