typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_rc;
extern H_rc *D_004C2794;

void func_0029C520(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001843A0();
    s8 r;
    u32 t;
    f32 a, b, c, d;

    switch (p[0x1FC]) {
    case 2:
        if (p[6] == 0) {
            if (*(s8 *)(p + 0x151) & 1) {
                p[0x151] = 0;
                p[0x1B5] = 2;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]] += 1;
            }
            if (*(s8 *)(p + 0x151) & 2) {
                p[0x151] = 0;
                p[0x1B5] = 0x19;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]] += 1;
            }
            r = func_00175700(p);
            if (r < 0) func_001843A0(p);
        } else {
            func_00175700(p);
            if (p[7] == 0) {
                if (*(s8 *)(p + 0x151) != 0) {
                    t = p[7];
                    p[7] = t + 1;
                    *(f32 *)(p + 0x60) = 6.4285712242126465f;
                    *(f32 *)(p + 0x6C) = -0.5357142686843872f;
                    *(f32 *)(p + 0x5C) = 8.333333015441895f;
                    *(f32 *)(p + 0x68) = -0.15625f;
                    if ((*(u16 *)(p + 0x20E) & 0x800) == 0) {
                        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
                    }
                    if (*(s16 *)(p + 0x140) == 0) {
                        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
                    }
                }
            } else {
                if (*(s8 *)(p + 0x151) == 0) {
                    p[6] = 0;
                    p[7] = 0;
                    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
                    *(f32 *)(p + 0x5C) = 0.0f;
                    *(f32 *)(p + 0x60) = 0.0f;
                    *(f32 *)(p + 0x68) = 0.0f;
                    *(f32 *)(p + 0x6C) = 0.0f;
                }
            }
        }
        break;
    case 0:
    case 1:
        r = func_00175700(p);
        if (r < 0) func_001843A0(p);
        break;
    }
}
