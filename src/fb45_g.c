typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b[0x5B8]; } E3d;
typedef struct { u8 *f0; u32 f4; u32 f8; } S12;
typedef struct { u8 pad[0x18]; S12 e[6]; } PP;
extern E3d D_004F20B0[];
extern u8 *D_004C2840;

void func_003D86F0(PP *pp)
{
    u8 *p = (u8 *)pp;
    extern void func_003D86B0(E3d *);
    extern void func_00135DB0(s32);
    extern void func_00135150(s32);
    extern void func_0016CF10(void);
    extern void func_001604D0(void);
    extern void func_001917F0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001E3CE0(s32);
    extern void func_003D9B60(s32);
    extern u8 *func_00327CF0(u8 *, u8);
    extern void func_0016CF40(void);
    extern void func_003D90E0(u8 *);
    s32 s0;
    s32 i;
    u8 *s1;
    u8 *a0;
    u8 *a1;
    s32 v0;
    s32 t;

    p[1] = 2;
    p[0] = 5;
    *(s16 *)(p + 0x14) = 0x96;
    *(s16 *)(p + 0x12) = 0x168;
    i = 0;
    do {
        func_003D86B0(&D_004F20B0[i]);
        i++;
    } while (i < 6);
    s0 = 0;
    if (p[3] != 0) {
        func_00135DB0(2);
        s0 = 4;
    } else {
        func_00135150(2);
        if (*(s8 *)(p + 0x3E) >= 0) {
            a0 = *(u8 **)(p + 0xC);
            v0 = 0;
            if (a0 != 0) {
                if (a0[1] == 0x12) {
                    v0 = (*(s32 (**)(u8 *))(*(s32 *)(a0 + 0x43C) + 0x60))(a0);
                }
            }
            s1 = pp->e[*(s8 *)(p + 0x3E)].f0;
            a1 = *(u8 **)(p + 8);
            if (a1 != 0) {
                if ((a1[2] & 0x20) != 0 || v0 != 0) {
                    func_0016CF10();
                    func_001604D0();
                    if (p[0x38] != 0 && (t = *(s8 *)(*(s8 *)(p + 0x3E) + (s32)p + 0x34)) > 1) {
                        if (t > 2) *(u32 *)(p + 0x64) = 0x50000000;
                        else *(u32 *)(p + 0x64) = 0x30000000;
                        *(u32 *)(p + 0x68) = 0;
                        s0 = 2;
                    } else if (s1[0x269] == 6) {
                        *(u32 *)(p + 0x68) = 0;
                        *(u32 *)(p + 0x64) = 0x70000000;
                        s0 = 3;
                    } else {
                        *(u32 *)(p + 0x68) = 0;
                        *(u32 *)(p + 0x64) = 0x10000000;
                        s0 = 1;
                    }
                    func_001917F0(s1, *(s32 *)(p + 0x68), *(s32 *)(p + 0x64));
                    a0 = *(u8 **)(p + 0xC);
                    if (a0 != 0) {
                        if (a0[1] == 0x1E && p[7] == 0x22) {
                            func_001E3210(a0, 0x20);
                        } else {
                            func_001E3710(a0, 0x41);
                        }
                    } else {
                        func_001E3710(a0, 0x41);
                    }
                    func_001E3CE0(0x20);
                } else {
                    func_001E3710(s1, 0x42);
                    func_001E3CE0(0x1F);
                    s0 = 0;
                }
            }
        }
        *(u16 *)(p + 0x3C) = 0xAAAA;
        D_004C2840[0x9C] = 0;
        p[0x76] = 0;
    }
    if (*(s8 *)(p + 0x3E) < 0) {
        if (p[3] != 0) s0 = 6;
        else s0 = 5;
    }
    p[0x8C] = s0;
    func_003D9B60(s0);
    D_004C2840[0x19] = 1;
    p[0x46] = 1;
    t = *(s8 *)(p + 0x3E);
    if (t >= 0) {
        if (*(s8 *)(pp->e[t].f0 + 0x539) == 0) {
            if (p[0x48] == 8) {
                a1 = D_004C2840;
                if (*(s8 *)(a1 + 0xAF) != 0) {
                    if (p[0x45] == 2) {
                        if (*(s8 *)(a1 + 0x8F) == 0) {
                            a1[0x8C] = 1;
                            D_004C2840[0xA8] = 1;
                            p[0x84] = 1;
                            p[0x85] = 0x3C;
                            func_00327CF0(pp->e[*(s8 *)(p + 0x3E)].f0, 7);
                            func_0016CF40();
                        }
                    } else {
                        a1[0x19] = 0;
                        p[0x46] = 0;
                    }
                }
            }
        }
    }
    D_004C2840[0x19] = 1;
    func_003D90E0(p);
}
