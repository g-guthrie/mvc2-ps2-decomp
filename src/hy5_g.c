typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7c[4]; } GG;
extern GG *D_004C2794;

void func_0031C2A0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001843A0(u8 *);
    extern s32 func_001853E0(u8 *);
    extern void func_001855D0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_0019B110(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s8 r;
    switch (p[0x1FC]) {
    case 0:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        }
        break;
    case 1:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            if (func_001853E0(p) == 0) {
                if (*(s8 *)(p + 0x1B2) != 0) {
                    if ((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x200) {
                        *(u16 *)(p + 0x366) = 0;
                        func_001855D0(p);
                        func_001E3210(p, 0x1F);
                        if (*(s8 *)(p + 0x151) == 1) {
                            p[0x1B5] = 0x1C;
                            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                            *(s32 *)(p + 0x1D8) = 0;
                            D_004C2794->h7c[p[2]]++;
                            func_001757E0(p, 7, 4);
                        } else {
                            p[0x1B5] = 1;
                            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                            *(s32 *)(p + 0x1D8) = 0;
                            D_004C2794->h7c[p[2]]++;
                            func_001757E0(p, 7, 1);
                        }
                    }
                }
            }
        }
        break;
    case 2:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_0019B110(p, 1);
        }
        break;
    }
}
