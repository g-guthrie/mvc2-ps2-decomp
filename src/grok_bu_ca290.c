typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern u8 *func_003DA750(int, int, int);
extern void func_001CA3A0(u8 *);

void func_001CA290(u8 *p)
{
    u8 *o;
    o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_001CA3A0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        o[0x20] = 0;
        *(u16 *)(o + 0x26) = 0x1F01;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
    }
    o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_001CA3A0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        o[0x20] = 1;
        *(u16 *)(o + 0x26) = 0x1F01;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
    }
    o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_001CA3A0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        o[0x20] = 2;
        *(u16 *)(o + 0x26) = 0x1F01;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
    }
}
