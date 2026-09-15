typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

void func_00161A70(u8 *p) {
    int n = *(int *)(p + 220);
    if (n) {
        *(int *)(p + 220) = n - 1;
        F(p, 120) += F(p, 92);
        F(p, 124) += F(p, 96);
        F(p, 128) += F(p, 104);
    } else {
        p[35] = 0;
    }
}

void func_0028ADA0(u8 *p, u8 *q)
{
    if (--*(s16 *)(p + 28) == 0) {
        q[24]++;
        *(s16 *)(p + 28) = 10;
    }
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
}

void func_00292110(u8 *p, u8 *q)
{
    if (--*(s16 *)(p + 28) == 0) {
        q[24]++;
        *(s16 *)(p + 28) = 10;
    }
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
}
