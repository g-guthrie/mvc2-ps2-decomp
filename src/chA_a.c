typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

typedef struct { u8 c[4]; f32 f4; f32 f8; f32 fC; } Glyph;
typedef struct { f32 x, y, z, w; } V4;
typedef struct { f32 u, v; } V2;

extern Glyph D_004B4F40[];
extern u32 D_00446460[];
extern s8 *D_004C2840;
extern f32 D_004F7FD0[], D_004F7FD4[];
extern f32 D_004CB140[], D_004CB144[], D_004CB148[], D_004CB14C[];
extern f32 D_004CB150[], D_004CB154[], D_004CB158[], D_004CB15C[];
extern f32 D_004CB160[], D_004CB164[], D_004CB168[], D_004CB16C[];
extern u32 D_004CB170[], D_004CB174[], D_004CB178[];
extern f32 D_004CB17C[], D_004CB180[], D_004CB184[], D_004CB188[], D_004CB18C[], D_004CB190[];
extern f32 D_004CB194[], D_004CB19C[], D_004CB1A0[];
extern f32 D_004CB1A4[], D_004CB1AC[], D_004CB1B0[];
extern f32 D_004CB1B4[], D_004CB1B8[], D_004CB1BC[], D_004CB1C0[];
extern u32 D_004CB1C4[], D_004CB1C8[], D_004CB1CC[];
extern f32 D_004CB1D0[], D_004CB1D8[], D_004CB1E0[], D_004CB1E4[];
extern u8 D_0058C7A0[];

void func_0016D4B0(u8 *p, s32 flag, f32 z) {
    extern f64 func_00119058(f32);
    extern f64 func_00119858(f64, f64);
    extern f64 func_00119510(f64, f64);
    extern f32 dptofp(f64);
    extern void func_003DF0C0(f32 *);
    extern void func_00420BF0(u8 *, f32 *);
    u8 *q;
    Glyph *e;
    u32 *tbl;
    f32 x, y, w, k;
    u32 c;
    u8 ch;
    u8 n;
    f64 h;

    q = p + 4;
    while (*q) q++;
    e = &D_004B4F40[*(u16 *)(p + 2)];
    q = p + 4;
    tbl = D_00446460;
    x = e->f8 * (f32)p[0];
    y = e->f8 * (f32)p[1];
    y -= 16.0f;
    if (D_004C2840[0x4C] != 5 || D_004C2840[0] != 2 || D_004C2840[1] != 1 ||
        D_004C2840[2] != 2 || D_004C2840[3] != 3) {
        x += D_004F7FD0[0];
        y += D_004F7FD4[0];
    }
    D_004CB160[0] = x;
    D_004CB140[0] = x;
    x += e->f4 * e->fC;
    D_004CB1B4[0] = x;
    D_004CB150[0] = x;
    D_004CB154[0] = y;
    D_004CB144[0] = y;
    y += e->f4;
    D_004CB1BC[0] = z;
    D_004CB1B8[0] = y;
    D_004CB1AC[0] = z;
    D_004CB19C[0] = z;
    D_004CB168[0] = z;
    D_004CB164[0] = y;
    D_004CB158[0] = z;
    D_004CB1C0[0] = 1.0f;
    D_004CB1B0[0] = 1.0f;
    D_004CB1A0[0] = 1.0f;
    D_004CB16C[0] = 1.0f;
    D_004CB15C[0] = 1.0f;
    D_004CB14C[0] = 1.0f;
    D_004CB148[0] = z;
    D_004CB170[0] = tbl[e->c[0]];
    D_004CB174[0] = tbl[e->c[1]];
    D_004CB178[0] = tbl[e->c[2]];
    D_004CB1CC[0] = tbl[e->c[2]];
    *(V4 *)D_004CB194 = *(V4 *)D_004CB150;
    *(V4 *)D_004CB1A4 = *(V4 *)D_004CB160;
    D_004CB1C4[0] = D_004CB174[0];
    D_004CB1C8[0] = D_004CB178[0];
    while ((ch = *q) != 0) {
        c = ch;
        if (c == 0x5E) {
            q++;
            c = *q;
            ch = c + 0x3C;
            if (c == 0x5A) ch = 0x5C;
        }
        n = ch; n -= 0x20;
        w = (f32)(n & 0xF) / 16.0;
        D_004CB18C[0] = w;
        D_004CB17C[0] = w;
        w = w + e->fC / 16.0;
        D_004CB1E0[0] = w;
        D_004CB184[0] = w;
        w = (f32)(n >> 4) / 16.0f;
        D_004CB188[0] = w;
        D_004CB180[0] = w;
        D_004CB1E4[0] = w + 0.0625f;
        D_004CB180[0] += 0.002f;
        D_004CB188[0] += 0.002f;
        D_004CB190[0] = w + 0.0625f;
        *(V2 *)D_004CB1D0 = *(V2 *)D_004CB184;
        *(V2 *)D_004CB1D8 = *(V2 *)D_004CB18C;
        if (flag == 0) {
            func_003DF0C0(D_004CB140);
            func_003DF0C0(D_004CB194);
        } else {
            func_00420BF0(D_0058C7A0, D_004CB140);
        }
        q++;
        k = 0.75f;
        D_004CB140[0] += k * e->f4;
        D_004CB150[0] += k * e->f4;
        D_004CB160[0] += k * e->f4;
        D_004CB194[0] += k * e->f4;
        D_004CB1A4[0] += k * e->f4;
        D_004CB1B4[0] += k * e->f4;
    }
}
