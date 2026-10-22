typedef unsigned char u8; typedef signed char s8; typedef unsigned int u32; typedef signed int s32; typedef float f32;

void func_001757E0(u8 *, s32, s32);
void func_00183D50();
void func_00175700();

void func_002577D0(u8 *p) {
    u8 *v3, *a1, *a2, *a3;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    v3 = p + 0x5C;
    a2 = p + 0x68;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    a1 = p + 0x60;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    a3 = p + 0x6C;
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0) {
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0x40855555;
        if (*(u8 *)(p + 0x1E6) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41700000;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        *(u8 *)(p + 0x1E7) = 1;
        func_001757E0(p, 0x14, 0x14);
        return;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(u8 *)(p + 7) = 3;
        *(u8 *)(p + 0x20D) = 0;
        *(u32 *)v3 = 0;
        *(u32 *)a1 = 0;
        *(u32 *)a2 = 0;
        *(u32 *)a3 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50();
        func_001757E0(p, 0x14, 0x15);
    } else {
        func_00175700();
    }
}
