typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x84]; s8 b84; u8 pad85[0x106 - 0x85]; u16 h106[8]; } H8D;
extern H8D *D_004C2840;

#define H(o) (*(u16 *)(p + (o)))
void func_00181C40(u8 *p)
{
    s32 v;
    u32 m, a;
    H(0x35A) = H(0x358);
    H(0x358) = H(0x356);
    v = H(0x354);
    H(0x360) = v;
    H(0x356) = v;
    v = *(s16 *)(p + 0x4F0) & 0xBFFE;
    H(0x35E) = v;
    H(0x354) = v;
    if (D_004C2840->h106[p[2]] != 0) {
        if (H(0x354) & 0x200) {
            if (D_004C2840->b84 % 2 == 0) {
                m = (u16)(*(s16 *)(p + 0x356) & 0x200);
                a = H(0x35E);
                a ^= m;
                H(0x354) = H(0x35E) = a;
            }
        }
        if (H(0x354) & 0x40) {
            if (D_004C2840->b84 % 2 == 0) {
                m = (u16)(*(s16 *)(p + 0x356) & 0x40);
                a = H(0x35E);
                a ^= m;
                H(0x354) = H(0x35E) = a;
            }
        }
    }
    v = ~*(s16 *)(p + 0x356) & *(s16 *)(p + 0x354);
    H(0x362) = v;
    H(0x35C) = v;
    if (p[0x1E6] != 0) {
        v = H(0x35E);
        if (v & 0xC00) H(0x35E) = v ^ 0xC00;
        v = H(0x362);
        if (v & 0xC00) H(0x362) = v ^ 0xC00;
        v = H(0x360);
        if (v & 0xC00) H(0x360) = v ^ 0xC00;
    }
}
