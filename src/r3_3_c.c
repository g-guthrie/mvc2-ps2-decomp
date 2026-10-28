/* try30.sh "-O3 -Op -sdatathreshold 0": 6/124 words differ: a0 vs a1 temp for 0x24 copy/0x168 load; else-arm dsll32 v1,v1 vs retail dsll32 v1,zero */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
extern u8 D_0044E0B0[];
typedef struct { u8 b0; u8 p1; u16 h2; f32 f4, f8, fc, f10; } QE;
typedef struct { u8 pad[0x1E]; s16 f1e; u8 p20; u8 b21; } SA;

void func_001D3C10(u8 *a, u8 *b) {
    extern void func_00175580(u8 *, s32, s32, s32);
    extern void func_003DAA40(u8 *);
    u32 t;
    QE *q;
    s32 v;
    f32 k;
    f32 m;
    u16 h;
    SA *sa;
    if (a[4] == 0) {
        t = a[4];
        a[4] = t + 1;
        *(B3c *)(a + 0xEC) = *(B3c *)(b + 0xEC);
        a[0x13C] = 1;
        a[2] = b[2];
        a[1] = b[1];
        *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
        *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
        a[0x1B7] = b[0x1B7];
        a[0x1B8] = b[0x1B8];
        *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
        *(V3 *)(a + 0x50) = *(V3 *)(b + 0x50);
        *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
        a[0x13C] = 0;
        *(s16 *)(a + 0x1E) = 0;
        return;
    }
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    h = *(u16 *)(b + 0x168);
    if (h == 0x1500 || h == 0x1510) {
        sa = (SA *)a;
        v = *(s8 *)(b + 0x151);
        if (v != 0) {
            if (sa->f1e == (s8)v) return;
            sa->f1e = (s8)v;
            q = (QE *)(D_0044E0B0 + a[0x21] * 0xB4 + (sa->f1e - 1) * 20);
            if ((a[0x13C] = q->b0) == 0) return;
            func_00175580(a, 0x1B, 0x12, q->h2);
            *(f32 *)(a + 0x50) = q->f4;
            *(f32 *)(a + 0x54) = q->f8;
            m = 0.949999988079071f * q->fc;
            *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + q->f10;
            if (*(s16 *)(b + 0x140) == 0) m = -m;
            *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + m;
        } else {
            a[0x13C] = 0;
            *(s16 *)(a + 0x1E) = (s8)(v = 0);
        }
    } else {
        *(f32 *)(a + 0x50) = *(f32 *)(a + 0x54) = 1.0f;
        func_003DAA40(a);
    }
}
