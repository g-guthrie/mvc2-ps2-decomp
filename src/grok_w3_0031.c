typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_003C1250(u8 *, s32, s32);
extern void func_00311380(u8 *);
extern void func_003113C0(u8 *);
extern void func_00316940(u8 *, u8 *);
extern void func_003175D0(u8 *);
extern void func_003182F0(u8 *);
void func_00319D40(u8 *, f32 *);
extern void func_0031C940(u8 *);
extern void func_0031CB00(u8 *);
extern void func_00186A60(u8 *, s32);
extern void func_00184540(u8 *);
extern void func_001843A0(u8 *);
extern s32 func_003D92F0(u8 *);
extern void func_003C4910(u8 *, s32, s32);
extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_001861B0(u8 *);
extern void func_0031BA60(u8 *);
extern void func_0031BB50(u8 *);
extern void func_0031BCA0(u8 *);
extern void func_0031BD90(u8 *);
extern void func_00314F40(u8 *, u8 *);
extern u8 D_0045D8D0[];
extern u8 D_0045D420[];
extern u8 D_0045D990[];
extern u8 D_004F1F45;
extern u8 D_004F1F46;
typedef void (*DispatchFn)(u8 *);

void func_00313EB0(u8 *p)
{
    s16 t;
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t != 0) {
        p[6]++;
        func_001757E0(p, 22, 9);
    }
}

void func_00313FC0(u8 *p)
{
    s16 t;
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t != 0) {
        p[6]++;
        func_001757E0(p, 22, 18);
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
}

void func_00314280(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 22, 12);
        *(s16 *)(p + 28) = *(s8 *)(p + 337);
    }
}

void func_00313BF0(u8 *p)
{
    if ((*(s16 *)(p + 28) & 1) == 0)
        func_003C1250(p, 2, 0);
    if ((*(s16 *)(p + 28) & 0xf) == 0)
        func_001E3210(p, 31);
}

void func_00314760(u8 *p, u8 *q)
{
    s16 t = *(s16 *)(p + 30);
    *(s16 *)(p + 30) = t - 1;
    if (t == 0) {
        *(s16 *)(p + 30) = 16;
        q[11] ^= 1;
        if (q[11] == 0)
            *(u32 *)(p + 92) = 0xBDD55555u;
        else
            *(u32 *)(p + 92) = 0x3DD55555u;
    }
}

void func_003168F0(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(p + 476);
    func_00175700(p);
    *(f32 *)(p + 52) = *(f32 *)(r + 52);
    func_00316940(p, q);
}

void func_00316B60(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 1245)) {
    case 0:
        p[509] = 0;
        p[439] = 0;
        break;
    case 1:
        p[509] = 1;
        p[439] = 1;
        break;
    case 2:
        p[509] = 10;
        p[439] = 1;
        break;
    default:
        break;
    }
    func_00186A60(p, 21);
}

void func_00317700(u8 *p)
{
    if (p[530] == 0) {
        if ((*(s8 *)(p + 490) & 0xf) != 0)
            func_003175D0(p);
    } else if ((*(s8 *)(p + 490) & 0xf0) != 0)
        func_003175D0(p);
}

void func_00318230(u8 *p)
{
    func_003182F0(p);
    p[6]++;
    func_001757E0(p, 18, 1);
    func_00175C00(p, 0);
}

void func_00319CE0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        p[6]++;
        func_00319D40(p, (f32 *)(D_0045D8D0 + ((u32)p[439] << 4)));
    }
}

void func_00319D40(u8 *p, f32 *src)
{
    *(f32 *)(p + 92) = src[0];
    *(f32 *)(p + 104) = src[1];
    *(f32 *)(p + 96) = src[2];
    *(f32 *)(p + 108) = src[3];
    if (*(s16 *)(p + 320) != 0) {
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        *(f32 *)(p + 104) = -*(f32 *)(p + 104);
    }
    p[525] = 2;
}

void func_0031C8F0(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 0)
        func_0031C940(p);
    else
        func_0031CB00(p);
}

void func_00311310(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 1)
        func_003113C0(p);
    else
        func_00311380(p);
    if (func_001864A0(p))
        func_001865B0(p);
}

void func_003124C0(u8 *p)
{
    s16 t;
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0)
        p[7]++;
}

void func_003165B0(u8 *p)
{
    s16 t;
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0)
        func_00184540(p);
}

void func_00312730(u8 *p)
{
    if (func_003D92F0(p)) {
        if (p[525] == 2)
            func_00184540(p);
        else
            func_001843A0(p);
    } else
        ((DispatchFn *)D_0045D420)[p[32]](p);
}

void func_00314E80(u8 *p, u8 *q)
{
    func_00314F40(p, q);
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 20, 8);
        q[9] = 0;
        q[10] = 0;
    }
}

void func_00316BD0(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 1245)) {
    case 0:
        p[509] = 0;
        p[439] = 1;
        break;
    case 1:
        p[509] = 1;
        p[439] = 1;
        break;
    case 2:
        p[509] = 10;
        p[439] = 1;
        break;
    default:
        break;
    }
    func_00186A60(p, 21);
}

void func_00318A60(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        p[6]++;
        p[655] = 0;
        p[654] = 16;
        if (p[525] == 2)
            func_003C4910(p, 4, 0);
        else
            func_003C4910(p, 0, 0);
    }
}

void func_00318C40(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        p[6]++;
        p[697] = 1;
        p[696] = 1;
        p[699] = 0;
        p[698] = 0;
        func_003C4910(p, 1, 0);
        func_003C4910(p, 3, 0);
    }
}

void func_00319000(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[6]++;
    *(u32 *)(p + 92) = 0xC1D55555u;
    *(u32 *)(p + 104) = 0x3ED55555u;
    if (*(s16 *)(p + 320)) {
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        *(f32 *)(p + 104) = -*(f32 *)(p + 104);
    }
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
    p[696] = 12;
    func_001757E0(p, 22, 26);
}

s32 func_0031B410(u8 *p)
{
    if (func_00189310(p, D_0045D990, p + 896) == 0)
        return 0;
    func_0018A990(p, p + 896);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[509] = 0;
    func_00186A60(p, 21);
    return 1;
}

void func_0031B9E0(u8 *p)
{
    func_001861B0(p);
    if (p[530] == 0) {
        if (p[525] == 0)
            func_0031BA60(p);
        else
            func_0031BB50(p);
    } else if (p[525] == 0)
        func_0031BCA0(p);
    else
        func_0031BD90(p);
}

