typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00126400();
extern void func_002F1DF0();
extern void func_00197610(u8 *, u8 *, u8 *);
extern void func_001754A0(u8 *, s32, s32);
extern void func_001BB8D0();
extern void (*D_0044C040[])();
extern void *func_003DA750();
extern void func_00381050();
extern void func_00185490();
extern void func_00184540();
extern void func_001DB2E0(u8 *);
extern void func_00358DD0();
extern u8 D_0044DA60[];
extern u8 *D_004C283C;
extern void func_00170E60();
extern void func_0032F5C0();
extern f32 D_004F1FD8;
extern f32 D_004F1FDC;
extern void func_0030C470();
extern void func_003BA230();
extern void func_00309310();
extern void func_0016CBD0();
extern u32 D_004C2820;
extern s32 func_00189B90();
extern void func_00186A60();
extern u8 D_0044F620[];
extern s32 func_003D92F0();
extern void func_001843A0();
extern void func_001C8CE0();
extern void func_001757E0();
extern s16 *D_004C2794;
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C4B0();

void func_002F0090(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00126400();
        func_002F1DF0(p);
    }
}

void func_00196A10(u8 *p, u8 *q) {
    u8 *r;
    u32 t = p[5];
    p[5] = t + 1;
    r = p + 0x88;
    if (p[0x21] < 4) {
        *(u16 *)(r + 0x20) = *(u16 *)(q + 0x168);
        func_00197610(p, q, r);
        func_001754A0(p, 0x1B, (u8)(p[0x21] + 0xF));
    }
}

void func_00380FE0(u32 a, u8 b, u8 c) {
    u8 *v = func_003DA750(0, 1, 0);
    if (v) {
        *(void **)(v + 0x10) = func_00381050;
        *(u32 *)(v + 0x18) = a;
        v[0x20] = b;
        v[0x23] = c;
    }
}

void func_0026AB90(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        func_00185490(p);
        func_00184540(p);
    }
}

void func_001DB1F0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    {
        s32 v = *(s8 *)(q + 0x151);
        s8 c = v;
        if (v == 0) {
            func_001DB2E0(p);
        } else if (p[0x22] == c) {
            p[0x22] = c & 1;
            p[0x152] = 1;
            func_00175700(p);
        }
    }
}

void func_00196700(u8 *p, u8 *q) {
    u8 *r;
    u32 t = p[5];
    p[5] = t + 1;
    r = p + 0x88;
    if (p[0x21] < 4) {
        *(u16 *)(r + 0x20) = *(u16 *)(q + 0x168);
        func_00197610(p, q, r);
        func_001754A0(p, 0x1B, (u8)(p[0x21] + 0xB));
    }
}
