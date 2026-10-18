typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 a[6]; } S24;
typedef unsigned long long u64;
typedef long long s64;
typedef struct { s32 cls; s32 sign; s32 exp; s32 pad; u64 frac; } FP;

static u32 *func_003F1530(void *file) { return file; }

u8 *func_003F15A0(u8 *a, u32 n)
{
    u32 *r;
    u32 cnt = 0;
    u32 i;
    r = func_003F1530(a);
    if (n < r[1]) {
        a += 12;
        for (i = 0; i < r[1]; i++) {
            if (*a != 0) {
                if (cnt == n)
                    return a;
                cnt++;
            }
            a += *(s32 *)(a + 8);
        }
    }
    return 0;
}
