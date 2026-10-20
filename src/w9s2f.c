typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct { s32 w[16]; } B64;
extern s32 D_004C2B40[2];
extern B64 D_006327B0[];
extern void func_003DDC30(void *, f32);
void func_004172E0(u32 a) {
    func_003DDC30(&D_006327B0[D_004C2B40[0]], (f32)(6.283185307179586 * (s32)(u16)a / 65536.0));
}
