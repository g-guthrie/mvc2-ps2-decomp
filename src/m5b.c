typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004BF4D0[2];
extern void func_0015A4A0(f32 *v, s32 a);
extern void func_001E3710(void *p, s32 a);

void func_0017B8E0(u8 *p) {
    f32 v[3];
    *(u8 **)(p + 0x228) = D_004BF4D0;
    p[6] = 3;
    *(s16 *)(p + 0x1C) = 0;
    p[0x1F1] = 0;
    v[0] = *(f32 *)(p + 0x260);
    v[1] = *(f32 *)(p + 0x264);
    v[2] = *(f32 *)(p + 0x3C);
    func_0015A4A0(v, *(s16 *)(p + 0x140));
    func_001E3710(p, 0x44);
}

extern volatile s32 D_004C28B0;
extern u8 D_004F80D0[];
extern void func_00176230(void *p, s32 a);
extern void func_0016F4D0(void *p, s32 a);
extern void func_00415020(s32 a, s32 b);
extern void func_00415300(void);
extern void func_00415320(void *a, void *b, s32 c);
extern void func_00415590(void *a, void *b, s32 c, s32 d);
void func_0016F430(void *p, void *q) {
    s32 g = D_004C28B0;
    func_00176230(q, g);
    func_0016F4D0(p, D_004C28B0);
    func_00415020(0xC10, D_004C28B0);
    func_00415300();
    func_00415320(D_004F80D0, p, 0xC10);
    func_00415590(D_004F80D0, p, 6, 0);
}

extern u16 *volatile D_004C2710;
extern s32 func_001CCB50(void *p);
extern void func_00175670(void *p);
void func_001CC000(u8 *p) {
    u16 *g = D_004C2710; u8 *q = *(u8 **)(p + 0x18); if (*g != *(u16 *)(q + 0x168)) {
        func_001CCB50(p);
    } else if (*(s8 *)(q + 0x151) != 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
        func_00175670(p);
    }
}

extern s8 func_00175700(void *p);
extern s16 *D_004C2794;
extern void func_001843A0(void *p);
void func_0026C0F0(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p[0x1FC] == 2 && p[0x15B] != 0) {
        p[0x1B5] = 8;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794[p[2] + 0x3E] += 1;
        p[0x15B] = 0;
    }
}
