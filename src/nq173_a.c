typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003562B0(u8 *);

void func_00356080(u8 *p)
{
    u8 *o = *(u8 **)(p + 0x18);
    u32 t;
    if (p[0x20] == 6) {
        if (p[5] == 0) {
            func_00175700(p);
            *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
            if ((s8)p[0x151] == 0) return;
            p[0x151] = 0;
            t = p[5]; p[5] = t + 1;
        } else if (p[6] == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if ((s8)p[0x1B2] != 0 || (s8)p[0x1B3] != 0) {
                t = p[6]; p[6] = t + 1;
                return;
            }
            if (*(f32 *)(p + 0x38) <= *(f32 *)(o + 0x430)) {
                t = p[6]; p[6] = t + 1;
                *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
                return;
            }
            func_001E7F60(p);
        } else {
            if ((s8)func_00175700(p) >= 0) return;
            t = p[4]; p[4] = t + 1;
            func_003562B0(p);
            return;
        }
        return;
    }
    if ((s8)o[0x1B4] == 0) {
        if ((s8)func_00175700(p) < 0) {
            t = p[4]; p[4] = t + 1;
            func_003562B0(p);
            return;
        }
        if (o[0x214] != 0) {
            if ((s8)func_00175700(p) < 0) {
                t = p[4]; p[4] = t + 1;
                func_003562B0(p);
                return;
            }
        }
    }
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (p[0x20] != 4) { func_001E7F60(p); return; }
}
