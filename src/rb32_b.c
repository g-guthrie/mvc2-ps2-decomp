typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

static void func_002CFA20(u8 *p)
{
    int command = p[0x15b];
    if (command) {
        unsigned int offset;
        p[0x1b5] = command;
        p[0x1b2] = *(unsigned short *)(p + 0x1c0) = 0;
        *(int *)(p + 0x1d8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7c);
        p[0x15b] = 0;
    }
}
static void (*keep_002CFA20)(u8 *) = func_002CFA20;

void func_002CFC30(u8 *p)
{
    extern int func_00175700(u8 *);
    extern int func_001757E0(u8 *, int, int);
    extern void func_001CFE00(u8 *, int);
    f32 v;
    u32 t;
    s32 q;
    s8 r;

    p[0x40C] = 2;
    p[0x33C] = 5;
    q = *(s8 *)(p + 0x1B2);
    if (q != 0) {
        if (((s8)q & 1) == 0) {
            *(s16 *)(p + 0x1C) = 1;
        }
    }
    if ((s8)func_00175700(p) < 0) {
        if (*(s16 *)(p + 0x1C) == 0) {
            p[6] = 7;
            func_001757E0(p, 0x16, 6);
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
        } else {
            t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0;
            p[0x20] = 0;
            *(s16 *)(p + 0x1E) = 4;
            func_001757E0(p, 0x16, 7);
            if (p[0x1E6] != 0) {
                v = 6.666666507720947f;
            } else {
                v = -6.666666507720947f;
            }
            *(f32 *)(p + 0x5C) = v;
            *(u32 *)(p + 0x60) = 0x41092492;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
        }
        return;
    } else {
        q = *(s8 *)(p + 0x150);
        if (q != 0) {
            func_001CFE00(p, (u8)((s8)q - 1));
            p[0x150] = 0;
        }
        if ((*(s8 *)(p + 0x151) = 1) != 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        }
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_002CFA20(p);
    }
}
