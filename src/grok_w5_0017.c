typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void (*jtbl_00446AA0[])(void);

extern void func_0012F040(s32);
extern void func_0012E320(void);
extern void func_0012E4C0(void);
extern void func_0012F060(s32);
extern void func_001E40E0(void);
extern void func_001E4140(void);
extern void func_001E4150(void);
extern s32 func_00184720(u8 *);
extern void func_00191F90(u8 *);
extern void func_00177430(u8 *);
extern void func_00177820(u8 *);
extern void func_00177180(u8 *);
extern void func_00177A60(u8 *);
extern void func_001783E0(u8 *);
extern void func_00178990(u8 *);
extern void func_00176AB0(u8 *);
extern int func_00175700(u8 *);
extern void func_00186CE0(u8 *, s32);
extern void func_00172320(s32);
extern int func_001757E0(u8 *, int, int);

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_001716D0(void) { jtbl_00446AA0[((s8 *)D_004C2840)[4]](); }

void func_00170BF0(void) {
    func_0012F040(0);
    func_0012E320();
    func_0012E4C0();
    func_0012F060(0);
    func_0012F060(1);
}

void func_00176920(void) {
    D_004C2840[2] = 6;
    D_004C2840[3] = 0;
    func_001E40E0();
    func_001E4140();
    func_001E4150();
}

void func_0017C170(u8 *p) {
    if (!func_00184720(p)) {
        func_00191F90(p);
    }
}

void residual_00177410(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    I(p, 0x60) = 0;
    I(p, 0x6C) = 0;
    func_00177430(p);
}

void residual_001777F0(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x6C) = 0xBFBC9249;
    func_00177820(p);
}

void residual_00177150(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x68) = 0;
    I(p, 0x6C) = 0xBF4DB6DB;
    func_00177180(p);
}

void func_00177A30(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x68) = 0;
    I(p, 0x6C) = 0xBFBC9249;
    func_00177A60(p);
}

void residual_001783B0(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x68) = 0;
    I(p, 0x6C) = 0xBF4DB6DB;
    func_001783E0(p);
}

void func_00178740(u8 *p) {
    p[6] = 5;
    p[7] = 0;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x68) = 0;
    I(p, 0x6C) = 0xBFBC9249;
    func_00178990(p);
}

void func_00176A70(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x68) = 0;
    I(p, 0x6C) = 0xBFBC9249;
    *(s16 *)(p + 0x1E) = 0;
    func_00176AB0(p);
}

void func_00177990(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00186CE0(p, 0x17);
    }
}

void func_00177F80(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00186CE0(p, 0xC);
    }
}






extern void func_00178050(u8 *);
void func_00178010(u8 *p) {
    p[6] += 1;
    F(p, 0x5C) = F(p, 0x22C);
    F(p, 0x60) = F(p, 0x230);
    I(p, 0x68) = 0;
    I(p, 0x6C) = 0xBFBC9249;
    *(s16 *)(p + 0x1E) = 0;
    func_00178050(p);
}
