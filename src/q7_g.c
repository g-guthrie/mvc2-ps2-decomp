typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3;

void func_00321F40(u8 *p, s32 b) {
    extern void func_001266A0();
    extern void func_00179160();
    extern s32 func_00118FA8(f32);
    V3 v;
    s32 r;
    f32 x;
    func_001266A0(p, 6, 6);
    v = *(V3 *)(p + 0x34);
    func_00179160(p, b);
    x = *(f32 *)(p + 0x34);
    r = func_00118FA8(x);
    if (r != func_00118FA8(v.x) || (r = func_00118FA8(*(f32 *)(p + 0x38))) != func_00118FA8(v.y)) {
        *(f32 *)(p + 0x34) = v.x + (x - v.x) / 2.0f;
        *(f32 *)(p + 0x38) = v.y + (*(f32 *)(p + 0x38) - v.y) / 2.0f;
        p[0x152] = 8;
    }
}
