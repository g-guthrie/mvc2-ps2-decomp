typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001E3A40(u8 *);

void func_00285E50(u8 *p)
{
    u8 *child;

    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x151) == 0)
            return;
        p[0x151] = 0;
        child = *(u8 **)(p + 0x1DC);
        *(u8 **)(child + 0x1C8) = p;
        child[0x20A] = 2;
        child[0x1B5] = 0x20;
        func_001E3A40(p);
    } else {
        func_001843A0(p);
    }
}
