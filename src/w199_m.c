typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern float func_00115D10(float, float, s32);
extern float func_00115358(float, float);
extern s32 func_00113E78(float, float *);

float func_00116FA0(float x)
{
    float y[2];
    s32 hx;
    s32 n;
    do {
        union { float f; s32 w; } gh_u;
        gh_u.f = x;
        hx = gh_u.w;
    } while (0);
    hx &= 0x7fffffff;
    if (hx <= 0x3f490fd8) {
        return func_00115358(x, 0.0f);
    }
    n = func_00113E78(x, y);
    switch (n & 3) {
    case 0:
        return func_00115358(y[0], y[1]);
    case 1:
        return -func_00115D10(y[0], y[1], 1);
    case 2:
        return -func_00115358(y[0], y[1]);
    default:
        return func_00115D10(y[0], y[1], 1);
    }
}
