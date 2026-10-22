typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C23C4;
extern f32 D_004C2400;
extern s32 D_004C22C4;
extern s32 D_004C23FC;
extern s32 D_004C23D0;
extern u8 D_004BC070[];

void func_00401B78(u8 *o, s32 *a, s32 *b)
{
    extern void func_003FB128(u8 *);
    extern void func_00401A48(u8 *, s32 *, s32 *);
    extern void func_00401B68(void);
    extern s32 func_003FFFF0(s32);
    extern s32 func_003FFF78(s32);
    extern s32 func_003FFFA8(s32);
    s32 w, h;
    f32 d;
    s32 t;
    s32 r;
    u32 c;
    u8 ty;
    s32 g;

    if (o == 0 || a == 0 || b == 0) {
        func_003FB128(D_004BC070);
        return;
    }
    if (D_004C23C4 == 0) {
        func_00401A48(o, a, b);
        return;
    }
    ty = o[1];
    D_004C2400 = 0;
    if ((u32)(ty - 3) < 2) {
        if (*(s8 *)(o + 0x72) == 0)
            *a = (D_004C22C4 - *(s32 *)(o + 0xA0)) * 100 + *(s32 *)(o + 0x9C);
        else
            *a = *(s32 *)(o + 0x9C);
        func_00401A48(o, &w, &h);
        d = (f32)w / (f32)h - (f32)*a / (f32)D_004C23FC;
        D_004C2400 = d * 1000.0f;
        if (D_004C2400 > 60.0f || D_004C2400 < -60.0f) {
            if (D_004C23D0 == 1) {
                t = D_004C23C4;
                D_004C23C4 = 0;
                func_00401B78(o, &w, &h);
                D_004C23C4 = t;
                func_00401B68();
            }
            c = (u32)((f32)w / (f32)h * (f32)D_004C23FC);
            g = D_004C22C4;
            *(u32 *)(o + 0x9C) = c;
            *(s32 *)(o + 0xA0) = g;
        }
    } else if ((s8)ty == 5) {
        w = func_003FFFF0(*(s32 *)(o + 4));
        h = func_003FFF78(*(s32 *)(o + 4));
        r = func_003FFFA8(*(s32 *)(o + 4));
        w = w * (16 / r);
        *a = (s32)((f32)w / (f32)h * (f32)D_004C23FC);
        *a = *a + *(s32 *)(o + 0x9C) + 1;
    } else {
        *a = 0;
    }
    *a += *(s32 *)(o + 0x88);
    *b = D_004C23FC;
}
