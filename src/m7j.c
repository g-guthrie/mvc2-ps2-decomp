typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 func_00175700();
extern void func_001757E0();
extern void func_001E3210();
extern void func_001E3710();
void func_0020E920(u8 *a) {
    s8 r = func_00175700(a);
    if (r < 0) {
        u32 t = a[6];
        f32 v;
        a[6] = t + 1;
        if (a[0x1E6]) v = 6.6666665f;
        else v = -6.6666665f;
        *(f32 *)(a + 0x5C) = v;
        *(u32 *)(a + 0x60) = 0xC1AB6DB6;
        func_001E3210(a, 4);
        func_001E3710(a, 0x4B);
        func_001757E0(a, 0x15, 0x27);
    }
}

extern void func_002D5590();
extern void func_0015D010();
void func_002D5720(u8 *a) {
    V3 v;
    s32 k = 0;
    func_002D5590(a);
    if (a[0x22] & 1) {
        *(s16 *)(a + 0x140) ^= 1;
        *(s8 *)(a + 0x1E6) = *(s8 *)(a + 0x140);
        *(s16 *)(*(u8 **)(a + 0x1DC) + 0x140) ^= 1;
        *(s8 *)(*(u8 **)(a + 0x1DC) + 0x1E6) = *(s8 *)(*(u8 **)(a + 0x1DC) + 0x140);
    }
    a[0x1B4] = 10;
    v.x = -85.0f;
    v.y = 92.14285f;
    v.z = 0.0f;
    func_0015D010(a, &v);
    func_001757E0(a, 0xF, 4);
}

void func_00266680(u8 *a) {
    s8 r = func_00175700(a);
    if (r < 0) {
        u32 t = a[6];
        f32 v;
        a[6] = t + 1;
        *(u32 *)(a + 0x60) = 0x4122DB6D;
        *(u32 *)(a + 0x6C) = 0xBEE76DB6;
        if (*(s16 *)(a + 0x140)) v = -4.1666665f;
        else v = 4.1666665f;
        *(f32 *)(a + 0x5C) = v;
        func_001757E0(a, 1, 2);
    } else {
        *(volatile s8 *)(a + 0x151);
    }
}
