typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; u32 f1c; } G_b;
extern G_b *D_004C2840;

void func_002D9850(u8 *p)
{
    extern s32 func_00174170();
    extern void func_001D0F90(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00175C00(u8 *, s32);
    s32 v;

    *(s32 *)(p + 0x2B8) = *(s8 *)(p + 0x161);
    v = *(s32 *)(p + 0x2C0);
    if (v != 0) *(s32 *)(p + 0x2C0) = v - 1;
    if (p[0x215] != 0) {
        v = *(s32 *)(p + 0x2C8) - 1;
        *(s32 *)(p + 0x2C8) = v;
        if (v == 0) p[0x215] = 0;
    }
    if (p[0x1E4] == 0) {
        v = *(s32 *)(p + 0x2C4) - 1;
        *(s32 *)(p + 0x2C4) = v;
        if (v < 0) {
            *(s32 *)(p + 0x2C4) = (D_004C2840->f1c & 0x1F) + 0x20;
            func_001D0F90(p, 0, func_00174170() & 1);
        }
    }
    v = *(s32 *)(p + 0x2F8);
    if (v != 0) {
        *(s32 *)(p + 0x2F8) = v - 1;
    } else {
        v = *(s32 *)(p + 0x2E4) - 1;
        *(s32 *)(p + 0x2E4) = v;
        if (v < 0) {
            *(s32 *)(p + 0x2E4) = 1;
            *(s32 *)(p + 0x2E8) += 1;
            *(s32 *)(p + 0x2E8) &= 3;
            func_00176160(p, 1, *(s32 *)(p + 0x2E8) + 6, 1);
            *(s32 *)(p + 0x2EC) += 1;
            if (*(s32 *)(p + 0x2EC) > 4) *(s32 *)(p + 0x2EC) = 0;
            func_00176160(p, 2, *(s32 *)(p + 0x2EC) + 0xA, 1);
        }
        v = *(s32 *)(p + 0x300);
        if (v > 0) {
            if (*(u16 *)(p + 0x168) != *(u16 *)(p + 0x304)) {
                *(s32 *)(p + 0x300) = 0;
                func_00175C00(p, 1);
                return;
            }
            v = v - 1;
            *(s32 *)(p + 0x300) = v;
            func_00176160(p, 0, ((v % 6) >> 1) + (p[0x25] * 3 + 0x10), 1);
        }
    }
}
