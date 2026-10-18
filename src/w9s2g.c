typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct { s32 w[16]; } B64;
extern s32 D_004C2B38[2], D_004C2B40[2];
extern B64 *D_004C2B48[2];
extern B64 D_006327B0[];
s32 func_00416CC0(s32 n) {
    D_004C2B38[0] -= n;
    if (D_004C2B38[0] < 0) {
        D_004C2B38[0] = 0;
        return 0;
    }
    D_006327B0[D_004C2B40[0]] = D_004C2B48[0][D_004C2B38[0]];
    return 1;
}
