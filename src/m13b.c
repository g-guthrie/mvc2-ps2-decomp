typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);


void func_002BBAE0(u8 *p) {
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 2;
        *(f32 *)(p + 0x38) += 34.28571319580078f;
        if (p[0x1E6] != 0) {
            v = 20.0f;
        } else {
            v = -20.0f;
        }
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBE092492;
    }
}

void func_0037E8A0(u8 *p, void *owner) {
    *(f32 *)(p + 0x50) += (3.0f - *(f32 *)(p + 0x50)) / (f32) * (s16 *)(p + 0x1C);
    *(f32 *)(p + 0x54) += (3.0f - *(f32 *)(p + 0x54)) / (f32) * (s16 *)(p + 0x1C);
    *(f32 *)(p + 0x118) += (-*(f32 *)(p + 0x118)) / (f32) * (s16 *)(p + 0x1C);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    }
}

extern void func_001E7F60(u8 *);

void func_003628C0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= -3.2142856121063232f) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x6C) = 0;
    }
    func_001E7F60(p);
}
