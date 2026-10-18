typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G94;
extern G94 *D_004C2794;
extern s16 D_004C1D7C[2];

void func_00387870(u8 *p) {
    extern void func_00387330();
    extern void func_00175700();
    extern void func_001E7F60();
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        s32 t;
        *(s16 *)(p + 0x1C) = D_004C1D7C[0];
        t = *(s32 *)(p + 0xD0) - 1;
        *(s32 *)(p + 0xD0) = t;
        if (t == 0) {
            u32 u = p[5];
            p[5] = u + 1;
            *(s16 *)(p + 0x1C) = D_004C1D7C[1];
        }
        func_00387330(p, p[0xD4]);
        *(s32 *)(p + 0xD4) = *(s32 *)(p + 0xD4) + 1;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        *(s8 *)(p + 0x1B5) = 0x3A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    func_001E7F60(p);
}
