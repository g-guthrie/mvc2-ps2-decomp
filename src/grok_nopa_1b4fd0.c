typedef unsigned char u8;
typedef unsigned short u16;

extern void func_001B50B0(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);

void func_001B4FD0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    if (*(u16 *)(p + 208) != *(u16 *)(q + 360)) {
        p[4] = 2;
    } else {
        p[6]++;
        p[316] = 1;
        func_001B50B0(q, p);
        func_001754A0(p, 27, p[32]);
    }
}
