typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_p;
extern G_p *D_004C2794;
extern u16 *D_004C2990;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_00379620(u8 *p)
{
    extern void func_003797A0(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *a2;
    s8 c;
    f32 k, t;
    u8 *q;
    a2 = *(u8 **)(p + 0x18);
    if (*D_004C2990 != *(u16 *)(a2 + 0x168)) {
        func_003797A0(p);
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(a2 + 0x34);
    if (*(s16 *)(p + 0x140) != 0)
        *(f32 *)(p + 0x34) += 6.666666507720947f;
    else
        *(f32 *)(p + 0x34) += 6.666666507720947f;
    q = *(u8 **)(p + 0x18);
    k = 12.857142448425293f;
    t = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x38) = t;
    *(f32 *)(p + 0x38) = t - k;
    if (*(s8 *)(a2 + 0x1B4) != 0 && (*(s8 *)(p + 0x150) & 0x80) == 0)
        return;
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (*(s16 *)(p + 0x1C) == 0) {
            *(s16 *)(p + 0x1C) = 1;
            D_004F1F45[0] = 2;
            D_004F1F46[0] = 1;
        }
    }
    if (func_00175700(p) < 0) {
        func_003797A0(p);
        return;
    }
    c = *(s8 *)(p + 0x151);
    if (c != 0) {
        p[0x1B5] = c + 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 0;
    }
    func_001E7F60(p);
}
