typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { float x, y, z; } V3;
typedef struct { u8 pad[0x34]; f32 f34, f38, f3c, pad2[0x7]; f32 f5c, f60, f64, f68, f6c; } FS;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } GB;

extern GB *D_004C2794;
extern void func_0026DF70(u8 *);
extern void func_00175700();
extern s32 func_001757E0(u8 *, s32, s32);
extern u8 *func_001B5FA0(u8 *, s32);

void func_0026DFE0(u8 *p)
{
    u8 *q = p + 0x2B8;
    V3 v;
    u8 *o;
    f32 c;
    func_0026DF70(p);
    func_00175700();
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        q[6] = 0;
        p[0x209] = 3;
        q[1] = 0;
        p[0x20D] = 2;
        if (p[0x1B7] == 0) {
            func_001757E0(p, 0x15, 0xC);
            *(s16 *)(p + 0x1C) = 0x20;
            *(s16 *)(p + 0x1E) = 0x1B;
            *(u32 *)(p + 0x60) = 0x41892492;
            v = *(V3 *)(p + 0x34);
            c = 266.6666564941406f;
            if (*(s16 *)(p + 0x140) == 0) c = -c;
            v.x += c;
            *(float *)(p + 0x64) = v.x;
        } else {
            func_001757E0(p, 0x15, 0xF);
            *(s16 *)(p + 0x1C) = 0x18;
            *(s16 *)(p + 0x1E) = 0x13;
            *(u32 *)(p + 0x60) = 0x414DB6DB;
            v = *(V3 *)(p + 0x34);
            c = 400.0f;
            if (*(s16 *)(p + 0x140) == 0) c = -c;
            v.x += c;
            *(float *)(p + 0x64) = v.x;
        }
        o = func_001B5FA0(p, 0);
        if (o) *(V3 *)(o + 0x34) = *(V3 *)(p + 0x34);
        o = func_001B5FA0(p, 1);
        if (o) *(V3 *)(o + 0x34) = v;
        *(float *)(p + 0x38) += 171.42855834960938f;
        c = 160.0f;
        if (*(s16 *)(p + 0x140) == 0) c = -c;
        *(float *)(p + 0x34) += c;
        v.y += 90.0f;
        c = -26.66666603088379f;
        if (*(s16 *)(p + 0x140) == 0) c = -c;
        v.x += c;
        *(float *)(p + 0x5C) = (v.x - *(float *)(p + 0x34)) / 32.0f;
        *(u32 *)(p + 0x68) = 0;
        {
            FS *fs = (FS *)p;
            float w = (v.y - fs->f38) / 32.0f;
            fs->f6c = (2.0f * w - 2.0f * fs->f60) / 32.0f;
        }
    }
}
