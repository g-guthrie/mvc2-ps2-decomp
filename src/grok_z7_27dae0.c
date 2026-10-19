typedef unsigned char u8;
typedef float f32;

extern u8 D_004D18A0;
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00155420(u8 *);
extern void func_00383900(u8 *);

void func_0027DAE0(u8 *p)
{
    p[0x13C] = 0;
    p[0x159] = 0xFF;
    if (D_004D18A0 >= 2) {
        p[6]++;
        p[0x13C] = 1;
        func_00185490(p);
        func_001757E0(p, 18, 0);
        *(unsigned *)(p + 0x74) = 0x3F59999A;
        *(int *)(p + 0x78) = 0;
        *(int *)(p + 0x7C) = 0;
        *(int *)(p + 0x80) = 0;
        func_00155420(p);
        func_00383900(p);
    }
}
