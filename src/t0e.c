typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static s32 func_0028A490(u8 *p) { return p[0x10] != 0; }
extern void func_0028A530(u8 *p);
extern void func_0028B0B0(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
void func_0028A6B0(u8 *p, u8 *q) {
    u32 t;
    if (func_0028A490(p) != 0) {
        p[7] = 6;
        q[0x18] = 0;
        func_0028A530(p);
    } else {
        if (q[0x18] == 0) {
            t = q[0x18];
            q[0x18] = t + 1;
            q[0x19] = 0;
            func_001757E0(p, 0x16, 8);
        }
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x34) += 4.166666507720947f;
        } else {
            *(f32 *)(p + 0x34) += -4.166666507720947f;
        }
        func_0028B0B0(p);
    }
}
