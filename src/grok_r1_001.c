typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_004D18A0;
extern u8 D_00583B9B;
extern u8 D_00583B90[];
extern u8 D_004D17C9;
extern s32 D_004F1CB8;
extern s32 D_004F1CB0;
extern float D_004F1D0C;
extern float D_004F1D10;
extern float D_004F1D14;
extern float D_004F1CAC;
extern void func_003DAA40(u8 *);
extern void func_00151650(u8);
extern void func_00417A50(float, float, float);
extern void func_00414C70(float);
extern s32 func_00119098(float value);
extern void func_003DF850(s32 index, s32 value);
extern s32 func_0010ADC0(void);
extern s32 func_0010B360(s32, s32, s32);
extern s32 func_0010BBD8(s32, s32, s32, s32);
extern s32 func_0016B0C0(s32, s32, s32);


void func_00134120(u8 *p, u8 *owner_unused) {
    if (D_004D18A0) {
        p[5] = 0;
        p[0x20] = 0;
        p[0x21] = 0;
    }
}

void func_0013C5A0(u8 *p) {
    D_00583B9B = 2;
    func_003DAA40(p);
}

void func_0013A480(u8 *p) {
    D_00583B90[p[0x20]] = 5;
    func_003DAA40(p);
}

void func_00151640(void) { func_00151650(D_004D17C9); }




void func_001532F0(void) {
    func_00417A50(D_004F1D0C, D_004F1D10, D_004F1D14);
}

void func_0016F0C0(float x) {
    D_004F1CAC = x;
    func_00414C70(x);
}

void func_00414C70(float value) {
    s32 alpha = func_00119098(255.0f * value);
    u32 color = (((u32)alpha & 0xff) << 24) | 0x00ffffff;
    func_003DF850(14, (s32)color);
}


void func_0010AE38(void) { if (func_0010ADC0()) return; }
void func_0010B950(s32 a, s32 b, s32 c) { if (func_0010B360(a, b, c)) return; }
void func_0010BCE0(s32 a, s32 b, s32 c) { if (func_0010BBD8(a, b, c, 1)) return; }
