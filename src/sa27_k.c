typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 h1C;
    s16 h1E;
    u8 pad20[0x5C - 0x20];
    u32 w5C;
    u32 w60;
    u8 pad64[4];
    u32 w68;
    u32 w6C;
    u8 pad70[0x151 - 0x70];
    s8 b151;
    u8 pad152[0x1DC - 0x152];
    u8 *w1DC;
    u8 pad1E0[0x1FE - 0x1E0];
    u8 b1FE;
    u8 pad1FF[2];
    u8 b201;
    u8 pad202[0x304 - 0x202];
    u32 w304;
    u8 pad308[0x33C - 0x308];
    u8 b33C;
    u8 pad33D[0x40C - 0x33D];
    u8 b40C;
} A29;

void func_0029DB50(A29 *p)
{
    extern void func_00175700(A29 *);
    extern void func_001757E0(A29 *, s32, s32);
    extern void func_001CB610(A29 *, s32);
    extern void func_0018FDB0(A29 *);
    extern void func_00191480(u8 *, A29 *, s32);
    extern void func_001548D0(A29 *, u32 *, s32);
    extern s32 func_00174170(void);
    extern void func_00178F20(A29 *, u8 *);
    u32 v[4];
    s16 h;
    p->b40C = 2;
    p->b33C = 5;
    p->b1FE = 1;
    p->b201 = 2;
    func_00175700(p);
    h = p->h1C - 1;
    p->h1C = h;
    if (h < 0) {
        if (p->h1E == 0) {
            p->h1C = 0x3F;
            p->h1E = p->h1E + 1;
            func_001757E0(p, 0x16, 5);
            func_001CB610(p, 3);
            p->w304 = 0x21;
        } else {
            u32 t;
            p->w304 = 0x22;
            t = p->b6;
            p->b6 = t + 1;
            p->h1C = 0x3F;
            func_001757E0(p, 0x16, 6);
            p->w5C = 0;
            p->w68 = 0;
            p->w60 = 0x40CDB6DB;
            p->w6C = 0xBD892492;
        }
    } else if (p->b151 != 0) {
        p->b151 = 0;
        *(u8 **)(p->w1DC + 0x1C8) = (u8 *)p;
        if (p->h1E == 0)
            p->w1DC[0x1B5] = 0x3A;
        else
            p->w1DC[0x1B5] = 0x3B;
        func_0018FDB0(p);
        func_00191480(p->w1DC, p, 1);
        if (p->h1E != 0) {
            v[0] = 0xC2700000;
            v[1] = 0x42F00000;
            func_001548D0(p, v, 3);
        } else {
            s32 r = func_00174170() & 7;
            v[0] = 0xC2F6AAAA;
            v[1] = 0x42F00000;
            func_001548D0(p, v, r + 9);
        }
    }
    func_00178F20(p, p->w1DC);
}
