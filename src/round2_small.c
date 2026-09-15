typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern int func_00189150(u8 *);
extern int func_001891F0(u8 *, int);
extern void func_00186A60(u8 *, int);
extern s8 func_00175700(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001843A0(u8 *);
extern void func_0028D8B0(u8 *);
extern void func_00294BC0(u8 *);

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

int func_00216320(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!*(s8 *)U32(p, 1056)) return 0;
    p[5] = 0; p[6] = 0; p[7] = 0; p[509] = 8;
    func_00186A60(p, 29);
    return 1;
}
int func_00233970(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!*(s8 *)U32(p, 1056)) return 0;
    p[5] = 0; p[6] = 0; p[7] = 0; p[509] = 8;
    func_00186A60(p, 29);
    return 1;
}
int func_002DC820(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!*(s8 *)U32(p, 1056)) return 0;
    p[5] = 0; p[6] = 0; p[7] = 0; p[509] = 8;
    func_00186A60(p, 29);
    return 1;
}
int func_0031B790(u8 *p) {
    if (!func_00189150(p)) return 0;
    if (!*(s8 *)U32(p, 1056)) return 0;
    p[5] = 0; p[6] = 0; p[7] = 0; p[509] = 8;
    func_00186A60(p, 29);
    return 1;
}

void func_0028AFA0(u8 *p) {
    func_0028D8B0(p);
    if ((s8)func_00175700(p) < 0) {
        p[707] = 0;
        S32(p, 92) = 0; S32(p, 96) = 0; S32(p, 104) = 0; S32(p, 108) = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}
void func_0028B8B0(u8 *p) {
    func_0028D8B0(p);
    if ((s8)func_00175700(p) < 0) {
        p[707] = 0;
        S32(p, 92) = 0; S32(p, 96) = 0; S32(p, 104) = 0; S32(p, 108) = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}
void func_0028CB70(u8 *p) {
    func_0028D8B0(p);
    if ((s8)func_00175700(p) < 0) {
        p[707] = 0;
        S32(p, 92) = 0; S32(p, 96) = 0; S32(p, 104) = 0; S32(p, 108) = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}

void func_00292310(u8 *p) {
    func_00294BC0(p);
    if ((s8)func_00175700(p) < 0) {
        p[707] = 0;
        S32(p, 92) = 0; S32(p, 96) = 0; S32(p, 104) = 0; S32(p, 108) = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}
void func_00292C20(u8 *p) {
    func_00294BC0(p);
    if ((s8)func_00175700(p) < 0) {
        p[707] = 0;
        S32(p, 92) = 0; S32(p, 96) = 0; S32(p, 104) = 0; S32(p, 108) = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}
void func_00293EC0(u8 *p) {
    func_00294BC0(p);
    if ((s8)func_00175700(p) < 0) {
        p[707] = 0;
        S32(p, 92) = 0; S32(p, 96) = 0; S32(p, 104) = 0; S32(p, 108) = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}

int func_002487F0(u8 *p) {
    if (!(u8)func_001891F0(p, 3)) return 0;
    p[5] = 0; p[7] = 0; p[6] = 0; p[509] = 3;
    func_00186A60(p, 21);
    return 1;
}
int func_00286A90(u8 *p) {
    if (!(u8)func_001891F0(p, 3)) return 0;
    p[5] = 0; p[7] = 0; p[6] = 0; p[509] = 3;
    func_00186A60(p, 21);
    return 1;
}
int func_0028E350(u8 *p) {
    if (!(u8)func_001891F0(p, 3)) return 0;
    p[5] = 0; p[7] = 0; p[6] = 0; p[509] = 3;
    func_00186A60(p, 21);
    return 1;
}
