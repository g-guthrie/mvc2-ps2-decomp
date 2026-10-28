typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_nq42b;

typedef struct {
    u8 pad0[3];
    s8 b3;
    u8 pad4[0xE - 4];
    s16 he;
    u8 pad10[0x91 - 0x10];
    s8 b91;
} G_nq42b;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x1C - 5];
    s16 h1c;
    u8 pad1e[0x20 - 0x1E];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    V3_nq42b v34;
    u8 pad40[0x13C - 0x40];
    u8 b13c;
} P_nq42b;

extern G_nq42b *D_004C2840;
extern V3_nq42b D_004407A0[8];
extern void (*D_00440800[])();

typedef struct { u8 pad0[0x1C]; s16 h; u8 pad1e[2]; u8 idx; u8 pad21[0x13]; f32 f34, f38, f3c; } P13F5F0;
extern V3_nq42b D_004406E0[8];
static void func_0013F5F0(P13F5F0 *p) {
    V3_nq42b *a = &D_004406E0[p->idx];
    V3_nq42b *b = &D_004407A0[p->idx];
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


void func_0013F6B0(P_nq42b *p) {
    extern void func_003DAA40();
    G_nq42b *q = D_004C2840;
    if (q->b3 != 4 || q->b91 != 0) {
        func_003DAA40();
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
