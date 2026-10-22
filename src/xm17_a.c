typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00174470(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern s8 func_00175700(u8 *);
extern void func_00174A40(u8 *, s32);

typedef struct { u8 pad[0x7C]; s16 w[1]; } G4;
extern G4 *D_004C2794;
typedef struct { u8 pad[0x1B2]; s8 b1b2; s8 b1b3; s8 b1b4; } SA;

void func_003A8680(u8 *p) {
    u8 *g = *(u8 **)(p + 0x18);
    SA *sa = (SA *)p;
    u8 t[16] = {0x33,0x33,0x33,0x33,0x34,0x42,0x43,0x44,0x34,0x42,0x43,0x44,0x34,0x42,0x43,0x44};
    if (p[5] == 0) {
        if (func_00174470(p) == 0) {
            { extern void func_003A8AE0(); func_003A8AE0(p); }
            return;
        }
        if (*(s8 *)(p + 0x1B3) != 0 || *(f32 *)(p + 0x38) < *(f32 *)(g + 0x430)) {
            f32 a = 3.3333332538604736f;
            f32 b = -0.006510416511446238f;
            if (*(s16 *)(p + 0x140) != 0) {
                a = -a;
                b = -b;
            }
            *(f32 *)(p + 0x5C) = a;
            *(f32 *)(p + 0x60) = -6.4285712242126465f;
            *(f32 *)(p + 0x68) = b;
            *(f32 *)(p + 0x6C) = -0.2678571343421936f;
            p[6] = 1;
            goto L8864;
        } else {
            s16 s = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = s;
            if (s == 0) {
                { extern void func_003A8A20(); func_003A8A20(p); }
                *(u32 *)(p + 0x5C) = 0;
                goto L8858;
            }
            {
                s32 b = sa->b1b4;
                if (b != 0) {
                    b -= 2;
                    sa->b1b4 = b;
                    if ((s8)b > 0) return;
                    sa->b1b4 = 0;
                    { extern void func_003A8A20(); func_003A8A20(p); }
                    { u32 q = p[0x21] - 1; p[0x21] = q; if ((q & 0xFF) == 0) goto L8854; }
                    p[0x1B5] = (t + p[0x20] * 4)[*(u32 *)(g + 0x2D4)];
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(u32 *)(p + 0x1D8) = 0;
                    D_004C2794->w[p[2]]++;
                    func_00175700(p);
                    if (p[0x20] != 0) return;
                    { extern void func_001E7F60(); func_001E7F60(p); }
                    return;
                } else {
                    if (sa->b1b2 != 0) {
                        u32 q;
                        sa->b1b2 = 0;
                        { extern void func_003A8A20(); func_003A8A20(p); }
                        q = p[0x21] - 1;
                        p[0x21] = q;
                        if ((q & 0xFF) == 0) {
                        L8854:
                            *(u32 *)(p + 0x5C) = 0;
                        L8858:
                            *(u32 *)(p + 0x60) = 0;
                            *(u32 *)(p + 0x68) = 0;
                            *(u32 *)(p + 0x6C) = 0;
                        L8864:
                            p[5]++;
                            func_001757E0(p, 0x15, 3);
                            return;
                        }
                    }
                }
            }
        }
        if (p[0x20] != 0) {
            u16 v;
            p[0x22]--;
            if (*(s16 *)(p + 0x140) != 0) p[0x22] += 2;
            p[0x22] &= 0x1F;
            { u32 q = p[7] - 1; p[7] = q; if ((q & 0xFF) == 0) {
                p[7] = 3;
                v = (u16)(*(s16 *)(p + 0x1E) + 0x64);
                if (v > 0x3E8) v = 0x3E8;
                *(s16 *)(p + 0x1E) = v;
            } }
            func_00174A40(p, *(s16 *)(p + 0x1E));
        }
        if (*(s8 *)(g + 0x539) == 0) {
            u16 h = *(u16 *)(g + 0x35E);
            f32 z = 0.0f;
            if (h & 0x2000) z = 3.75f;
            if (h & 0x1000) z = -3.75f;
            *(f32 *)(p + 0x38) += z;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_00175700(p);
        { extern void func_001E7F60(u8 *); func_001E7F60(p); }
        return;
    }
    if (p[6] != 0) *(s8 *)(p + 0x13C) ^= 1;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) p[4]++;
}
