typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

#define PHYSXY \
    F(p, 52) += F(p, 92); \
    F(p, 92) += F(p, 104);

extern int func_00175670(u8 *);
extern int func_00175700(u8 *);
extern void func_001AFC90(u8 *);
extern void func_001CCB50(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001E3710(u8 *, int);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);

void func_001ADAE0(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001AFC90(p); return; }
}
void func_001ADE30(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001AFC90(p); return; }
}
void func_001AE310(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001AFC90(p); return; }
}
void func_001AE4E0(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001AFC90(p); return; }
}
void func_001AF0F0(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001AFC90(p); return; }
}
void func_001AF290(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001AFC90(p); return; }
}

void func_001CC6D0(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001CCB50(p); return; }
}
void func_001CC860(u8 *p) {
    if ((s8)func_00175670(p) < 0) { func_001CCB50(p); return; }
}

void func_001F8920(u8 *p) {
    PHYSXY
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[337] != 0) {
        p[337] = 0;
        I(p, 92) = 0;
        I(p, 104) = 0;
    }
}
void func_0027A810(u8 *p) {
    PHYSXY
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[337] != 0) {
        p[337] = 0;
        I(p, 92) = 0;
        I(p, 104) = 0;
    }
}

void func_00217700(u8 *p) {
    if ((s8)p[337] != 0) {
        p[337] = 0;
        func_001E3710(p, 22);
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (func_001864A0(p)) func_001865B0(p);
}
void func_0031CBB0(u8 *p) {
    if ((s8)p[337] != 0) {
        p[337] = 0;
        func_001E3710(p, 22);
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (func_001864A0(p)) func_001865B0(p);
}
