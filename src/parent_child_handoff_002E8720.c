typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern void func_0018FCA0(u8 *, s32);
extern void func_0018F9E0(u8 *, s32);
extern s32 func_00182E20(u8 *);
extern s32 func_00182D30(u8 *);
extern void func_00175C00(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_00126400(void);
extern int func_001757E0(u8 *, s32, s32);

void func_002E8720(u8 *p)
{
    u8 *child = *(u8 **)(p + 0x1DC);
    if ((s8)func_00175700(p) < 0) {
        func_0018FCA0(child, -3);
        if (*(s16 *)(child + 0x434) == 0)
            goto state_advance;
        func_0018F9E0(p, 2);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        f32 velocity = *(f32 *)(p + 0x60);
        if (velocity < 0.0f)
            velocity = -velocity;
        if (!(velocity < 2.9464285373687744f))
            *(f32 *)(p + 0x6C) = -*(f32 *)(p + 0x6C);
    }
    {
        s16 timer = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = timer;
        if (timer != 0) {
            if (func_00182E20(p) != 0)
                p[0x152] = 1;
            if (func_00182D30(child) == 0)
                return;
        }
    }
state_advance:
    {
        s32 completionType;
        p[6]++;
        p[7] = 0;
        *(s16 *)(p + 0x1C) = 0;
        func_00175C00(p, 0);
        func_001E3210(p, 0x2B);
        if (p[0x20D] != 2) {
            completionType = 0x21;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        } else {
            completionType = 0x25;
        }
        *(u8 **)(child + 0x1C8) = p;
        child[0x20A] = 1;
        child[0x24E] = 2;
        child[0x1E6] = p[0x1E6];
        child[0x20D] = 2;
        child[0x1B5] = completionType;
        func_00126400();
        p[0x22] = 0x18;
        *(u32 *)(p + 0x5C) = 0x40A00000;
        if (p[0x1E6] != 0) {
            p[0x22] = 8;
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x412B6DB6;
        *(u32 *)(p + 0x6C) = 0xBF700000;
        p[0x20D] = 2;
        func_001757E0(p, 0x0F, 0x0B);
    }
}
