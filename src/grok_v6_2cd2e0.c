typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_002CD2E0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        p[0x151] = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 15.833333015441895f : -15.833333015441895f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.390625f : 0.390625f;
        *(f32 *)(p + 0x60) = 4.285714149475098f;
        *(f32 *)(p + 0x6C) = -0.5357142686843872f;
    }
}
