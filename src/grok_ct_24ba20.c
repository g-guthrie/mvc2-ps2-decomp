typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_0018AB10(u8 *);

void func_0024BA20(u8 *p)
{
    unsigned int offset;
    s16 t = *(s16 *)(p + 0x1E);
    t = t - 1;
    *(s16 *)(p + 0x1E) = t;
    if (t != 0) {
        if (!func_0018AB10(p))
            return;
        p[0x2BE]++;
        if ((s8)p[0x2BE] <= 0)
            return;
        p[0x2B8 + 6] = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 3;
        if (*(s16 *)(p + 0x1E) > 0)
            return;
        *(s16 *)(p + 0x1E) = 4;
    } else {
        *(s16 *)(p + 0x1E) = 4;
    }
    if (p[0x20D] == 0) {
        p[0x1B5] = 0x37;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    } else {
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
}
