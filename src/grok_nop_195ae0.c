typedef unsigned char u8;

extern void func_00197600(u8 *);
extern int func_00417A40(void);
extern void func_00175580(u8 *, int, int, int);

void residual_00195AE0(u8 *p)
{
    p[5]++;
    if (p[33] < 4) {
        func_00197600(p);
        func_00175580(p, 27, 8, func_00417A40() & 3);
    }
}
