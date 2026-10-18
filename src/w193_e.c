typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern void func_00183d50(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_002D83C0(u8 *p)
{
    extern void func_00175700(u8 *);
    f32 *a2, *a3, *t0, *t1;
    f32 f;
    s32 v;
    func_00175700(p);
    a2 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    t1 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    f = *(f32 *)(p + 0x60);
    if (f <= 0.0f) {
        if (*(f32 *)(p + 0x38) + 68.57142639160156f <= *(f32 *)(p + 0x430)) {
            p[6]++;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *a2 = 0.0f;
            *a3 = 0.0f;
            *t0 = 0.0f;
            *t1 = 0.0f;
            D_004F1F45[0] = 3;
            D_004F1F46[0] = 1;
            func_00183d50(p);
            if (*(s8 *)(p + 0x1B2) != 0) {
                p[0x20D] = 1;
                v = p[0x1B7] * 2 + 0x15;
            } else {
                p[0x20D] = 3;
                v = p[0x1B7] * 2 + 0x18;
            }
            func_001757E0(p, 0x15, v & 0xFF);
        }
    }
}

extern void func_001863F0(u8 *);
extern void func_00184540(u8 *);
extern void func_001843A0(u8 *);
extern void func_00355060(u8 *, s32);

void func_0021F340(u8 *p)
{
    extern s8 func_00175700(u8 *);
    f32 f;
    if (!(*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430))) {
        func_001863F0(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) {
        if (p[0x20D] == 2) {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x68) = 0;
            f = 2.1428570747375488f;
            *(f32 *)(p + 0x60) += f;
            *(u32 *)(p + 0x6C) = 0xBF092492;
            func_00184540(p);
        } else {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001843A0(p);
        }
    } else if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (p[0x20D] == 2) {
            func_00355060(p, (u8)(p[0x1B7] + 3));
        } else {
            func_00355060(p, p[0x1B7]);
        }
    }
}

extern u8 D_004F20B0[];
extern void func_001757E0(u8 *, s32, s32);

void func_003A4970(u8 *p, u8 *q)
{
    u8 *e;
    s32 i;
    f32 k;
    f32 dx, dz, r, c;
    u32 a, b;
    e = D_004F20B0;
    e += (1 >> (q[2] & 1)) * 0x5B8;
    for (i = 0; i < 3; i++, e += 0xB70) {
        if (e[0] == 0) {
            continue;
        }
        k = 2.1428570747375488f;
        a = *(volatile u8 *)(e + 0x14C);
        b = e[0x14D];
        c = k * (f32)(s32)(a + b);
        dx = *(f32 *)(p + 0x34) - *(f32 *)(e + 0x34);
        dz = *(f32 *)(p + 0x38) - (c + (*(f32 *)(e + 0x38) - k * (f32)b));
        r = dx * dx + dz * dz;
        if (r < c * c) {
            if (p[0x21] == 0) {
                p[0x21] = 1;
                func_001757E0(p, 0x17, 0x1B);
                break;
            }
        } else if (p[0x21] != 0) {
            p[0x21] = 0;
            func_001757E0(p, 0x17, 0x1C);
        }
    }
}
