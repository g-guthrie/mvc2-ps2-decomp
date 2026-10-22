typedef signed char s8;
typedef signed int s32;

typedef struct { s8 *d; s8 *s; } CP;
extern CP D_004C2A70;

void func_003DCDC0(s8 *dst, s8 *src, s32 n) {
    CP c = D_004C2A70;
    s32 i;
    c.d = dst;
    c.s = src;
    for (i = 0; i < n; i++) {
        *c.d++ = *c.s++;
    }
}
