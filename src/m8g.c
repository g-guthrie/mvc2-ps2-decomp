typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175910(void *p, s32 a, s32 b, s32 c);
extern void func_00174910(void *p, s32 a);
extern void func_003B07D0(void *p, void *q);

void func_003B00D0(u8 *p, u8 *q) {
    u32 t = p[7];
    if (t == 0) {
        p[7] = t + 1;
        if (*(s16 *)(p + 0x140) == 0) {
            p[0x22] = 0x18;
        } else {
            p[0x22] = 8;
        }
        func_00175910(p, 0x17, 3, 0xC);
    } else {
        func_00174910(p, 0x2BC);
    }
    func_003B07D0(p, q);
}
