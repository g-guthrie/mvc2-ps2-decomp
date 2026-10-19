typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 v[1]; } G0;
extern G0 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_001F0AB0(u8 *p)
{
    u16 *pad = (u16 *)(p + 0x2B8);
    u16 w;
    u32 t = p[7];
    p[7] = t + 1;
    p[0x1B5] = 0x35;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->v[p[2]]++;
    func_0018C4B0(p, 8);
    func_00185490(p);
    *(u32 *)(p + 0x60) = 0x40CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 21, 3);
    *(u32 *)(p + 0x5C) = 0x40200000;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        if (*(s8 *)(p + 0x539) != 0) {
            w = *pad;
            if ((w & 0x800) == 0)
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        } else {
            w = *(u16 *)(p + 0x354);
            if ((w & 0x800) == 0)
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    } else if (*(s8 *)(p + 0x539) != 0) {
        w = *pad;
        if ((w & 0x400) == 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    } else {
        w = *(u16 *)(p + 0x354);
        if ((w & 0x400) == 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}
