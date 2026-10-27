typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00244F20(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (p[0x1E6] == 0) {
        if ((s8)p[0x211] == 2) {
            func_00184540(p);
            return;
        }
    } else {
        if ((s8)p[0x211] == 1) {
            func_00184540(p);
            return;
        }
    }
    if ((s8)p[0x1B2] != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) += 34.285713196f;
        if (p[6] == 1) {
            func_001757E0(p, 0x14, 4);
            *(u32 *)(p + 0x5C) = 0x40D55555;
            *(u32 *)(p + 0x68) = 0xBE555555;
            *(u32 *)(p + 0x60) = 0x41892492;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        } else {
            func_001757E0(p, 0x14, 5);
            *(u32 *)(p + 0x5C) = 0x40555555;
            *(u32 *)(p + 0x68) = 0xBDD55555;
            *(u32 *)(p + 0x60) = 0x41892492;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        }
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

void func_00277100(u8 *p) {
    extern int func_00175700(u8 *);
    extern f32 func_00117078(f32);
    extern void func_001757E0(u8 *, s32, s32);
    f32 prod;
    f32 t;
    f32 c;
    f32 r;
    s16 h;
    u8 *q;
    f32 *pa;
    f32 *pb;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    pa = (f32 *)(p + 0x5C);
    t = *(f32 *)(p + 0x68);
    t = *(f32 *)(p + 0x5C) + t;
    *pa = t;
    prod = t * *(f32 *)(p + 0x68);
    pb = (f32 *)(p + 0x68);
    if (prod >= 0.0f) {
        *pa = 0.0f;
        *pb = 0.0f;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h != 0) {
        q = *(u8 **)(p + 0x220);
        r = func_00117078(*(f32 *)(p + 0x34) - *(f32 *)(q + 0x34));
        if (r > 90.0f) {
            if (*(s8 *)(p + 0x1B2) == 0) return;
        }
    }
    if (p[0x1B7] != 0) {
        func_001757E0(p, 0x15, 0x14);
        if (*(s16 *)(p + 0x140) != 0) c = 4.0f;
        else c = -4.0f;
        *(f32 *)(p + 0x5C) = c;
        if (*(s16 *)(p + 0x140) != 0) c = -0.2f;
        else c = 0.2f;
        *(f32 *)(p + 0x68) = c;
    } else {
        func_001757E0(p, 0x15, 0x13);
        if (*(s16 *)(p + 0x140) != 0) c = 4.0f;
        else c = -4.0f;
        *(f32 *)(p + 0x5C) = c;
        if (*(s16 *)(p + 0x140) != 0) c = -0.2f;
        else c = 0.2f;
        *(f32 *)(p + 0x68) = c;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
}
