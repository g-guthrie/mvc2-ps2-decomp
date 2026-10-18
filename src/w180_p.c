typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32; typedef struct { u8 pad[0x38]; f32 f38; } PK;

void func_0029A970(u8 *p) {
    s8 r;
    f32 v;
    u8 *o;
    s32 *q;
    s32 *q2;
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_001266A0(u8 *, s32, s32);
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        if (p[0x1E6] != 0) {
            v = -7.5f;
        } else {
            v = 7.5f;
        }
        *(f32 *)(p + 0x5C) = v;
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBE892492;
    }
    r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        { u32 z = 0; p[0x151] = z; }
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 1;
        o[0x20D] = 2;
        func_001266A0(p, 0, 0);
        o[0x1B5] = 0x23;
        o[0x1E6] = p[0x1E6];
    }
    if (*(s8 *)(p + 0x150) == 0) {
        q = (s32 *)(p + 0x60);
        q2 = (s32 *)(p + 0x6C);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            ((PK *)p)->f38 = *(f32 *)(p + 0x430);
            *q = 0;
            *q2 = 0;
        }
    }
}
