typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2838;
extern f32 D_004F1F4C[];

void func_00161AD0(void) {
    u8 *o;
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00161C40();
    extern void func_00170DF0(u32);
    extern void func_001612F0(u8 *);
    if ((o = func_003DA750(0, 7, 0)) != 0) {
        o[0x13C] = 1;
        o[0x20] = 1;
        *(void **)(o + 0x10) = func_00161C40;
        o[0x22] = 0x47;
        *(s16 *)(o + 0xCC) = 0x47;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(f32 *)(o + 0x34) = D_004F1F4C[0];
        *(s32 *)(o + 0x38) = 0;
        *(s32 *)(o + 0xD0) = 0x20C01;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        func_00170DF0((u32)*(s32 *)(o + 0x84));
        func_001612F0(o);
        if ((o = func_003DA750(0, 7, 0)) != 0) {
            o[0x13C] = 1;
            o[0x20] = 2;
            *(void **)(o + 0x10) = func_00161C40;
            o[0x22] = 0x4A;
            *(s16 *)(o + 0xCC) = 0x4A;
            *(s32 *)(o + 0x84) = D_004C2838;
            *(f32 *)(o + 0x34) = D_004F1F4C[0];
            *(s32 *)(o + 0x38) = 0;
            *(s32 *)(o + 0xD0) = 0x20C01;
            *(s16 *)(o + 0x1C) = 0;
            *(s16 *)(o + 0x1E) = 0;
            func_00170DF0((u32)*(s32 *)(o + 0x84));
            if ((o = func_003DA750(0, 7, 0)) != 0) {
                o[0x13C] = 1;
                o[0x20] = 0;
                *(void **)(o + 0x10) = func_00161C40;
                *(s16 *)(o + 0xCC) = 0x49;
                *(s32 *)(o + 0x84) = D_004C2838;
                *(f32 *)(o + 0x34) = D_004F1F4C[0];
                *(s32 *)(o + 0x38) = 0;
                *(s32 *)(o + 0xD0) = 0x20C01;
                *(s16 *)(o + 0x1C) = 0;
                *(s16 *)(o + 0x1C) = 0;
                *(s16 *)(o + 0x1E) = 0;
                func_00170DF0((u32)*(s32 *)(o + 0x84));
            }
        }
    }
}
