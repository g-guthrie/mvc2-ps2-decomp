typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_0021C690(u8 *p, void *a1) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00179160(u8 *, void *);
    extern s32 func_00118FA8(f32);
    V3 v;
    f32 x;
    func_001266A0(p, 6, 6);
    v = *(V3 *)(p + 0x34);
    func_00179160(p, a1);
    x = *(f32 *)(p + 0x34);
    if (func_00118FA8(x) != func_00118FA8(v.x) ||
        func_00118FA8(*(f32 *)(p + 0x38)) != func_00118FA8(v.y)) {
        *(f32 *)(p + 0x34) = v.x + (x - v.x) / 2.0f;
        *(f32 *)(p + 0x38) = v.y + (*(f32 *)(p + 0x38) - v.y) / 2.0f;
        p[0x152] = 8;
    }
}
