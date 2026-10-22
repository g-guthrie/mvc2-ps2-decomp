typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C0CA8[8];

void func_002B1C20(u8 *p)
{
    extern void func_0018C6E0(void *);
    extern void func_00182C30(u8 *, s32);
    extern void func_00182DB0(u8 *, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 v;
    s16 w;
    u32 vec[4];
    if (*(u16 *)(p + 0x20E) & 0x400) {
        v = *(s16 *)(p + 0x140) ^ 1;
        *(s16 *)(p + 0x140) = v;
        p[0x1E6] = v;
    }
    w = *(s16 *)(p + 0x140) ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = w;
    (*(u8 **)(p + 0x1DC))[0x1E6] = w;
    func_0018C6E0(p);
    p[0x1B4] = 10;
    if (p[0x20B] == 0) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = *(f32 *)(*(u8 **)(p + 0x1DC) + 0x430);
        if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x42C) & 0x4000000) {
            *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 128.57142639160156f + *(f32 *)(p + 0x430);
        }
        if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x428) & 0x20000000) {
            *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 57.857139587402344f + *(f32 *)(p + 0x430);
        }
        if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x428) & 0x10000000) {
            *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 49.28571319580078f + *(f32 *)(p + 0x430);
        }
        *(s16 *)(p + 0x1C) = 0x60;
        func_00182C30(*(u8 **)(p + 0x1DC), 0x28);
        func_00182DB0(p, 1);
        vec[0] = 0xC1D55555;
        vec[1] = 0x432FB6DB;
    } else {
        func_001266A0(p, 5, 5);
        vec[0] = 0xC276AAAA;
        vec[1] = 0x42DA9249;
    }
    func_0015D010(p, vec);
    func_001757E0(p, 0xF, D_004C0CA8[p[0x20B]]);
}
