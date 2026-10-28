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
    u8 b5;
    u8 b6;
    u8 pad7[0x1E - 7];
    s16 h1E;
    u8 pad20[0x44 - 0x20];
    u32 w44;
    u8 pad48[0x54 - 0x48];
    f32 f54;
    u8 pad58[0x60 - 0x58];
    f32 f60;
    u8 pad64[0x6C - 0x64];
    f32 f6C;
    u8 pad70[0x84 - 0x70];
    s32 w84;
    u8 pad88[0xCC - 0x88];
    s16 hCC;
} S335400;

extern f32 D_004B7F68[];
extern s16 D_004B7F70[][2];
extern s32 D_004C283C;

void func_00335400(S335400 *p) {
    extern void func_00335540(S335400 *);
    f32 k;
    u32 t;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (double)(p->f60 = D_004B7F68[p->b5]) / 360.0) & 0xFFFF;
    k = 200.0f;
    t = p->b5;
    p->b5 = t + 1;
    p->b5 &= 1;
    p->f6C = D_004B7F68[p->b5];
    p->f54 = (p->f6C - p->f60) / k;
    p->h1E++;
    if (p->h1E > 9) {
        p->h1E = 0;
        t = p->b6;
        p->b6 = t + 1;
        p->b6 &= 3;
        p->hCC = D_004B7F70[p->b6][0];
        p->w84 = D_004C283C;
    }
    p->b4 = 1;
    func_00335540(p);
}

void func_003356F0(S335400 *p) {
    extern void func_00335830(S335400 *);
    f32 k;
    u32 t;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (double)(p->f60 = D_004B7F68[p->b5]) / 360.0) & 0xFFFF;
    k = 200.0f;
    t = p->b5;
    p->b5 = t + 1;
    p->b5 &= 1;
    p->f6C = D_004B7F68[p->b5];
    p->f54 = (p->f6C - p->f60) / k;
    p->h1E++;
    if (p->h1E > 9) {
        p->h1E = 0;
        t = p->b6;
        p->b6 = t + 1;
        p->b6 &= 3;
        p->hCC = D_004B7F70[p->b6][0];
        p->w84 = D_004C283C;
    }
    p->b4 = 1;
    func_00335830(p);
}
