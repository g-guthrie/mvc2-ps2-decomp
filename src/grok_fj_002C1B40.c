typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001E3710(u8 *, int);
extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002C1B40(u8 *p)
{
    if (*(s8 *)(p + 0x150)) {
        p[0x150] = 0;
        if (p[0x1FC] == 0x61)
            func_001E3710(p, 0x14);
        else if (p[0x1FC] == 0x62)
            func_001E3710(p, 0x15);
        else
            func_001E3710(p, 0x16);
    }
    func_00175700(p);
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
    if (*(s16 *)(p + 0x1E) && *(f32 *)(p + 0x38) > *(f32 *)(p + 0x430))
        return;
    p[6]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x20D] == 2) {
        if (p[0x1FC] == 0x61)
            func_001757E0(p, 0xC, 0xF);
        else if (p[0x1FC] == 0x62)
            func_001757E0(p, 0xC, 0x10);
        else
            func_001757E0(p, 0xC, 0x11);
    } else {
        if (p[0x1FC] == 0x61)
            func_001757E0(p, 0xC, 0xC);
        else if (p[0x1FC] == 0x62)
            func_001757E0(p, 0xC, 0xD);
        else
            func_001757E0(p, 0xC, 0xE);
    }
}
