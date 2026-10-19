typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001FD510(u8 *);
extern void func_001FD5B0(u8 *);
extern void func_001FD670(u8 *);

void func_001FD6B0(u8 *p)
{
    u8 s = p[0x1FC];
    if (s == 2) {
        if (p[6] == 0) {
            if ((s8)func_00175700(p) < 0)
                func_001843A0(p);
        } else {
            u8 t = p[7];
            if (t == 2)
                func_001FD670(p);
            else if (t == 1)
                func_001FD5B0(p);
            else if (t == 0)
                func_001FD510(p);
        }
    } else if (s == 1 || s == 0) {
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
    }
}
