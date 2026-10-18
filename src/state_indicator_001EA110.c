typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G4;
extern G4 *D_004C2794;

void func_001EA110(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001843A0();
    f32 d;

    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (p[6] != 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                p[0x1B5] = 0x13;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
            if (*(s8 *)(p + 0x150) != 0) {
                if (p[0x1E6] != 0) {
                    d = 3.3333332538604736f;
                } else {
                    d = -3.3333332538604736f;
                }
                *(f32 *)(p + 0x34) += d;
            }
        }
        break;
    }
}
