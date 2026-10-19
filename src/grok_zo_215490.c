typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_00215490(u8 *p)
{
    f32 *vx;
    f32 *vz;

    vx = (f32 *)(p + 0x5C);
    vz = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if ((s8)p[0x151] == 2) {
        p[6]++;
        *vx = 0;
        *vz = 0;
        *(unsigned int *)(p + 0x60) = 0xC0CDB6DB;
        *(unsigned int *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
