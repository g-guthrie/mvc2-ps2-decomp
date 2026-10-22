typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_a;
extern H_a *D_004C2794;

void func_002134F0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00186A20(u8 *);
    extern void func_001863F0(u8 *);
    extern void func_00352170(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u8 c;
    s16 h;
    f32 x;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0xF) {
        func_00186A20(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001863F0(p);
    }
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        c = 0x30;
        if (p[0x269] == 3) c = 0x48;
        p[0x1B5] = c;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]] += 1;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (*(s16 *)(p + 0x1C) != 0) {
            if ((*(u16 *)(p + 0x366) & 0x300) != 0) {
                *(u16 *)(p + 0x366) = 0;
                *(f32 *)(p + 0x60) += 17.14285659790039f;
                h = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = h;
                c = 0x30;
        if (p[0x269] == 3) c = 0x48;
        p[0x1B5] = c;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]] += 1;
                p[0x168] = (*(s16 *)(p + 0x1C) & 1) ? 6 : 5;
                func_001757E0(p, 0x14, p[0x168]);
                return;
            }
        }
    }
    if (*(s8 *)(p + 0x151) == 3) {
        p[0x151] = 0;
        func_00352170(p, 2);
        t = p[6];
        p[6] = t + 1;
    }
}
