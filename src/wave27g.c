typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s8 func_00175700(u8 *a);
void func_001757E0(u8 *a, s32 b, s32 c);
typedef struct { f32 x, y, z; } V3;
void func_001843A0(u8 *a);
void func_00183920(u8 *a, V3 *v);
void func_001E3710(u8 *a, s32 b);
void func_002BDCF0(u8 *a) {
    s8 r = func_00175700(a);
    if (r < 0) {
        func_001843A0(a);
    } else {
        s8 f = a[0x151];
        if (f & 1) {
            V3 v;
            a[0x151] = 0;
            v.x = 25.0f;
            v.y = 162.85713f;
            v.z = 0.0f;
            func_00183920(a, &v);
        } else if (f & 2) {
            a[0x151] = 0;
            func_001E3710(a, 0x16);
        }
    }
}

void func_003793F0(u8 *a);
void func_003792B0(u8 *a) {
    *(f32 *)(a + 0x34) = *(f32 *)(*(u8 **)(a + 0x18) + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(*(u8 **)(a + 0x18) + 0x38);
    *(f32 *)(a + 0x38) += 548.57141f;
    func_001757E0(a, 0x15, 7);
    for (;;) {
        if (*(s8 *)(*(u8 **)(a + 0x18) + 0x161) == *(s8 *)(a + 0x161)) {
            a[0x13C] = 1;
            return;
        }
        if (func_00175700(a) < 0) {
            func_003793F0(a);
            return;
        }
    }
}
