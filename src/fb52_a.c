typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x460];
    f32 f460;
    f32 f464;
    f32 f468;
    f32 f46C;
    u8 pad470[0x498 - 0x470];
    f32 f498;
    u8 pad49C[4];
    f32 f4A0;
    u8 pad4A4[0x4C8 - 0x4A4];
    f32 f4C8;
} P165E50;

extern s32 func_0016B250(P165E50 *p, s32 n);
extern void func_0016B0C0(P165E50 *p, s32 q, s32 n);
extern s32 func_00166C80(P165E50 *p, s32 q, s32 n);

s32 func_00165E50(P165E50 *p, s32 q) {
    f32 lo, hi, t;
    if (func_0016B250(p, 4) == 0) {
        return 0;
    }
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 3);
    p->f460 = p->f4C8;
    func_0016B0C0(p, q, 4);
    p->f464 = p->f4C8;
    func_0016B0C0(p, q, 3);
    p->f468 = p->f4C8;
    func_0016B0C0(p, q, 4);
    p->f46C = p->f4C8;
    if (p->f460 != 0.0f) {
        lo = p->f468 - p->f460;
        hi = p->f468 + p->f460;
        if (!(lo <= hi)) {
            t = lo;
            lo = hi;
            hi = t;
        }
        if (!(lo <= p->f498) || hi < p->f498) {
            return func_00166C80(p, q, 0);
        }
    }
    if (p->f464 != 0.0f) {
        lo = p->f46C - p->f464;
        hi = p->f46C + p->f464;
        if (!(lo <= hi)) {
            t = lo;
            lo = hi;
            hi = t;
        }
        if (!(lo <= p->f4A0) || hi < p->f4A0) {
            return func_00166C80(p, q, 0);
        }
    }
    return func_00166C80(p, q, 1);
}
