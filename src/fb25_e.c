typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00472A80[];

void func_003A0AE0(u8 *p, u8 *q)
{
    u8 *r;
    s32 v;
    s32 h;
    extern s32 func_00175700(u8 *);
    extern s32 func_00174170(void);
    extern s32 func_00174240(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_003A0E80(u8 *, u8 *, s32, s32);
    extern void func_001D1B80(u8 *, u8 *, s32);

    r = q + 0x2B8;
    switch (p[5]) {
    case 0:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if ((s8)func_00175700(p) < 0) {
            p[5]++;
            if (p[0x20] == 0) {
                *(s16 *)(p + 0x1C) = 3;
                *(s16 *)(p + 0x1E) = q[0x1B7];
                p[0x21] = 1;
            } else {
                *(s16 *)(p + 0x1C) = 0x20;
                *(s16 *)(p + 0x1E) = D_00472A80[func_00174170() & 0xF];
                p[0x21] = 6;
            }
            func_001757E0(p, 0x17, (u8)(p[0x21] + *(s16 *)(p + 0x1E)));
        }
        func_001E7F60(p);
        break;
    case 1:
        if (*(s8 *)(q + 0x1B3) != 0 || *(s8 *)(p + 0x1B3) != 0) {
            p[5]++;
            func_001757E0(p, 0x17, 5);
        } else if (q[0x1E4] == 0x1C && q[0x269] != 8) {
            p[5]++;
            func_001757E0(p, 0x17, 4);
        } else {
            if ((*(s8 *)(p + 0x151) & 1) != 0) {
                p[0x151] = 0;
                func_003A0E80(p, q, p[0x20], *(s16 *)(p + 0x1E));
            }
            if ((*(s8 *)(p + 0x151) & 2) != 0) {
                p[0x151] = 0;
                func_001D1B80(p, q, *(s16 *)(p + 0x1E));
            }
            if ((s8)func_00175700(p) < 0) {
                h = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = h;
                if ((s16)h == 0) {
                    p[5]++;
                    func_001757E0(p, 0x17, 4);
                } else if (p[0x20] != 0) {
                    *(s16 *)(p + 0x1E) = D_00472A80[func_00174170() & 0xF];
                    func_001757E0(p, 0x17, (u8)(p[0x21] + *(s16 *)(p + 0x1E)));
                }
            }
            func_001E7F60(p);
        }
        break;
    case 2:
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            p[5]++;
            *(u32 *)(p + 0x5C) = 0x4162AAAA;
            if (*(s16 *)(p + 0x140) != 0) {
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            }
            *(u32 *)(p + 0x60) = 0x411A4924;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
        }
        break;
    case 3:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (func_00174240(p) == 0) {
            p[4]++;
            p[5] = 0;
            p[0x13C] = 0;
            *r = 0;
        }
        break;
    }
}
