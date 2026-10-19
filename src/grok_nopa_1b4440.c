typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_001B5350(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);

void func_001B4440(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    if (*(u16 *)(p + 208) != *(u16 *)(q + 360)) {
        p[6]++;
        p[316] = 1;
        func_001B5350(q, p);
        func_001754A0(p, 27, p[32]);
        p[36] = 0;
        if (*(float *)(p + 92) < 0.0f)
            *(s16 *)(p + 320) = 0;
        else
            *(s16 *)(p + 320) = 1;
    }
}
