typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G93;
extern G93 *D_004C2794;

void func_003C5840(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern u8 *func_003C4990(u8 *, u8, u8);
    extern void func_001E3210(u8 *, s32);
    extern void func_003C57E0(u8 *);
    extern void func_00183C40(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001E7F60(u8 *);
    extern void func_003C5780(u8 *);
    extern void func_003C5B20(u8 *, u8 *);
    u32 t;
    s32 v;
    switch (p[5]) {
    case 0:
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            p[6] = 0;
            *(s8 *)(p + 0x151) = 0;
            t = p[5];
            p[5] = t + 1;
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_003C4990(p, 8, 0);
            func_001E3210(q, 0x1B);
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x1B3) != 0) {
            func_003C57E0(p);
        } else {
            v = *(s8 *)(p + 0x1B4);
            if (v != 0) {
                *(s8 *)(p + 0x1B4) = v - 1;
                func_00183C40(p);
            } else {
                if (*(s8 *)(p + 0x1B2) != 0) {
                    v = *(s16 *)(p + 0x1C);
                    if (v != 0) {
                        *(s16 *)(p + 0x1C) = v - 1;
                        p[0x1B5] = 0x42;
                        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                        *(s32 *)(p + 0x1D8) = 0;
                        D_004C2794->f7c[p[2]]++;
                    }
                }
                func_00175700(p);
                *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
                *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
                *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
                t = p[6];
                if (t == 0) {
                    if (!(154.28570556640625f + *(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))) {
                        p[6] = t + 1;
                        func_001757E0(p, 0x15, 0x14);
                        func_001E3710(q, 0x1A);
                    }
                }
                if (!(*(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))) {
                    t = p[5];
                    p[5] = t + 1;
                    func_001757E0(p, 0x15, 0x15);
                }
                func_001E7F60(p);
            }
        }
        break;
    case 2:
        if (*(s8 *)(p + 0x1B3) != 0) {
            func_003C57E0(p);
        } else {
            func_00175700(p);
            if (*(s8 *)(p + 0x151) != 0) {
                *(s8 *)(p + 0x151) = 0;
                t = p[5];
                p[5] = t + 1;
                func_003C5780(p);
            } else if (*(s8 *)(p + 0x1B3) == 0) {
                func_001E7F60(p);
            }
        }
        break;
    case 3:
        func_003C5B20(p, q);
        break;
    }
}
