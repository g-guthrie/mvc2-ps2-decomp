typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00292420(u8 *p) {
    extern void func_00292550();
    u8 *a2;
    s32 f;
    u16 g;
    a2 = p + 0x2B8;
    if (*(s8 *)(p + 0x539) != 0) {
        func_00292550(p);
        return;
    }
    f = (u16)(*(s16 *)(p + 0x35E) & 0x3F60);
    if (f != 0) {
        if ((*(u16 *)(p + 0x362) & 0x360) != 0) {
            p[7] = 7;
            a2[0x18] = 0;
            return;
        }
        g = f;
        if ((g & 0x2000) != 0) {
            if ((g & 0x800) != 0) {
                p[7] = 4;
            } else if ((g & 0x400) != 0) {
                p[7] = 5;
            } else {
                p[7] = 3;
            }
            a2[0x18] = 0;
            return;
        } else if ((g & 0x800) != 0) {
            if (p[7] != 1) {
                p[7] = 1;
                a2[0x18] = 0;
            }
            return;
        } else if ((g & 0x400) != 0) {
            if (p[7] != 2) {
                p[7] = 2;
                a2[0x18] = 0;
            }
            return;
        }
    }
    if (a2[0x19] == 0) {
        if (p[7] != 0) {
            p[7] = 0;
            a2[0x18] = 0;
        }
    }
}
