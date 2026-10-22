typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004553C0[])(u8 *);
typedef struct { u8 pad[0x3F8]; s16 h3F8, h3FA, h3FC; } SM;

void func_0027FBB0(u8 *p) {
    extern void func_002804E0(u8 *);
    extern void func_00181C40(u8 *);
    extern void func_00187A20(u8 *);
    extern void func_0027D6B0(u8 *);
    extern void func_00190C10(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00190B30(u8 *);
    extern void func_0018D290(u8 *);
    extern void func_00190580(u8 *);
    extern void func_00183C40(u8 *);
    s32 t;
    u32 w;
    u8 *q;
    u8 *r;
    if (*(s8 *)(p + 0x539) != 0) {
        func_002804E0(p);
    }
    func_00181C40(p);
    func_00187A20(p);
    func_0027D6B0(p);
    if (p[0x216] == 0 && ((SM *)p)->h3F8 != 0) {
        s16 h = ((SM *)p)->h3F8 - 1;
        *(s16 *)((s32)p + 0x3F8) = h;
        if (h <= 0) {
            p[0x406] = 0;
            func_00190C10(p);
            func_00175C00(p, 1);
        } else {
            p[0x406] = 1;
        }
    }
    if (p[0x216] != 0 || p[0x406] != 0) {
        func_00190B30(p);
    }
    func_0018D290(p);
    t = *(s8 *)(p + 0x1B4);
    if (t != 0) {
        p[0x1B4] = t - 1;
        w = *(u16 *)(p + 0x364);
        w |= *(u16 *)(p + 0x354);
        *(u16 *)(p + 0x364) = w;
        w = *(u16 *)(p + 0x366);
        w |= *(u16 *)(p + 0x35C);
        *(u16 *)(p + 0x366) = w;
        func_00190580(p);
        if (p[5] != 3) {
            func_00183C40(p);
        }
        if (p[5] == 1) {
            p[0x1FE] = 1;
        }
    } else {
        t = *(s8 *)(p + 0x201);
        if (t != 0) p[0x201] = t - 1;
        t = *(s8 *)(p + 0x1FF);
        if (t != 0) p[0x1FF] = t - 1;
        t = *(s8 *)(p + 0x24B);
        if (t != 0) p[0x24B] = t - 1;
        t = *(s8 *)(p + 0x200);
        if (t != 0) p[0x200] = t - 1;
        t = *(s8 *)(p + 0x206);
        if (t != 0) p[0x206] = t - 1;
        t = *(s8 *)(p + 0x207);
        if (t != 0) p[0x207] = t - 1;
        t = *(s8 *)(p + 0x33C);
        if (t != 0) {
            s8 u = t - 1;
            p[0x33C] = u;
            if (u <= 0) p[0x33B] = 0;
        }
        {
            s16 h = ((SM *)p)->h3FA;
            if (h != 0) {
                h = h - 1;
                *(s16 *)((s32)p + 0x3FA) = h;
                if (h == 0) p[0x402] = 0;
            }
            h = ((SM *)p)->h3FC;
            if (h != 0) {
                h = h - 1;
                *(s16 *)((s32)p + 0x3FC) = h;
                if (h == 0) p[0x403] = 0;
            }
        }
        D_004553C0[p[5]](p);
        q = *(u8 **)(p + 0x220);
        r = q + 0x249;
        if (*r != 0 && q[5] == 0) {
            *r = 0;
        }
    }
    p[0x159] = 0xFF;
    *(s8 *)(p + 0x1B0) = -0x80;
    if (*(s8 *)(p + 0x200) != 0) {
        p[0x1B0] = 0;
    }
    *(s8 *)(p + 0x1B1) = -0x80;
    if (*(s8 *)(p + 0x201) != 0 || p[5] == 1 || (p[5] == 2 && p[0x20A] == 0)) {
        p[0x1B1] = 0;
    }
}
