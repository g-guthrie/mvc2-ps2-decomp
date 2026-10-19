typedef unsigned char u8;
typedef float f32;

extern int func_001757E0(u8 *, int, int);

void func_002B4470(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    func_001757E0(p, 18, 0);
    if (*(short *)(p + 0x140)) {
        *(f32 *)(p + 0x5C) = 3.3333332538604736f;
        *(f32 *)(p + 0x34) += -106.66666412353516f;
    } else {
        *(f32 *)(p + 0x5C) = -3.3333332538604736f;
        *(f32 *)(p + 0x34) += 106.66666412353516f;
    }
}
