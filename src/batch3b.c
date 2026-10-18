typedef unsigned char u8;
typedef signed char s8;

void func_00317430(u8 *p) {
    s8 *q = (s8 *)(p + 0x2B8);
    s8 *r = q + 7;
    s8 v = *(s8 *)(p + 0x2BF);
    if (v != 0) *r = v - 1;
}
