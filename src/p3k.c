typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00118F48(f32 *, u32 *);

s32 func_00119098(f32 x) {
    u32 o[4];
    func_00118F48(&x, o);
    if ((o[0] ^ 2) == 0) return 0;
    if (o[1] != 0) return 0;
    if ((s32)o[2] < 0) return 0;
    if ((s32)o[2] >= 0x20) return -1;
    if ((s32)o[2] > 0x1E) return o[3] << (o[2] - 0x1E);
    return o[3] >> (0x1E - o[2]);
}
