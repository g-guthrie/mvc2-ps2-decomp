typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern s32 D_004F1CDC[];
extern V3 D_004606C0[];
extern f32 D_004606C8[];

void func_00344180(u8 *p)
{
    extern void func_003431D0(void);
    extern void func_00343330(s32);
    extern void func_00343700(s32);
    extern void func_00343C90(s32);
    extern void func_00343960(s32);
    extern void func_003453C0(void);
    extern void func_00343BE0(s32);
    extern void func_001E3630(s32);
    extern void func_001E3CE0(s32);
    extern s32 func_00417A40(void);
    extern void func_00343A60(V3 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_00343E80(s32 *, s32 *, s32);
    s32 i;
    s32 o1, o2;
    V3 v;

    switch (p[4]) {
    case 0:
        p[4]++;
        func_003431D0();
        for (i = 0; i < 6; i++) func_00343330(i);
        for (i = 0; i < 8; i++) func_00343700(i);
        for (i = 0; i < 4; i++) func_00343C90(i);
        for (i = 0; i < 6; i++) func_00343960(i);
        break;
    case 1:
        if (D_004F1CDC[0] == 1) {
            D_004C2840[0x91] = 1;
            p[4]++;
            func_003453C0();
            for (i = 0; i < 3; i++) func_00343BE0(i);
            func_001E3630(0x1F);
        }
        break;
    case 2:
        {
            s32 r, off;
            D_004C2840[0x91] = 1;
            if (*(s16 *)(p + 0x1C) % 12 == 0) {
                r = func_00417A40() % 2;
                off = r * 12;
                v = *(V3 *)((u8 *)D_004606C0 + off);
                v.x = *(f32 *)((u8 *)D_004606C0 + off) + (f32)(func_00417A40() % 2000 - 1000);
                v.z = *(f32 *)((u8 *)D_004606C8 + off) + (f32)(func_00417A40() % 500 - 250);
                func_00343A60(&v, r);
            }
            if (*(s16 *)(p + 0x1C) + 3 == 0) func_001E3630(0x1E);
            if ((*(s16 *)(p + 0x1C) + 7) % 10 == 0) {
                if (func_00417A40() % 2 != 0) func_001E3710(p, 0x30);
            }
            if (*(s16 *)(p + 0x1C) % 100 == 0) func_001E3710(p, 0x31);
            {
                s16 h = *(s16 *)(p + 0x1C) + 1;
                *(s16 *)(p + 0x1C) = h;
                if (h >= 0xB4) p[4]++;
            }
        }
        break;
    case 3:
        {
            s32 off, r;
            D_004C2840[0x91] = 1;
            if (*(s16 *)(p + 0x1C) % 12 == 0) {
                r = func_00417A40() % 2;
                off = r * 12;
                v = *(V3 *)((u8 *)D_004606C0 + off);
                v.x = *(f32 *)((u8 *)D_004606C0 + off) + (f32)(func_00417A40() % 2000 - 1000);
                v.z = *(f32 *)((u8 *)D_004606C8 + off) + (f32)(func_00417A40() % 500 - 250);
                func_00343A60(&v, r);
            }
            if (*(s16 *)(p + 0x1C) + 3 == 0) func_001E3630(0x1E);
            if ((*(s16 *)(p + 0x1C) + 7) % 20 == 0) {
                if (func_00417A40() % 2 != 0) func_001E3710(p, 0x30);
            }
            if (*(s16 *)(p + 0x1C) % 200 == 0) func_001E3710(p, 0x31);
            {
                s16 h = *(s16 *)(p + 0x1C) + 1;
                *(s16 *)(p + 0x1C) = h;
                if (h >= 0x168) p[4]++;
            }
        }
        break;
    case 4:
        D_004C2840[0x91] = 0;
        if (D_004F1CDC[0] == 2) {
            p[4]++;
            func_001E3630(0x1F);
            func_001E3CE0(0x44);
        }
        break;
    default:
        break;
    }
    func_00343E80(&o1, &o2, 0);
    func_00343E80(&o1, &o2, 1);
    func_00343E80(&o1, &o2, 2);
    func_00343E80(&o1, &o2, 3);
}
