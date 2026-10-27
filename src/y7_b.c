typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_004000D0(s32 a0);



void func_0020E480(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001266A0();
    extern void func_001843A0();
    s8 r;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    r = func_00175700(p);
    if (r < 0) {
        func_001266A0(p, 0, 0);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

u8 *func_0037DC60(u8 *a, u8 *b) {
    extern u8 *func_003DA750();
    extern void func_0037DCD0();
    u8 *o;
    if ((o = func_003DA750(0, 1, 1)) != 0) {
        *(void **)(o + 0x10) = func_0037DCD0;
        *(u8 **)(o + 0x18) = b;
        *(s16 *)(o + 0x26) = 0x1705;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        o[0x23] = a[0x23];
    }
}

extern f32 D_004F2000, D_004C9F48, D_004C9F44, D_004F1FFC, D_004F1F98, D_004F1F9C;

void func_00274FB0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    f32 z = 0.0f;
    f32 *q, *r;
    s16 v;
    func_00175700(p);
    q = (f32 *)(p + 0x5C);
    r = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *q = z;
        *r = z;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x168] = 2;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}
