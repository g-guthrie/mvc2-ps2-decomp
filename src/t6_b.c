typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_001757E0();
extern s16 D_004C27A4;
void func_002EFC00(u8 *p) {
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 0x10);
    }
    func_00175700(p);
    if (p[0x20] >= 0) {
        s16 w = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = w;
        if (w < 0) {
            *(s16 *)(p + 0x1C) = 1;
            if (D_004C27A4 >= 2) {
                u32 t = p[0x20];
                p[0x20] = t - 1;
            }
        }
    }
}


extern u8 D_00583B90[];
extern s8 D_004C27C4;
extern s8 D_004C27C0;
extern void func_00138280();
extern void func_001E6370();
void func_0032ACD0(u8 *p) {
    u32 t = p[5];
    switch (t) {
    case 0:
        p[5] = t + 1;
        D_00583B90[*(s8 *)(p + 0x538)] = 0;
        func_00138280(p[0x538], 0);
        func_001E6370(*(s8 *)(p + 0x538));
        break;
    case 1:
        p[5] = t + 1;
        D_004C27C4 = 1;
        D_004C27C0 = D_004C27C0 | (*(s8 *)(p + 0x538) + 1);
    case 2:
        if (D_00583B90[*(s8 *)(p + 0x538)] == 0) {
            p[4] = 2;
            p[5] = 0;
        }
        break;
    }
}

