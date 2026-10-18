typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern void func_001E3710(u8 *, s32);
extern s32 func_0018AAC0(u8 *);
extern s32 func_001864A0(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
void func_00202860(u8 *p) {
    f32 oldVelocity;
    func_00175700(p);
    oldVelocity = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += oldVelocity;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x5C) > 0.0f) {
        if (oldVelocity < 0.0f)
            goto crossed_zero;
    }
    if (*(f32 *)(p + 0x5C) < 0.0f) {
        if (oldVelocity <= 0.0f)
            goto after_crossing;
    } else {
        goto after_crossing;
    }
crossed_zero:
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
after_crossing:
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        func_001E3710(p, 22);
    }
    if (func_0018AAC0(p) != 0) {
        if (*(s8 *)(p + 0x539) == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                p[0x152] = 1;
            }
        } else if (*(s8 *)(p + 0x151) != 0) {
            s8 stage;
            p[0x151] = 0;
            stage = *(s8 *)(p + 0x152);
            if (stage != 1)
                p[0x152] = stage - 1;
        }
    }
    if (func_001864A0(p) != 0) {
        p[6]++;
        func_001757E0(p, 15, 3);
    }
}
