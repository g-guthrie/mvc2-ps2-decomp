typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00583B90[];
extern s8 D_00583BC7[];
extern s8 D_004C27C0[2];
extern s8 D_004C27C4[2];
extern u8 *D_004C2840[1];

void func_0032C3F0(void) {
    extern void func_001E60B0(), func_001E6490(), func_001382F0(), func_00138280();
    s8 *q, *p;
    s8 v;
    p = (s8 *)D_004C2840[0];
    q = p + 5;
    v = *q;
    switch (v) {
    case 0:
        *q = v + 1;
        D_004C27C4[0] = 1;
        D_004C27C0[0] |= (s8)(D_00583BC7[0] + 1);
        func_001E60B0(D_00583BC7[0]);
        func_001E6490(D_00583BC7[0]);
        if (*(s8 *)(D_004C2840[0] + 0x85) == 7) func_001382F0((u8)D_00583BC7[0]);
        else func_00138280((u8)D_00583BC7[0], 1);
        break;
    case 1:
        if (D_00583B90[D_00583BC7[0]] == 0) {
            p[4] = p[4] + 1;
            D_004C2840[0][5] = 0;
        }
        break;
    }
}
