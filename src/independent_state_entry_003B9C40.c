typedef unsigned char u8;
typedef signed short s16;

void func_003B9C40(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1e) - 1;
    *(s16 *)(p + 0x1e) = t;
    if (t == 0) {
        p[5]++;
        *(s16 *)(p + 0x1e) = 4;
    }
}
