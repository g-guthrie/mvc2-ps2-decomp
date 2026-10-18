typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { f32 x, y, z; } V2;
void func_001266A0(u8 *a, s32 b, s32 c);
void func_0015D010(u8 *a, V2 *v);
void func_0018C6E0(u8 *a);
void func_001757E0(u8 *a, s32 b, s32 c);
void func_0029A560(u8 *a) {
    V2 v;
    func_001266A0(a, 5, 5);
    v.x = -83.33333f;
    v.y = 158.57143f;
    func_0015D010(a, &v);
    a[0x1B4] = 10;
    func_0018C6E0(a);
    a[6] = 0;
    func_001757E0(a, 0xF, 4);
}

f32 func_00117078(f32 x);
void func_00175700(u8 *a);
void func_0029D280(u8 *a) {
    *(f32*)(a + 0x34) += *(f32*)(a + 0x5C);
    func_00175700(a);
    if (func_00117078(*(f32*)(a + 0x34) - *(f32*)(a + 0x68)) < 8.333333f) {
        u32 t = a[5];
        a[5] = t + 1;
        *(f32*)(a + 0x34) = *(f32*)(a + 0x68);
        func_001757E0(a, 0, 0);
    }
}

s8 func_00175670(void);
void func_001B7C40(void);
void func_001B7BB0(u8 *a) {
    if (a[5] == 0) {
        if (func_00175670() < 0) {
            u32 t = a[5];
            a[5] = t + 1;
            *(f32*)(a + 0x118) = 1.0f;
        }
    } else {
        f32 x = *(f32*)(a + 0x118) - 0.05f;
        *(f32*)(a + 0x118) = x;
        if (x <= 0.0f) func_001B7C40();
    }
}
