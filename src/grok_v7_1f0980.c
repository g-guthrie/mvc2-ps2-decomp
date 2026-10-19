typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;

extern int func_00183D90(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_001F0980(u8 *p)
{
    u16 *pad = (u16 *)(p + 0x2B8);
    u16 w;
    func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 0) {
        *(int *)(p + 0x5C) = 0;
        return;
    }
    if (*(s8 *)(p + 0x539) != 0) {
        w = *pad;
        if (w & 0x800) {
            *(int *)(p + 0x5C) = 0xC0200000;
        } else if (w & 0x400) {
            *(int *)(p + 0x5C) = 0x40200000;
        } else {
            *(int *)(p + 0x5C) = 0;
        }
    } else {
        w = *(u16 *)(p + 0x354);
        if ((w & 0xC00) == 0) {
            *(int *)(p + 0x5C) = 0;
        } else if (w & 0x800) {
            *(int *)(p + 0x5C) = 0xC0200000;
        } else if (w & 0x400) {
            *(int *)(p + 0x5C) = 0x40200000;
        }
    }
}
