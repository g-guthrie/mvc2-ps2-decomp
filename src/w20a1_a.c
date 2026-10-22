typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F46[];
extern u8 D_004F1F45[];

void func_00243360(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00158C70(f32 *, s32);
    extern void func_001E3A40(u8 *);
    extern void func_00126400(void);
    u8 *q;
    s32 *z0, *z1;
    f32 v[4];
    s32 r;
    u32 t;

    if (p[7] == 0) {
        func_00175700(p);
        z0 = (s32 *)(p + 0x60);
        z1 = (s32 *)(p + 0x6C);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            t = p[7];
            p[7] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            *z0 = 0;
            *z1 = 0;
            func_001757E0(p, 0xF, 3);
        }
    } else {
        if ((s8)func_00175700(p) < 0) {
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 2;
            q[0x1E6] = p[0x1E6];
            *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140);
            q[0x20D] = 2;
            q[0x1B5] = 0x22;
            v[0] = *(f32 *)(q + 0x34);
            v[1] = *(f32 *)(q + 0x430);
            func_00158C70(v, q[2]);
            func_001E3A40(p);
            func_00126400();
            D_004F1F46[0] = 1;
            D_004F1F45[0] = 2;
            t = p[6];
            p[6] = t + 1;
            p[7] = 0;
            p[0x20D] = 2;
            *(u32 *)(p + 0x5C) = 0x40A00000;
            *(u32 *)(p + 0x68) = 0xBD200000;
            *(u32 *)(p + 0x60) = 0x41960000;
            *(u32 *)(p + 0x6C) = 0xBF5EDB6D;
            if (p[0x1E6] != 0) {
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            }
            func_001757E0(p, 0xF, 4);
        }
    }
}
