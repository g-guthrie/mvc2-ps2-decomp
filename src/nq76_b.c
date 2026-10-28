typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

typedef struct { u8 b[0x40]; } S40_nq76b;
typedef struct { u8 b[0x4C]; } S4C_nq76b;

extern s32 D_004C2AD4;
extern s32 D_004C2A98[8];
extern u8 D_0061C720[], D_0061C6E0[], D_0061BEA0[];
extern S40_nq76b D_0061BEE0[];
extern S4C_nq76b D_0061B420[];

s32 func_003DFF80(u32 a)
{
    extern s32 func_003E00C0(void);
    s32 r = 0;

    switch (a) {
    case 1:
        switch (D_004C2AD4 & 0x380) {
        case 0x100: return 1;
        case 0x80: return 2;
        case 0:
        default: return 0;
        }
    case 21:
        r = D_004C2AD4 & 3;
        if (r == 0) return 1;
        if (r == 2) return 2;
        break;
    case 4: case 5: case 6: case 7:
        return D_004C2A98[a];
    case 20:
        return func_003E00C0();
    case 22: return (s32)D_0061C720;
    case 23: return (s32)D_0061C6E0;
    case 24: return (s32)D_0061BEA0;
    case 25: case 26: case 27: case 28: case 29: case 30: case 31: case 32:
    case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40:
    case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48:
    case 49: case 50: case 51: case 52: case 53: case 54: case 55: case 56:
        return (s32)&D_0061BEE0[a - 25];
    case 57: case 58: case 59: case 60: case 61: case 62: case 63: case 64:
    case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72:
    case 73: case 74: case 75: case 76: case 77: case 78: case 79: case 80:
    case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88:
        return (s32)&D_0061B420[a - 57];
    case 89: case 90: case 91:
        break;
    }
    return r;
}
