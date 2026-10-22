typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A3;

void func_002373B0(u8 *p, u8 *q) {
    extern void func_00126400(void);
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern u32 func_00237E40(u8 *, u32);
    extern void func_00237D40(u8 *, s32);
    extern s32 func_00237BC0(u8 *, u8 *);
    extern s32 func_00237CD0(u8 *, u8 *);
    s16 t;
    u8 *a;
    s32 v;
    u32 d;
    s32 m;
    s32 w;
    u32 e;
    p[0x40C] = 2;
    p[0x33C] = 5;
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) goto A;
    if (q[0x19] != 0) {
        if (*(s16 *)(p + 0x274) == 0) goto A;
    }
    if (D_004D18A3 != 0) goto A;
    w = *(s8 *)(p + 0x1B2);
    if (w == 0) goto B;
    if (((s8)w & 1) != 0) goto A;
    a = *(u8 **)(p + 0x1C4);
    if (a[3] != 0) goto A;
    if (a[5] != 3) goto A;
    q[0x19] = 1;
    *(u8 **)(q + 0x20) = a;
    if (q[0x18] != 0) goto B;
A:
    p[6] += 1;
    p[7] = 0;
    *(f32 *)(p + 0x5C) = -(*(f32 *)(p + 0x5C) / 16.0f);
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    func_00126400();
    func_00185490(p);
    func_001757E0(p, 0x16, 3);
    return;
B:
    if (q[0x19] != 0 && *(s8 *)(p + 0x1B2) == 0) {
        s32 u = q[0x17] - 1;
        q[0x17] = u;
        if ((u & 0xFF) == 0) {
            q[0x17] = 5;
            q[0x1E] = p[0x22];
            d = func_00237E40(p, *(u32 *)(q + 0x20)) & 0xFF;
            d = (d - q[0x1E]) & 0xFF;
            if (d != 0) {
                e = d & 0x3F;
                e &= ~5;
                m = e != 0 ? 0xFF : 1;
                p[0x22] = (s8)q[0x1E] + (s8)m;
                func_00237D40(p, p[0x22]);
            }
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00237BC0(p, q) != 0) {
        p[7] += 1;
        q[0x1C] = 0;
        v = (q[0x1B] & 8) >> 2;
        v += 4;
        if (!(*(f32 *)(p + 0x5C) <= 0.0f)) v += 1;
        func_001757E0(p, 0x16, v & 0xFF);
    } else if (func_00237CD0(p, q) != 0) {
        p[7] += 1;
        q[0x1C] = 1;
        v = (q[0x1B] & 1) << 1;
        v += 8;
        if (!(*(f32 *)(p + 0x60) <= 0.0f)) v += 1;
        func_001757E0(p, 0x16, v & 0xFF);
    }
}
