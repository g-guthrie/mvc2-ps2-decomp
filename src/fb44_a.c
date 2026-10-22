typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_00317930(u8 *p) {
    extern void func_00183D90();
    extern void func_001863F0();
    extern void func_00317780();
    extern void func_00317800();
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_00182380();
    extern void func_001821D0();
    extern void func_001820A0();
    extern void func_00182300();
    extern void func_00184540();
    extern s32 func_001864A0();
    extern void func_001865B0();
    switch (p[0x213]) {
    case 3:
        func_00183D90(p);
    case 0:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001863F0(p);
        if (p[0x20D] == 0) {
            if (p[0x1FC] == 2) {
                if (p[0x212] == 0) func_00317780(p);
                else func_00317800(p);
            } else {
                if (func_00175700(p) < 0) func_001843A0(p);
            }
        } else {
            if (func_00175700(p) < 0) func_001843A0(p);
        }
        break;
    case 2:
        func_00182380(p);
        func_001821D0(p);
    case 1:
        func_001820A0(p);
        func_00182300(p);
        if (func_00175700(p) < 0) func_00184540(p);
        if (func_001864A0(p) != 0) func_001865B0(p);
        break;
    default: break;
    }
}
