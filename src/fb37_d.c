typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G2A;
extern G2A *D_004C2794;

void func_002A9BA0(u8 *p)
{
    s8 r;
    u32 t;
    f32 v;
    f32 w;
    extern s8 func_00175700(void);
    extern void func_002AA0E0(u8 *);
    extern void func_00394780(u8 *, s32, s32);
    extern s32 func_001757E0(u8 *, s32, s32);

    p[0x40C] = 2;
    p[0x33C] = 5;
    r = func_00175700();
    if (r >= 0) {
        func_002AA0E0(p);
        if (*(s8 *)(p + 0x161) & 1)
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            func_00394780(p, 8, 0);
        }
        return;
    }
    t = p[6];
    if (t == 2) {
        p[6] = t + 1;
        p[0x1B5] = 0x37;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        *(s16 *)(p + 0x1C) = 0;
        v = p[0x1E6] ? 8.333333015f : -8.333333015f;
        *(f32 *)(p + 0x5C) = v;
        func_00394780(p, 2, 0);
        func_001757E0(p, 0x15, 0x13);
        return;
    }
    p[6] = t + 1;
    p[0x1B5] = 0x38;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(s16 *)(p + 0x1C) = 0;
    v = p[0x1E6] ? 26.66666603f : -26.66666603f;
    *(f32 *)(p + 0x5C) = v;
    w = p[0x1E6] ? -1.25f : 1.25f;
    *(f32 *)(p + 0x68) = w;
    *(u32 *)(p + 0x60) = 0x42092492;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    func_00394780(p, 8, 0);
    func_001757E0(p, 0x15, 0x14);
}
