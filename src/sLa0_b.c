#pragma opt_lifetimes off
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[5];
    s8 b5;
    u8 pad6[2];
    s16 h8;
    u8 padA[2];
    s16 hC;
    s16 hE;
    u8 pad10[0x88 - 0x10];
    s8 b88;
} G_b;

typedef struct { u8 a; s8 b[3]; } Sc_b;
extern G_b *D_004C2840;
extern u8 *D_004C2674;
extern u8 *D_004C2678;
extern u8 D_004C2668;
extern u8 D_004C2664;
extern u8 D_004C2670;
extern u8 D_004C266C;
extern u8 D_004C27C4;
extern s8 D_004C27C0;
extern u16 D_004F4480[];
extern u16 D_004F4494[];

void func_0016B7C0(void)
{
    extern void func_003298B0(s32, s32, s32);
    extern void func_001E40E0(void);
    extern void func_001E4140(void);
    extern void func_001E42D0(s32);
    extern void func_0016D190(void);
    extern u8 *func_0016C280(s32, u8, f32, f32, f32, f32);
    extern void func_0016BF80(f32, f32);
    extern void func_0016BF10(void);
    s16 t;
    s16 v;
    s8 a;
    f32 x;
    u8 *s;
    s32 c;
    s8 *q;

    t = D_004C2840->h8;
    D_004C2840->h8 = t - 1;
    if (t == 0) {
        D_004C2840->b5++;
        D_004C2840->h8 = 0x20;
        D_004C2668 = 1;
        func_003298B0(0xFF000000, 0x20, 1);
        return;
    }
    if (D_004C2840->h8 == 0xDC) {
        func_001E40E0();
        func_001E4140();
        func_001E42D0(0x14);
    }
    func_0016D190();
    if (--D_004C2840->hC == 0) {
        v = *D_004C2674;
        D_004C2840->hC = v;
        if (v != 0xFF) {
            D_004C2840->hC = D_004C2840->hC * 60;
            s = D_004C2674;
            q = ((Sc_b *)s)->b;
            switch (s[1]) {
            case 0: break;
            default:
                D_004C27C4 = 1;
                D_004C27C0 = *q + 13;
            }
            { s32 id = s[2] + 0x910; f32 f1 = 1.0f; f32 f32v = 32.0f; f32 f2 = 2.0f; f32 f0 = 0.0f;
            func_0016C280(id, s[3], f32v, f0, f1, f2); }
            D_004C2674 += 4;
        }
    }
    if (*D_004C2678 != 0xFF) {
        if (--D_004C2840->hE == 0) {
            D_004C2840->hE = 0x20;
            x = 304.0f;
            s = D_004C2678;
            if (*s == 0xFE) D_004C2670 = 1;
            if (*s == 0xFD) D_004C2670 = 0;
            if (*s == 0xFC) D_004C2664 = 1;
            goto test;
        body:
            if (c != 0x20) func_0016BF80(x, -1.0f);
            if (D_004C2664 == 0) x += 16.0f;
            else x += 32.0f;
            D_004C2678++;
        test:
            if ((c = *(s = D_004C2678)) < 0xF0) goto body;
            if (*s == 0xFE) D_004C2670 = 1;
            if (*s == 0xFD) D_004C2670 = 0;
            if (*s == 0xFC) D_004C2664 = 1;
            D_004C2678++;
        }
    } else {
        D_004C266C = 1;
    }
    a = D_004C2840->b88;
    if (((a & 1) && (D_004F4480[0] & 0x8000)) || ((a & 2) && (D_004F4494[0] & 0x8000))) {
        func_0016BF10();
    }
}
