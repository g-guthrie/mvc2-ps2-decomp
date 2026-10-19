typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_00185490(u8 *);
extern void func_00184540(void *);
extern void func_001266A0(u8 *, int, int);

void func_001F6E90(u8 *p)
{
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        func_00185490(p);
        func_00184540(p);
    } else if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x1B5] = 0x21;
        p[0x1B5] = 0x21;
    }
}
