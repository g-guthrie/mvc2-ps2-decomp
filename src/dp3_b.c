typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;


extern int func_00175670(u8 *);
extern void func_001AFC90(u8 *);
void func_001AD450(u8 *p)
{
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        *(f32 *)(p + 0x60) = (f32)(-((f64)*(f32 *)(p + 0x60) / 2.0));
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 2.0f;
        *(s16 *)(p + 0x1C) = 0x30;
    }
}

void func_001AD530(u8 *p)
{
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (--*(s16 *)(p + 0x1C) != 0) {
        p[0x13C] = (*(s16 *)(p + 0x1C) & 4) ? 1 : 0;
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
            *(f32 *)(p + 0x60) = (f32)(-((f64)*(f32 *)(p + 0x60) / 2.0));
        }
    } else {
        func_001AFC90(p);
    }
}
