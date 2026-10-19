typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001845F0(u8 *);
extern s32 func_00184720(u8 *);
extern void func_00175C00(u8 *, s32);
extern s32 func_00185A90(u8 *);
extern s32 func_001864a0(u8 *);
extern void func_001865B0(u8 *);
extern void func_0018F460(u8 *);

void func_0017D840(u8 *p)
{
    if (p[1] == 0x25) {
        if (func_00175700(p) < 0) {
            p[5] = 0;
            p[0x1E7] = 1;
            func_001845F0(p);
            return;
        }
        {
            void (*cb)(u8 *) = *(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60);
            cb(p);
        }
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x20D] = 2;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            if (func_00184720(p) != 0) {
                func_00175C00(p, 1);
            } else if (func_00185A90(p) != 0) {
                func_00175C00(p, 1);
            } else if (func_001864a0(p) != 0) {
                func_00175C00(p, 1);
                func_001865B0(p);
            }
        }
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_0018F460(p);
        if (func_00175700(p) < 0) {
            p[5] = 0;
            p[0x1E7] = 1;
            func_001845F0(p);
        } else if (func_00184720(p) == 0) {
            if (func_00185A90(p) == 0) {
                if (func_001864a0(p) != 0) {
                    func_001865B0(p);
                }
            }
        }
    }
}
