typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 f0; s8 f1; s8 f2; } G_c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_c;
extern G_c *D_004C29FC;
extern H_c *D_004C2794;

void func_0039A3C0(u8 *p)
{
    extern void func_0039A630(u8 *);
    extern void func_0039A210(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_00175700(u8 *);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s8 v;
    u32 n;
    s16 h;
    f32 x;

    p[0x24] = 0;
    *(s16 *)(p + 0x13E) = *(s16 *)(*(u8 **)(p + 0x18) + 0x13E);
    *(s8 *)(p + 0x13D) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13D);
    if ((*(u8 **)(p + 0x18))[4] == 2) func_0039A630(p);
    v = D_004C29FC->f2 - 1;
    D_004C29FC->f2 = v;
    if (v < 0) {
        D_004C29FC->f2 = 3;
        n = p[0x22]; n = n + 1;
        p[0x22] = n;
        p[0x22] = ((s8)(n & 0xFF)) & 0x1F;
    }
    x = func_00417500(((0x28 - p[0x22]) & 0x1F) << 11);
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * x;
    x = func_00417440(((0x28 - p[0x22]) & 0x1F) << 11);
    *(f32 *)(p + 0x60) = 2.142857074737549f * x;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        func_0039A630(p);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        v = D_004C29FC->f1 - 1;
        D_004C29FC->f1 = v;
        if (v < 0) {
            h = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = h;
            if (h < 0) {
                func_0039A210(p);
                return;
            }
            D_004C29FC->f1 = 6;
            p[0x1B5] = 0x26;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]] += 1;
        }
    }
    func_001E7F60(p);
}
