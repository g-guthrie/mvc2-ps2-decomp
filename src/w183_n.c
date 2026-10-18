typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 pad1[0x16]; s16 a; u8 pad2[0x28]; u32 w48; } PN;

void func_0015B8B0(PN *p) {
    extern void func_0015BA00(PN *);
    extern s32 func_00118FA8(f32);
    *(u8 *)((s32)p + 0x13C) = 1;
    func_0015BA00(p);
    if (p->b5 != 0) {
        f32 c = 10.0f; f32 d = (f32)p->a; p->a = func_00118FA8(d + c);
        if (p->a >= 0) {
            p->a = 0;
            p->b4 = 0;
        }
        p->w48 = (u16)(0.5 + 65536.0 * (double)p->a / 360.0);
    } else {
        p->a = func_00118FA8((f32)p->a - 10.0f);
        if (p->a < -179) {
            p->a = -180;
            p->b4 = 0;
        }
        p->w48 = (u16)(0.5 + 65536.0 * (double)p->a / 360.0);
    }
}
