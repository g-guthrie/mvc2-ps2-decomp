typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0;
    s8 b1;
    u8 b2;
    u8 pad3[5];
    s16 h8;
    s16 hA;
} G43;

extern G43 *D_004C2840;
extern f32 D_004F1D2C[];

void func_003D1B80(void)
{
    extern void func_001E22C0(void);
    extern s32 func_0012E560(void);
    extern void func_003D26F0(void);
    extern void func_003D26E0(void);
    extern void func_00140FD0(void);
    extern void func_00140020(s32);
    extern void func_001410D0(void);
    extern void func_0013FCE0(s32);
    extern void func_00140370(s32);
    extern void func_001E3CA0(s32);
    extern void func_003DA6F0(s32);
    extern void func_0016D190(void);
    extern void func_003298B0(s32, s32, s32);
    extern void func_001E4150(void);
    extern void func_003D7310(void *);
    extern void func_00152790(void);
    func_001E22C0();
    D_004C2840->h8 -= 1;
    if (D_004C2840->h8 == 0) {
        if (func_0012E560() == 0) {
            D_004C2840->h8 += 1;
        } else {
            D_004C2840->b1 += 1;
            D_004C2840->b2 = 0;
            goto done;
        }
    }
    func_003D26F0();
    func_003D26E0();
done:
    D_004C2840->hA += 1;
    if (D_004C2840->hA == 0xF0) func_00140FD0();
    switch (D_004C2840->hA) {
    case 0xF0: func_00140020(0); break;
    case 0xFA: func_00140020(1); break;
    case 0x104: func_00140020(2); break;
    case 0x10E: func_00140020(3); break;
    case 0x118: func_00140020(4); break;
    case 0x122: func_00140020(5); break;
    case 0xBC: func_00140020(6); break;
    case 0xC6: func_00140020(7); break;
    case 0xD0: func_00140020(8); break;
    case 0xDA: func_00140020(9); break;
    case 0xE4: func_00140020(10); break;
    case 0xEE: func_00140020(11); break;
    }
    if (D_004C2840->hA == 0x177) func_001410D0();
    if (D_004C2840->hA == 0x15E) {
        func_0013FCE0(2);
        func_0013FCE0(0);
        func_0013FCE0(1);
    }
    switch (D_004C2840->hA) {
    case 0x19A: func_00140370(0); break;
    case 0x1A4: func_00140370(1); break;
    case 0x1C2: func_00140370(2); break;
    case 0x1CC: func_00140370(3); break;
    case 0x1EA: func_00140370(4); break;
    case 0x1F4: func_00140370(5); break;
    }
    if (D_004C2840->hA == 0x190) func_0013FCE0(4);
    if (D_004C2840->hA == 0x15E) func_001E3CA0(2);
    if (D_004C2840->hA < 0x140) D_004F1D2C[0] += 4.625f;
    func_003DA6F0(13);
    func_0016D190();
    if (D_004C2840->hA == 0x15E) func_003298B0(-1, 0x14, 0);
    if (D_004C2840->hA == 0x348) {
        func_001E4150();
        func_003298B0(-1, 0x3C, 1);
    }
    func_003D7310(func_00152790);
}
