typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00154790(u8 *buf, s32 a, s32 b, s32 c);
extern void func_00156E80(u8 *buf, s32 a);

static void func_0018D6F0(u8 *p, u8 *q, u8 *buf) {
    *(s32 *)buf = 0;
}

void func_0018D9A0(u8 *p) {
    u8 buf[16];
    u8 *q = *(u8 **)(p + 0x1C8);
    u8 *e;
    u32 a3;
    if (q == 0) return;
    if (q[3] != 0 && q[3] != 1) return;
    *(u8 **)(p + 0x1D0) = *(u8 **)(q + 0x184) + (p[0x1B6] & 0x7F) * 0x1C;
    e = *(u8 **)(p + 0x1D0);
    if (e == 0) return;
    if (*(s8 *)(e + 0xB) < 0) return;
    func_0018D6F0(p, q, buf);
    a3 = e[8];
    if (p[0x1BA] != 0) a3 = (32 - (s8)a3) & 0x1F;
    func_00154790(buf, *(s16 *)(p + 0x140), e[0xB], a3);
    if ((e[0x12] & 0x40) != 0) func_00156E80(buf, 0);
}
