typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x1C - 5];
    s16 h1C;
    u8 pad1E[0x44 - 0x1E];
    u32 w44;
    u8 pad48[0x54 - 0x48];
    f32 f54;
    u8 pad58[0x60 - 0x58];
    f32 f60;
} S335;

extern double func_00119058(f32);
extern void func_003DAA40(void);

void func_00335830(S335 *p) {
    u8 *owner = *(u8 **)((u8 *)p + 0x18);
    if (owner[4] == 2)
        func_003DAA40();
    p->h1C++;
    p->w44 = (u32)(0.5 + 65536.0 * func_00119058(p->f60) / 360.0) & 0xFFFF;
    p->w44 += (u32)(0.5 + 65536.0 * func_00119058(p->f54 * (f32)p->h1C) / 360.0) & 0xFFFF;
    if (p->h1C > 200) {
        p->h1C = 0;
        p->b4 = 0;
    }
}
