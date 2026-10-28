typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_00446D90[];
extern s8 D_00446D50[];

void func_0018C6F0(u8 *p)
{
    extern void func_0018C510(u8 *, s16);
    extern void func_0018C4B0(u8 *, s16);
    u8 *s0;
    u8 *s1;
    s16 v;
    s16 h;
    s16 w;

    s0 = *(u8 **)(p + 0x1CC);
    s1 = *(u8 **)(p + 0x1D0);
    v = 1;
    if (s0 == 0) s0 = *(u8 **)(p + 0x220);
    if (!(s1[2] & 0x20)) {
        v = s1[0xE] & 0x3F;
        if (v == 0) {
            if (s1[2] & 0x40) v = 8;
            else if (s1[2] & 0x10) v = 8;
            else v = *(s8 *)(s0 + 0x424);
        }
    }
    if (!(v & 0x80)) func_0018C510(p, v);
    if (s1[2] & 0x20) return;
    if (s1[0xE] & 0x40) return;
    w = s1[0xE] & 0x3F;
    if (w == 0) {
        if (s1[2] & 0x40) w = 8;
        else if (s1[2] & 0x10) w = 8;
        else w = *(s8 *)(s0 + 0x424);
    }
    v = w;
    if (v == 0) v = 1;
    h = *(s16 *)(s0 + 0x274);
    if (h > 10) h = 10;
    v = (v * D_00446D90[h]) >> 5;
    if (v == 0) v = 1;
    v = (v * D_00446D50[s0[1]]) >> 5;
    if (v == 0) v = 1;
    func_0018C4B0(s0, v);
}
