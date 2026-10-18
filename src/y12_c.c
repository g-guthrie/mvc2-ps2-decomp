typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];
extern s8 D_004F25F3[];
extern s8 D_004F25E9[];
extern s8 D_004D193C[];

void func_001801E0(void) {
    extern void func_0011D8F8();
    u8 i;
    s32 off = 0;
    s32 k = 0;
    for (i = 0; i < 3; ) {
        u8 *e = D_004F20B0 + off;
        func_0011D8F8(e, 0, 0x4D0);
        e[2] = 0;
        e[0x1B8] = k;
        e[0x425] = i;
        e[0x426] = i;
        off += 0xB70;
        k += 2;
        i++;
    }
    D_004D193C[0] = D_004F25F3[0];
    if (D_004F25E9[0] != 0) D_004D193C[0] = 0;
}

void func_00309CF0(u8 *p) {
    extern void func_0030C470();
    extern void func_003BA230(u8*,s32,u8);
    extern void func_00309310();
    u8 i;
    switch (p[0x1FC]) {
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_0030C470(p);
            for (i = 0; i < 5; i++) {
                func_003BA230(p, 0, i);
            }
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_003BA230(p, 6, 0);
        }
        break;
    }
    func_00309310(p);
}
