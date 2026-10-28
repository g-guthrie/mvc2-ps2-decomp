/* func_0016FAA0: MW 3.0.3 ./try.sh src/s6c_d.c "-O3,p -sdatathreshold 8". Landed by a combined shape+declaration search: E5 * typed entity pointer, ONE named result local r1 reused for both func_00416180 results, a separate h2 for the second table load, D_004BF490[i] written inline (no index pointer), decl order e, r1, h, h2, i, base, k. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C28B8;
extern u8 *D_004C28AC;
extern u8 *D_004C2840;
extern s32 D_004C28B0;
extern s32 D_004C2834;
extern u8 D_004BF498[8];
extern u8 D_004BF490[8];
typedef struct { u8 b[0x5B8]; } E5;
extern E5 D_004F20B0[];

typedef struct { s32 a, b, c, d; } A4;
typedef struct { s32 w0, w1; s32 *pp; s32 w3; s32 x[4]; } Buf;

void func_0016FAA0(void) {
    extern s32 func_00416180(s32, s32);
    extern void func_00176230(s32, s32);
    extern void func_004161D0(Buf *, s32);
    extern void func_003DCDC0(s32, s32, s32);
    extern void func_0016F530(s32, s32, u8 *, u8 *, s32, A4 *);
    extern void func_0016F4D0(u8 *, u8 *);
    E5 *e;
    s32 r1;
    s32 h;
    s32 h2;
    s32 i;
    u8 *base;
    s32 k;
    Buf buf;
    A4 arg;
    func_0016F4D0(D_004C28AC, base = D_004C28B8);
    i = 0;
    do {
        e = &D_004F20B0[i];
        if (*(s8 *)(D_004C2840 + 0x29) == 0) {
            k = 2;
        } else {
            s32 c = *(s8 *)((u8 *)e + 0x540);
            k = 2;
            if (c < 0x20) {
                if ((1 << c) & 0xD0010000) k = 4;
            } else {
                c -= 0x20;
                if ((1 << c) & 0x4000042) k = 4;
            }
        }
        func_00176230(func_00416180(*(s32 *)((u8 *)e + 0x194), 2), D_004C28B0);
        r1 = func_00416180(D_004C28B0, D_004BF498[*(s8 *)((u8 *)e + 0x4DD)]);
        h = *(s32 *)(base + D_004BF490[i] * 16 + 0xA8);
        func_004161D0(&buf, r1);
        func_003DCDC0(h, r1, *buf.pp);
        r1 = func_00416180(D_004C28B0, k);
        h2 = *(s32 *)(base + D_004BF490[i] * 16 + 0x108);
        func_004161D0(&buf, r1);
        func_003DCDC0(h2, r1, *buf.pp);
        i++;
    } while (i < 6);
    arg.a = 4;
    arg.b = 0x2F;
    arg.c = 0;
    arg.d = -1;
    func_0016F530(0xC90, D_004C2834, (u8 *)(u32)D_004C28AC, base, 6, &arg);
}
