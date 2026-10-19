typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(void *);
extern void func_0018C4B0(void *, int);
extern void func_0035F470(u8 *);
extern void func_002413C0(u8 *, u8 *);

void func_00240F60(u8 *p, u8 *q)
{
    func_00175700(p);
    if ((s8)p[0x150] != 0) {
        p[7]++;
        *(s16 *)(p + 0x1E) = 0x168;
        p[0x28F] = 1;
        p[0x28E] = 0x10;
        func_0018C4B0(p, 5);
        func_0035F470(p);
        func_002413C0(p, q);
    }
}
