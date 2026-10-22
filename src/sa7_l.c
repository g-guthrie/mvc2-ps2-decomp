typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 *D_004C2794;

void func_0018C510(u8 *p, s32 a)
{
    extern void func_001E3710(u8 *, s32);
    s8 *q;
    s8 c;
    s16 v;
    s32 t;
    
    if (p[5] == 0 && p[0x269] == 3 && *(s8 *)(p + 0x1B3) == 0) {
        return;
    }
    if (*(s8 *)(D_004C2840 + 0x52) != 0) {
        a = (s16)(a + a);
    }
    if (a == 0) {
        return;
    }
    a = (s16)a;
    if (a > 0) {
        if (*D_004C2794 != 4) return;
        if (p[0x269] == 3) return;
        q = *(s8 **)(p + 0x420);
        c = *q;
        if (c >= 5) {
            **(s16 **)(p + 0x41C) = 0;
            return;
        }
        v = a + **(s16 **)(p + 0x41C);
        if (v > 0x90) {
            v = v - 0x90;
            c = c + 1;
            *q = c;
            if (c >= 5) {
                v = 0;
                **(s8 **)(p + 0x420) = 5;
            }
            func_001E3710(p, 0x45);
        }
        **(s16 **)(p + 0x41C) = v;
    } else {
        v = a + **(s16 **)(p + 0x41C);
        if (v < 0) {
            q = *(s8 **)(p + 0x420);
            c = *q;
            if (c != 0) {
                v = v + 0x90;
                c = c - 1;
                *q = c;
                if (c < 0) {
                    v = 0;
                    **(s8 **)(p + 0x420) = 0;
                }
            } else {
                v = 0;
            }
        }
        **(s16 **)(p + 0x41C) = v;
    }
}
