typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

extern f32 *D_004C2708;
static void func_001C88F0(u8 *p)
{
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x34) += D_004C2708[0];
    else
        *(f32 *)(p + 0x34) -= D_004C2708[0];
    *(f32 *)(p + 0x38) += D_004C2708[1];
}
extern void func_00175700(u8 *);
extern void func_001C8AE0(u8 *);

extern f32 *D_004C26D0;
static void func_00192E30(u8 *p)
{
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x34) += D_004C26D0[0];
    else
        *(f32 *)(p + 0x34) -= D_004C26D0[0];
    *(f32 *)(p + 0x38) += D_004C26D0[1];
}
extern void func_00193060(u8 *);

#define F(p, o) (*(f32 *)((p) + (o)))
static void func_00396EC0(u8 *d, u8 *s, u8 *a) {
    F(d, 52) = F(s, 52);
    F(d, 56) = F(s, 56);
    F(d, 52) += F(a, 8);
    F(d, 56) += F(a, 12);
}
extern void (*D_004C1E40[2])(u8 *, u8 *, u8 *);

void func_00397140(u8 *p, u8 *q, u8 *r) {
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_00396EC0(p, q, r);
    D_004C1E40[p[5]](p, q, r);
}
