typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700();
void func_001AADC0(u8 *p, u8 *q) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(q + 0x430) < *(f32 *)(p + 0x38))) {
        p[7] = 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_00175700(p, q);
    }
}



extern void func_003C5780(u8 *p);
extern void func_001E7F60(u8 *p);
void func_003C6540(u8 *p) {
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[5];
        p[5] = t + 1;
        *(u8 *)(p + 0x151) = 0;
        func_003C5780(p);
    } else if (*(s8 *)(p + 0x1B3) == 0) {
        func_001E7F60(p);
    }
}


extern void (*D_004536D0[])(u8 *);
void func_00257E30(u8 *p) {
    u8 *e = *(u8 **)(p + 0x220);
    D_004536D0[p[7]](p);
    if (e[0x247] == 10 && *(u8 **)(e + 0x1C8) == p) e[0x24A] = 0;
}

extern u8 *func_003DA750();
extern void func_001D37D0();
extern s32 func_001745B0();
void func_003B5020(u8 *p) {
    u8 *r = *(u8 **)(p + 0x14);
    u8 *q = r + 0x88;
    if (r[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else if (*(s16 *)(p + 0x1E) <= *(s16 *)(q + 0x18)) {
        p[0x13C] = func_001745B0(p);
    }
}
