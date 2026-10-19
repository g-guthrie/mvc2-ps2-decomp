typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_004C2AD4;
extern u32 D_004C2A98[];
extern void *func_003E00C0(void);
extern u8 D_0061C720[];
extern u8 D_0061C6E0[];
extern u8 D_0061BEA0[];
extern u8 D_0061BEE0[];
extern u8 D_0061B420[];

void *func_003DFF80(u32 a0)
{
    if (a0 >= 0x5C)
        return 0;
    switch (a0) {
    case 1: {
        u32 v = D_004C2AD4 & 0x380;
        if (v == 0)
            return 0;
        if (v == 0x80)
            return (void *)2;
        if (v == 0x100)
            return (void *)1;
        return 0;
    }
    case 0x15: {
        u32 v = D_004C2AD4 & 3;
        if (v == 0)
            return (void *)1;
        if (v == 2)
            return (void *)2;
        return 0;
    }
    case 4:
    case 5:
    case 6:
    case 7:
        return (void *)D_004C2A98[a0];
    case 0x14:
        return func_003E00C0();
    case 0x16:
        return D_0061C720;
    case 0x17:
        return D_0061C6E0;
    case 0x18:
        return D_0061BEA0;
    case 0x19:
    case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F:
    case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25:
    case 0x26: case 0x27: case 0x28: case 0x29: case 0x2A: case 0x2B:
    case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30: case 0x31:
    case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
    case 0x38:
        return D_0061BEE0 + (a0 - 0x19) * 0x40;
    case 0x39:
    case 0x3A: case 0x3B: case 0x3C: case 0x3D: case 0x3E: case 0x3F:
    case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45:
    case 0x46: case 0x47: case 0x48: case 0x49: case 0x4A: case 0x4B:
    case 0x4C: case 0x4D: case 0x4E: case 0x4F: case 0x50: case 0x51:
    case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57:
    case 0x58:
        return D_0061B420 + (a0 - 0x39) * 76;
    default:
        return 0;
    }
}
