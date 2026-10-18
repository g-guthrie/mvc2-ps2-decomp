typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G4p;
extern G4p *D_004C2794;

void func_00324CB0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_0018AB10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 v;
    s16 h;
    u32 t;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(f32 *)(p + 0x60);
    if (func_0018AB10(p) != 0) {
        v = *(f32 *)(p + 0x6C);
        func_00175700(p);
    }
    *(f32 *)(p + 0x5C) = v;
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        p[0x1B5] = 0x7C;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 0xA);
        p[0x1B5] = 0x6D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
}
