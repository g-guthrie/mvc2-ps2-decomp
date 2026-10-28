/* MW 3.0.3 (./try.sh) -O3 -sdatathreshold 0; static func_003BB910 is a real callee (verified at its own address). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[1]; u8 b1; u8 pad2[1]; u8 b3; u8 pad4[0x425 - 4]; u8 b425; u8 pad426[0x430 - 0x426]; f32 f430; } Q3BC;
typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x18 - 6];
    Q3BC *q18;
    u8 pad1c[0x21 - 0x1C];
    u8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad70[0x1B2 - 0x70];
    s8 b1B2;
    u8 pad1B3[0x1C4 - 0x1B3];
    Q3BC *q1C4;
} P3BC;

extern f32 D_00474670[];

static void func_003BB910(u8 *p) { p[4]++; p[5] = 1; p[6] = 0; p[316] = 1; }

void func_003BC0C0(P3BC *p) {
    extern s32 func_003BCFB0(P3BC *);
    extern s32 func_003BD4C0(P3BC *);
    extern void func_003BB8F0(P3BC *);
    extern void func_003BB730(P3BC *);
    extern s32 func_003BD650(P3BC *);
    extern void func_003BB890(P3BC *);
    extern void func_00175700(P3BC *);
    extern void func_001E7F60(P3BC *);
    Q3BC *q;
    Q3BC *r;
    s32 a;
    s32 c;
    f32 f0, f1, f2, f3;
    q = p->q18;
    if (func_003BCFB0(p) != 0) {
        func_003BB910((u8 *)p);
        return;
    }
    if (func_003BD4C0(p) != 0) {
        func_003BB8F0(p);
        return;
    }
    if (p->b5 == 0) {
        a = p->b1B2;
        if (a != 0) {
            r = p->q1C4;
            if (r->b3 == 0) {
                if (r->b425 != 0 || ((c = r->b1) >= 0x18 && c < 0x1B)) {
                    func_003BB910((u8 *)p);
                } else {
                    if (((s8)a & 0x7F) != 0) {
                        func_003BB910((u8 *)p);
                    } else {
                        func_003BB890(p);
                    }
                }
            } else {
                func_003BB910((u8 *)p);
            }
        } else if (func_003BD650(p) != 0) {
            func_003BB8F0(p);
        } else {
            p->f34 += p->f5c;
            p->f5c += p->f68;
            p->f38 += p->f60;
            p->f60 += p->f6c;
            f3 = q->f430;
            f2 = D_00474670[p->b21];
            f1 = f3;
            f1 -= f2;
            if (p->f38 < f1) {
                p->f38 = f3 + f2;
                func_003BB910((u8 *)p);
            } else {
                func_00175700(p);
                func_001E7F60(p);
            }
        }
    } else {
        func_003BB730(p);
    }
}
