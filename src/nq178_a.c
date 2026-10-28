typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x55]; s8 f55; s8 f56; u8 pad1[0x53]; s8 fAA; } G_c;
extern u8 *D_004C2794;
extern G_c *D_004C2840;
extern u8 D_004D18A0[];
typedef struct { u8 pad[0x434]; s16 f434; s16 f436; s16 f438; } A_c;

void func_0018D340(u8 *a, u8 *b) {
    extern s32 func_0018B890(u8 *, s32, u8 *, s32);
    extern s32 fptosi(f32);
    extern void func_0018FEB0(u8 *);
    extern void func_00190540(u8 *, s32);
    extern void func_001902F0(u8 *);
    u8 *s0;
    s16 t;
    s16 u;
    s32 m;
    s32 s1;
    s32 r;
    A_c *sa = (A_c *)a;
    if (*D_004C2794 != 4) return;
    s0 = *(u8 **)(a + 0x1D0);
    if (a[1] == 9) {
        if (*(s8 *)(b + 0x1B0) & 2) return;
    }
    t = *s0;
    if (t == 0) return;
    if ((*(u16 *)(b + 0x1C0) & 0x100) == 0) {
        if ((s0[2] & 0xB0) == 0) return;
    }
    r = *(s32 *)(a + 0x1CC);
    if (r == 0) r = *(s32 *)(a + 0x220);
    s1 = (s16)fptosi((f32)(s16)func_0018B890(a, r, s0, t) / 8.0f);
    if (s1 <= 0) s1 = 1;
    if ((m = D_004C2840->f56) == 1) {
        s1 = 0;
    } else if (m == 2) {
        s1 = (s16)(s1 + s1);
    }
    if ((s0[2] & 0x30) == 0) {
        if (*(u16 *)(b + 0x1C0) & 0x100) {
            if (*(s16 *)(a + 0x434) == 1) return;
        }
    }
    if (s0[0x12] & 2) return;
    if (D_004D18A0[0] != 4) return;
    if (*(s16 *)(a + 0x434) == 0) return;
    if (D_004C2840->f55 != 1) {
        u = *(s16 *)(a + 0x438) - s1;
        *(s16 *)(a + 0x438) = u;
        if (u <= 0) sa->f438 = 0;
    }
    *(s16 *)(a + 0x27C) = *(s16 *)(a + 0x290) = *(s16 *)(a + 0x434);
    u = *(s16 *)(a + 0x434) - s1;
    *(s16 *)(a + 0x434) = u;
    if (u <= 0) {
        if ((s0[0x12] & 0x20) == 0 && D_004C2840->fAA == 0) {
            func_0018FEB0(a);
        } else {
            *(s16 *)(a + 0x434) = 1;
            if (*(s16 *)(a + 0x438) <= 0) sa->f438 = 1;
        }
    }
    func_00190540(a, s1);
    func_001902F0(a);
}
