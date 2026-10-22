typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0023C180(u8 *p)
{
    extern void func_00175700();
    extern void func_001757E0();
    s16 v;
    f32 x, y;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s16 *)(p + 0x1E);
    if (v == 0) {
        if (p[0x23] != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            p[7] = 0;
            return;
        }
    } else {
        *(s16 *)(p + 0x1E) = v - 1;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x169] = 0x15;
        p[0x168] = *(s8 *)(p + 0x1B7) + 2;
        func_001757E0(p, p[0x169], p[0x168]);
        if (p[0x1E6] != 0) {
            x = 6.666666507720947f;
        } else {
            x = -6.666666507720947f;
        }
        *(f32 *)(p + 0x5C) = x;
        if (p[0x1E6] != 0) {
            y = -0.2083333283662796f;
        } else {
            y = 0.2083333283662796f;
        }
        *(f32 *)(p + 0x68) = y;
    }
}

void func_0031EAB0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_0019B110();
    extern void func_00354460();
    extern void func_001757E0();
    extern void func_001E3210();
    s8 r;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0019B110(p, 5);
        func_00354460(p, 0);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x19));
        func_001E3210(p, 0x1F);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(u32 *)(p + 0x5C) = 0xC12D5555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
}

void func_002D3EE0(u8 *p)
{
    extern void func_00175700();
    extern void func_002D4240();
    extern void func_001757E0();
    extern void func_001266A0();
    extern void func_001E3710();
    f32 *a3, *t0, *t1, *t2;
    s16 h;
    func_00175700(p);
    a3 = (f32 *)(p + 0x5C);
    t1 = (f32 *)(p + 0x68);
    t0 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t2 = (f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
        p[6] = 5;
        p[0x20D] = 0;
        func_002D4240(p);
        return;
    }
    *(s16 *)(p + 0x1E) -= 1;
    if (*(s16 *)(p + 0x1E) < 0) {
        if (p[0x1E6] != 0) {
            if ((*(s8 *)(p + 0x211) & 1) == 0) return;
        } else {
            if ((*(s8 *)(p + 0x211) & 2) == 0) return;
        }
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        *a3 = 0;
        *t0 = 0;
        *t1 = 0;
        *t2 = 0;
        func_001757E0(p, 0x15, 0x11);
        func_001266A0(p, 1, 0xD);
        func_001E3710(p, 0x34);
    }
}

void func_00294650(u8 *p)
{
    extern void func_0015D010();
    extern void func_0018C6E0(void *);
    extern void func_001757E0();
    f32 v[4];
    v[0] = 0;
    if (*(s8 *)(p + 0x1E7) >= 0) {
        *(u32 *)&v[0] = 0xC0D55555;
        if (p[0x1E6] != 0) {
            v[0] = -v[0];
        }
        if (*(s8 *)(p + 0x1E7) != 0) {
            v[0] = -v[0];
        }
    }
    *(f32 *)(p + 0x5C) = v[0];
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    if (p[0x22] & 1) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    *(u32 *)&v[0] = 0xC292AAAA;
    *(u32 *)&v[1] = 0x42D64924;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) /= 2.0f;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

