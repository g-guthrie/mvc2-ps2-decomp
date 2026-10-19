typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001F9000(u8 *);

void residual_001F8F40(u8 *p)
{
    if ((s8)p[0x151] == 0) {
        volatile int *z;
        p[6]++;
        z = (int *)(p + 0x5C);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        z[3] = 0;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x5C) = 0xC17D5555;
        else
            *(unsigned int *)(p + 0x5C) = 0x417D5555;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x68) = 0x3EA00000;
        else
            *(unsigned int *)(p + 0x68) = 0xBEA00000;
        *(unsigned int *)(p + 0x60) = 0x40CDB6DB;
        *(unsigned int *)(p + 0x6C) = 0xBF092492;
        func_001F9000(p);
    } else
        func_00175700(p);
}
