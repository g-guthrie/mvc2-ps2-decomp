typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern void *func_003B5A40(u8 *, int);
extern void func_00307420(u8 *, void *);

void func_003073A0(u8 *p, void *context)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001E3210(p, 21);
        func_001E3210(p, 47);
        func_003B5A40(p, p[0x1B7]);
        func_00307420(p, context);
    }
}
