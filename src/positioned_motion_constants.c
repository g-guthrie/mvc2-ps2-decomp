typedef unsigned char u8;

extern void func_00243360(u8 *);
extern void func_002405A0(u8 *);

void func_00243330(u8 *p)
{
    p[6]++;
    *(float *)(p + 96) = 4.285714f;
    *(float *)(p + 108) = -1.6071428060531616f;
    *(float *)(p + 92) = 0.0f;
    *(float *)(p + 104) = 0.0f;
    func_00243360(p);
}

void func_00240540(u8 *p)
{
    p[6]++;
    *(short *)(p + 28) = 24;
    *(float *)(p + 92) = 15.833333f;
    *(float *)(p + 104) = -0.4017857f;
    if (p[486] != 0) {
        *(float *)(p + 92) = -*(float *)(p + 92);
        *(float *)(p + 104) = -*(float *)(p + 104);
    }
    *(float *)(p + 96) = 0.0f;
    *(float *)(p + 108) = 0.0f;
    func_002405A0(p);
}
