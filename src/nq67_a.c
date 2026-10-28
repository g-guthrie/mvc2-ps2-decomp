typedef unsigned char u8;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern V3 D_004B7FA0[];
extern f32 D_00583C10[];
extern f32 D_00583C14[];
extern f32 D_00583C18[];

void func_00336B40(u8 *p) {
    extern void func_00336C60(u8 *);
    *(V3 *)(p + 0x5C) = D_004B7FA0[p[5]];
    p[5]++;
    p[5] &= 1;
    *(V3 *)(p + 0x68) = D_004B7FA0[p[5]];
    D_00583C10[p[0x23] * 3] = (*(f32 *)(p + 0x68) - *(f32 *)(p + 0x5C)) / 100.0f;
    D_00583C14[p[0x23] * 3] = (*(f32 *)(p + 0x6C) - *(f32 *)(p + 0x60)) / 100.0f;
    D_00583C18[p[0x23] * 3] = (*(f32 *)(p + 0x70) - *(f32 *)(p + 0x64)) / 100.0f;
    p[4] = 1;
    func_00336C60(p);
}

extern V3 D_004B7FD0[];
extern f32 D_00583BF0[];
extern f32 D_00583BF4[];
extern f32 D_00583BF8[];

void func_003370F0(u8 *p) {
    extern void func_00337210(u8 *);
    *(V3 *)(p + 0x5C) = D_004B7FD0[p[5]];
    p[5]++;
    p[5] &= 1;
    *(V3 *)(p + 0x68) = D_004B7FD0[p[5]];
    D_00583BF0[p[0x23] * 3] = (*(f32 *)(p + 0x68) - *(f32 *)(p + 0x5C)) / 100.0f;
    D_00583BF4[p[0x23] * 3] = (*(f32 *)(p + 0x6C) - *(f32 *)(p + 0x60)) / 100.0f;
    D_00583BF8[p[0x23] * 3] = (*(f32 *)(p + 0x70) - *(f32 *)(p + 0x64)) / 100.0f;
    p[4] = 1;
    func_00337210(p);
}
