typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G325;
extern G325 *D_004C2794;

void func_00325230(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    f32 f;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) return;
    f = *(f32 *)(p + 0x5C);
    if (*(s16 *)(p + 0x140) == 0) f = -f;
    *(f32 *)(p + 0x34) += f;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) < 0.0f) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x3C;
        t = p[0x168];
        p[0x168] = t + 1;
        if (*(s8 *)(p + 0x1B2) != 0 && ((s8)*(s8 *)(p + 0x1B2) & 0x11) == 0) {
            t = p[6];
            p[6] = t + 1;
            t = p[0x168];
            p[0x168] = t + 1;
        }
        func_001757E0(p, 0x15, p[0x168]);
    }
    t = p[0x22] + 0x20;
    p[0x22] = t;
    if ((t & 0xFF) == 0) {
        s16 h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h > 0) {
            u32 v = p[0x1B5] + 1;
            p[0x1B5] = v;
            p[0x1B5] = v;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7C[p[2]]++;
        }
        func_001E3710(p, 0x4B);
    }
}
