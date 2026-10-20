typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_00347AA0(u8 *);
extern void func_00347F90(u8 *, int);
extern void func_00183d50(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001F9930(u8 *);
extern void func_00175700(u8 *);

void func_001F97D0(u8 *p)
{
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_00347AA0(p);
        func_00347F90(p, 0);
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        func_00183d50(p);
        func_001757E0(p, 21, 4);
        func_001F9930(p);
        return;
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
    }
}
