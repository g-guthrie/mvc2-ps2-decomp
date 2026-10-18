typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 *func_003DA750(s32 a, s32 b, s32 c);
void func_0033D990(void);
void func_00170DF0(u32 a);
extern u32 D_004C283C;
extern u32 D_004C2838;
void func_0033D910(u8 *a) {
    u8 *p = func_003DA750(0, 6, 1);
    if (p != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_0033D990;
        *(s16 *)(p + 0xCC) = 0x1E;
        *(u32 *)(p + 0x84) = D_004C283C;
        *(s32 *)(p + 0xD0) = 0x800;
        *(u8 **)(p + 0x14) = a;
        *(u8 **)(p + 0xC8) = a + 0x88;
        func_00170DF0(*(u32 *)(p + 0x84));
    }
}

extern u8 *D_004C2840;
void func_003DA410(void);
void func_001E40E0(void);
void func_001E4140(void);
void func_001E4150(void);
void func_001278F0(void) {
    u8 *p;
    D_004C2840[1] = 1;
    D_004C2840[2] = 0;
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    p = D_004C2840;
    {
        u32 t = p[0x2C];
        p[0x2C] = t + 1;
    }
    func_003DA410();
    func_001E40E0();
    func_001E4140();
    func_001E4150();
}
