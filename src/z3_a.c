typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_00500000;
static s32 func_00291800(void) { return D_00500000 + 1; }
void func_00291A20(u8 *p, u8 *q) {
    extern void func_002918A0();
    extern void func_00292420();
    extern void func_001757E0();
    f32 f;
    if (func_00291800()) {
        p[7] = 6;
        q[0x18] = 0;
        func_002918A0();
        return;
    }
    if (q[0x18] == 0) {
        q[0x18]++;
        q[0x19] = 0;
        func_001757E0(p, 0x16, 8);
    }
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x34) += 4.1666665077209473f;
    } else {
        *(f32 *)(p + 0x34) += -4.1666665077209473f;
    }
    func_00292420(p);
}
