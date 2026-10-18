typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750();
extern void func_003814D0();

void func_00381420(u8 *a) {
    s8 i;
    s8 n = 0;
    for (i = 0; i < 16; i++) {
        u8 *o = func_003DA750(a, 1, 2);
        if (o != 0) {
            *(void **)(o + 0x10) = (void *)func_003814D0;
            o[0x20] = 1;
            *(u8 **)(o + 0x18) = a;
            *(s16 *)(o + 0x26) = 0x1903;
            o[0x1B7] = a[0x1B7];
            o[0x23] = n;
            n++;
        }
    }
}

extern u8 *D_004C2938;
extern void func_00345F40();

s32 func_00345E30(u8 *a) {
    s8 i;
    s8 n = 0;
    for (i = 0; i < 12; i++) {
        u8 *o = func_003DA750(a, 1, 2);
        if (o != 0) {
            *(void **)(o + 0x10) = (void *)func_00345F40;
            o[0x20] = 1;
            *(u8 **)(o + 0x18) = a;
            *(s16 *)(o + 0x26) = 1;
            o[0x8E] = n;
            n++;
            o[0x98] = D_004C2938[0x10];
        }
    }
    return 0;
}
