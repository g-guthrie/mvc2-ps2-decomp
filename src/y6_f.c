typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x38]; f32 f38; u8 pad1[0x3F4]; f32 f430; } F2F;

s32 func_002FBF20(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_0045C010[];
    F2F *q = (F2F *)p;
    if (func_00189310(p, D_0045C010, p + 0x380) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s32 v;
        if (!(102.85713958740234f + q->f430 < q->f38)) return 0;
        v = *(s8 *)(p + 0x1E8);
        if (v != 0) return 0;
        p[0x1E8] = v + 1;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; } F3A;

void func_003A3340(u8 *p, u8 *q) {
    extern s32 func_003A3810();
    extern void func_003A3880();
    extern s32 func_00175700();
    extern s32 func_001748C0();
    extern void func_001757E0();
    f32 vec[4];
    s32 r;
    if (func_003A3810(p, q) == 0) {
        func_003A3880(p, q);
        return;
    }
    r = func_00175700(p);
    if ((s8)r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0x20;
        *(s16 *)(p + 0x1E) = 0x10;
        vec[0] = (*(F3A **)(q + 0x220))->f34;
        vec[1] = (*(F3A **)(q + 0x220))->f38;
        r = func_001748C0(q + 0x34, vec);
        p[0x22] = (u8)r >> 3;
        *(s32 *)(p + 0xD4) = (p[0x1B7] != 0) ? 0x384 : 0x190;
        func_001757E0(p, 0x15, 3);
    }
}
