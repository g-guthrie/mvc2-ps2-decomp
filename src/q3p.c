typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_006337A0[];

void func_0041D1D0(s16 idx) {
    u8 *p;
    u8 *q;
    if (idx < 0 || idx >= 0x38) return;
    p = D_006337A0[idx];
    p[5] = 1;
    p[4] = 1;
    *(f32 *)(p + 0x80) = 1.0f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x78) = 1.0f;
    *(f32 *)(p + 0x3C) = -12.85000038f;
    *(f32 *)(p + 0x54) = 1.299999952f;
    *(f32 *)(p + 0x50) = 1.299999952f;
    q = *(u8 **)(D_006337A0[idx] + 0xD8);
    if (q != 0) {
        *(f32 *)(q + 0x3C) = -12.84500027f;
        *(f32 *)(q + 0x54) = 1.399999976f;
        *(f32 *)(q + 0x50) = 1.399999976f;
    }
}

typedef struct { u8 pad[0x160]; s8 b[8]; } S160;
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern s8 func_00175700(u8 *p);
extern void func_001843A0(u8 *p);
extern void func_001E3710(u8 *p, s32 a);

void func_001EF450(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
        switch (p[6]) {
        case 0:
            if (func_00175700(p) < 0) func_001843A0(p);
            break;
        case 1:
            if (func_00175700(p) < 0) {
                func_001843A0(p);
            } else {
                s8 *q = ((S160 *)p)->b;
                s8 f = q[1];
                s8 *r = q + 1;
                if (f != 0) {
                    *r = 0;
                    D_004F1F45 = 1;
                    D_004F1F46 = 1;
                    func_001E3710(p, 0x2C);
                }
                if (((s8 *)p)[0x151] != 0) {
                    p[0x151] = 0;
                    *(s16 *)(p + 0x140) ^= 1;
                }
            }
            break;
        }
        break;
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            if (((s8 *)p)[0x151] != 0) {
                if (p[0x1E6] != 0) *(f32 *)(p + 0x34) += 6.6666665f;
                else *(f32 *)(p + 0x34) -= 6.6666665f;
            }
            if (p[0x15B] != 0) {
                func_001E3710(p, 0x16);
                p[0x15B] = 0;
            }
        }
        break;
    }
}
