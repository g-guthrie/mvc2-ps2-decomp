typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0036D9F0(u8 *p, s32 arg)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0036DF50(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern f32 func_00417440(s32);
    u8 *q;
    s16 h;
    s32 b;
    u32 t;
    f32 f;

    if (*(f32 *)(p + 0x50) > 1.0f) {
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
    } else {
        *(f32 *)(p + 0x50) += 0.03999999910593033f;
        *(f32 *)(p + 0x54) += 0.03999999910593033f;
    }
    b = *(s8 *)(p + 0x1B2);
    if (b != 0) {
        q = *(u8 **)(p + 0x1C4);
        if (q[3] == 0) {
            if (q[0x425] == 0) {
                if ((((s8)b) & 1) == 0) {
                    if ((*(u32 *)(q + 0x428) & 0x07000000) != 0) {
                        t = p[5];
                        p[5] = t + 1;
                        *(s16 *)(p + 0x1C) = 0x28;
                        func_001757E0(p, 0x17, 0x1D);
                        return;
                    } else {
                        p[5] = 4;
                        *(s16 *)(p + 0x1C) = 0x12C;
                        *(s16 *)(p + 0x1E) = 0x5A;
                        p[0x23] = q[1];
                        *(s32 *)(p + 0x5C) = 0;
                        *(s32 *)(p + 0x60) = 0;
                        *(s32 *)(p + 0x68) = 0;
                        *(s32 *)(p + 0x6C) = 0;
                        func_001757E0(p, 0x17, 0x1D);
                        func_0036DF50(p, arg);
                    }
                } else {
                    t = p[5];
                    p[5] = t + 1;
                    *(s16 *)(p + 0x1C) = 0x28;
                    func_001757E0(p, 0x17, 0x1D);
                }
            } else {
                t = p[5];
                p[5] = t + 1;
                *(s16 *)(p + 0x1C) = 0x28;
                func_001757E0(p, 0x17, 0x1D);
            }
        } else {
            t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x1C) = 0x28;
            func_001757E0(p, 0x17, 0x1D);
        }
    } else {
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x17, 1);
        }
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        f = func_00417440((s32)((u32)(s32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1E) / 360.0) & 0xFFFFu));
        f = 5.0f * f;
        *(f32 *)(p + 0x38) += f;
        h = *(s16 *)(p + 0x1E) - 6;
        *(s16 *)(p + 0x1E) = h;
        if (h == 0) *(s16 *)(p + 0x1E) = 0x168;
        func_001E7F60(p);
    }
}
