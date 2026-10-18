typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700(u8 *);
void func_00289800(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x34) += -13.333333015f;
        } else {
            *(f32 *)(p + 0x34) += 13.333333015f;
        }
    }
}
