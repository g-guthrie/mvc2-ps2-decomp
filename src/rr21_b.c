typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C272C;

void func_001E3D20(u32 a0, u32 a1, s32 a2, s32 a3)
{
    extern void func_001E4A10(u8, u8, s32, s16, f32);
    extern void func_001E4C40(u8, u8, s32, s16, f32);
    extern void func_001E59E0(void);
    f32 f;

    if (a0 < 6) {
        if (a1 - 0x28 > 2) {
            if (a1 != 0x2B) goto L1;
        }
        return;
    }
L1:
    if (D_004C272C != 0) return;
    if (a1 > 0xA0) return;
    if (a0 == 6) {
        if (a1 <= 0x1A || a1 - 0x25 <= 1 || (a1 >= 0x48 && a1 < 0x4E)) {
            f = 0.4f;
            if (a1 == 0x48 || a1 == 0x4B || a1 == 0x4C) {
                switch (a3) {
                case 0: f = 2.5f; break;
                case 0x13: f = 2.0f; break;
                case 0x14: f = 3.0f; break;
                case 0x2E: f = 0.5f; break;
                case 0x36: f = 3.0f; break;
                default: f = 2.0f; break;
                }
            }
            func_001E4A10(a0, a1, 0x80, a2, f);
            return;
        }
    }
    if (a0 == 7) {
        if ((a1 != 0 && a1 <= 5) || (a1 >= 0x3A && a1 <= 0x3B) || a1 == 0x40 || a1 == 0x42 || (a1 >= 0x4C && a1 < 0x4E)) {
            f = 0.8f;
            if (a1 == 0x39) f = 1.0f;
            func_001E4C40(a0, a1, 0x80, a2, f);
            return;
        }
    }
    func_001E59E0();
}
