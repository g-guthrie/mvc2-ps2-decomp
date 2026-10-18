typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002C4A70(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_0018FDB0();
    extern void func_00154790();
    extern void func_001266A0();
    f32 v[4];
    u8 *q;
    s32 t;
    if (func_00175700(p) < 0) func_001843A0(p);
    t = *(s8 *)(p + 0x151);
    if (t != 0) {
        if (t < 0) {
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x1B5] = 0x4B;
            func_0018FDB0(p);
            v[1] = 122.14285278320312f + *(f32 *)(p + 0x38);
            if (*(s16 *)(p + 0x140) != 0) *(u32 *)&v[0] = 0x42BE0000;
            else *(u32 *)&v[0] = 0xC2BE0000;
            v[0] += *(f32 *)(p + 0x34);
            v[2] = *(f32 *)(p + 0x3C);
            func_00154790(v, *(s16 *)(p + 0x140), 1, 0);
        } else {
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 1;
            q[0x20D] = 2;
            func_001266A0(p, 0, 0);
            q[0x1B5] = 0x23;
        }
    }
}

void func_001C6900(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 f;
    s32 h;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (q[0x1E4] != 0x16) {
        p[7] = 3;
        return;
    }
    h = *(s16 *)(p + 0x140);
    if (h == 0) f = 80.0f + *(f32 *)(q + 0x34);
    else f = *(f32 *)(q + 0x34) - 80.0f;
    if ((h == 0 && *(f32 *)(p + 0x34) <= f) || (h != 0 && !(*(f32 *)(p + 0x34) < f))) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x34) = f;
        *(s16 *)(q + 0x1C) = 0;
        func_001757E0(p, 0x19, 0x19);
    }
}

void func_0018E5A0(u8 *p, u8 *q) {
    extern void func_0018C970();
    extern void func_0018E810();
    extern void func_001757E0();
    u8 *o;
    u32 s;
    p[0x247] = 0x18;
    if ((*(u16 *)(q + 0x1C0) & 0x800) == 0) p[0x1EE] = 0xFF;
    p[0x248] = 0;
    if ((o = *(u8 **)(p + 0x1CC)) == 0) o = *(u8 **)(p + 0x220);
    s = p[0x1BA];
    if (p[0x1E6] != 0) {
        if (*(f32 *)(p + 0x34) < *(f32 *)(o + 0x34) - 23.333332061767578f) p[0x1BA] = s ^ 1;
    } else {
        if (!(*(f32 *)(p + 0x34) <= 23.333332061767578f + *(f32 *)(o + 0x34))) p[0x1BA] = s ^ 1;
    }
    func_0018C970(p, q);
    p[0x1BA] = s;
    func_0018E810(p, q);
    if (p[0x1F5] == 0) p[0x1F5] = 1;
    p[0x20D] = 3;
    func_001757E0(p, 0xD, 0xD);
}
