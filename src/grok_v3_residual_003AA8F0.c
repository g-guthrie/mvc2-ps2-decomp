typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_003ACC30(u8 *, u8 *);
extern void (*D_00473A80[])(u8 *);

void residual_003AA8F0(u8 *p, u8 *a1)
{
    u8 *parent = *(u8 **)(p + 0x18);
    u8 kind;
    u8 *n;
    int a3;

    if (parent[5] != 0)
        goto fallback;
    kind = parent[0x1E4];
    if (kind == 0x15) {
        if (parent[0x1FD] != a1[0x36])
            goto fallback;
    }
    if (kind == 0x1D) {
        if (parent[0x1FD] != a1[0x36])
            goto fallback;
    }
    if (kind == 0x15)
        goto body;
    if (kind == 0x1D)
        goto body;
    goto fallback;
body:
    parent[0x1FE] = 1;
    a3 = 0;
    a1[0xE] = 0xE;
    n = p;
    *(f32 *)(a1 + 0x10) = *(f32 *)(parent + 0x34) + *(f32 *)(a1 + 0x18);
    *(f32 *)(a1 + 0x14) = *(f32 *)(parent + 0x38) + *(f32 *)(a1 + 0x1C);
    p[0x24] = *(s8 *)(parent + 0x24);
    p[0x13C] = 0;
    a1[0x34] = 0;
    a3 += 8;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    n = *(u8 **)(n + 0xC); n[0x13C] = 0;
    if (a3 < 14) {
        do {
            n = *(u8 **)(n + 0xC);
            a3 += 1;
            n[0x13C] = 0;
        } while (a3 < 14);
    }
    D_00473A80[p[5]](p);
    return;
fallback:
    func_003ACC30(p, a1);
}
