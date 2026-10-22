typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004B6E70[];

s32 func_001E6920(s32 c, s32 mode) {
    s32 i;
    if (mode == 0) {
        i = (u8)c;
        if (i >= 0x30 && i < 0x3A) {
            i = i - 0x30;
        } else if (i == 0x73) {
            i = 0x14;
        } else if (i == 0x74) {
            i = 0x15;
        } else if (i == 0x6E) {
            i = 0x16;
        } else if (i == 0x64) {
            i = 0x17;
        } else if (i == 0x68) {
            i = 0x18;
        } else if (i == 0x72) {
            i = 0x19;
        } else {
            i = 0x1A;
        }
    } else {
    mode = (u8)mode;
    if (mode == 1) {
        i = (u8)c;
        if (i >= 0 && i < 10) {
            i = i + 10;
        } else if (i == 10) {
            i = 0x1A;
        } else if (i >= 0x41 && i < 0x5B) {
            i = i - 0x23;
        } else if (i == 0x1B) {
            i = 0x38;
        } else {
            i = 0x1A;
        }
    } else if (mode == 2) {
        i = (u8)c;
        if (i == 0x57) {
            i = 0x3C;
        } else if (i == 0x49) {
            i = 0x3D;
        } else if (i == 0x4E) {
            i = 0x3E;
        } else if (i == 0x53) {
            i = 0x3F;
        } else {
            i = 0x1A;
        }
    } else if (mode == 3) {
        c = (u8)c;
        if (c >= 0 && c < 0xB) {
            i = c + 0x41;
        } else if (c == 0x57) {
            i = 0x4C;
        } else if (c == 0x49) {
            i = 0x4D;
        } else if (c == 0x4E) {
            i = 0x4E;
        } else if (c == 0x53) {
            i = 0x4F;
        }
    }
    }
    return D_004B6E70[i];
}
