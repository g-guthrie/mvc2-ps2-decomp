typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_00319B10(u8 *p) {
    extern void func_00318500(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern int func_001757E0(u8 *, s32, s32);
    extern void func_00183D10(u8 *);
    extern int func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_003C4910(u8 *, u8, u8);
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00318500(p);
        func_0018C4B0(p, 8);
        p[0x1B5] = *(s8 *)(p + 0x2C0) + 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, (u8)(*(s16 *)(p + 0x2C0) * 2 + 0xC));
        func_00183D10(p);
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_003C4910(p, *(s16 *)(p + 0x2C0) + 5, 0);
        }
    }
}
