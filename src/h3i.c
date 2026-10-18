typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 a[4];
} A;

void func_001C1C50(u8 *p, u8 *q)
{
    A *s = (A *)(p + 0xD0);
    u16 *w = &s->a[3];
    u32 t = *(u16 *)(p + 0xD6);
    u8 *a = q + 0x2B8;
    t = t - 1;
    *(u16 *)(p + 0xD6) = t;
    if ((u16)t == 0) {
        *w = 0x78;
        if (a[2] < 0x32) {
            a[2] = a[2] + 1;
        }
    }
}
