typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern s32 func_001843A0();
extern void func_001863F0();
extern int func_00174470(const void *);
extern s32 func_00350FD0();

/* Provisional: missing actor argument and incorrect return contract. */
s32 func_00278C70(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0();
    if ((s8)func_00175700(p) < 0) { return func_001843A0(p); }
}

extern s32 func_00175670();
extern void func_00282700();

/*BB*/
void func_00282680(u8 *p) {
    u32 c = p[0x1FC];
    if (c == 1) goto a;
    switch (c) {
    case 2:
        if (p[6] == 0) goto a;
        func_00282700(p);
        break;
    case 0:
    a:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

extern s32 func_001757E0();
extern void func_00280330(void *);

s32 func_0027E820(u8 *p) {
    s32 r;
    if (*(s16 *)(p + 0x1C)) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) r = func_001757E0(p, 3, 2);
        return r;
    } else {
        if ((s8)func_00175700(p) < 0) {
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_00280330(p);
        }
    }
}

extern u8 *func_001E7FD0(u8 *);
extern s32 *D_00451AF0[];

u8 *func_0022B620(u8 *p) {
    u8 *r = 0;
    if (D_00451AF0[p[0x20D]]) {
        u32 t = *(u16 *)(p + 0x20E) & 0xC00;
        if (t) {
            p[0x22] = t >> 10;
            if (p[0x212] == 0 && p[0x1B7] == 1) {
                r = func_001E7FD0(p);
                if (r) p[0x20B] = 2;
            }
        }
    }
    return r;
}

extern void func_001CEA00();
extern void *func_003996C0(void *, u8);

void func_002C7B40(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        u8 *f = p + 0x160;
        s8 b = *(s8 *)(f + 1);
        u8 *g = f + 1;
        if (b & 1) {
            *g = b & ~1;
            func_001CEA00(p, 6);
        }
        if (*(s8 *)(p + 0x151)) {
            p[0x151] = 0;
            func_003996C0(p, 0);
        }
    }
}
