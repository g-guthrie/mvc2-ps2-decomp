typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    s8 st, b1, cnt, pad3;
    s32 a[2];
    s32 b[2];
    f32 z[2];
    s32 n;
    s32 rate;
    f32 f24;
    f32 f28;
    s32 w2C;
} S3F5F;
extern S3F5F D_00478E78[];
extern f32 D_004BF280;
S3F5F *func_003F5F88(s32 n, s32 *a, s32 *b)
{
    extern void func_003F9630();
    extern void func_003F9660();
    S3F5F *s;
    s32 i = 0;
    s32 j;
    f32 r;
    while (i < 8) { if (D_00478E78[i].st == 0) break; i++; }
    if (i == 8) return 0;
    func_003F9630();
    s = &D_00478E78[i];
    s->cnt = n;
    for (j = 0; j < n; j++) {
        s->a[j] = a[j];
        s->z[j] = 0.0f;
        s->b[j] = b[j];
    }
    r = D_004BF280;
    s->rate = 44100;
    s->n = n;
    s->b1 = 0;
    s->w2C = 0;
    s->f24 = r;
    s->f28 = r;
    s->st = 1;
    func_003F9660();
    return s;
}
