/* Metrowerks 3.0: ./try.sh src/grok_fo_34b380.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern s32 func_00175700(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_001E7F60(u8 *);

void residual_0034B380(u8 *p)
{
    u8 *q;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    q = *(u8 **)(p + 0x18);
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_00175700(p);
        if (p[0x20] != 2)
            func_001E3710(p, 0x2F);
        else
            func_001E3710(p, 0x31);
        return;
    }
    if (p[0x20] != 2 && *(s8 *)(p + 0x1B2) != 0) {
        p[5]++;
        func_00175700(p);
        return;
    }
    func_001E7F60(p);
}
