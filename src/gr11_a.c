typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

void func_001C9230(u8 *p) {
    extern void func_001C93F0();
    extern void func_00175700();
    u8 *q;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x24] = 0;
    } else {
        p[0x24] = 7;
    }
    q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x15) {
        p[4]++;
        func_001C93F0(p);
        return;
    }
    switch (q[0x168]) {
    default:
        p[4]++;
        func_001C93F0(p);
        break;
    case 6: case 8: case 9:
        func_00175700();
        break;
    }
}
