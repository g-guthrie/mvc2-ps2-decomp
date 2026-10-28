typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a; s16 b; } Nq132E;
extern Nq132E D_004CB010[];

void func_00150670(u32 *p) {
    extern void func_00150830(Nq132E *, s32);
    u32 sum;
    s32 i;
    sum = 0;
    for (i = 0; i < 56; i++) sum += p[i];
    if (sum != 0) {
        for (i = 0; i < 56; i++) {
            D_004CB010[i].a = 1000.0f * ((f32)p[i] / (f32)sum);
            D_004CB010[i].b = (i > 23) ? i + 3 : i;
        }
    } else {
        for (i = 0; i < 56; i++) {
            D_004CB010[i].a = 0;
            D_004CB010[i].b = (i > 23) ? i + 3 : i;
        }
    }
    func_00150830(D_004CB010, 56);
}
