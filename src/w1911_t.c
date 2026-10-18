typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { u8 pad[0x91]; u8 b91; } Cfg;
typedef struct { u16 h0; u8 pad[18]; } Ent20;
extern Cfg *D_004C2840;
extern void (*D_00477390[])(u8 *, s32);
extern Ent20 D_004F4480[];
extern u8 D_004B9358[];
extern void func_003D4630(void);
extern void func_003D3750(void);
void func_003D44E0(u8 *p) {
    extern void func_003D7350(s32, s32, s32, u8 *, s32);
    extern void func_003D7310(void (*)(void));
    s32 s0;
    s32 v;
    s16 h;
    D_004C2840->b91 = 1;
    p[0x18] = 0;
    v = *(s8 *)(p + 0xC);
    if (v == 0) {
        h = *(s16 *)(p + 0xA);
        if (h != 0) *(s16 *)(p + 0xA) = h - 1;
        else p[0xC] = v + 1;
    } else {
        s0 = 0;
        if (*(s8 *)p != 1) s0 = 1;
        D_00477390[*(s8 *)(p + 0xD)](p, s0);
        if (*(s8 *)(p + 0xC) != 0) {
            func_003D7350(0x44, 0x28, (u8)(s0 + 0x20), D_004B9358, s0 + 1);
        }
        if (D_004F4480[s0].h0 != 0) {
            p[2] = 0;
            *(s16 *)(p + 8) = 0x4650;
        }
        if (*(s16 *)(p + 8) != 0) {
            *(s16 *)(p + 8) = *(s16 *)(p + 8) - 1;
        } else {
            if (p[2] != 0x60) p[2] = p[2] + 1;
        }
        if (*(s8 *)(p + 0xC) != 0) func_003D7310(func_003D4630);
    }
    func_003D7310(func_003D3750);
}
