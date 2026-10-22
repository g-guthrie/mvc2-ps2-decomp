typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } Gc;
extern Gc *D_004C2794;
extern u16 *D_004C29E0;
extern u8 *D_004C29E4;

void func_00398820(u8 *p)
{
    extern s32 func_00174470(u8 *);
    extern void func_00398A60(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *q;
    f32 c;
    f32 f;
    s8 r;
    s16 h;
    u32 t;
    u32 z;
    u32 col;
    if (func_00174470(p) == 0) {
        func_00398A60(p);
        return;
    }
    if (*D_004C29E0 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_00398A60(p);
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    c = 115.71427917480469f;
    f = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x38) = f;
    *(f32 *)(p + 0x38) = f + c;
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) += 116.66666412353516f;
    } else {
        *(f32 *)(p + 0x34) -= 116.66666412353516f;
    }
    if (p[6] != 0) {
        r = func_00175700(p);
        if (r < 0) {
            D_004C29E4[2] = 1;
            func_00398A60(p);
        }
        goto end;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (p[0x1B7] != 0) {
            p[0x1B5] = 0x4F;
            z = p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            p[0x1B5] = 0x45;
            z = p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x14, 3);
        return;
    }
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        *(s16 *)(p + 0x1C) = 0;
        if (*(s8 *)(p + 0x151) != 0) {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x14, 3);
        }
    }
end:
    func_001E7F60(p);
}
