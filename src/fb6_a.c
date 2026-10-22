typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 *D_004C26D0;
static void func_00192E30(u8 *p)
{
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x34) += D_004C26D0[0];
    else
        *(f32 *)(p + 0x34) -= D_004C26D0[0];
    *(f32 *)(p + 0x38) += D_004C26D0[1];
}

void func_00193010(u8 *p) {
    extern void func_00193060(u8 *);
    extern void func_00175700(u8 *);
    s32 v;
    func_00192E30(p);
    v = *(s8 *)(*(u8 **)(p + 0x18) + 0x161);
    if (v != 5 && v != 8) {
        func_00193060(p);
    } else {
        func_00175700(p);
    }
}
