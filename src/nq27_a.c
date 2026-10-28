typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gra32a;
extern Gra32a *D_004C2794;
extern s16 *D_004C298C;

void func_00378AB0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00174A40(u8 *, s32);
    extern s32 func_00174240(u8 *);
    extern s32 func_00378CA0(u8 *);
    extern s32 func_001E7F60(u8 *);
    s32 t;
    func_00175700(p);
    func_00174A40(p, *D_004C298C);
    { s16 *g = D_004C298C; s32 w = *g; *g = w + 0x32; }
    if (func_00174240(p) == 0) {
        func_00378CA0(p); return;
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    t = p[0x20];
    p[0x20] = t + 1;
    if ((u8)(t + 1) < 5) {
        p[0x1B5] = *(s8 *)(p + 0x20) + 0x3E;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        return;
    }
    func_001E7F60(p);
}
