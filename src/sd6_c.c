typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* sd6_c: MW 3.0.3: ./try.sh src/sd6_c.c "-O3 -Op -sdatathreshold 8" */
void func_002846E0(u8 *p) {
    extern void func_00175700();
    extern void func_002848D0();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *a, *b;
    u32 k;
    f32 *c, *d;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(f32 *)(p + 0x60) < 0.0f) {
        *(u32 *)(p + 0x6C) = 0xBF892492;
    } else {
        *(s16 *)(p + 0x1C) = 0;
    }
    func_00175700(p);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    k = p[0x1E6];
    if ((k == 0 && !(*(f32 *)(p + 0x5C) <= 0.0f)) || (k != 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        *(u32 *)a = 0;
        *(u32 *)c = 0;
    }
    func_002848D0(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x1A);
    }
}
