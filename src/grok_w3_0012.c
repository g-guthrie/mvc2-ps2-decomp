typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 D_00583B90[];
extern void (*D_004C25DC)(void);
extern s16 D_004C2790;
extern s16 D_004C278C;
extern s16 D_004C2788;
extern s16 D_004C2784;
typedef signed short s16;
typedef signed int s32;

extern u8 D_00583B90[];
extern void (*D_004C25DC)(void);
extern u8 *D_004C2840;
extern void func_00139380(u8 *);
extern void func_001396E0(u8 *);
extern void func_00122670(void);
extern void func_00133760(s32);

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct {
    f32 a, b, c, d;
} Vec4;

void residual_00139560(u8 *p) {
    S(p, 0x1c) = S(p, 0x1c) - 1;
    if (S(p, 0x1c) <= 0) {
        p[4]++;
    }
}

void func_0013A320(u8 *p) {
    S(p, 0x1c) = S(p, 0x1c) - 1;
    if (S(p, 0x1c) <= 0) {
        p[4]++;
    }
}

void func_0013B380(u8 *p) {
    S(p, 0x1c) = S(p, 0x1c) - 1;
    if (S(p, 0x1c) <= 0) {
        p[4]++;
        p[0x13c] = 0;
    }
}

void residual_0013A410(u8 *p) {
    p[4]++;
    D_00583B90[p[0x20]] = 4;
}

void func_00138940(u8 *p) {
    if (p[0x22]) {
        p[4]++;
        D_00583B90[p[0x20]] = 3;
    }
}

void func_001396A0(u8 *p) {
    if (D_00583B90[p[0x20]] == 3) {
        p[4]++;
    }
}

void func_00132F70(u8 *p) {
    u8 *q = P(p, 0x14);
    ((s8 *)p)[0x13c] = ((s8 *)q)[0x13c];
    q = P(p, 0x14);
    *(Vec4 *)(p + 0x74) = *(Vec4 *)(q + 0x74);
}

void func_0012ACD0(void) {
    if (D_004C25DC) {
        D_004C25DC();
    }
}

void func_00128380(void) {
    D_004C2790 += 0x1000;
    D_004C278C += 0x800;
    D_004C2788 += 0x400;
    D_004C2784 += 0x200;
}

void func_00138A20(u8 *p) {
    p[4]++;
    func_00139380(p);
    func_001396E0(p);
}

void func_00122770(s32 a0, s32 a1, s32 *a2) {
    func_00122670();
    *a2 -= 0x4000;
}

void func_00133720(void) {
    if (*(s32 *)(D_004C2840 + 0x14) != 0x40) {
        func_00133760(0);
        func_00133760(1);
    }
}
