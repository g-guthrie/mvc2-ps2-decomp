typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x106]; u16 t106[8]; } G;
extern G *D_004C2840;
extern volatile u8 D_004C28D4;

void func_001F6A90(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00182E20(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_001549B0(u8 *, u32 *);
    extern void func_001E3210(u8 *, s32);
    s16 c;
    u32 t;
    u32 v[4];
    u8 *q;
    func_00175700(p);
    c = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = c;
    if (c == 0) {
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0xF, 0x33);
        return;
    }
    if (func_00182E20(p) != 0) {
        if (D_004C2840->t106[*(s8 *)(p + 0x538)] != 0) {
            t = D_004C28D4;
            D_004C28D4 = t + 1;
            if (D_004C28D4 % 3 == 0) p[0x152] = 1;
        }
    }
    if (func_00182D30(*(u8 **)(p + 0x1DC)) == 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            D_004C28D4 = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            p[0x1B5] = q[0x1B5] = 0x24;
            func_0018FDB0(p);
            v[0] = 0xC33AAAAA;
            v[1] = 0x43092492;
            func_001549B0(p, v);
            func_001E3210(p, 0x20);
        }
    } else {
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0xF, 0x33);
    }
}
