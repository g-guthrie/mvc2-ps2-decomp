typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2AA;
typedef struct {
    u8 p0[0x34];
    f32 f34, f38;
    u8 p1[0x5C - 0x3C];
    f32 f5c, f60;
    u8 p2[4];
    f32 f68, f6c;
    u8 p3[0x430 - 0x70];
    f32 f430;
} S2AA;

extern G2AA *D_004C2794;

void func_002AA970(S2AA *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    f32 *a;
    u32 t;
    f32 *b;
    if (*(s8 *)((u8 *)p + 0x151) == 0) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        t = ((u8 *)p)[0x1E6];
        a = &p->f5c;
        b = &p->f68;
        if ((t != 0 && p->f5c < 0.0f) || (t == 0 && p->f5c > 0.0f)) {
            *a = 0;
            *b = 0;
        }
        if (p->f38 <= p->f430) {
            p->f38 = p->f430;
        }
    }
    if (func_00175700(p) < 0) {
        p->f5c = 0;
        p->f68 = 0;
        func_00184540(p);
    } else if (((u8 *)p)[0x15B] != 0) {
        u8 *q = (u8 *)p;
        q[0x15B] = 0;
        q[0x1B5] = 0x49;
        q[0x1B2] = *(u16 *)(q + 0x1C0) = 0;
        *(s32 *)(q + 0x1D8) = 0;
        D_004C2794->f7c[q[2]]++;
    }
}
