typedef unsigned char u8;
typedef struct Record { short skip; short payload; } Record;
extern Record D_004B7D00[];
extern float D_004B7CF0[];
extern void func_00334840(u8 *);
void func_003346D0(u8 *p) {
    float *scales = D_004B7CF0;
    short *record = (short *) D_004B7D00;
    int i;
    if (p[5] < p[0x21]) {
        for (i = 0; i < p[4]; ++i) record += *record * 2;
        *(int *)(p+0xd4) = record[p[5]];
        record += p[0x21];
        record += p[5];
        *(float *)(p+0x6c) = scales[record[-1]];
        *(float *)(p+0x60) = (scales[record[0]] - *(float *)(p+0x6c)) / *(int *)(p+0xd4);
        p[6] = 2;
        func_00334840(p);
    } else {
        p[5] = 0; p[6] = 3;
    }
}
extern Record D_004B7D70[];
extern float D_004B7D58[];
extern void func_003343B0(u8 *);
void func_00334240(u8 *p) {
    float *scales = D_004B7D58;
    short *record = (short *) D_004B7D70;
    int i;
    if (p[5] < p[0x21]) {
        for (i = 0; i < p[4]; ++i) record += *record * 2;
        *(int *)(p+0xd4) = record[p[5]];
        record += p[0x21];
        record += p[5];
        *(float *)(p+0x6c) = scales[record[-1]];
        *(float *)(p+0x60) = (scales[record[0]] - *(float *)(p+0x6c)) / *(int *)(p+0xd4);
        p[6] = 2;
        func_003343B0(p);
    } else {
        p[5] = 0; p[6] = 3;
    }
}
extern Record D_004B7DD0[];
extern float D_004B7DC8[];
extern void func_00333E30(u8 *);
void func_00333CC0(u8 *p) {
    float *scales = D_004B7DC8;
    short *record = (short *) D_004B7DD0;
    int i;
    if (p[0x21] > p[5]) {
        for (i = 0; i < p[4]; ++i) record += *record * 2;
        *(int *)(p+0xd4) = record[p[5]];
        record += p[0x21];
        record += p[5];
        *(float *)(p+0x70) = scales[record[-1]];
        *(float *)(p+0x64) = (scales[record[0]] - *(float *)(p+0x70)) / *(int *)(p+0xd4);
        p[6] = 2;
        func_00333E30(p);
    } else {
        p[5] = 0; p[6] = 3;
    }
}
