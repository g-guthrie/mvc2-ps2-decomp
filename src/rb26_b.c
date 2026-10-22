typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00326230(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001549B0(u8 *, f32 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_00126400(void);
    extern void func_00178F20(u8 *, u8 *);
    extern void func_00179150(u8 *, u8 *);
    f32 v[4];
    u32 t;

    func_00175700(p);
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        v[0] = 0;
        v[1] = 0;
        func_001549B0(p, v);
        func_001E3710(p, 2);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
        (*(u8 **)(p + 0x1DC))[0x20A] = 1;
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x21;
        v[0] = 266.6666564941406f;
        if (*(s16 *)(p + 0x140) != 0) {
            v[0] = -v[0];
        }
        v[0] += *(f32 *)(p + 0x34);
        v[1] = *(f32 *)(p + 0x430);
        *(f32 *)(p + 0x5C) = (*(f32 *)(p + 0x34) - v[0]) / 32.0f;
        *(u32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = -0.8035714030265808f;
        *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x38) - v[1]) / 32.0f - -12.857142448425293f;
        func_00126400();
        return;
    }
    if (*(s8 *)(p + 0x150) != 0) {
        func_00178F20(p, *(u8 **)(p + 0x1DC));
    } else {
        func_00179150(p, *(u8 **)(p + 0x1DC));
    }
}
