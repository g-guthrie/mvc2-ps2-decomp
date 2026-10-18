typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003CCFE0(u8 *o) {
    u8 *func_003CA7E0(); void func_003DAA40();
    u8 *a = *(u8**)(o + 0x18);
    if (a[5] == 0 && a[0x1E4] == 0x1D) {
        u8 *r = func_003CA7E0(a, *(s16*)(o + 0x1E));
        u8 *p;
        s16 t;
        if (r == 0) return;
        p = *(u8**)(o + 0x14);
        if (p != 0) {
            f32 c = 53.33333206f;
            if (*(s16*)(r + 0x140) != 0) c = -c;
            *(f32*)(r + 0x34) = *(f32*)(p + 0x34) + c;
        }
        *(u8**)(o + 0x14) = r;
        t = *(s16*)(o + 0x1E) - 1;
        *(s16*)(o + 0x1E) = t;
        if (t >= 0) return;
    }
    func_003DAA40(o);
}

void func_00324B60(u8 *o) {
    void func_00175700(); void func_00175C00(); void func_00176160(); void func_001830D0();
    f32 v[4];
    s32 t;
    o[0x33C] = 5;
    func_00175700();
    t = *(s8*)(o + 0x150);
    if (t != 0) {
        if ((s8)t < 0) {
            func_00175C00(o, 1);
        } else {
            func_00176160(o, 0, *(s16*)(o + 0x1C) + o[0x15B], 0);
        }
    }
    if (*(s8*)(o + 0x151) != 0) {
        u32 t = o[6]; o[6] = t + 1;
        o[0x151] = 0;
        v[0] = 0.0f;
        v[1] = 34.28571319f;
        func_001830D0(o, v, 1);
    }
}

void func_002F5810(u8 *o) {
    s32 func_00175700(); void func_00184540();
    f32 z = 0.0f;
    s32 r = func_00175700(o);
    if ((s8)r < 0) {
        *(f32*)(o + 0x5C) = z;
        *(f32*)(o + 0x68) = z;
        if (*(s8*)(o + 0x1B2) == 0) {
            *(f32*)(o + 0x60) = z;
            func_00184540(o);
            return;
        }
        func_00184540(o);
    } else if (*(s8*)(o + 0x1B2) != 0) {
        *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
        *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
        *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
        *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    }
}

void func_001FDEC0(u8 *o) {
    void func_00175700(); void func_001757E0();
    s16 t;
    func_00175700(o);
    *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
    *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    t = *(s16*)(o + 0x1C) - 1;
    *(s16*)(o + 0x1C) = t;
    if (t == 0) {
        u32 u = o[6]; o[6] = u + 1;
        *(f32*)(o + 0x68) = (o[0x1E6] != 0) ? -0.8333333135f : 0.8333333135f;
        func_001757E0(o, 2, 2);
    }
}

extern f32 D_004F1FD0[];
void func_00268280(u8 *o, u8 *q) {
    void func_001266A0(); void func_00175700(); s32 func_00268A60(); void func_001E3210();
    func_001266A0(o, 1, 7);
    o[0x209] = 2;
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    func_00175700(o);
    if (func_00268A60(o) == 0) {
        if (!(*(f32*)(o + 0x38) < D_004F1FD0[0] - 51.42856979f - 85.71427917f)) {
            u32 t = o[6]; o[6] = t + 1;
            *(s16*)(q + 0x1C) = 0;
            func_001E3210(o, 3);
        }
    }
}

void func_0025DB70(u8 *o) {
    void func_00175700(); void func_001757E0();
    func_00175700(o);
    *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
    *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    if (*(s16*)(o + 0x1C) == 0) {
        u32 u = o[6]; o[6] = u + 1;
        *(f32*)(o + 0x68) += (o[0x1E6] != 0) ? -0.3125f : 0.3125f;
        *(u32*)(o + 0x6C) = 0xBF092492;
        func_001757E0(o, 2, 2);
    }
    {
        s16 t = *(s16*)(o + 0x1C);
        *(s16*)(o + 0x1C) = t - 1;
    }
}
