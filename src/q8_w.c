typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G4;
extern G4 *D_004C2794;

void func_002DD540(u8 *p) {
    extern void func_001861B0();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s8 func_00175700();
    extern void func_001843A0();
    u8 k;
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 1;
        p[0x1B5] = 0x12;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001861B0(p);
        func_0018C4B0(p, 5);
        func_001757E0(p, 0x14, 5);
        func_001E3710(p, 0x16);
    }
    k = p[0x213] = 3;
    if (k != 0) {
        func_00183D90(p);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    }
}
