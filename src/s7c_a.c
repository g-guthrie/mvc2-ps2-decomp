/* func_00149020: MW 3.0.3 -O4 -Op -sdatathreshold 8; switch table @N -> jtbl_004B3830 (objcopy --redefine-sym) */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern f32 D_00443BB0[], D_00443BB4[], D_00443BC0[], D_00443BC4[];
extern f32 D_004F7FD0[], D_004F7FD4[];
extern f32 D_00443AF0[], D_00443AF4[], D_00443B00[], D_00443B04[];
extern f32 D_00443B10[], D_00443B14[], D_00443B20[], D_00443B24[];
extern f32 D_00443B30[], D_00443B34[], D_00443B40[], D_00443B44[];
extern f32 D_00443B50[], D_00443B54[], D_00443B60[], D_00443B64[];
extern f32 D_00443B70[];
extern s8 D_004F7D10[];
extern u8 D_004B36E0[];
typedef struct { u8 pad[0xE]; s16 hE; } G2840;
extern G2840 *D_004C2840;

void func_00149020(void)
{
    extern void func_00123090();
    extern void func_00417AE0(s32, f32 *);
    f32 *v;
    s32 i;
    s8 *e;
    u8 *t;

    func_00123090();

    D_00443B00[0] = D_00443AF0[0] = 320.0f - D_00443BB0[0] / 2.0f + D_004F7FD0[0];
    D_00443B20[0] = D_00443B10[0] = 320.0f + D_00443BB0[0] / 2.0f + D_004F7FD0[0];
    D_00443B14[0] = D_00443AF4[0] = 240.0f - D_00443BB4[0] / 2.0f + D_004F7FD4[0];
    D_00443B24[0] = D_00443B04[0] = 240.0f + D_00443BB4[0] / 2.0f + D_004F7FD4[0];
    func_00417AE0(4, D_00443AF0);

    {
        f32 a, b, c, d;
        a = 320.0f - D_00443BC0[0] / 2.0f + D_004F7FD0[0];
        b = 320.0f + D_00443BC0[0] / 2.0f + D_004F7FD0[0];
        c = 240.0f - D_00443BC4[0] / 2.0f + D_004F7FD4[0];
        d = 240.0f + D_00443BC4[0] / 2.0f + D_004F7FD4[0];
        D_00443B30[0] = a;
        D_00443B40[0] = a;
        D_00443B50[0] = b;
        D_00443B60[0] = b;
        D_00443B34[0] = c;
        D_00443B54[0] = c;
        D_00443B44[0] = d;
        D_00443B64[0] = d;
    }
    func_00417AE0(4, D_00443B30);

    v = D_00443B70;
    for (i = 0; i < 2; i++) {
        e = D_004F7D10 + i * 16;
        switch (e[0]) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        case 10: case 11:
            e[0xC] += e[4 + e[0]];
            break;
        case 8:
            e[0xC] += e[2];
            break;
        case 9:
            e[0xC] += e[3];
            break;
        }
        t = D_004B36E0 + e[0xC] * 8;
        v[0] = v[8] = D_004F7FD0[0] + 4.0f * (f32)(t[0] + i * 0x35) - 4.0f;
        v[4] = v[12] = 8.0f + (D_004F7FD0[0] + 4.0f * (f32)(t[2] + i * 0x35));
        v[1] = v[5] = D_004F7FD4[0] + 16.0f * (f32)(e[0] + 11) - 2.0f - 16.0f;
        v[9] = v[13] = 1.0f + (16.0f + (D_004F7FD4[0] + 16.0f * (f32)(e[0] + 11))) - 16.0f;
        if (D_004C2840->hE == 8) {
            func_00417AE0(4, v);
        }
    }
}
