typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0xA]; s16 h0A; } G75;
extern G75 *D_004C2840;
extern f32 D_004CACA8[];
extern f32 D_004CACA0[];

void func_00141CF0(u8 *p) {
    extern void func_00141420(u8 *);
    extern s32 func_00417690(f32, f32);
    extern void func_001415B0(u8 *);
    s32 t;
    s32 k;
    t = D_004C2840->h0A;
    k = (s8)p[0x31];
    if (t >= 0x5BB) {
        if (k >= 0x14 && k < 0x20) {
            f32 v = *(f32 *)(p + 0x50) - 0.06499999761581421f;
            *(f32 *)(p + 0x50) = v;
            if (v <= 0.0f) {
                p[0] = 0;
            }
            return;
        } else if (((k >= 9 && k <= 0x13) || k == 1) && p[0x23] != 0x20 && p[0x23] != 0x22 && p[0x23] != 0x25) {
            *(f32 *)(p + 0x3C) += 0.75f + 0.019999999552965164f * (f32)(t - 0x5BB);
            if (*(f32 *)(p + 0x3C) >= 0.0f) {
                p[0] = 0;
            }
            return;
        } else if (k == 4 || k == 3) {
            if (*(f32 *)(p + 0x3C) >= 0.0f) {
                p[0] = 0;
                return;
            }
        }
    }
    switch (p[0x23]) {
    case 0xA:
    case 0xB:
    case 0xC: {
        s16 n = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = n;
        if (n == 0) goto kill;
        break;
    }
    case 0xD:
        if (t == 0x1BD) {
            p[0x25] = 2;
        }
        break;
    case 0xE:
    case 0x10:
        if (t == 0x1E3) goto kill;
        if (t > 0x1CF) {
            func_00141420(p);
            return;
        }
        break;
    case 0x1F:
        if (t == 0x20B) {
            *(f32 *)(p + 0x80) = 1.0f;
            *(f32 *)(p + 0x7C) = 1.0f;
            *(f32 *)(p + 0x78) = 1.0f;
            *(f32 *)(p + 0x74) = 1.0f;
        }
        break;
    case 0x20:
        if (t == 0x3E8) {
            *(f32 *)(p + 0x80) = 1.0f;
            *(f32 *)(p + 0x7C) = 1.0f;
            *(f32 *)(p + 0x78) = 1.0f;
            *(f32 *)(p + 0x74) = 1.0f;
        }
        break;
    case 0x2F:
        if (t >= 0x3B4) {
            switch (t & 3) {
            case 0:
                *(f32 *)(p + 0x34) += 0.20000000298023224f;
                break;
            case 1:
                *(f32 *)(p + 0x34) -= 0.20000000298023224f;
                break;
            case 2:
                *(f32 *)(p + 0x34) -= 0.20000000298023224f;
                break;
            case 3:
                *(f32 *)(p + 0x34) += 0.20000000298023224f;
                break;
            }
        }
        break;
    case 0x34:
        *(s32 *)(p + 0x48) += 0xB6;
        func_00141420(p);
        break;
    case 0x36:
        *(s32 *)(p + 0x48) += 0x38E;
        break;
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3B:
        if (t >= 0x41A) {
            *(s32 *)(p + 0x44) = func_00417690(D_004CACA8[0] - *(f32 *)(p + 0x3C), D_004CACA0[0] - *(f32 *)(p + 0x34)) & 0xFFFF;
        } else {
            *(s32 *)(p + 0x44) = func_00417690(D_004CACA0[0] - *(f32 *)(p + 0x34), D_004CACA8[0] - *(f32 *)(p + 0x3C)) + 0x8000;
        }
        return;
    }
    if (p[0x25] == 1) {
        f32 w;
        *(f32 *)(p + 0x78) += 0.05000000074505806f;
        if (!(*(f32 *)(p + 0x78) < 1.0f)) {
            *(f32 *)(p + 0x78) = 1.0f;
            p[0x25] = 0;
        }
        w = *(f32 *)(p + 0x78);
        *(f32 *)(p + 0x80) = w;
        *(f32 *)(p + 0x7C) = w;
    }
    if (p[0x25] == 2) {
        f32 v = *(f32 *)(p + 0x78) - 0.03333333507180214f;
        *(f32 *)(p + 0x78) = v;
        if (v <= 0.0f) goto kill;
        *(f32 *)(p + 0x80) = v;
        *(f32 *)(p + 0x7C) = v;
    }
    if (p[0x20] & 1) {
        *(f32 *)(p + 0x34) += 10.0f * *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) += 10.0f * *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x3C) += 10.0f * *(f32 *)(p + 0x64);
    }
    if (p[0x20] & 2) {
        s32 a;
        a = *(s32 *)(p + 0xD4);
        *(s32 *)(p + 0x40) += a;
        a = *(s32 *)(p + 0xD8);
        *(s32 *)(p + 0x44) += a;
        a = *(volatile s32 *)(p + 0xDC);
        *(s32 *)(p + 0x48) += a;
    }
    if (p[0x20] & 4) {
        *(f32 *)(p + 0x50) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x54) += *(f32 *)(p + 0x6C);
        *(f32 *)(p + 0x58) += *(f32 *)(p + 0x70);
    }
    if (p[0x20] != 0) {
        s16 n = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = n;
        if (n <= 0) {
            func_001415B0(p);
        }
    }
    return;
kill:
    p[0] = 0;
    p[0x13C] = 0;
}
