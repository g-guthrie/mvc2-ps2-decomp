typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_001AC3F0();
extern void (*D_004BF7F8[2])();
void func_001AB040(u8 *p, u8 *q) {
    if (q[0x425] == 0 && (q[0x1E4] != 0x1C || q[0x26A] != 0)) {
        func_001AC3F0();
    } else {
        D_004BF7F8[p[7]]();
    }
}
