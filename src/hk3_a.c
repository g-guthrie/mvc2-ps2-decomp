typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } HK3B_G;
extern HK3B_G *D_004C2794;

void func_0037AE70(u8 *a0, s32 a1, u8 *a2) {
    u8 *s1;

    s1 = a0;
    *(f32 *)(s1 + 0x50) = 0.8500000238418579f;
    if (s1[1] != (*(u8 **)(s1 + 0x18))[1]) {
        func_0037B400(s1);
        return;
    }
    if (*(void **)a2 != 0) {
        if (func_0037B300(s1) == 0) {
            s1[4] = 4;
            *(s16 *)(s1 + 0x1E) = 0x14;
            *(f32 *)(s1 + 0x118) = 1.0f;
            *(s8 *)(s1 + 0x13C) = 1;
            return;
        }
    }
    if ((s8)func_00175700(s1) >= 0) {
        return;
    }
    if (*(void **)a2 == 0) {
        if (s1[5] != 0) {
            *(f32 *)(s1 + 0x38) = 102.0f;
        }
        *(s16 *)(s1 + 0x1E) = 0x30;
        *(s8 *)(s1 + 0x1B5) = 0x37;
        s1[0x1B2] = *(u16 *)(s1 + 0x1C0) = 0;
        *(u32 *)(s1 + 0x1D8) = 0;
        D_004C2794->f7c[s1[2]]++;
    }
    s1[4] = 3;
    func_001757E0(s1, 0x17, 0xF);
    func_001E7F60(s1);
    *(f32 *)(s1 + 0x50) = 1.0f;
    *(f32 *)(s1 + 0x54) = 1.0f;
    *(s8 *)(s1 + 0x13C) = 0;
    func_0037B710(s1);
}
