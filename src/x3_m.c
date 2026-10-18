typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G94;
extern G94 *D_004C2794;

void func_00251280(u8 *p) {
    extern void func_00175700();
    extern void func_001AD170();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 v;
        u32 t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 0x1E;
        *(s16 *)(p + 0x1E) = 9;
        p[0x1B5] = 0x3C;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x22] = 1;
        if (p[0x1E6] != 0) v = 11.666666030883789f;
        else v = -11.666666030883789f;
        *(f32 *)(p + 0x5C) = v;
        func_001AD170(p, 5, 0);
    }
}
