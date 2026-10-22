typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_a;
extern H_a *D_004C2794;

extern void func_0022FFB0(u8 *a, u8 *b);




extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_0017F2F0(u8 *p)
{
    extern void func_00175C00(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_0015B200(u8 *, u8 *, s32, s32);
    extern void func_001E3A10(u8 *);
    extern void func_00163D70(u8 *);
    extern void func_00178E60(u8 *);
    extern s32 func_001864a0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 z = 0.0f;
    u32 t;

    if (*(s16 *)(p + 0x1E) > 0) func_00175C00(p, 6);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x211) != 0 && p[0x24C] == 0) {
        func_0015B200(p, p + 0x34, 1, 8);
        *(s16 *)(p + 0x1E) = -1;
        func_00175C00(p, 1);
        p[0x24C] = 1;
        func_001E3A10(p);
        func_00163D70(p);
        if (p[0x249] != 0) {
            D_004F1F45[0] = 3;
            D_004F1F46[0] = 1;
        }
    }
    if (*(s16 *)(p + 0x1C) == 0 && *(f32 *)(p + 0x60) <= z) {
        *(s16 *)(p + 0x1C) = 1;
        func_00178E60(p);
    }
    if (*(f32 *)(p + 0x60) <= z) {
        if (func_001864a0(p) != 0) {
            if (p[0x24C] == 0) {
                func_0015B200(p, p + 0x34, 1, 8);
                *(s16 *)(p + 0x1E) = -1;
                func_00175C00(p, 1);
            }
            t = p[6];
            p[6] = t + 1;
            p[0x1FF] = 2;
            *(s16 *)(p + 0x28C) = 5;
            p[0x20D] = 3;
            func_001757E0(p, 0xD, 0x1A);
        }
    }
}
