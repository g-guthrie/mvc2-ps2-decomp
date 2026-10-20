typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern s32 func_00175700(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_0027A680(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        if (*(s16 *)(p + 0x1C) >= 6) {
            s16 e = ++*(s16 *)(p + 0x1E);
            if (e & 1) {
                p[0x1B5] = 0x34;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->t[p[2]]++;
            } else {
                p[0x1B5] = 0x3D;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->t[p[2]]++;
            }
        } else {
            p[0x1B5] = 0x3A;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t[p[2]]++;
        }
    }
    if (--*(s16 *)(p + 0x1C) == 0) {
        p[6]++;
        func_001E3710(p, 0x3A);
        if (!p[0x1E6])
            *(s32 *)(p + 0x68) = 0x3E855555;
        else
            *(s32 *)(p + 0x68) = 0xBE855555;
        func_001757E0(p, 0x15, 8);
    }
}
