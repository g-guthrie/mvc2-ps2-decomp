typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x38]; f32 f38; } S38;

void func_0021E150(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    f32 b, a, k;
    f32 c, d;

    switch (p[0x1FC]) {
    default:
        return;
    case 2:
        switch (p[7]) {
        case 0:
            if ((s8)func_00175700(p) < 0) {
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x6C) = 0;
                func_001843A0(p);
            }
            break;
        case 1:
            if ((s8)func_00175700(p) < 0) {
                p[7] = 3;
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x6C) = 0;
                func_001757E0(p, 8, 3);
                func_001E3210(p, 3);
                func_001E3710(p, 0x16);
            } else {
                a = *(f32 *)(p + 0x430);
                b = *(f32 *)(p + 0x38);
                if (a >= b) {
                    ((S38 *)p)->f38 = a;
                    p[0x152] = 1;
                    *(u32 *)(p + 0x60) = 0;
                    *(u32 *)(p + 0x6C) = 0;
                    func_001E3710(p, 0x34);
                }
            }
            break;
        case 2:
            if ((s8)func_00175700(p) < 0) {
                func_001843A0(p);
            } else {
                c = *(f32 *)(p + 0x430);
                d = *(f32 *)(p + 0x38);
                if (c > d) {
                    ((S38 *)p)->f38 = c;
                    p[0x152] = 1;
                    *(u32 *)(p + 0x5C) = 0;
                    *(u32 *)(p + 0x60) = 0;
                    *(u32 *)(p + 0x68) = 0;
                    *(u32 *)(p + 0x6C) = 0;
                    func_001E3710(p, 0x34);
                }
            }
            break;
        case 3:
            if ((s8)func_00175700(p) < 0) {
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x68) = 0;
                *(u32 *)(p + 0x6C) = 0;
                func_001843A0(p);
            } else if ((s8)p[0x151] == 2 && (*(u16 *)(p + 0x35E) & 0x800) != 0) {
                if (p[0x1E6] != 0) {
                    *(u32 *)(p + 0x5C) = 0x4192AAAA;
                    *(u32 *)(p + 0x68) = 0xBF055555;
                    k = -120.0f;
                    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) - k;
                } else {
                    *(u32 *)(p + 0x5C) = 0xC192AAAA;
                    *(u32 *)(p + 0x68) = 0x3F055555;
                    k = 120.0f;
                    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) - k;
                }
                func_001E3710(p, 0x16);
                func_001757E0(p, 8, 6);
            } else if (*(u16 *)(p + 0x168) == 0x806) {
                p[0x209] = 1;
            }
            break;
        default:
            break;
        }
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 0:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
