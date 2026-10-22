typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

static void func_001CB680(u8 *p, u8 *o)
{
    s32 n;
    u32 *d, *s;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(V3 *)(p + 80) = *(V3 *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
}

void func_001CB730(u8 *a, u8 *b)
{
    extern s32 func_001754A0(u8 *, s32, s32);
    extern s32 func_00175670(u8 *);
    s32 r;
    if (a[4] == 0) {
        func_001CB680(a, b);
        func_001754A0(a, 0x1B, 0x18);
    }
    a[0x24] = 0xB;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
    r = func_00175670(a);
    if ((s8)r < 0) {
        a[4]++;
        a[0x13C] = 0;
    }
}

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
static void func_002555E0(u8 *p) {
    if (S(p, 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}

void func_0025AC10(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    func_002555E0(p);
    if (*(s8 *)(p + 0x153) < 0) {
        p[6]++;
        *(s16 *)(p + 0x140) ^= 1;
        func_001757E0(p, 0x16, 0xA);
    }
    func_00175700(p);
}

void func_001CBBC0(u8 *a, u8 *b)
{
    extern s32 func_001754A0(u8 *, s32, s32);
    extern s32 func_00175670(u8 *);
    extern void func_0015E630(u8 *);
    f32 k;
    s16 v;
    if (*(u32 *)(a + 0xD4) != *(u16 *)(b + 0x168)) {
        a[4]++;
        a[0x13C] = 0;
        a[0] = 0;
        return;
    }
    if (a[4] == 0) {
        a[0] = 1;
        func_001CB680(a, b);
        k = 106.66666412353516f;
        v = *(s16 *)(b + 0x140);
        *(s16 *)(a + 0x140) = v;
        if (v != 0) k = -k;
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + k;
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x430);
        func_001754A0(a, 0x1B, 0x35);
        a[0x159] = 0xE0;
        func_0015E630(a);
    }
    func_00175670(a);
    a[0x159] = 0xE0;
}
