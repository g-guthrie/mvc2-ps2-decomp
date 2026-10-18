typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001B70B0(u8 *a0) {
    extern void (*D_0044BE80[])(u8 *, u8 *);
    u8 *p = *(u8 **)(a0 + 0x18);
    if (p[5] != 0 || p[0x1E4] != 0x1D) {
        a0[4] = 2;
    } else {
        D_0044BE80[a0[5]](a0, p);
    }
}

void func_001FB730(u8 *p) {
    extern void func_001266A0();
    extern void func_0015D010();
    extern void func_0018C6E0();
    extern void func_001757E0();
    f32 v[3];
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    v[0] = 86.6666641f;
    v[1] = 300.0f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 2);
}

typedef struct Q379 { u8 pad[0x34]; f32 f34; f32 f38; u8 pad2[0x161-0x3c]; s8 b161; } Q379;
typedef struct P379 { u8 pad[0x18]; Q379 *q; u8 pad2[0x13C-0x1C]; u8 b13c; } P379;
void func_00379350(P379 *pp) {
    u8 *p = (u8 *)pp;
    extern void func_001757E0();
    extern s32 func_00175700();
    extern void func_003793F0();
    f32 t;
    ((Q379 *)p)->f34 = pp->q->f34;
    ((Q379 *)p)->f38 = pp->q->f38;
    ((Q379 *)p)->f38 += 548.571411f;
    func_001757E0(p, 0x15, 8);
    for (;;) {
        if (*(s8 *)(*(u8 **)(p + 0x18) + 0x161) == *(s8 *)(p + 0x161)) {
            p[0x13C] = 1;
            return;
        }
        if ((s8)func_00175700(p) < 0) {
            func_003793F0(p);
            return;
        }
    }
}

typedef struct F5C {
    u8 pad0[0x7];
    u8 b7;
    u8 pad1[0x34 - 8];
    f32 f34;
    f32 f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6c;
} F5C;

void func_002FDE50(F5C *p) {
    extern void func_00175700();
    extern s32 func_001864a0();
    extern void func_001757E0();
    extern void func_00183d50();
    func_00175700();
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_001864a0(p) != 0) {
        u32 t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        func_001757E0(p, 0x14, 1);
        func_00183d50(p);
        *(s16 *)((u8 *)p + 0x1C) = 0x28;
    }
}

