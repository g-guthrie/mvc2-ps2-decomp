typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad[0x36]; s8 f36[8]; } G;
extern G *D_004C2794;
extern u16 *D_004C26F0;
extern u8 D_0045BA10[];

extern void func_001830D0(void *p, f32 *v);
extern s32 func_0036BFF0(void *p, s32 a, s32 b, s32 c);
extern s32 func_00175700(void *p);
extern void func_00175C00(void *p, s32 a);
extern void func_001E3A40(void *p);
extern void func_0018B500(void *p, void *q);
extern void func_0016CE90();
extern void func_00190C60(void *p, void *q);
extern void func_001E3210(void *p, s32 a);
extern void func_0018C6F0(void *p);
extern void func_001BA5C0(void *p);
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_00186A60(void *p, s32 a);

void func_002FBA40(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    u32 *r1 = (u32 *)(p + 0x60);
    u32 *r2 = (u32 *)(p + 0x6C);
    f32 a;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!((a = *(f32 *)(p + 0x430)) - 120.0f < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = a;
        *r1 = 0;
        *r2 = 0;
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x24;
        p[0x1B5] = 0x24;
        q[0x20A] = 2;
        q[0x1E6] = p[0x1E6];
        {
            u32 t2 = q[0x1E6];
            q[0x1E6] = t2 ^ 1;
        }
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        func_00175700(p);
        func_001E3A40(q);
    }
}

void func_0018F800(u8 *p) {
    *(u32 *)(p + 0x1CC) = *(u32 *)(p + 0x1DC);
    p[0x1B6] = p[0x1B5];
    func_0018B500(p, *(void **)(p + 0x1CC));
    if (p[0x247] == 0x15) {
        p[0x247] = 2;
        p[0x24A] = 0;
    }
    if (*(s16 *)(p + 0x434) == 0) {
        if (p[0x1F0] == 0) {
            p[0x1F0] = 0xFF;
            func_0016CE90();
            if (D_004C2794->f36[p[2]] < 3) {
                func_00190C60(p, *(void **)(p + 0x1CC));
            }
            func_001E3210(p, 0);
        }
    }
    func_00175C00(p, 1);
    func_0018C6F0(p);
}

void func_001BA4C0(u8 *p) {
    u8 *q;
    *(u32 *)(p + 0x50) = 0x3F866666;
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    q = *(u8 **)(p + 0x18);
    if (p[1] != q[1]) {
        func_001BA5C0(p);
        return;
    }
    if (*D_004C26F0 != *(u16 *)(q + 0x168)) {
        p[4] = 2;
        p[0x13C] = 0;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(u32 *)(p + 0x118) = 0x3F000000;
    } else {
        *(u32 *)(p + 0x118) = 0x3F800000;
    }
}

