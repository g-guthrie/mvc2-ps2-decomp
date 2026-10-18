typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189660(void *a, void *b, void *c);
extern void func_00186A60(void *a, s32 b);
extern u8 D_00450AA0[];
extern s8 func_00175700(void *p);
extern void func_001843A0(void *p);
extern void func_0037D930(void *p, s32 a);
extern void func_001BBD80(void *p, s32 a);

s32 func_002108E0(u8 *p) {
    s32 r;
    if (func_00189660(p, D_00450AA0, p + 0x398) == 0) {
        r = 0;
    } else {
        p[0x1FD] = 4;
        p[5] = 0;
        func_00186A60(p, 0x15);
        p[7] = 0;
        p[6] = 0;
        r = 1;
    }
    return r;
}

void func_00274920(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
    } else if (p[0x1FC] == 2) {
        if (*(s8 *)(p + 0x151) == 2) {
            p[0x151] = 0;
            func_0037D930(p, 1);
            func_001BBD80(p, 1);
        }
        if (*(s8 *)(p + 0x151) == 3) {
            p[0x151] = 0;
            func_001BBD80(p, 4);
        }
    }
}
