typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_b;
extern G_b *D_004C2794;
extern s32 D_00455ABC[];

void func_002837D0(u8 *p) {
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *a, *b;
    u32 k;
    f32 *c, *d;
    s32 v;
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
    v = *(s8 *)(p + 0x151);
    if (v != 0) {
        s8 w = v;
        p[0x1B5] = *(s8 *)((u8 *)D_00455ABC + ((w >> 1) << 2));
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x151] = 0;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
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
