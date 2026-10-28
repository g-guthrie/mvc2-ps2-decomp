typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_001DCA90(u8 *p, u8 *q)
{
    extern int func_00175700(u8 *);
    extern void func_003BEF10(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001DCDC0(u8 *, u8 *);
    s16 h;
    u8 t;
    if (p[0x21] == 0) {
        if (*(f32 *)(p + 0x38) < 377.1428527832031f + *(f32 *)(q + 0x430))
            *(f32 *)(p + 0x38) += 4.285714149475098f;
        if (p[5] == 0) {
            *(s8 *)(p + 0x13C) ^= 1;
            func_00175700(p);
            if (*(s16 *)(p + 0x1C) == 0x1E) func_001757E0(p, 0x16, 0x13);
            if (*(s16 *)(p + 0x1C) > 0x50 && *(s8 *)(p + 0x151) != 0) {
                t = p[0x22];
                t += 0x20;
                p[0x22] = t;
                if (t & 0x80) {
                    *(s16 *)(p + 0x1E) ^= 1;
                    func_003BEF10(p, *(u16 *)(p + 0x1E));
                }
            }
            if (q[0x1E4] == 0x1D && q[5] == 0) {
                h = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = h;
                if (h >= 0) return;
            }
            p[5]++;
            *(s8 *)(p + 0x13C) |= 2;
            func_001757E0(p, 0x16, 0x12);
        } else {
            if ((s8)func_00175700(p) < 0) {
                p[4]++;
                p[0x13C] = 0;
            }
        }
        return;
    }
    if (q[5] != 0 || q[0] == 0) {
        func_001DCDC0(p, q);
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    func_00175700(p);
}
