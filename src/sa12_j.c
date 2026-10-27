typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004BFC18[2];
extern s16 D_004BFC1C[2];

void func_001F1F60(u8 *p) {
    extern void func_00175700(u8 *);
    extern u8 *func_001E7FD0(u8 *);
    extern void func_0015D010(u8 *, f32 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185770(u8 *, u8 *);
    u8 *r;
    f32 v[4];
    *(s16 *)(p + 0x3F8) = 2;
    if (*(s8 *)(p + 0x161) != 0) {
        func_00175700(p);
        if ((r = func_001E7FD0(p)) == 0) return;
        p[6] = 4;
        p[7] = 0;
        *(u32 *)&v[0] = 0xC312AAAA;
        *(u32 *)&v[1] = 0x432B6DB6;
        func_0015D010(p, v);
        func_001266A0(p, 5, 5);
        p[0x20B] = 0xC5;
        func_001757E0(p, 0xF, 0x18);
        func_00185770(p, r);
        return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    if (p[0x216] == 0) {
        if (p[0x269] == 8) {
            *(u32 *)(p + 0x5C) = 0x40A00000;
            *(u32 *)(p + 0x68) = 0;
        } else {
            *(u32 *)(p + 0x5C) = 0x40BAAAAA;
            *(u32 *)(p + 0x68) = 0x3C555555;
        }
        *(s16 *)(p + 0x1C) = D_004BFC18[p[0x1B7]];
    } else {
        *(u32 *)(p + 0x5C) = 0x40555555;
        *(u32 *)(p + 0x68) = 0x3C555555;
        *(s16 *)(p + 0x1C) = D_004BFC1C[p[0x1B7]];
    }
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
}
