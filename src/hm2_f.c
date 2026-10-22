typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002A9E50(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_002AA0E0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *s1, *s2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    s1 = p + 0x5C;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    s2 = p + 0x68;
    if (p[0x1E6] == 0) goto L9E4;
    if (*(f32 *)(p + 0x5C) < 0.0f) goto F08;
L9E4:
    if (p[0x1E6] != 0) goto F10;
    if (*(f32 *)(p + 0x5C) <= 0.0f) goto F10;
F08:
    *(s32 *)s1 = 0;
    *(s32 *)s2 = 0;
F10:
    if (*(s8 *)(p + 0x161) < 0) goto F2C;
    func_00175700(p);
    func_002AA0E0(p);
F2C:
    if (!(*(f32 *)(p + 0x60) < 0.0f)) goto F7C;
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    *(f32 *)s1 = 0.0f;
    *(f32 *)s2 = 0.0f;
    func_001757E0(p, 0x15, 5);
F7C:
    return;
}
