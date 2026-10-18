typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern s8 D_004F25E9[];

void func_003D90E0(u8 *p) {
    if (p[0x46] != 0) {
        if (*(s8 *)(D_004C2840 + 0x8F) != 0) {
            s8 a3 = p[0x3E];
            s32 a2 = 0;
            if (a3 < 0) {
                p[0x9D] = 0;
                p[0x9C] = 0;
                return;
            }
            if (a3 != 0) a2 = 1;
            if (D_004F25E9[a3 * 0x5B8] == 0) {
                u8 *q = (u8 *)(a2 + (s32)p);
                s8 *r = (s8 *)(q + 0x9C);
                s8 t = *r + 1;
                *r = t;
                if (t > 0x63) *r = 0x63;
                p[(a2 ^ 1) + 0x9C] = 0;
            }
        } else {
            s8 v = p[0x3E];
            if (v >= 0) {
                u8 *q = (u8 *)(v + (s32)p);
                if ((s8)q[0x36] == 0) {
                    s8 t = q[0x9A];
                    q[0x9A] = t + 1;
                } else {
                    q[0x9A] = 0;
                }
            }
        }
    }
}
