typedef unsigned char u8;
typedef float f32;

extern void func_00183D10(u8 *);
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002AE190(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    func_00183D10(p);
    func_00185490(p);
    *(f32 *)(p + 0x5C) = p[0x1E6] ? 5.833333015441895f : -5.833333015441895f;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(unsigned short *)(p + 0x1C) = 0x28;
    func_001757E0(p, 22, 18);
}
