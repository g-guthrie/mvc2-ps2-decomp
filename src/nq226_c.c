typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3_nqc;
extern V3_nqc D_004B14A0[];
extern V3_nqc D_004B12A0[];

typedef struct {
    u8 pad0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 pad20[0x34 - 0x20];
    V3_nqc v34;
    s32 w40;
    s32 w44;
    s32 w48;
    u8 pad4c[0x68 - 0x4C];
    V3_nqc v68;
} O13D;

void func_0013D350(O13D *p) {
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    V3_nqc *b0, *b1, *b2, *a0, *a1, *a2;
    f32 w0, w1, w2;
    double k;
    s32 i;
    func_0032FEB0((f32)p->h1e / 5.0f, &w0, &w1, &w2);
    i = p->h1c;
    b0 = &D_004B12A0[i - 1];
    a1 = &D_004B14A0[i];
    b1 = &D_004B12A0[i];
    a0 = &D_004B14A0[i - 1];
    a2 = &D_004B14A0[i + 1];
    b2 = &D_004B12A0[i + 1];
    k = 65536.0;
    p->w40 = (u32)(s32)(0.5 + k * (double)(a0->x * w0 + a1->x * w1 + a2->x * w2) / 360.0) & 0xFFFF;
    k = 65536.0;
    p->w44 = (u32)(s32)(0.5 + k * (double)(a0->y * w0 + a1->y * w1 + a2->y * w2) / 360.0) & 0xFFFF;
    k = 65536.0;
    p->w48 = (u32)(s32)(0.5 + k * (double)(a0->z * w0 + a1->z * w1 + a2->z * w2) / 360.0) & 0xFFFF;
    p->v68.x = a0->x * w0 + a1->x * w1 + a2->x * w2;
    p->v68.y = a0->y * w0 + a1->y * w1 + a2->y * w2;
    p->v68.z = a0->z * w0 + a1->z * w1 + a2->z * w2;
    p->v34.x = b0->x * w0 + b1->x * w1 + b2->x * w2;
    p->v34.y = b0->y * w0 + b1->y * w1 + b2->y * w2;
    p->v34.z = b0->z * w0 + b1->z * w1 + b2->z * w2;
    p->h1e++;
    p->h1e = p->h1e % 5;
    if (p->h1e == 0) {
        if (++p->h1c >= 0x29) {
            p->h1c = 1;
            p->h1e = 0;
        }
    }
}
