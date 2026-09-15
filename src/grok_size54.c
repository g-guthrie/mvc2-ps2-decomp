typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern void func_00186A60(u8 *, int);

#define INIT_00215A70 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 2; break; \
        case 1: p[509] = 2; break; \
        case 2: p[509] = 2; break; \
        } \
        func_00186A60(p, 29); \
    }

void func_00215A70(u8 *p) { INIT_00215A70 }
void func_00215AD0(u8 *p) { INIT_00215A70 }
void func_00225D20(u8 *p) { INIT_00215A70 }
void func_00225D80(u8 *p) { INIT_00215A70 }

#define INIT_0030C4A0 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 8; break; \
        case 1: p[509] = 1; break; \
        case 2: p[509] = 0; break; \
        } \
        func_00186A60(p, 29); \
    }

void func_0030C4A0(u8 *p) { INIT_0030C4A0 }
void func_0030C500(u8 *p) { INIT_0030C4A0 }

#define INIT_00248200 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 1; break; \
        case 1: p[509] = 2; break; \
        case 2: p[509] = 0; break; \
        } \
        p[439] = 0; \
        func_00186A60(p, 21); \
    }

void func_00248200(u8 *p) { INIT_00248200 }
void func_00248260(u8 *p) { INIT_00248200 }

void func_001615D0(u8 *p) {
    int n = *(int *)(p + 220);
    if (n) {
        *(int *)(p + 220) = n - 1;
        F(p, 120) += F(p, 80);
        F(p, 124) += F(p, 84);
        F(p, 128) += F(p, 88);
    } else {
        p[35] = 0;
    }
}

void func_00161820(u8 *p) {
    int n = *(int *)(p + 220);
    if (n) {
        *(int *)(p + 220) = n - 1;
        F(p, 120) += F(p, 80);
        F(p, 124) += F(p, 84);
        F(p, 128) += F(p, 88);
    } else {
        p[35] = 0;
    }
}

void func_0028ADA0(u8 *p, u8 *q)
{
    if (--*(signed short *)(p + 28) == 0) {
        q[24]++;
        *(signed short *)(p + 28) = 10;
    }
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
}

void func_00292110(u8 *p, u8 *q)
{
    if (--*(signed short *)(p + 28) == 0) {
        q[24]++;
        *(signed short *)(p + 28) = 10;
    }
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
}
