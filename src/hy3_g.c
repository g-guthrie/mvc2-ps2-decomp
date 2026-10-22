typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0029DE80(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00183d50();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_00126400();
    u32 t;
    s32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x34) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x5C);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x5C) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x68);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x60);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x60) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x6C);
    v = *(f32 *)(*(u8 **)(p + 0x1DC) + 0x430) > *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38);
    if (v != 0) {
        *(u32 *)(*(u8 **)(p + 0x1DC) + 0x5C) = 0;
        *(u32 *)(*(u8 **)(p + 0x1DC) + 0x60) = 0;
        *(u32 *)(*(u8 **)(p + 0x1DC) + 0x68) = 0;
        *(u32 *)(*(u8 **)(p + 0x1DC) + 0x6C) = 0;
        *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = *(f32 *)(*(u8 **)(p + 0x1DC) + 0x430);
        (*(u8 **)(p + 0x1DC))[0x13C] = 0;
    }
    if (*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38)) return;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    t = p[6];
    p[6] = t + 1;
    *(s16 *)(p + 0x1C) = 0x24;
    func_00183d50(p);
    func_001757E0(p, 0x16, 7);
    func_00191480(*(u8 **)(p + 0x1DC), p, 1);
    (*(u8 **)(p + 0x1DC))[0x20A] = 0x10;
    (*(u8 **)(p + 0x1DC))[0x1B5] = 0x3C;
    p[0x1B5] = 0x3C;
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 51.42856979370117f + *(f32 *)(p + 0x430);
    (*(u8 **)(p + 0x1DC))[0x13C] = 1;
    func_0018FDB0(p);
    *(s32 *)(p + 0x304) = 0x24;
    func_00126400();
}
