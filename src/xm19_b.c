typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0; s8 b1; u8 pad[0x536]; s8 b538; u8 pad2[7]; s8 b540; u8 b541; } GB;
typedef struct { u8 pad[0x4C]; s8 b4C; u8 pad2[0x3B]; s8 b88; } G2840;

extern u8 D_004F20B0[];
extern s16 D_00583BDC[];
extern s8 D_00583B90[];
extern u8 D_00583B92[];
extern u8 D_00583BC0[];
extern GB *D_004C2904;
extern s8 D_004C2900;
extern u16 D_004C291C[16];
extern s8 D_004C27C0;
extern s8 D_004C27C4;
extern s8 D_004C2760;
extern G2840 *D_004C2840;

void func_0032B000(u8 *p)
{
    extern void func_001E3CE0(s32);
    extern void func_00137F20(u8);
    extern s32 func_00137F90(u8);
    extern u32 func_0032D6D0(GB *, s32);
    extern void func_001E60B0(s32);
    extern void func_001E6490(s32);
    extern void func_00139D00(GB *, s32);
    extern void func_00139EE0(u8 *);
    extern void func_0032D660(GB *, s32);
    extern void func_0012E780(s32);
    extern void func_0038CCA0(u8);
    extern u8 func_0032DAB0(u8 *, GB *, s32);
    s32 r;

    D_004C2904 = (GB *)(D_004F20B0 + ((s8)p[0x538] + *(s16 *)(p + 0x1E) * 2) * 0x5B8);
    D_004C2900 = D_004C2904->b540;
    if (D_00583BDC[0] == 0) {
        D_004C291C[(s8)p[0x538]] = 0x200;
        D_004C2904->b1 = D_004C2904->b540;
        goto tail;
    }
    if ((D_004C291C[(s8)p[0x538]] & 0x3C00) != 0) {
        func_001E3CE0((u8)((s8)p[0x538] * 2 + 0x40));
        do {
            if (D_004C291C[(s8)p[0x538]] & 0x800) {
                D_00583B90[(s8)p[0x538] + 4]--;
            }
            if (D_004C291C[(s8)p[0x538]] & 0x400) {
                D_00583B90[(s8)p[0x538] + 4]++;
            }
            if (D_004C291C[(s8)p[0x538]] & 0x2000) {
                D_00583B90[(s8)p[0x538] + 6]--;
            }
            if (D_004C291C[(s8)p[0x538]] & 0x1000) {
                D_00583B90[(s8)p[0x538] + 6]++;
            }
            func_00137F20(p[0x538]);
            r = func_00137F90(p[0x538]);
            D_004C2904->b540 = r;
            if ((s8)r < 0) continue;
            if (func_0032D6D0(D_004C2904, p[0x538]) == 0) continue;
            D_004C2904->b1 = D_004C2904->b540;
            break;
        } while (1);
    }
    if (D_004C2900 != D_004C2904->b540) {
        D_004C27C4 = 1;
        D_004C27C0 |= (s8)p[0x538] + 1;
        func_001E60B0((s8)p[0x538] + *(s16 *)(p + 0x1E) * 2);
        func_001E6490((s8)p[0x538] + *(s16 *)(p + 0x1E) * 2);
    }
    if ((D_004C291C[(s8)p[0x538]] & 0x3FC) == 0) return;
tail:
    func_001E3CE0((u8)((s8)p[0x538] * 2 + 0x41));
    func_00139D00(D_004C2904, p[0x538]);
    D_00583BC0[(s8)p[0x538]] = 0;
    p[5] = 2;
    p[6] = 0;
    func_00139EE0(p);
    D_00583B92[(s8)p[0x538]] |= (u8)(1 << (s8)p[0x1E]);
    func_0032D660(D_004C2904, p[0x538]);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (D_004C2840->b88 == 0) {
        func_0012E780((s8)p[0x538] + *(s16 *)(p + 0x1E) * 2 + 0x12);
    }
    if (D_004C2840->b4C != 5) {
        func_0038CCA0(D_004C2904->b540);
    } else if (D_004C2760 == 0) {
        switch (D_004C2904->b538) {
        case 0:
        case 2:
        case 4:
            func_0038CCA0(D_004C2904->b540);
            break;
        default:
            break;
        }
    } else {
        switch (D_004C2904->b538) {
        case 1:
        case 3:
        case 5:
            func_0038CCA0(D_004C2904->b540);
            break;
        default:
            break;
        }
    }
    D_004C2904->b541 = func_0032DAB0(p, D_004C2904, (s16)D_004C291C[(s8)p[0x538]]);
}
