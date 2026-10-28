typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

/* Camera shake channels: per-channel step ratio, alternating sign, step count. */
typedef struct { f32 ratio; s32 sign; s32 count; } Shk;
extern f32 D_004ACBE8[];
extern s32 D_004ACBF8[];
extern u8 D_004C25C8;
extern Shk D_004C2580[2];
extern f32 D_004C25CC;
extern f32 D_004F1F50[];
extern f32 D_004F1F98[];
extern u8 D_004F1F45[];

void func_001260E0(u8 a) {
    f32 *fp; s32 *ip;
    fp = D_004ACBE8; ip = D_004ACBF8;
    fp += a - 1; ip += a - 1;
    if (D_004C25C8 == 0) {
        D_004C2580[1].count = *ip;
        D_004C25C8 = 1;
        D_004C2580[1].sign = 1;
        D_004C25CC = *fp;
        D_004C2580[1].ratio = D_004C25CC / (f32)D_004C2580[1].count;
    }
    if (D_004C2580[1].count) {
        D_004C2580[1].count--;
        D_004F1F98[0] = D_004F1F50[0] = D_004F1F50[0] + D_004C2580[1].sign * D_004C25CC;
        D_004C2580[1].sign *= -1;
        D_004C25CC = D_004C25CC - D_004C2580[1].ratio;
    } else {
        D_004C25C8 = 0;
        D_004F1F45[0] = 0;
    }
}

void func_001261B0(u8 a) {
    f32 *fp; s32 *ip;
    fp = D_004ACBE8; ip = D_004ACBF8;
    fp += a - 1; ip += a - 1;
    if (D_004C25C8 == 0) {
        D_004C2580[0].count = *ip;
        D_004C25C8 = 1;
        D_004C2580[0].sign = 1;
        D_004C25CC = *fp;
        D_004C2580[0].ratio = D_004C25CC / (f32)D_004C2580[0].count;
    }
    if (D_004C2580[0].count) {
        D_004C2580[0].count--;
        D_004F1F98[0] = D_004F1F50[0] = D_004F1F50[0] + D_004C2580[0].sign * D_004C25CC;
        D_004C2580[0].sign *= -1;
        D_004C25CC = D_004C25CC - D_004C2580[0].ratio;
    } else {
        D_004C25C8 = 0;
        D_004F1F45[0] = 0;
    }
}
