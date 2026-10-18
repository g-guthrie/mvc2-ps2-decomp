typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8, D_004F1FCC, D_004F1FD0;

void func_00268350(u8 *p, u8 *q) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern s32 func_00268A60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 f2, c;
    u32 t;
    func_001266A0(p, 1, 7);
    *(s16 *)(q + 0x1C) -= 0x800;
    *(s32 *)(p + 0x48) = *(s16 *)(q + 0x1C);
    p[0x209] = 2;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00268A60(p) == 0) {
        f2 = D_004F1FD0;
        c = 51.42856979370117f;
        if (!(*(f32 *)(p + 0x38) < f2 - c)) {
            *(f32 *)(p + 0x38) = f2;
            if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x34) = D_004F1FCC - 40.0f;
            else *(f32 *)(p + 0x34) = 40.0f + D_004F1FC8;
            t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(s32 *)(p + 0x48) = 0;
            func_001757E0(p, 0x15, 0x16);
        }
    }
}

void func_001F9000(u8 *p) {
    extern void func_00183d50();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    f32 *a, *c, *b, *d;
    f32 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    c = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 2, 3);
        *(u32 *)a = 0;
        *(u32 *)c = 0;
        *(u32 *)b = 0;
        *(u32 *)d = 0;
        if (p[0x1E6] != 0) v = -5.0f; else v = 5.0f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = 0.20833332836627960f; else v = -0.20833332836627960f;
        *(f32 *)(p + 0x68) = v;
    } else {
        func_00175700(p);
    }
}
