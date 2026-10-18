typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001C7EC0(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    u32 t;
    f32 c, k;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(q + 0x151) == 0) {
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 0x32;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x68) = 0xBDD55555;
        } else {
            *(u32 *)(p + 0x68) = 0x3DD55555;
        }
        *(u32 *)(p + 0x6C) = 0x3E2B6DB6;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        c = -3.3333332538604736f;
        if (*(s16 *)(p + 0x140) != 0) c = -c;
        k = 8.571428298950195f;
        *(f32 *)(q + 0x34) = c + *(f32 *)(p + 0x34);
        *(f32 *)(q + 0x38) = k + *(f32 *)(p + 0x38);
    }
}

void func_003B3BB0(u8 *p, u8 *q) {
    extern void func_003B4030(u8 *, u8 *, s16 *);
    extern s32 func_00175700(u8 *);
    extern void func_003B4010(u8 *, u8 *);
    extern void func_001E7F60(u8 *);
    s16 *a2;
    s8 r;
    u32 t;
    a2 = (s16 *)(p + 0xD0);
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        func_003B4030(p, q, a2);
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x34) += (f32)a2[1];
    *(f32 *)(p + 0x38) += (f32)a2[2];
    r = func_00175700(p);
    if (r < 0) {
        t = p[4];
        p[4] = t + 1;
        func_003B4010(p, q);
    } else if (p[0x1B5] != 0xFF) {
        func_001E7F60(p);
    }
}
