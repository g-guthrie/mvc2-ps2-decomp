typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; u8 b4; u8 pad5[0x17]; s16 h1c; u8 pad1e[0x2a]; s32 w48; } S4;
static s32 func_0015BA00(S4 *p) { return p->h1c > 0; }
void func_0015BC90(S4 *p, u8 *q) {
    extern void func_0015BD40();
    *(u8 *)((u8 *)p + 0x13C) = 1;
    if (func_0015BA00(p) != 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        func_0015BD40();
    } else {
    s16 h = *(s16 *)(q + 0x140); p->h1c = h ? 0 : -180;
    p->w48 = (u16)(65536.0 * p->h1c / 360.0 + 0.5);
    }
}

