typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

void func_00287780(PH *p) {
    extern s8 func_00175700();
    extern void func_001843A0(PH *);
    f32 c;
    switch (((u8 *)p)[0x1FC]) {
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p->b6 == 0 && ((s8 *)p)[0x151] != 0) {
            *(s8 *)((s32)p + 0x151) = 0;
            p->b6++;
            if (*(s16 *)((u8 *)p + 0x140) == 0) {
                c = -53.33333206176758f;
                p->f34 = p->f34 + c;
            } else {
                c = -53.33333206176758f;
                p->f34 = p->f34 - c;
            }
        }
        break;
    case 0:
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}
