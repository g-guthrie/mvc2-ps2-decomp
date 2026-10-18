typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[3]; } E_17CD50;
typedef struct { E_17CD50 e[1]; } G_17CD50;
extern G_17CD50 *D_004C2794;
void func_0017CD50(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    extern void func_00186CE0();
    f32 *v1, *a3, *t0, *t1;
    u32 i;
    s32 k;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t1 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)v1 = 0;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
        *(u32 *)t1 = 0;
        func_001757E0(p, 0, 0);
        func_00183d50(p);
        i = p[2];
        k = ((u8 *)D_004C2794->e[i].w[6])[5];
        if (k >= 2) { func_00186CE0(p, 0); } else { (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x48))(p); }
    }
}
