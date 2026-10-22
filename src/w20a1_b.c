typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_b;
extern G_b *D_004C2794;
extern u8 D_004C04B8[2];
extern u8 D_004C04BC[2];
extern u8 D_004C04C0[2];
extern u8 D_004C0504[2];

void func_00255720(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *a;
    u32 t;
    f32 f;

    a = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
        *(s16 *)(a + 2) = 1;
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C04B8;
        p[0x1BB] = 0;
        break;
    case 1:
        *(s16 *)(a + 2) = 1;
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C04BC;
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(s8 *)(p + 0x1E7) != 0) {
            p[0x168] = 2;
            p[0x1B5] = 2;
            *(u8 **)(p + 0x408) = D_004C04C0;
            p[0x1BB] = 2;
            break;
        }
        f = (p[0x1E6] != 0) ? 15.833333015441895f : -15.833333015441895f;
        *(f32 *)(p + 0x5C) = f;
        f = (p[0x1E6] != 0) ? -0.1041666641831398f : 0.1041666641831398f;
        *(f32 *)(p + 0x68) = f;
        p[0x168] = 3;
        p[0x1B5] = 0x15;
        *(u8 **)(p + 0x408) = D_004C0504;
        p[0x1BB] = 2;
        t = *(volatile u8 *)(p + 0x1B5);
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x14, p[0x168]);
        return;
    default:
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
