/* Interpolate adjacent animation scale entries in a relative record stream. */
typedef unsigned char u8;
typedef struct Record { short skip; short payload; } Record;
extern Record D_004B78D0[];
extern float D_004B78C8[];
extern void func_00332420(u8 *), func_00332110(u8 *);
void func_00332270(u8 *p) {
    if (p[6] < p[7] - 1) {
        short *record = (short *) D_004B78D0;
        float *scales = D_004B78C8;
        int i;
        for (i = 0; i < p[4]; ++i) record += *record * 2;
        record++;
        *(int *)(p+0xd4) = record[p[6]];
        record += p[7] - 1;
        record += p[6];
        *(float *)(p+0x50) = scales[record[0]];
        *(float *)(p+0x54) = (scales[record[1]] - *(float *)(p+0x50)) / *(int *)(p+0xd4);
        p[5] = 2;
        func_00332420(p);
    } else {
        p[4]++; p[4] %= 0x6; p[5] = 0; p[6] = 0; func_00332110(p);
    }
}
extern Record D_004B7A70[];
extern float D_004B7A60[];
extern void func_00333330(u8 *), func_00333020(u8 *);
void func_00333180(u8 *p) {
    if (p[6] < p[7] - 1) {
        short *record = (short *) D_004B7A70;
        float *scales = D_004B7A60;
        int i;
        for (i = 0; i < p[4]; ++i) record += *record * 2;
        record++;
        *(int *)(p+0xd4) = record[p[6]];
        record += p[7] - 1;
        record += p[6];
        *(float *)(p+0x50) = scales[record[0]];
        *(float *)(p+0x54) = (scales[record[1]] - *(float *)(p+0x50)) / *(int *)(p+0xd4);
        p[5] = 2;
        func_00333330(p);
    } else {
        p[4]++; p[4] %= 0x6; p[5] = 0; p[6] = 0; func_00333020(p);
    }
}
extern Record D_004B79A0[];
extern float D_004B7990[];
extern void func_003338C0(u8 *), func_003335B0(u8 *);
void func_00333710(u8 *p) {
    if (p[6] < p[7] - 1) {
        short *record = (short *) D_004B79A0;
        float *scales = D_004B7990;
        int i;
        for (i = 0; i < p[4]; ++i) record += *record * 2;
        record++;
        *(int *)(p+0xd4) = record[p[6]];
        record += p[7] - 1;
        record += p[6];
        *(float *)(p+0x50) = scales[record[0]];
        *(float *)(p+0x54) = (scales[record[1]] - *(float *)(p+0x50)) / *(int *)(p+0xd4);
        p[5] = 2;
        func_003338C0(p);
    } else {
        p[4]++; p[4] %= 0x6; p[5] = 0; p[6] = 0; func_003335B0(p);
    }
}
