typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void func_002636E0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    u32 ca;
    f32 v;
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            if (p[0x1E6] != 0) v = 1.666666627f * (f32)*(s8 *)(p + 0x151);
            else v = -(1.666666627f * (f32)*(s8 *)(p + 0x151));
            *(f32 *)(p + 0x34) += v;
            p[0x151] = 0;
        }
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ca = p[2] * 2;
            ca += (u32)D_004C2794;
            ca += 0x7C;
            ++*(s16 *)ca;
        }
        break;
    case 0:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
