typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004F1CB8;
u32 func_00174170(void);
void func_001E3710(u8 *p, s32 a);
void func_00154850(f32 *v, s32 a, s32 b, s32 c);
void func_00191600(u8 *q, u8 *p, s32 a);
void func_001266A0(u8 *p, s32 a, s32 b);
void func_00185510(u8 *p);

void func_002AE5B0(u8 *p)
{
    f32 v[4];
    f32 *w;
    u8 *q;
    s16 h;
    u32 t;

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    D_004F1CB8 = 2;
    p[0x201] = 2;
    p[0x209] = 2;
    h = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = h;
    if (h <= 0) {
        *(s16 *)(p + 0x1E) = 4;
        if ((func_00174170() & 1) != 0) {
            func_001E3710(p, 0);
        } else {
            func_001E3710(p, 1);
        }
        v[0] = 1.6666666269302368f * (f32)(func_00174170() & 0x7F);
        v[1] = 2.142857074737549f * (f32)(func_00174170() & 0x3F);
        w = &v[1];
        if ((func_00174170() & 1) != 0) v[0] = -v[0];
        if ((func_00174170() & 1) != 0) *w = -*w;
        v[0] += *(f32 *)(p + 0x34);
        *w += 205.7142791748047f + *(f32 *)(p + 0x38);
        v[2] = *(f32 *)(p + 0x3C);
        func_00154850(v, *(s16 *)(p + 0x140), 1, 0);
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        q = *(u8 **)(p + 0x1DC);
        func_00191600(q, p, 0x10);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 8;
        q[0x20D] = 0;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x24;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s16 *)(p + 0x1C) = 0x40;
        D_004F1CB8 = 0;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x34) += 26.66666603088379f;
        } else {
            *(f32 *)(p + 0x34) -= 26.66666603088379f;
        }
        func_00185510(p);
    }
}
