typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa19_d.c "-O3 -Op -sdatathreshold 8" */
typedef struct { f32 f0; u8 pad[8]; s16 fc; } T_d;
extern T_d *D_004C2974;
extern u8 *D_004C2978;

void func_00367920(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018D9A0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern int func_00174470(const void *);
    extern void func_00367F60(u8 *);
    extern void func_001E7F60(u8 *);
    f32 v;
    s16 h;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        if (*(s8 *)(p + 0x1B3) != 0) {
            func_0018D9A0(p);
            func_001E3210(p, 0x2C);
            func_001E3210(p, 0x30);
        }
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
        if (*(s16 *)(p + 0x140) != 0) {
            v = -5.0f;
        } else {
            v = 5.0f;
        }
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(f32 *)(p + 0x38) = D_004C2974->f0;
        func_001757E0(p, 0x17, 0xC);
        return;
    }
    if (func_00174470(p) == 0) {
        D_004C2978[2] = 0;
        func_00367F60(p);
    } else {
        h = D_004C2974->fc - 1;
        D_004C2974->fc = h;
        if (h == 0) {
            D_004C2974->fc = 0xB4;
            func_001E3210(p, 0x31);
        }
        func_001E7F60(p);
    }
}
