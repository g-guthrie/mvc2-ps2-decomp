struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F7F4C[];
extern s32 D_004C283C;

void func_003CE5D0(u8 *p) {
    extern void func_003DAA40(struct Object *);
    extern s32 func_00153AA0();
    extern void func_00170DA0(s32, s32, s32, s16);
    if (D_004F7F4C[0] == 0) {
        func_003DAA40((struct Object *)p);
        return;
    }
    (*(s16 *)(p + 0x1C))++;
    if (*(s16 *)(p + 0x1C) >= 1000) *(s16 *)(p + 0x1C) = 0;
    (*(s16 *)(p + 0x1E))++;
    if (*(s16 *)(p + 0x1E) >= 1000) *(s16 *)(p + 0x1E) = 0;
    func_00170DA0(D_004C283C, 2, func_00153AA0(p), *(s16 *)(p + 0xCC));
    *(f32 *)(p + 0xE0) = -(1.0f - 0.001f * *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0xE4) = 1.0f - 0.001f * *(s16 *)(p + 0x1E);
    *(u32 *)(p + 0xD0) |= 0x20000;
}
