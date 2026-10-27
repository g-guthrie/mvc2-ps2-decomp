/* Motion transitions and their shared actor helpers. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C2794;
extern int func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern void func_00186A20(u8 *);
extern void func_002CF190(u8 *);
static void func_002CEC90(u8 *p) {
    s8 v = *(s8 *)(p + 0x150);
    if (v) {
                p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { u32 offset = p[2] * 2; offset += (u32)D_004C2794; ++*(s16 *)(offset + 0x7C); }
        p[0x150] = 0;
    }
}

static void func_002CEC40(u8 *p) {
 float previous=*(float *)(p+0x60);
 *(float *)(p+0x38)+=previous;
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (previous * *(float *)(p+0x60)<0.0f) *(float *)(p+0x6c)=-1.205357074737548828125f;
}

void func_002CF110(u8 *p) {
    func_002CEC90(p);
    func_002CEC40(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_002CF190(p);
    } else if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
}

void func_002CEEB0(u8 *p)
{
    extern int func_00175700(u8 *);

    f32 v, z, w;
    f32 *q5c, *q68;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q5c = (f32 *)(p + 0x5C);
    q68 = (f32 *)(p + 0x68);
    z = 0.0f;
    v = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) * v < z) {
        *q5c = z;
    }
    *(s32 *)q68 = 0;
    func_00175700(p);
    func_002CEC90(p);
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (p[0x1E6] != 0) {
            v = 16.666666030883789f;
        } else {
            v = -16.666666030883789f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) {
            w = -0.625f;
        } else {
            w = 0.625f;
        }
        *(f32 *)(p + 0x68) = w;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) {
            v = 20.0f;
        } else {
            v = -20.0f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) {
            w = -0.625f;
        } else {
            w = 0.625f;
        }
        *(f32 *)(p + 0x68) = w;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
}

void func_002CF010(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_002CEC90(p);
    if ((s8)p[0x151] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
    }
}
