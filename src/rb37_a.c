typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 b[20]; } E;
extern E D_004CD183[];

void func_001E3710(u8 *p, u8 k)
{
    extern void func_001741D0(u8 *, f32 *);
    extern s32 func_00118FA8(f32);
    extern void func_001E48B0();
    extern void func_001E2490(s32, s32);
    extern void func_001E3D20(s32, u32, s32, u32);
    f32 v[2];
    s32 n;
    u32 kk;
    func_001741D0(p + 0x34, &v[0]);
    n = func_00118FA8(v[0] / 40.0f);
    if (n < 0) n = 0;
    if (n > 15) n = 15;
    kk = k;
    switch (kk) {
    case 0x3A:
    case 0x3B:
    case 0x1F:
        break;
    case 0x51:
        func_001E48B0();
        switch (p[1]) {
        case 4:
func_001E2490(D_004CD183[p[0x1B8]].b[0], 0x11);
func_001E2490(D_004CD183[p[0x1B8]].b[0], 0x17);
func_001E2490(D_004CD183[p[0x1B8]].b[0], 0x18);
func_001E2490(D_004CD183[p[0x1B8]].b[0], 0x30);
            return;
        case 0x2D:
            break;
        default:
            break;
        }
        break;
    default:
        func_001E3D20(6, kk, n, p[1]);
        break;
    }
}
