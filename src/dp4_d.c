typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16; typedef signed int s32;
typedef struct Record { short skip; short payload; } Record;
extern Record D_004B7A70[];
extern float D_004B7A60[];

extern void func_00333180(u8 *);
void func_00333020(u8 *p) {
    short *record = (short *) D_004B7A70;
    float *scales = D_004B7A60;
    int i;
    float f;
    for (i = 0; i < p[4]; ++i) record += *record * 2;
    p[7] = *(s8 *)record;
    record += p[7];
    f = scales[*record];
    *(unsigned int *)(p + 0x40) = (u16)(s32)(0.5 + 65536.0 * (double)f / 360.0);
    p[5] = 1;
    func_00333180(p);
}
