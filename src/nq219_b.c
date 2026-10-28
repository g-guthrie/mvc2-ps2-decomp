typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 *D_004C2840;
extern s8 D_004F20B0[];
extern s8 D_004F2668[];
extern s8 D_004F2C20[];
extern s8 D_004F31D8[];
extern s8 D_004F3790[];
extern s8 D_004F3D48[];
extern s8 D_004F25E9[];
extern s8 D_004F2BA1[];
extern s8 D_004F3159[];
extern s8 D_004F3711[];
extern s8 D_004F3CC9[];
extern s8 D_004F4281[];
extern s8 D_004F7F34[];

void func_001712F0(void) {
    extern void func_001801B0(void);
    extern void func_003DA410(void);
    extern void func_001E4480(s32, s32);
    s8 l0[6], l1[6], l2[6], l3[6];
    s8 *e, *f, *q, *r;
    s32 i, off;
    *(s8 *)(D_004C2840 + 3) += 1;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    D_004C2840[0x8A] = 0;
    D_004C2840[0x19] = 1;
    D_004C2840[0xA8] = 0;
    D_004F25E9[0] = 1;
    D_004F2BA1[0] = 1;
    D_004F3159[0] = 1;
    D_004F3711[0] = 1;
    D_004F3CC9[0] = 1;
    D_004F4281[0] = 1;
    i = 0;
    off = 0;
    do {
        e = D_004F20B0 + off;
        f = D_004F20B0 + ((*(s8 *)(e + 0x538) & 1) + (((u8 *)e)[0x553] << 1)) * 0x5B8;
        l0[i] = f[0x540];
        l1[i] = f[0x4DD];
        l2[i] = f[0x541];
        l3[i] = ((u8 *)f)[0x570];
        e[0x553] = i / 2;
        i++;
        off += 0x5B8;
    } while (i < 6);
    for (i = 0; i < 6; i++) {
        e = D_004F20B0 + i * 0x5B8;
        e[0x540] = l0[i];
        e[0x4DD] = l1[i];
        e[0x541] = l2[i];
        e[0x570] = l3[i];
    }
    if ((D_004C2840[0x9D] = D_004C2840[0x88]) == 3) {
        D_004C2840[0x8F] = 1;
        D_004C2840[0x85] = 0;
    } else {
        D_004C2840[0x8F] = 0;
        q = D_004F20B0;
        r = D_004F20B0 + 0x5B8;
        if (D_004C2840[0x88] != 1) {
            q = D_004F20B0 + 0x5B8;
            r = D_004F20B0;
        }
        *(s32 *)(q + 0x4EC) = *(s32 *)(q + 0x548);
        *(s32 *)(q + 0x4E8) = *(s32 *)(q + 0x54C);
        *(s32 *)(r + 0x4EC) = 0;
        *(s32 *)(r + 0x4E8) = 0;
        D_004C2840[0x85] = q[0x542];
        if (D_004C2840[0x49] == 0) {
            D_004C2840[0x8D] = q[0x4DE];
        }
    }
    if (*(s8 *)(D_004C2840 + 0x4C) == 2) {
        if (D_004F7F34[0] != 1) {
            D_004F25E9[0] = 0;
            D_004F2BA1[0] = 0;
            D_004F3159[0] = 0;
            D_004F3711[0] = 0;
            D_004F3CC9[0] = 0;
            D_004F4281[0] = 0;
        } else {
            D_004C2840[0x88] = D_004C2840[0x18];
        }
    }
    if (D_004C2840[0x88] & 1) {
        D_004F25E9[0] = 0;
        D_004F3159[0] = 0;
        D_004F3CC9[0] = 0;
    }
    if (D_004C2840[0x88] & 2) {
        D_004F2BA1[0] = 0;
        D_004F3711[0] = 0;
        D_004F4281[0] = 0;
    }
    func_001801B0();
    func_003DA410();
    func_001E4480(6, 1);
}
