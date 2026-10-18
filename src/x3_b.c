typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002FD880(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 *v1, *a3, *a2, *t0;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x68);
    a2 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t0 = (f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)v1 = 0;
        *(u32 *)a2 = 0;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
        func_001757E0(p, 2, 3);
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}

typedef struct { s32 w[4]; } E18;
extern E18 *D_004BFEE8[2];

