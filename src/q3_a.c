typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F1F41[];
extern u8 *D_004C25D4[2];
extern u8 *D_004C25D0[2];
void func_00126470(void) {
    if (D_004F1F41[0] != 2) {
        if (D_004C25D4[0][1] == 0x1A) {
            D_004F1F41[0] = 4;
        } else if (D_004C25D0[0][1] == 0x1A) {
            D_004F1F41[0] = 3;
        } else {
            D_004F1F41[0] = 0;
        }
    }
}

extern s8 D_004F7F3F[];
extern u8 *D_004C2840;

void func_0032BEF0(u8 *p) {
    if (D_004F7F3F[0] != 0) {
        s8 *a = (s8 *)(D_004C2840 + 0x90);
        if (*a == 0) {
            if (*(s8 *)(p + 0x538) != 0) {
                *a = 1;
                *(s8 *)(D_004C2840 + 0x89) |= 1;
            } else {
                *a = 2;
                *(s8 *)(D_004C2840 + 0x89) |= 2;
            }
        }
    }
}

extern u8 *D_004C29C4;
extern u8 *D_004C29BC;
extern u8 *D_004C29C0;
extern void (*D_00471A60[])(u8 *);
extern void (*D_00471A70[])(u8 *);
static void func_0038E500(u8 *p) {
    f32 k = 1.6666666f;
    f32 v;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    v = k * (f32)(D_004C29C4[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    *(f32 *)(p + 0x34) += v;
    *(u32 *)(p + 0x50) = 0x3F866666;
}

void func_0038E570(u8 *p) {
    if (p[0x20] == 0) {
        u8 *q = *(u8 **)(p + 0x18);
        D_004C29C4 = p + 0x88;
        D_004C29BC = q + 0x2B8;
        D_00471A60[p[4]](p);
    } else {
        u8 *q = *(u8 **)(p + 0x18);
        D_004C29C4 = p + 0x88;
        D_004C29BC = q + 0x2B8;
        D_004C29C0 = *(u8 **)(p + 0x18) + 0x88;
        func_0038E500(p);
        D_00471A70[p[4]](p);
    }
}
