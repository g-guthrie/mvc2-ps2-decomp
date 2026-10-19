typedef unsigned char u8;
typedef signed short s16;

extern void func_001B2FF0(u8 *);

void func_001B2FB0(u8 *p)
{
    s16 timer = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = timer - 1;
    if (timer <= 0) {
        p[5]++;
        func_001B2FF0(p);
    }
}
