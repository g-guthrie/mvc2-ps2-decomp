typedef unsigned char u8;
typedef signed char s8;
typedef struct Record { short skip; short payload; } Record;
extern Record D_004B78D0[];
extern float D_004B78C8[];

void func_00332110(u8 *p) {
    extern void func_00332270(u8 *);
    Record *record = D_004B78D0;
    float *scales = D_004B78C8;
    int i;
    for (i = 0; i < p[4]; ++i) record += record->skip;
    p[7] = *(signed char *)record;
    *(unsigned int *)(p + 0x40) = (unsigned short)(int)(0.5 + 65536.0 * (double)scales[((short *)record)[p[7]]] / 360.0);
    p[5]++;
    func_00332270(p);
}
