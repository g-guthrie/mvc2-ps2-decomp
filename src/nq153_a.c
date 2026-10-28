typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct {u8 pad[0x7C];s16 f7c[];} G3c;
extern G3c *D_004C2794 __attribute__((section(".sdata")));

static inline void reset_action(u8 *p, u8 *q) {
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 {s16 *c = (s16*)((*q << 1) + (u32)D_004C2794); c[0x3E]++;}
}

void func_0039F8D0(u8 *a, u8 *b) {
    extern void func_001757E0(u8 *, s32, u8);
    extern s32 func_00174170(void);
    u32 t;
    s32 v;
    u8 *q;
    q = a + 2;
    t = a[4];
    a[4] = t + 1;
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x42;
    a[0x1B5] = 0x5B;
    reset_action(a, q);
    *(B3c *)(a + 0xEC) = *(B3c *)(b + 0xEC);
    a[0x13C] = 1;
    *q = b[2];
    a[1] = b[1];
    *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
    a[0x1B7] = b[0x1B7];
    a[0x1B8] = b[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
    *(V3 *)(a + 0x50) = *(V3 *)(b + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    a[0x13C] = 0;
    if (a[0x21] == 0) {
        u8 *o;
        s16 d;
        s32 c;
        s8 e;
        e = 0;
        if (a[0x20]) e = 7;
        *(s8 *)(a + 0x24) = e;
        o = *(u8 **)(b + 0x220);
        *(f32 *)(a + 0x34) = *(f32 *)(o + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(o + 0x430);
        c = 0x58;
        if (*(s16 *)(a + 0x140)) c = -0x58;
        *(f32 *)(a + 0x34) += 1.6666666269302368f * (f32)c;
        d = a[0x20] << 5;
        if (a[0x20]) d = -d;
        *(f32 *)(a + 0x34) += 1.6666666269302368f * (f32)d;
        v = 0x13;
    } else {
        a[5] = 1;
        *(s16 *)(a + 0x1C) = 0x3C;
        v = 0x14;
    }
    func_001757E0(a, 0x17, v);
    b[0x152] = (func_00174170() & 3) + 1;
}
