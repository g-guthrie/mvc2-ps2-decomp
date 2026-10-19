typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 x, y, z; } T3;
extern T3 D_0044C3C0[];
void func_001BEDE0(u8 *p, u8 *q) {
    T3 *e;
    s16 h;
    *(f32 *)(p + 0x50) += 0.4000000059604645f;
    *(f32 *)(p + 0x54) += 0.25f;
    *(f32 *)(p + 0x118) += -*(f32 *)(p + 0x118) / *(s16 *)(p + 0x1C);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        s16 d;
        e = &D_0044C3C0[p[0x20]];
        d = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = d;
        if (d == 0) *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * e->x;
        else *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 1.6666666269302368f * e->x;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737549f * e->y;
    }
}

void func_0015A950(u8 *p) {
    extern void func_003DAA40();
    s32 v = *(s32 *)(p + 0xD4);
    if (v != 0) {
        *(s32 *)(p + 0xD4) = v - 1;
        return;
    }
    p[0x13C] = 1;
    {
        f32 c = 0.2777777910232544f;
        f32 z = 0.0f;
        f32 f;
        *(f32 *)(p + 0x50) += c * *(s32 *)(p + 0xD8);
        *(f32 *)(p + 0x58) += c * *(s32 *)(p + 0xD8);
        {
            s16 h = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = h;
            if (h == 0) {
                *(s16 *)(p + 0x1C) = 1;
                f = *(f32 *)(p + 0x78) - 0.25f;
                *(f32 *)(p + 0x78) = f;
                if (f < z) *(f32 *)(p + 0x78) = z;
                f = *(f32 *)(p + 0x7C) - 0.25f;
                *(f32 *)(p + 0x7C) = f;
                if (f < z) *(f32 *)(p + 0x7C) = z;
                f = *(f32 *)(p + 0x80) - 0.25f;
                *(f32 *)(p + 0x80) = f;
                if (f < z) *(f32 *)(p + 0x80) = z;
            }
        }
        {
            s16 h = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = h;
            if (h == 0) func_003DAA40(p);
        }
    }
}

void func_0015AC20(u8 *p) {
    extern void func_003DAA40(u8 *);
    s32 delay = *(s32 *)(p + 0xD4);
    f32 rate = 0.46666666865348816f;
    if (delay != 0) {
        *(s32 *)(p + 0xD4) = delay - 1;
        return;
    }

    p[0x13C] = 1;
    *(f32 *)(p + 0x50) += rate * (f32)*(s32 *)(p + 0xD8);
    *(f32 *)(p + 0x54) += rate * (f32)*(s32 *)(p + 0xD8);

    if (*(s16 *)(p + 0x1C) == 0) {
        *(s16 *)(p + 0x1C) = 1;
        {
            f32 value = *(f32 *)(p + 0x74) - 0.0416666679084301f;
            *(f32 *)(p + 0x74) = value;
            if (value < 0.0f) *(f32 *)(p + 0x74) = 0.0f;
        }
        {
            f32 value = *(f32 *)(p + 0x78) - 0.0416666679084301f;
            *(f32 *)(p + 0x78) = value;
            if (value < 0.0f) *(f32 *)(p + 0x78) = 0.0f;
        }
        {
            f32 value = *(f32 *)(p + 0x7C) - 0.0416666679084301f;
            *(f32 *)(p + 0x7C) = value;
            if (value < 0.0f) *(f32 *)(p + 0x7C) = 0.0f;
        }
        {
            f32 value = *(f32 *)(p + 0x80) - 0.0416666679084301f;
            *(f32 *)(p + 0x80) = value;
            if (value < 0.0f) *(f32 *)(p + 0x80) = 0.0f;
        }
    }

    {
        s16 value = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = value;
        if (value == 0) func_003DAA40(p);
    }
}
