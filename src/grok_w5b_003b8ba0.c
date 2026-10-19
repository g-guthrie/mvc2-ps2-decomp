typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2840;
extern void func_003B8C10(u8 *);

void func_003B8BA0(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t) {
        if (*(u32 *)(D_004C2840 + 0x1C) & 1)
            p[0x13C] = 0;
        else
            p[0x13C] = 1;
    } else {
        p[5]++;
        p[0x13C] = 1;
        func_003B8C10(p);
    }
}
