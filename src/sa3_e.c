typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa3_e.c "-O3 -Op -sdatathreshold 8" */
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_f;
extern G_f *D_004C2794;
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_00263970(u8 *p) {
    s8 t;
    f32 v;
    switch (p[0x1FC]) {
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        t = *(s8 *)(p + 0x151);
        if (t != 0) {
            if (p[0x1E6] != 0) {
                v = 1.666666627f * (f32)t;
            } else {
                v = -(1.666666627f * (f32)t);
            }
            *(f32 *)(p + 0x34) += v;
            p[0x151] = 0;
        }
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            p[0x1B5] = 5;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = 0x1A;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 0:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    default:
        break;
    }
}
