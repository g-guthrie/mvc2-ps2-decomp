typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0018D6F0(u8 *p, u8 *other, f32 *buf);
extern void func_00154790(f32 *buf, s32 a, s32 b, s32 c);
/* Provisional: the second argument is unused by the known callee body. */
extern void func_00156E80(f32 *buf, s32 a);
extern void func_001E38B0(void *p);

void func_0018D580(u8 *p, u8 *x) {
    u8 *q = *(u8 **)(p + 0x1D0);
    if (*(s8 *)(q + 0xB) >= 0) {
        f32 buf[4];
        u32 c;
        func_0018D6F0(p, x, buf);
        c = q[8];
        if (p[0x1BA] != 0) {
            c = (32 - (s8)c) & 0x1F;
        }
        func_00154790(buf, *(s16 *)(p + 0x140), q[0xB], c);
        if (q[0x12] & 0x40) {
            func_00156E80(buf, 0);
        }
    }
    func_001E38B0(p);
}
